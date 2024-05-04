from array import * 
arr=array('i',[]) 
str=[2,4,6,8] 
for i in str: 
    arr.append(int(i)) 
 
print("Array is: ") 
for i in arr:     
   print(i, end=" ") 
 
x = int(input("\nEnter number to be added to array: ")) 
arr.append(x) 
for i in arr:     
   print(i, end=" ") 
print("\n") 
 
print("Reversed array is: ") 
str2=arr[::-1] 
 
for i in str2:     
   print(i, end=" ") 
print("\n") 
 
print("Item size is: ", end="") 
print(arr.itemsize) 
print("\n") 
 
arr1=[1,3,5,7,9] 
arr.extend(arr1) 
print("Array after extended is :") 
for i in arr:     
   print(i, end=" ") 
print("\n") 
 
n=int(input("Enter the index of element to be pop from the array: ")) 
arr.pop(n) 
for i in arr:     
   print(i, end=" ") 
print()
