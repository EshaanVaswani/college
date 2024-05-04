class Batsman:
    def bat(self):
        return "I can bat"

class Bowler:
    def bowl(self):
        return "I can bowl"

class AllRounder(Batsman, Bowler):
    def do_both(self):
        return f"{self.bat()} and {self.bowl()}"

allrounder = AllRounder()
print(allrounder.do_both())
