class MinMax {
    public static void main(String args[]){
        System.out.println("Eshaan Vaswani C33 181 \n");

        int a,b,c,max,min;
        a = Integer.parseInt(args[0]);
        b = Integer.parseInt(args[1]);
        c = Integer.parseInt(args[2]);
        max = a > b ? (a > c ? a : c) : (b > c ? b : c);
        min = a < b ? (a < c ? a : c) : (b < c ? b : c);
        System.out.println("Maximum = " + max);
        System.out.println("Minimum = " + min);
    }
}
