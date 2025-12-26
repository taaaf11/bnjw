from subprocess import run
import os

folders = "P1 P2 P3".split()

for folder in folders:
    os.chdir(folder)
    
    cpp_files = [f for f in os.listdir('.') if f.endswith('.cpp')]

    for file in cpp_files:
        run(f"gcc -c {file} -o o-files/{file}.o")
        
    os.chdir("..")