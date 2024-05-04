import string 
str = string.ascii_lowercase 
str1 = 'the quick brown fox jumps over the lazy dog' 
count = 0 
for i in str:     
   if i not in str1.lower(): 
         count = 1         
         break 
if count == 1: 
   print("It is not a pangram") 
else: 
   print("It is a pangram")
