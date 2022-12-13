# 0x16. C - Simple Shell

## Write a simple UNIX command interpreter.
- [x] C
- [x] Group project
- [x] Syscall
- [x] Betty linter

## Introduction
This is a simple shell program inspired by early Unix shells like the Thompson, Korn, and C shells. Michelle Giraldo and Justin Majetich wrote it for a ALX School project. The shell provides an interface for users to interact with the kernel, as well as a number of built-in tools to facilitate this interaction. In interactive mode as seen below, the program solicits a command line from the user via the terminal, parses this input for valid commands, and executes them. 

Users can also pipe output from other commands into the shell to run it in non-interactive mode. In this mode, the shell will not prompt the user for input and will exit automatically when the commands received are completed. Refer to the included man page for more information on functionality and support.

### General Project Requirement
* All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Shell should not have any memory leaks
* No more than 5 functions per file
* All header files should be include guarded
* Write a README with the description of the project

### Compilation & Testing
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

#### Command Execution
After receiving a command, hsh tokenizes it into words using " " as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. hsh then proceeds with the following actions:

1. If the first character of the command is neither a slash (\) nor dot (.), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
1. If the first character of the command is none of a slash (\), dot (.), nor builtin, hsh searches each element of the PATH environmental variable for a directory containing an executable file by that name.
1. If the first character of the command is a slash (\) or dot (.) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.

#### Exit Status
hsh returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.

If a command is not found, the return status is 127; if a command is found but is not executable, the return status is 126.

All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

#### Signals
While running in interactive mode, hsh ignores the keyboard input Ctrl+c. Alternatively, an input of end-of-file (Ctrl+d) will exit the program.

User hits Ctrl+d in the third line.

	$ ./hsh
	$ ^C
	$ ^C
	$

### Conclusion
#### What we learn at the end of this project
* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What EOF / “end-of-file” is.


# Authors Info
 👤 **SULAIMON ABODUNRIN OPEYEMI**

 - GitHub: [@yemireble](https://github.com/yemireble)
 - Twitter: [@yemireble](https://twitter.com/yemireble)
 - LinkedIn: [LinkedIn](https://linkedin.com/in/)


 👤 **INENE ISRAEL OLUWANIYI**

 - GitHub: [@israel-09](https://github.com/israel-09)
 - LinkedIn: [LinkedIn](linkedin.com/in/????)
 - Twitter: [@????](https://twitter.com/?????)
