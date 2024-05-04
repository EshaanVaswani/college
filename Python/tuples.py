student_list = []

while True:
   print("\nMenu:")
   print("1. Add student details")
   print("2. Show all student details")
   print("3. Display details of a student by name")
   print("4. Exit")

   choice = input("Enter your choice: ")

   if choice == '1':
      n = int(input("Enter the number of students you want to add: "))
      for _ in range(n):
            roll_no = int(input("Enter roll number: "))
            name = input("Enter student's name: ")
            marks = tuple(float(input(f"Enter marks for subject {i+1}: ")) for i in range(3))
            student_list.append((roll_no, name, marks))
      print("Student details added successfully.")

   elif choice == '2':
      print("Showing all student details:")
      for student in student_list:
            print(f"Roll No: {student[0]}, Name: {student[1]}, Marks: {student[2]}")

   elif choice == '3':
      search_name = input("Enter the name of the student to search: ")
      found = False
      for student in student_list:
            if student[1].lower() == search_name.lower():
               print(f"Details of {search_name}: Roll No: {student[0]}, Marks: {student[2]}")
               found = True
               break
      if not found:
            print(f"No details found for student named {search_name}")

   elif choice == '4':
      print("Exiting the program...")
      break

   else:
      print("Invalid choice, please choose from 1 to 4.")
