def sum_elements(numbers):
    return sum(numbers)

def product_elements(numbers):
    product = 1
    for num in numbers:
        product *= num
    return product

def sum_even_indices(numbers):
    return sum(numbers[i] for i in range(0, len(numbers), 2))

def add_element(numbers, element):
    numbers.append(element)
    return numbers
