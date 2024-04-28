echo "How many numbers do you want to sum?"
read n
sum=0

for ((i = 1; i <= n; i++)); do
    echo "Enter number $i:"
    read num
    sum=$((sum + num))
done

echo "Sum of the entered numbers is: $sum"