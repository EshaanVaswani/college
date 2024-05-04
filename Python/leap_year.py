year = int(input("Enter year to be checked:"))
if year % 4 == 0:
   if year % 100 != 0 or year % 400 == 0:
      print("Leap year")
   else:
      print("Not a leap year")
else:
   print("Not a leap year")
