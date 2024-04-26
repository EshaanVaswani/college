class divisibleBy7 {
public static void main(String args[]){
    System.out.println("Eshaan Vaswani C33 181 \n");
    int i, sum=0;
    for(i=100; i<201; i++){
        if(i%7 == 0){
            System.out.println(i);
            sum = sum + i;
        }
    }
    System.out.println("Sum of numbers divisible by 7 between 100 and 200 is " + sum);
}
}
