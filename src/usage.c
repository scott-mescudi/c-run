#include <stdio.h>

void printUsage() {
    printf(
        "Commands:\n\n"
        
        "Clean up compiled files:\n"
        "   \"c clean\"\n"
        "     Removes leftover compiled files (e.g., .exe, .out) to clean up the workspace.\n\n"
        
        "Build a C project:\n"
        "   Link specified files:\n"
        "     \"c build --link <files>\"\n"
        "     Links the specified C files and creates an executable.\n\n"
        
        "   Build all C files in the current directory:\n"
        "     \"c build .\"\n"
        "     Automatically finds all .c files in the current directory and builds them into an executable.\n\n"
        
        "Check utility version:\n"
        "   \"c gcv\"\n"
        "     Displays details about the GCC version being used.\n\n"
        
        "Run a C program:\n"
        "   Run all C files in the current directory:\n"
        "     \"c run .\"\n"
        "     Finds all .c files, builds them, and runs the resulting executable.\n\n"
        
        "   Run a specific C file:\n"
        "     \"c run <filename>\"\n"
        "     Builds the specified .c file and runs the resulting executable.\n\n"
        
        "Initialize a new project:\n"
        "   \"c init <project_name>\"\n"
        "     Generates a simple starter template for a C project (e.g., a main.c file with basic structure).\n\n"
    );
}
