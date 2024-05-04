import os

def create_directories():
    os.mkdir("example_dir")
    print("Directory 'example_dir' created.")

    os.makedirs("nested_dir/sub_dir")
    print("Nested directories 'nested_dir/sub_dir' created.")

def remove_directories():
    os.rmdir("example_dir")
    print("Directory 'example_dir' removed.")

    os.removedirs("nested_dir/sub_dir")
    print("Nested directories 'nested_dir/sub_dir' removed.")

def change_directory():
    os.chdir("nested_dir")
    print("Changed current directory to 'nested_dir'.")

    os.chdir("..")
    print("Changed back to the parent directory.")

create_directories()

change_directory()

remove_directories()



