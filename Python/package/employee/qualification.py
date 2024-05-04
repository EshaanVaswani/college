class Qualification:
    def __init__(self, degree, experience):
        self.degree = degree
        self.experience = experience
    
    def display_qualification(self):
        return f"Degree: {self.degree}, Experience: {self.experience} years"
