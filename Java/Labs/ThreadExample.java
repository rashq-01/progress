
import java.lang.*;

// class GoodMorningThread extends Thread {
//     public void run() {
//         try {
//             while (true) {
//                 System.out.println("Good Morning..");
//                 Thread.sleep(1000);
//             }
//         } catch (InterruptedException e) {
//             System.out.println("Thread Interrupted : " + e);
//         }
//     }
// }
// class HelloThread extends Thread {
//     public void run() {
//         try {
//             while (true) {
//                 System.out.println("Hello");
//                 Thread.sleep(2000);
//             }
//         } catch (InterruptedException e) {
//             System.out.println("Thread Interrupted : " + e);
//         }
//     }
// }
// class Welcome extends Thread {
//     public void run() {
//         try {
//             while (true) {
//                 System.out.println("Welcom");
//                 Thread.sleep(3000);
//             }
//         } catch (InterruptedException e) {
//             System.out.println("Thread Interrupted : " + e);
//         }
//     }
// }
// public class ThreadExample {
//     public static void main(String[] args) {
//         new GoodMorningThread().start();
//         new HelloThread().start();
//         new Welcome().start();
//     }
// }
class GoodMorningThread implements Runnable {

    public void run() {
        try {
            while (true) {
                System.out.println("Good morning.");
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread Interrupted : " + e);
        }
    }
}

class Hello implements Runnable {

    public void run() {
        try {
            while (true) {
                System.out.println("Hello.");
                Thread.sleep(2000);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread Interrupted : " + e);
        }
    }
}

class Welcome implements Runnable {

    public void run() {
        try {
            while (true) {
                System.out.println("Welcome.");
                Thread.sleep(3000);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread Interrupted : " + e);
        }
    }
}

class ThreadExample {

    public static void main(String[] args) {
        Thread t1 = new Thread(new GoodMorningThread());
        Thread t2 = new Thread(new Hello());
        Thread t3 = new Thread(new Welcome());

        t1.start();
        t2.start();
        t3.start();
    }
}
