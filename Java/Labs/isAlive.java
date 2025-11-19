
class Mythread extends Thread {

    public void run() {
        try {
            for (int i = 1; i <= 3; i++) {
                System.out.println(Thread.currentThread().getName() + "-Count :" + i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Thead Interrupted : " + e);
        }
    }
}

public class isAlive {

    public static void main(String[] args) {
        Mythread t1 = new Mythread();
        Mythread t2 = new Mythread();

        t1.start();
        t2.start();

        System.out.println("Thread t1 isAlive status : "+ t1.isAlive());
        System.out.println("Thread t2 isAlive status : "+ t2.isAlive());

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            System.out.println("Main Thread Interrupted : " + e);
        }

        System.out.println("Thread t1 isAlive status : " + t1.isAlive());
        System.out.println("Thread t2 isAlive status : " + t2.isAlive());

        System.out.println("Main thread execution completed.");
    }
}
