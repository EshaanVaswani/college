str=input("Enter the string: ") 
letter=str[0] 
str=str.replace(letter,'@') 
str2 = letter+str[1:] 
for i in str2: 
    print(i, end='')
