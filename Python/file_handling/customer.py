class Customer:
    def __init__(self, customer_id, name, mobile_number):
        self.customer_id = customer_id
        self.name = name
        self.mobile_number = mobile_number

    def __str__(self):
        return f"{self.customer_id}, {self.name}, {self.mobile_number}"

def save_customers_to_file(customers, filename):
    with open(filename, 'w') as file:
        for customer in customers:
            file.write(str(customer) + '\n')

def read_customers_from_file(filename):
    with open(filename, 'r') as file:
        print("Customers from file:")
        for line in file:
            print(line.strip())


customers = []
n = int(input("Enter the number of customers: "))

for _ in range(n):
   customer_id = input("Enter customer ID: ")
   name = input("Enter customer name: ")
   mobile_number = input("Enter customer mobile number: ")
   customers.append(Customer(customer_id, name, mobile_number))

filename = "customers.txt"

save_customers_to_file(customers, filename)

read_customers_from_file(filename)

