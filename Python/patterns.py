#pattern1

print("\nPattern 1:\n")
c = 65
n = 5
for i in range(1, n+1):
   print(chr(c)*i)
   c += 1

#pattern2

print("\nPattern 2:\n")
n = 6
for i in range(1, n):
   print(" "*(i-1), end="")
   print("*"*(n-i))

#pattern3

print("\nPattern 3:\n")
ch = 1
a = 1
for r in range(1,6):
   ch=1
   for sp in range(6,r,-1):
      print(end=" ")
   for c in range(0,r):
      print(ch,end="")
      ch = ch+1
   a = r-1
   for e in range(0,r-1):
      print(a,end="")
      a = a-1
   print()	

#pattern 4

print("\nPattern 4:\n")
ch = '*'
i = 1
for r in range(6,1,-1):
   for sp in range(r,1,-1):
      print(end=" ")
   for c in range(0,i):
      print(ch+" ",end="")
   print()
   i = i+1
