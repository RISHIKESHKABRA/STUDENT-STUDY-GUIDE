import subprocess
import os

def test_compilation():
    cpp_file = os.path.join("src", "main.cpp")
    exe_file = "test_bin.exe" if os.name == "nt" else "./test_bin"
    
    res = subprocess.run(["g++", "-std=c++11", cpp_file, "-o", exe_file])
    assert res.returncode == 0, "C++ Compilation failed!"
    print("[TEST PASSED] Compilation Test")
    
    if os.path.exists(exe_file):
        os.remove(exe_file)

if __name__ == "__main__":
    try:
        test_compilation()
        print("\nAll automated tests completed successfully.")
    except Exception as e:
        print(f"\nTest Execution Failed: {e}")
