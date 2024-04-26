class MyThread extends Thread{
    public void run(){
        System.out.println("Thread running: " + Thread.currentThread().getName());
    }
}

public class MT1 {
    public static void main(String args[]){
        System.out.println("Eshaan Vaswani C33 181 \n");
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();

        t1.start();
        t2.start();

        System.out.println("Thread 1 name: " + t1.getName());
        System.out.println("Thread 2 name: " + t2.getName());
    }
}
