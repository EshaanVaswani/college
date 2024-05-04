import tkinter as tk
from tkinter import filedialog, messagebox, simpledialog

def save_data():
    name = name_entry.get()
    age = age_spinbox.get()
    gender = gender_var.get()
    subscription = subscribe_var.get()
    
    data = f"Name: {name}\nAge: {age}\nGender: {gender}\nSubscribed: {subscription}\n\n"
    
    with open("user_details.txt", "a") as file:
        file.write(data)
    
    messagebox.showinfo("Data Saved", "Your data has been saved successfully.")

def read_data():
    try:
        with open("user_details.txt", "r") as file:
            print(file.read())
        messagebox.showinfo("Data Read", "Data read in the Python console.")
    except FileNotFoundError:
        messagebox.showerror("Error", "Data file not found.")

root = tk.Tk()
root.title("User Information")

tk.Label(root, text="Name:").grid(row=0, column=0)
name_entry = tk.Entry(root)
name_entry.grid(row=0, column=1)

tk.Label(root, text="Age:").grid(row=1, column=0)
age_spinbox = tk.Spinbox(root, from_=0, to=100)
age_spinbox.grid(row=1, column=1)

gender_var = tk.StringVar(value="None")
tk.Label(root, text="Gender:").grid(row=2, column=0)
tk.Radiobutton(root, text="Male", variable=gender_var, value="Male").grid(row=2, column=1)
tk.Radiobutton(root, text="Female", variable=gender_var, value="Female").grid(row=2, column=2)

subscribe_var = tk.BooleanVar()
tk.Checkbutton(root, text="Subscribe to newsletter", variable=subscribe_var).grid(row=3, columnspan=2)

tk.Button(root, text="Save Data", command=save_data).grid(row=4, column=0)
tk.Button(root, text="Read Data", command=read_data).grid(row=4, column=1)

root.mainloop() 
