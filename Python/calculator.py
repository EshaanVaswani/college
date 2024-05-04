def add(*args):
    return sum(args)

def subtract(first, *args):
    result = first
    for num in args:
        result -= num
    return result

def multiply(*args):
    result = 1
    for num in args:
        result *= num
    return result

def divide(first, *second):
    try:
        result = first
        for num in second:
            result /= num
        return result
    except ZeroDivisionError:
        return "Error: Division by zero"

while True:
    print("\nMenu:")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")
    print("5. Exit")
    choice = input("Enter choice (1/2/3/4/5): ")

    if choice == '5':
        print("Exiting the program...")
        break

    numbers = input("Enter numbers separated by space: ")
    number_list = list(map(float, numbers.split()))

    if choice == '1':
        print("Result:", add(*number_list))
    elif choice == '2':
        print("Result:", subtract(*number_list))
    elif choice == '3':
        print("Result:", multiply(*number_list))
    elif choice == '4':
        if len(number_list) >= 2:
            print("Result:", divide(*number_list))
        else:
            print("Error: Need at least two numbers for division.")
    else:
        print("Invalid choice. Please choose between 1-5.")
