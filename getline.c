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
