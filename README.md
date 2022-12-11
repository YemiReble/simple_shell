# 0x16. C - Simple Shell

#### Write a simple UNIX command interpreter.
[x] C
[x] Group project
[x] Syscall

###Compilation & Testing
This shell can be compiled this way for testing:

	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

#### Testing
Interactive mode:

	$ ./hsh
	($) /bin/ls
	hsh main.c shell.c
	($)
	($) exit
	$

Non-interactive mode:

	$ echo "/bin/ls" | ./hsh
	hsh main.c shell.c test_ls_2
	$
	$ cat test_ls_2
	/bin/ls
	/bin/ls
	$
	$ cat test_ls_2 | ./hsh
	hsh main.c shell.c test_ls_2
	hsh main.c shell.c test_ls_2
	$
Section waiting for more updates...
