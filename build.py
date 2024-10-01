from os import walk
import os
import pathlib

mypath = pathlib.Path(__file__).parent.resolve()
entry_file = "entry.cpp"

#Get all files in path
filenames = next(walk(mypath), (None, None, []))[2]

cpp_files = []

for source_file in filenames:

    if source_file.endswith(".cpp"):

        if source_file == entry_file:
            continue

        cpp_files.append(source_file)

command = "g++ " + entry_file + " "

for cpp_file in cpp_files:
    command += cpp_file + " "

os.system(command)