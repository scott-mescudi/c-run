# C-run

This program provides a simple command-line tool to compile and execute C source files, inspired by the `go run` functionality in the Go programming language. It is designed for rapid prototyping and testing of C code snippets. The main features include building a `.c` file into an executable and running that executable directly from the command line.

## Features

- **Run**: Execute the compiled executable and measure its execution time.
- **Build**: Compile a C source file into an executable. (gcc is better)

## Requirements

- **GCC**.
- Standard libraries included with GCC.

## Installation

### Building the Program

- **Clone the Repository**: Start by cloning the repository to your local machine. Run the following command:
  ```bash
  git clone https://github.com/scott-mescudi/c-run.git
  ```
- **Navigate to the Project Directory**: Change to the cloned directory:
  ```bash
  cd c-run
  ```

- **Compile the Source Code**: Use GCC to compile the program.
  ```bash
  gcc main.c -o c.exe
  ```

- **Move the Executable to your PATH**: 
  ```bash
  move c.exe C:\Path\To\Your\Bin
  ```

- **Make the Executable Accessible**: Ensure the directory you moved `c.exe` to is in your system's PATH.

## Usage

After successfully building and moving the executable, you can use the tool from the command line.

### Commands

- **Build a C File**
   ```bash
   c.exe build <source_file.c>
   ```
   Example:
   ```bash
   c.exe build example.c
   ```

- **Run a C File**
   ```bash
   c.exe run <source_file.c>
   ```
   Example:
   ```bash
   c.exe run example.c
   ```

### Output

- Upon successfully building a file, an executable named `example.exe` (if the source file was `example.c`) will be created in the same directory.
- When you run an executable, the program will execute and print the time taken to run the program.

### Note

- Make sure to provide a valid C source file (`.c`).
- The executable created will be deleted after execution.

## Example

- **Building and Running a Sample Program**:
   - Create a file `hello.c` with the following content:
     ```c
     #include <stdio.h>
     int main() {
         printf("Hello, World!\n");
         return 0;
     }
     ```

   - Build it:
     ```bash
     c.exe build hello.c
     ```

   - Run it:
     ```bash
     c.exe run hello.c
     ```

   - You should see:
     ```
     Hello, World!
     ---------------------------------
     Time taken: X.XXXXXX seconds
     ```

## Notes

- The program performs basic validation of the input file to ensure it is a `.c` file.
- Make sure to have the GCC compiler installed and properly configured on your system to use this tool effectively.

Inspired by the simplicity of `go run`.
