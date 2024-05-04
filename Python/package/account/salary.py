class Salary:
    def __init__(self, pf, basic, hra):
        self.pf = pf
        self.basic = basic
        self.hra = hra

    def calculate_salary(self):
        return self.basic + self.hra - self.pf
