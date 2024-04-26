package calci;

public class Division {
    int n1,n2;

    public Division(int n1, int n2){
        this.n1 = n1;
        this.n2 = n2;
    }

    public int divide(){
        if(n2 != 0){
            return n1/n2;
        } else {
            System.out.println("Error! Can't divide by zero!!");
            return 0; 
        }
    }
}
