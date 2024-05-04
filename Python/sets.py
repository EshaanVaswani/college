set_A = set()
set_B = set()

while True:
   print("\nMenu:")
   print("1. Read sets A and B")
   print("2. Display set A and B")
   print("3. Perform intersection A ∩ B")
   print("4. Perform union A U B")
   print("5. Perform set difference A - B")
   print("6. Perform symmetric difference A ^ B")
   print("7. Exit")

   choice = input("Enter your choice: ")

   if choice == '1':
      elements_A = input("Enter elements for set A separated by space: ")
      set_A = set(map(int, elements_A.split()))
      elements_B = input("Enter elements for set B separated by space: ")
      set_B = set(map(int, elements_B.split()))
      print("Sets A and B have been successfully read.")

   elif choice == '2':
      print("Set A:", set_A)
      print("Set B:", set_B)

   elif choice == '3':
      print("Intersection of A and B:", set_A.intersection(set_B))

   elif choice == '4':
      print("Union of A and B:", set_A.union(set_B))

   elif choice == '5':
      print("Set difference A - B:", set_A.difference(set_B))

   elif choice == '6':
      print("Symmetric difference A ^ B:", set_A.symmetric_difference(set_B))

   elif choice == '7':
      print("Exiting the program...")
      break

   else:
      print("Invalid choice, please choose from 1 to 7.")
