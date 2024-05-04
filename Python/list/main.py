import list as lop

def main():
    input_numbers = input("Enter numbers separated by spaces: ")
    numbers = list(map(int, input_numbers.split()))
    
    while True:
        print("\nMenu:")
        print("1. Add number to the list")
        print("2. Summation of all elements")
        print("3. Product of all elements")
        print("4. Summation of elements at even indices")
        print("5. Exit")
        
        choice = input("Enter your choice: ")

        if choice == '1':
            num = int(input("Enter number to add: "))
            lop.add_element(numbers, num)
            print(f"Updated list: {numbers}")
        elif choice == '2':
            print("Sum of all elements:", lop.sum_elements(numbers))
        elif choice == '3':
            print("Product of all elements:", lop.product_elements(numbers))
        elif choice == '4':
            print("Summation of elements at even indices:", lop.sum_even_indices(numbers))
        elif choice == '5':
            print("Exiting the program...")
            break
        else:
            print("Invalid choice, please choose from 1 to 5.")

if __name__ == "__main__":
    main()
