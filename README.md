# Basic-UNIX-Linux-Shell
Simulating a basic UNIX-Linux-Shell in C

The shell handles the following commands and flags,

	Internal Commands:-
		1. 	cd [path] : cd accepts a path to a directory as an input and changes the directory as given in the 
			path.

			Corner cases:-
			a) In the case the path is not given, directory is changed to the root directory
			b) If the path given is incorrect the command outputs an error statement identifying the same

		2. pwd : pwd prints the path of the present working directory

			Corner cases:-
			a) In the case when there is something after the command pwd, it ignores that and is able to print
			   the current directory

		3. echo [FLAGS] [STRING] : echo prints whatever is written after it in the string section on the terminal

			FLAGS:-
			a) -n : Removes the line break at the end of the input string
			b) -E : Ignores the special meaning of the backslash characters

			Corner cases:-
			a) Identifies if the given flags are correct or not and if not outputs an error
			b) Behaves appropriately depending on whether the string given is in " " or not
			c) Handles a combination of the two flags implemented

		4. history [FLAGS] [ARG] : history is used to print out the the previous commands that have been
		   used on the shell. The history also has a file through which it can doesn't loss the commands from the
		   previous terminal use and maintains a history of 1000 commands

			FLAGS:-
			a) -c : Deletes all the previous history
			b) -s : Adds a statement following the flag to the list of history

			Corner cases:-
			a) Identifies if the given flags are correct or not and if not outputs an error
			b) If there is no input after the -s flag then it doesn't add anything to the history without causing 
			   an error
			c) Handles a combination of the two flags implemented

		5. exit : It is used to exit from the program


	External Commands:-
		1. date [FLAGS] : Prints the system date and time

			FLAGS:-
			a) -R : Output  date  and time in RFC 2822 format
			b) -u : Print or set Coordinated Universal Time (UTC)

			Corner cases:-
			a) Identifies if the given flags are correct or not and if not outputs an error
			b) Handles a combination of the two flags implemented

		2. ls [FLAGS] [FILE] : List directory contents of a file if mentioned or of the present working directory
		   if not

			FLAGS:-
			a) -a : Doesn't ignore the names of the directories that start with a '.'
			b) -i : Print the index number of each file 

			Corner Cases:-
			a) Identifies if the given flags are correct or not and if not outputs an error
			b) Handles a combination of the two flags implemented
			c) If a file is mentioned the list it's contents else list the contents of the pwd
			d) Identifies if the mentioned file exists else outputs an error message

		3. cat [FLAGS] [FILES] : Concatenate files and print on the standard output

			FLAGS:-
			a) -n : number all output lines
			b) -e : display $ at the end of each line

			Corner Cases:-
			a) Identifies if the given flags are correct or not and if not outputs an error
			b) Handles a combination of the two flags implemented
			c) If no flags or files given then an interractive environment is created where whatever is read from
			   standard input is written on standard output.
			d) Able to handle multiple files given as arguments
			e) Identifies if the file mentioned exists in the directory else outputs an error message

		4. mkdir [FLAGS] [ARGS] : It is used to make directories

			FLAGS:-
			a) -m MODE : Used to set the file mode depending on the MODE argument
			b) -v : Print a message for each created directory

			Corner Cases:-
			a) Identifies if the given flags are correct or not and if not outputs an error
			b) Handles a combination of the two flags implemented
			c) If a directory or file of the same name exists it alerts the user through an error message
			d) Able to create multiple files given as arguments

		5. rm [FLAGS] [FILES] : Remove files or directories

			FLAGS:-
			a) -i : Prompt before every removal
			b) -d : Remove empty directories

			Corner Cases:-
			a) Identifies if the given flags are correct or not and if not outputs an error
			b) Handles a combination of the two flags implemented
			c) Identifies if the given file doesn't and alerts the user through an error message
			d) Able to delete multiple files given as arguments
			e) Doesn't delete a directory that isn't empty in case of -d
