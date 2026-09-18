package oops;
import java.lang.*;

public class intoOop {

    static class box {

        int val;

        box() {
            this.val = 0;
        }
    }
    static void swap(box b1,box b2){
        int temp = b1.val;
        b1.val = b2.val;
        b2.val = temp;

    }

    public static void main(String[] args) {
        System.out.println("rajesh");
        box b1 = new box();
        box b2 = new box();
        b1.val = 10;
        b2.val = 20;
        System.out.println(b1.val);
        System.out.println(b2.val);
        swap(b1,b2);
        System.out.println(b1.val);
        System.out.println(b2.val);

    }
}
