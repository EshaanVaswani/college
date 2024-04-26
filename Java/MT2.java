class OddThread extends Thread {
    public void run() {
        for (int i = 1; i <= 15; i += 2) {
            System.out.println("Odd Thread: " + i);
        }
    }
}

class EvenThread extends Thread {
    public void run() {
        for (int i = 2; i <= 16; i += 2) {
            System.out.println("Even Thread: " + i);
            try {
                Thread.sleep(2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class MT2 {
    public static void main(String[] args) throws InterruptedException {
        OddThread oddThread = new OddThread();
        EvenThread evenThread = new EvenThread();

        oddThread.start();

        evenThread.start();
    }
}
