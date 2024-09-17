package main

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"strings"
	"time"
)

func getPath(filename string) (dir string, exefilename string, err error) {
	ext := filepath.Ext(filename)
	if ext != ".c" {
		return "", "", fmt.Errorf("%s is not a C file", filename)
	}

	_, err = os.Stat(filename)
	if err != nil {
		return "", "", fmt.Errorf("cannot find %s", filename)
	}

	exefilename = strings.TrimSuffix(filename, ".c")
	dir = filepath.Dir(exefilename)

	return dir, exefilename, nil
}

func build(filename, exefilename, ext string) error {
	cmd := exec.Command("gcc", filename, "-o", exefilename+ext)
	err := cmd.Run()
	if err != nil {
		return fmt.Errorf("error compiling C code")
	}

	return nil
}

func runExecutable(dir, exefilename, ext string) error {
	var command string
	if dir == "." {
		command = "./" + exefilename + ext
	} else {
		command = exefilename + ext
	}

	cmd := exec.Command(command)
	cmd.Stdout = os.Stdout
	cmd.Stdin = os.Stdin
	cmd.Stderr = os.Stderr
	err := cmd.Run()
	if err != nil {
		return fmt.Errorf("error executing compiled program: %v", err)
	}

	err = os.Remove(exefilename + ext)
	if err != nil {
		fmt.Printf("error cleaning up compiled program")
	}

	return nil
}

func isProgramInstalled(program string) bool {
	_, err := exec.LookPath(program)
	return err == nil
}

func getExecutableExtension() string {
	if runtime.GOOS == "windows" {
		return ".exe"
	}
	return ".sh"
}

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Error: please provide a flag")
		return
	}

	compiler := "gcc"
	if !isProgramInstalled(compiler) {
		fmt.Println("gcc is not installed")
		return
	}

	command := os.Args[1]
	if len(os.Args) < 3 && (command == "run" || command == "build") {
		fmt.Println("Error: missing filename")
		return
	}

	filename := os.Args[2]

	dir, exefilename, err := getPath(filename)
	if err != nil {
		fmt.Printf("error: %v", err)
		return
	}
	exeType := getExecutableExtension()

	switch command {
	case "run":
		err := build(filename, exefilename, exeType)
		if err != nil {
			fmt.Println(err)
		}

		start := time.Now()
		err = runExecutable(dir, exefilename, exeType)
		elapsed := time.Since(start)
		if err != nil {
			fmt.Println(err)
		}

		fmt.Printf("\nExecution time: %v\n", elapsed)

	case "build":
		err := build(filename, exefilename, exeType)
		if err != nil {
			fmt.Println(err)
		}
		fmt.Printf("Executable built: %s%s\n", exefilename, exeType)
	default:
		fmt.Println("Error: Unknown command")
	}
}
