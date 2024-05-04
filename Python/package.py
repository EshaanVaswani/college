from package.employee.profile import Profile
from package.employee.qualification import Qualification
from package.account.salary import Salary

emp_profile = Profile("John Doe", 30, "1990-01-01")
emp_qualification = Qualification("MSc", 5)

emp_salary = Salary(pf=500, basic=5000, hra=1000)
total_salary = emp_salary.calculate_salary()

print(emp_profile.display_profile())
print(emp_qualification.display_qualification())
print(f"Total Salary: {total_salary}")
