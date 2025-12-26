from subprocess import run
import os
import sys


if len(sys.argv) > 1:
    folders = sys.argv[1:]
else:
    folders = "P1 P2 P3".split()

# print(folders)
# exit(1)

for folder in folders:
    os.chdir(folder)
    
    cpp_files = [f for f in os.listdir('.') if f.endswith('.cpp')]

    for file in cpp_files:
        run(f"g++ -c {file} -o o-files/{file}.o")
        
    os.chdir("..")