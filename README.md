# C-Run - README

## Overview

This is a Go-based command-line utility designed to compile and run C programs using `gcc`. It simplifies common tasks when working with C code by allowing you to compile, run, and clean up C programs easily.

## Features

- **Compile and run C programs**: Compile and run a C program with the option to automatically clean up the executable file.
- **Compile only**: Build the executable without running the program.
- **Customizable file cleanup**: Optionally remove the compiled file after execution.

## Requirements

- **Go**: This utility is written in Go, so you need to have Go installed. Download it from [here](https://golang.org/dl/).
- **GCC**: The GNU Compiler Collection (GCC) must be installed to compile C programs.
- **Operating System**: The code uses the `.exe` extension for Windows. For other operating systems, you can adapt the extension as needed.

## Building the Go Program

To build the Go-based C Program Runner utility from the source code, follow these steps:

### Prerequisites

- **Go**: Ensure Go is installed. Download it from [here](https://golang.org/dl/).
- **GCC**: Ensure GCC is installed to compile C programs.

### Build Instructions

- **Navigate to the project directory** where the Go source file (`C-run.go`) is located.

- **Build the Go program** using the following command:

   ```bash
   go build C-run.go -o c.exe
   ```
   For Linux:
   ```bash
   go build C-run.go -o c
   ```

   This will generate an executable named `c.exe` (Windows) or `c` (Linux) in the current directory.

- **Move the executable** to a location in your system's PATH so that it can be run from anywhere. Use the following command for Linux:

   ```bash
   sudo mv c /usr/local/bin/
   ```

   For Windows, place `c.exe` in a directory included in your PATH environment variable.

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

- `<command>`: Specifies the action to perform, such as `run` or `build`.
- `<filename>`: The C file you want to compile or run (e.g., `hello.c`). The file should be located in the same directory or a path accessible to the utility.

## How It Works

- **Compiling C Programs**: The `runCProgram()` function calls GCC to compile the C program using:

   ```
   gcc <filename> -o <output>
   ```

   The resulting executable file is stored in the same directory as the original C file but without the `.c` extension.

- **Running the Program**: If the `run` command is used, the compiled program is executed. After execution, the executable is removed.

- **File Cleanup**: With the `run` command, the utility will clean up the compiled executable file after execution.

## Example

To compile and run a C program named `example.c`, run:

```bash
c run example.c
```

To compile the program without running it, use:

```bash
c build example.c
```