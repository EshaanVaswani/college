def read_dictionary():
    dictionary = {}
    entries = int(input("Enter the number of entries for the dictionary: "))
    for _ in range(entries):
        key = input("Enter key: ")
        value = input("Enter value: ")
        dictionary[key] = value
    return dictionary

def display_dictionary(dict_A, dict_B):
    print("Dictionary A:", dict_A)
    if dict_B:
        print("Dictionary B:", dict_B)

def sort_dictionaries(dict_A, dict_B):
    sorted_dict_A = dict(sorted(dict_A.items())) if dict_A else dict_A
    sorted_dict_B = dict(sorted(dict_B.items())) if dict_B else dict_B
    return sorted_dict_A, sorted_dict_B

def concatenate_dictionaries(dict_A, dict_B):
    return {**dict_A, **dict_B}

dict_A = {}
dict_B = {}

while True:
   print("\nMenu:")
   print("1. Read dictionary A")
   print("2. Read dictionary B")
   print("3. Display dictionaries")
   print("4. Sort and display both dictionaries")
   print("5. Concatenate dictionaries and display")
   print("6. Exit")

   choice = input("Enter your choice: ")

   if choice == '1':
      dict_A = read_dictionary()
      print("Dictionary A has been successfully read.")

   elif choice == '2':
      dict_B = read_dictionary()
      print("Dictionary B has been successfully read.")

   elif choice == '3':
      display_dictionary(dict_A, dict_B)

   elif choice == '4':
      if dict_A or dict_B:
            dict_A, dict_B = sort_dictionaries(dict_A, dict_B)
            print("Sorted Dictionary A by keys:", dict_A)
            print("Sorted Dictionary B by keys:", dict_B)
      else:
            print("No dictionaries to sort. Please enter at least one dictionary.")

   elif choice == '5':
      if dict_A and dict_B:
            new_dict = concatenate_dictionaries(dict_A, dict_B)
            print("Concatenated Dictionary:", new_dict)
      else:
            print("Both dictionaries must be entered before concatenating.")

   elif choice == '6':
      print("Exiting the program...")
      break

   else:
      print("Invalid choice, please choose from 1 to 6.")
