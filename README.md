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

## Usage

### Command Structure

```
c <command> <filename>
```

### Commands

1. **`run`**:
   - Compiles and runs the specified C program.
   - Automatically removes the compiled executable after execution.

   ```
   c run <filename>
   ```

   Example:

   ```
   c run hello.c
   ```

2. **`build`**:
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