# C-run

C-run is a simple command-line tool for compiling and running C programs, inspired by the `go run` functionality in Go. It is designed for rapid prototyping and testing of C code snippets. The tool simplifies compiling and running C programs with a variety of useful commands.

## Features

- **Run**: Compile and execute C programs, including handling multiple source files.
- **Build**: Compile and link C files into executables.
- **Clean**: Remove compiled files (e.g., `.exe`, `.out`) to clean up the workspace.
- **Check GCC Version**: Display details about the installed GCC version.
- **Initialize Project**: Generate a simple starter template for new C projects.

## Requirements

- **GCC**: The program requires GCC to compile C source files.
- Standard libraries included with GCC.

## Installation

### Building the Program

- **Clone the Repository**: Clone the repository to your local machine by running:
  ```bash
  git clone https://github.com/scott-mescudi/c-run.git
  ```

- **Navigate to the Project Directory**: Change into the directory:
  ```bash
  cd ./c-run/src
  ```

- **Compile the Source Code**: Use GCC to compile the program:
  ```bash
  gcc -o c build.c buildpipe.c init.c main.c misc.c run.c runpipe.c usage.c
  ```

- **Move the Executable to your PATH**: Move the compiled `c.exe` to a directory in your PATH for easier access:
  ```bash
  move c.exe C:\Path\To\Your\Bin
  ```

- **Make the Executable Accessible**: Ensure that the directory you moved `c.exe` to is in your system's PATH.

## Usage

After successfully building and moving the executable, you can use the tool from the command line.

### Commands

#### Clean up compiled files:
- **`c clean`**  
  Removes leftover compiled files (e.g., `.exe`, `.out`) to clean up the workspace.
  ```bash
  c clean
  ```

#### Build a C Project:
- **Link specified files**:
  - **`c build --link <files>`**  
    Links the specified C files and creates an executable.
    ```bash
    c build --link file1.c file2.c
    ```
  
- **Build all C files in the current directory**:
  - **`c build .`**  
    Automatically finds all `.c` files in the current directory and builds them into an executable.
    ```bash
    c build .
    ```

#### Check GCC Version:
- **`c gcv`**  
  Displays details about the GCC version being used.
  ```bash
  c gcv
  ```

#### Run a C Program:
- **Run all C files in the current directory**:
  - **`c run .`**  
    Finds all `.c` files in the current directory, builds them, and runs the resulting executable.
    ```bash
    c run .
    ```

- **Run a specific C file**:
  - **`c run <filename>`**  
    Builds the specified `.c` file and runs the resulting executable.
    ```bash
    c run example.c
    ```

#### Initialize a New Project:
- **`c init <project_name>`**  
  Generates a simple starter template for a C project, such as a `main.c` file with a basic structure.
  ```bash
  c init my_project
  ```


## Notes

- The program performs basic validation to ensure the input file is a valid `.c` file.
- Ensure that GCC is installed and properly configured on your system to use this tool effectively.
  
Inspired by the simplicity of `go run`.