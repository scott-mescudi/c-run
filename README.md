# C Program Runner - README

## Overview

This is a Go-based command-line utility designed to compile and run C programs using `gcc`. It provides options to compile a C file, run it immediately, and clean up the compiled binary after execution. It simplifies common actions when working with C code, such as compiling and executing.

## Features

- **Compile and run C programs**: You can compile and immediately run a C program, with the option to automatically clean up the executable file.
- **Compile only**: Build the executable without running the program.
- **Customizable file cleanup**: Optionally remove the compiled file after execution.

## Requirements

- **Go**: This utility is written in Go, so you need to have Go installed.
- **GCC**: The GNU Compiler Collection (GCC) must be installed on your system to compile C programs.
- **Operating System**: While the code uses the `.exe` extension, it can be easily adapted to work on non-Windows platforms by changing the file extension.



## Building the Go Program

To build the Go-based C Program Runner utility from the source code, follow the steps below:

### Prerequisites

- **Go**: Make sure Go is installed. You can download it from [here](https://golang.org/dl/).
- **GCC**: Ensure GCC is installed for compiling the C programs.

### Build Instructions

- **Navigate to the project directory** where the Go source file (`C-run.go`) is located.

- **Build the Go program** using the following command:

   ```bash
   go build C-run.go -o c.exe
   ```
   or for linux:
      ```bash
   go build C-run.go -o c.sh
   ```

   This will generate an executable named `c.exe` or `c.sh` in the current directory.

- **Move the executable** to a location in your system's PATH so that it can be run from anywhere. Use the following command to move the executable:
   linux:
   ```bash
   mv c.exe /usr/local/bin/
   ```

   Replace `$path` with the directory where you want to place the `c.exe` executable (e.g., `/usr/local/bin/` on Linux/Mac or a path in your Windows environment variables).


## Usage

```
c <command> <filename>
```

### Commands

- **`run`**:
   - Compiles and runs the specified C program.
   - Automatically removes the compiled executable after execution.

   ```
   c run <filename>
   ```

   Example:

   ```
   c run hello.c
   ```

- **`build`**:
   - Compiles the specified C program without running it.
   - The compiled executable remains in the working directory.

   ```
   c build <filename>
   ```

   Example:

   ```
   c build hello.c
   ```

### Parameters

- `<command>`: This specifies what action to perform, such as `run`, `build`.
- `<filename>`: The C file you want to compile or run (e.g., `hello.c`). This file should be located in the same directory or a path accessible to the utility.

## How It Works

- **Compiling C Programs**: The `runCProgram()` function calls GCC to compile the C program using the following command:

   ```
   gcc <filename> -o <output>
   ```

   The resulting executable file is stored in the same directory as the original C file but without the `.c` extension.

- **Running the Program**: If the `run` command is provided, the compiled program is executed. After running, the executable is removed.

- **File Cleanup**: When running with the `run` command, the utility will clean up the compiled executable file after execution.


## Example

To compile and run a C program named `example.c`, run:

```bash
c run example.c
```

If you only want to compile the program without running it, use:

```bash
c build example.c
```

## License

This project is released under the MIT License. Feel free to use and modify the code.