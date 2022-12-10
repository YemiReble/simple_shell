#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Macros and prototype function*/

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/* getline functions */
size_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
ssize_t read_buf(info_t *info, char *buf, size_t *i);

/**
 * struct liststr - singly linked list
 * @num: the number nodes
 * @str: string stringing :)
 * @next: point to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct getinfo - contains pseudo-arguements to pass into a function.
 *@arg: getline string that containes arguements
 *@argv: array strings from arg
 *@path: string path of the current command
 *@argc: argument count
 *@line_count: error count
 *@err_num: error code for exit()
 *@linecount_flag: count lines of input
 *@fname: program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ of LL env
 *@history: history node
 *@alias: alias node
 *@env_changed: if environ was changed
 *@status: return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the file description that read line input
 *@histcount: history line number count
 */
typedef struct getinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* _atoi function prototypes */
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);


#endif /* END ALL PROCESS FOR SHELL_H */
