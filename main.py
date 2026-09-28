import os
import subprocess
import sys

def build_and_run():
    cpp_source = os.path.join("src", "main.cpp")
    output_bin = "study_suite"
    
    if os.name == "nt":
        output_bin += ".exe"

    print("Compiling C++ Application...")
    compile_cmd = ["g++", "-std=c++11", cpp_source, "-o", output_bin]
    
    try:
        subprocess.run(compile_cmd, check=True)
        print(f"Compilation Successful! Running {output_bin}...\n")
        subprocess.run([f"./{output_bin}" if os.name != "nt" else output_bin])
    except FileNotFoundError:
        print("Error: 'g++' compiler not found in PATH. Please run directly inside Dev-C++.")
    except subprocess.CalledProcessError:
        print("Error: Compilation failed.")

if __name__ == "__main__":
    build_and_run()
