class Fail(Exception):
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)

class Student:
    def __init__(self, rno, name, marks):
        self.rno = rno
        self.name = name
        self.marks = marks

    def display(self):
        print(f"Roll No: {self.rno}, Name: {self.name}, Marks: {self.marks}")
        if self.marks < 40:
            raise Fail("Fail: Marks below 40.")

students = []
n = int(input("Enter the number of students: "))

for _ in range(n):
   rno = input("Enter roll number: ")
   name = input("Enter student's name: ")
   marks = float(input("Enter student's marks: "))
   students.append(Student(rno, name, marks))

print("\nStudent Details:")
for student in students:
   try:
      student.display()
   except Fail as e:
      print(e)
