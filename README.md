# The Simple Shell

**Written by Johanne ESSIERE and Seth NAMARA**

## What is the Shell?
A *Shell* provides you with an interface to the Unix system. It gathers input from you and executes programs based on that input. When a program finishes executing, it displays that program's output.

*Shell* is an environment in which we can run our commands, programs, and *shell* scripts. There are different flavors of a shell, just as there are different flavors of operating systems. Each flavor of shell has its own set of recognized commands and functions.

## Shell Prompt
The prompt, $, which is called the command prompt, is issued by the shell. While the prompt is displayed, you can type a command.

Shell reads your input after you press Enter. It determines the command you want executed by looking at the first word of your input. A word is an unbroken set of characters. Spaces and tabs separate words.

Following is a simple example of the echo command, which displays text to the terminal. Try the command:

        echo Hello, Johanne

then press enter. You should see the text Hello, Johanne printed back to you.

##Project Description
The purpose of this project is to create a simple UNIX command-line interpreter, often referred to as a shell. The shell reads input from the user, processes it, and executes the corresponding commands. 

The goal is to replicate basic functionality found in typical shell environments, such as displaying a prompt, executing commands, handling errors, and more.

##Getting Started
Clone this repository to your local machine using
	git clone https://github.com/your-username/simple_shell.git 

Compile the shell program using the provided compilation command:
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh*

Run the shell using:
	./hsh


You can now enter commands and interact with the shell.
For example  ls and hit enter

##Features
Display a prompt for user input.
Execute commands with or without arguments.
Handle built-in commands such as exit and env.
Support for tokenizing input to split it into commands and arguments.
Implement the PATH functionality to locate executable files.
Handle errors, including the "end of file" condition (Ctrl+D).
Maintain code style and standards according to the Betty style.

##Contributing
Contributions are welcome! Feel free to fork this repository, make your changes, and submit a pull request.

Remember your changes will be reviewed before they are accepted to affect this code.

##Acknowledgments
We would like to express our gratitude to the ALX Software Engineering team for providing the guidelines and framework for this project. Special thanks to Julien Barbier for his guidance and support throughout the project development.

We would also love to thank the mentors of cohort16. And our fellow students with whom we discussed for better understanding of the project.

