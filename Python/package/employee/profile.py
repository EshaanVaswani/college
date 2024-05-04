class Profile:
    def __init__(self, name, age, dob):
        self.name = name
        self.age = age
        self.dob = dob
    
    def display_profile(self):
        return f"Name: {self.name}, Age: {self.age}, Date of Birth: {self.dob}"
