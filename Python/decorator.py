def add_four(func):
    def wrapper(*args, **kwargs):
        result = func(*args, **kwargs)
        return result + 4
    return wrapper

def multiply_by_two(func):
    def wrapper(*args, **kwargs):
        result = func(*args, **kwargs)
        return result * 2
    return wrapper

@multiply_by_two
@add_four
def square(num):
    return num ** 2

@multiply_by_two
@add_four
def cube(num):
    return num ** 3

number = int(input("Enter a number: "))
print("Square with decorators:", square(number))
print("Cube with decorators:", cube(number))
