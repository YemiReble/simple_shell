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



/* Macros and prototype function
   for getline section */
#define USE_GETLINE 0
size_t input_buf(info_t *info, char **buf, size_t *len);




#endif /* END ALL PROCESS FOR SHELL_H */
