import subprocess

def compile_c_program(source_code, output_file, input_file):
    # The C compiler command (e.g., gcc or clang)
    compiler = "g++"  # Replace with "clang" if you prefer using Clang

    # Write the source code to a temporary file
    with open("tmp/temp.cpp", "w") as f:
        f.write(source_code)
    
    with open("tmp/in.txt", "w") as f:
        f.write(input_file)

    # Compile the C program
    try:
        subprocess.check_call([compiler, "tmp/temp.cpp", "-o", output_file])
        print(f"Compilation successful. Output file: {output_file}")
    except subprocess.CalledProcessError as e:
        print(f"Compilation failed. Error: {e}")
        return False

    return True

# Example usage:
source_code = """
#include <iostream>
using namespace std;

#define N 20

int m, n;
int f[N];
int main(){
	cin>>m>>n;
	for(int i=0; i<n; i++){
		int v; cin>>v;
		for(int j=m; j>=v; j--)
			f[j] = max(f[j],f[j-v]+v);
	}
	cout<<m-f[m]<<endl;
	return 0;
}
"""

inputs = """
24
6
8
3
12
7
9
7
"""

def run_c_program_with_input(executable, input_string):
    # Run the C program as a subprocess and capture the outputs
    with subprocess.Popen(
        [executable],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    ) as process:
        # Provide input to the C program
        stdout_output, stderr_output = process.communicate(input=input_string)

    # Return the outputs as strings
    return stdout_output, stderr_output

output_file = "tmp/a.out"  # Replace with the desired name for the output executable

if not compile_c_program(source_code, output_file, inputs):
    exit(0)
    # The C program was successfully compiled, you can now run it or do further processing.

stdout, stderr = run_c_program_with_input(output_file, inputs)

print(stdout)

print(stderr)

subprocess.run(["lldb"])


