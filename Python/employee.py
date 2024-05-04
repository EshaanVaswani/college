class Employee:
    empcount = 0  

    def __init__(self, emp_id):
        self.id = emp_id 
        self.name = None  
        Employee.empcount += 1 

    def set_name(self, name):
        self.name = name

    def get_name(self):
        return self.name

    def get_id(self):
        return self.id

    @classmethod
    def set_emp_count(cls, count):
        cls.empcount = count

    @classmethod
    def get_emp_count(cls):
        return cls.empcount

employee_list = []

while True:
   print("\nMenu:")
   print("1. Add Employee")
   print("2. Display All Employees")
   print("3. Display Total Number of Employees")
   print("4. Exit")

   choice = input("Enter your choice: ")

   if choice == '1':
      emp_id = int(input("Enter Employee ID: "))
      name = input("Enter Employee Name: ")
      employee = Employee(emp_id)
      employee.set_name(name)
      employee_list.append(employee)
      print(f"Employee added. Total number of employees: {Employee.get_emp_count()}")

   elif choice == '2':
      if employee_list:
            for emp in employee_list:
               print(f"Employee ID: {emp.get_id()}, Name: {emp.get_name()}")
      else:
            print("No employees to display.")

   elif choice == '3':
      print(f"Total number of employees: {Employee.get_emp_count()}")

   elif choice == '4':
      print("Exiting the program...")
      break

   else:
      print("Invalid choice, please choose from 1 to 4.")

