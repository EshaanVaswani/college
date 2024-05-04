def create_file(filename, content):
    with open(filename, 'w') as file:
        file.write(content)

def count_file_details(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
        words = [word for line in lines for word in line.split()]
        characters = [char for line in lines for char in line]
    return len(lines), len(words), len(characters)

def copy_content_to_new_file(source_filename, new_filename):
    with open(source_filename, 'r') as source_file:
        content = source_file.read()
    with open(new_filename, 'w') as new_file:
        new_file.write(content)

def read_file(filename):
    with open(filename, 'r') as file:
        print(file.read())


filename = "original.txt"
new_filename = "copy.txt"
content = "Hello, this is a test.\nThis is the second line.\nAnd here is the third line."

create_file(filename, content)

lines, words, chars = count_file_details(filename)
print(f"Original file has {lines} lines, {words} words, and {chars} characters.")

copy_content_to_new_file(filename, new_filename)
print("Contents of the new file:")
read_file(new_filename)


