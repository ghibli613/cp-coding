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

# Number of test cases
num_test_cases = int(input("Enter the number of test cases: "))

for test_id in range(1, num_test_cases + 1):
    print(f"\nRunning Test Case #{test_id}")

    # Run generate.cpp to create the input data for this test case
    input_data = run_program("generate", input_data=None)

    # Run both programs with the generated input
    output1 = run_program("program1", input_data)
    output2 = run_program("program2", input_data)

    # Compare the results
    print("Input Data:")
    print(input_data)
    print("Output of program1:", output1)
    print("Output of program2:", output2)

    if output1 == output2:
        print(f"Test Case #{test_id}: The outputs are the same!")
    else:
        print(f"Test Case #{test_id}: The outputs are different!")
        print("Stopping further tests.")

        # Compare the results
        print("Input Data:")
        print(input_data)
        print("Output of program1:", output1)
        print("Output of program2:", output2)
        
        break  # Stop the loop if outputs differ
else:
    print("\nAll test cases passed successfully!")
