#include <stdio.h>

void printUsage(){
    printf(
        "Commands:\n\n"
        "1. Clean up compiled files\n"
        "   c clean\n"
        "   Removes leftover compiled files (.exe or .out) to clean up the workspace.\n\n"
        "2. Build a C project\n"
        "   - Link specified files:\n"
        "     c build --link <files>\n"
        "     Links the specified C files to create an executable.\n\n"
        "   - Build all C files in the current directory:\n"
        "     c build .\n"
        "     Automatically finds all .c files in the current directory and performs a linker build.\n\n"
        "3. Check utility version\n"
        "   c version\n"
        "   Outputs the program's version and details about the GCC version being used.\n\n"
        "4. Run a C program\n"
        "   - Run all C files in the current directory:\n"
        "     c run .\n"
        "     Finds all .c files in the current directory, builds them, and runs the resulting executable.\n\n"
        "   - Run a specific C file:\n"
        "     c run <filename>\n"
        "     Builds the specified .c file and runs the resulting executable.\n\n"
        "5. Initialize a new project\n"
        "   c init <project name>\n"
        "   Generates a simple starter template for a C project (e.g., a main.c file with a basic structure).\n\n"
    );

}