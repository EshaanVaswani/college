numbers = []

while True:
   print("\nMenu:")
   print("1. Input numbers to the list")
   print("2. Put even and odd elements in two different lists")
   print("3. Merge and sort two lists")
   print("4. Update the first element with a value X")
   print("5. Print middle element of the list")
   print("6. Exit")

   choice = input("Enter your choice: ")

   if choice == '1':
      input_numbers = input("Enter numbers separated by spaces: ")
      numbers = list(map(int, input_numbers.split()))
      print("List updated to:", numbers)

   elif choice == '2':
      even_numbers = [num for num in numbers if num % 2 == 0]
      odd_numbers = [num for num in numbers if num % 2 != 0]
      print("Even numbers:", even_numbers)
      print("Odd numbers:", odd_numbers)

   elif choice == '3':
      second_list = input("Enter second list numbers separated by spaces: ")
      second_list = list(map(int, second_list.split()))
      merged_list = numbers + second_list
      merged_list.sort()
      print("Merged and sorted list:", merged_list)

   elif choice == '4':
      if numbers:
         new_value = int(input("Enter a new value for the first element: "))
         numbers[0] = new_value
         print("Updated list:", numbers)
      else:
         print("List is empty, add numbers first.")

   elif choice == '5':
      if numbers:
         middle_index = len(numbers) // 2
         if len(numbers) % 2 == 0:
            print("Middle elements:", numbers[middle_index - 1], numbers[middle_index])
         else:
            print("Middle element:", numbers[middle_index])
      else:
         print("List is empty, add numbers first.")

   elif choice == '6':
      print("Exiting the program...")
      break

   else:
      print("Invalid choice, please choose from 1 to 6.")
