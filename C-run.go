package main

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

func getPath(filename string) (dir string ,exefilename string ,err error){
	_, err = os.Stat(filename)
	if err != nil {
		return "", "", fmt.Errorf("cannot find %s", filename)
	}

	exefilename = strings.TrimSuffix(filename, ".c")
	dir = filepath.Dir(exefilename)

	return dir, exefilename, nil
}

func runCProgram(clean bool ,ext string) error {
	if len(os.Args) != 3{
		return fmt.Errorf("error: missing filename")
	}

	filename := os.Args[2]
	dir, exefilename, err := getPath(filename)
	if err != nil{
		return fmt.Errorf("error: cannot find %v ", filename)
	}


	cmd := exec.Command("gcc", filename, "-o", exefilename)
    err = cmd.Run()
    if err != nil {
        return fmt.Errorf("error compiling C code")
    }
	
	if clean{
		if dir == "." {
			cmd = exec.Command("./"+exefilename+ext)
		}else{
			cmd = exec.Command(exefilename+ext)
		}

		cmd.Stdout = os.Stdout
		cmd.Stdin = os.Stdin
		cmd.Stderr = os.Stderr
		fmt.Println(cmd)
		err = cmd.Run()
		if err!= nil {
			return fmt.Errorf("error running compiled program")
		}
		

		err := os.Remove(exefilename+ext)
		if err!= nil {
            fmt.Printf("error cleaning up compiled program")
        }
	}
	
	return nil
}

func main() {
	if len(os.Args) < 2{
		fmt.Println("Error: please provide a flag")
		return
	} 
	switch os.Args[1]{
	case "run":
		err := runCProgram(true, ".exe")
		if err != nil {
			fmt.Println(err)
		}
	case "build":
		err := runCProgram(false, ".exe")
        if err!= nil {
            fmt.Println(err)
        }
    case "clean":
	default:
		fmt.Println("Error: Unknown command")
	}
}