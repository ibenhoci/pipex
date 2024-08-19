# pipex
`pipex` is a command-line utility in C that simulates the behavior of piping commands in a Unix shell. It executes a sequence of commands with input and output redirection, mimicking the following shell command:

```bash
	< file1 cmd1 | cmd2 > file2
```

## Usage
To execute `pipex`, use the following command:

```bash
	./pipex file1 cmd1 cmd2 file2
```

1. `file1` - The input file from which data will be read.
2. `cmd1` - The first command to process the data from file1.
3. `cmd2` - The second command to process the output from cmd1.
4. `file2` - The output file where the final result will be written.

### Examples
1. Example 1:

```bash
	./pipex infile "ls -l" "wc -l" outfile
```
This command will execute the following shell pipeline:

```bash
	< infile ls -l | wc -l > outfile
```
It reads from infile, executes ls -l on the input, pipes the output to wc -l, and writes the result to outfile.

2. Example 2:

```bash
	./pipex infile "grep a1" "wc -w" outfile
```
This command will execute:

```bash
	< infile grep a1 | wc -w > outfile
```
It reads from infile, filters lines containing a1 using grep, pipes the result to wc -w, and writes the word count to outfile.

## Requirements
1. Makefile: A Makefile must be provided to compile the source files. The Makefile should not relink the program unnecessarily.
2. Error Handling: The program should handle errors gracefully. It must not terminate unexpectedly due to segmentation faults, double frees, or similar issues.
3. Memory Management: Ensure that the program does not have memory leaks.
4. Behavior: The program must behave exactly as the shell command < file1 cmd1 | cmd2 > file2.

## Compilation
To compile pipex, use the following command:

```bash
	make
```
This will build the pipex executable using the provided Makefile.

## Contributing
To contribute to this project:

1. Fork the Repository: Create your own copy of the repository.
2. Make Changes: Implement your changes or improvements.
3. Submit a Pull Request: Share your changes with a description of what you have done.
Ensure that your code adheres to the existing style and passes all tests.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments
Special thanks to contributors and educators who have provided valuable insights into process management and pipe handling in Unix-like systems.