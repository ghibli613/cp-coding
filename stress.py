import subprocess

def compile_cpp(file, output):
    try:
        subprocess.run(["g++", file, "-o", output], check=True)
        print(f"Compiled {file} successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Error compiling {file}: {e}")
        exit(1)

def run_program(executable, input_data, timeout=5):
    try:
        result = subprocess.run(
            [f"./{executable}"],
            input=input_data,
            capture_output=True,
            text=True,
            check=True,
            timeout=timeout  # Set a timeout in seconds
        )
        return result.stdout.strip()
    except subprocess.TimeoutExpired:
        print(f"Error: {executable} exceeded the timeout of {timeout} seconds and was terminated.")
        return "TIMEOUT"
    except subprocess.CalledProcessError as e:
        print(f"Error running {executable}: {e}")
        return "ERROR"

# Compile all C++ files
compile_cpp("generate.cpp", "generate")
compile_cpp("file1.cpp", "program1")
compile_cpp("file2.cpp", "program2")

# Run generate.cpp to create the input data
input_data = run_program("generate", input_data=None)

# Run both programs with the generated input
output1 = run_program("program1", input_data)
output2 = run_program("program2", input_data)

# Compare the results
print("Output of program1:", output1)
print("Output of program2:", output2)

if output1 == output2:
    print("The outputs are the same!")
else:
    print("The outputs are different!")
