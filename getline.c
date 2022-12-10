#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t y = 0;
	size_t len_i = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		y = getline(buf, &len_i, stdin);
#else
		y = _getline(info, buf, &len_i);
#endif
		if (y > 0)
		{
			if ((*buf)[y - 1] == '\n')
			{
				 /* if there is trail, remove trailing newline */
				(*buf)[y - 1] = '\0';
				y--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = y;
				info->cmd_buf = buf;
			}
		}
	}
	return (y);
}
/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buf + i; /* get pointer for return */
		check_chain(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}
	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}
