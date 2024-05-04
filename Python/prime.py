arr = [3, 4, 6, 9, 13, 14, 16, 17]  
non_prime_arr = [] 

for num in arr:
    if num > 1:  
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0: 
                non_prime_arr.append(num)
                break
        else:
            continue 
    else:
        non_prime_arr.append(num) 

print("Output arr[] =", non_prime_arr)	
