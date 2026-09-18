
public class Exceptational {

    // public static void main(String[] args) {
    //     try {
    //         int a = 10, b = 0;
    //         int result = a / b;
    //         System.out.println("Result : " + result);
    //     } catch (ArithmeticException e) {
    //         System.out.println("Exception caught : Division by zero is not allowed....");
    //     } finally {
    //         System.out.println("Execution Completed....");
    //     }
    // }


    public static void main(String[] args){
        try {
            int arr[] = {10,20,30};
            int a =10, b=0;
            int result = a/b;
            System.out.println("Array Element no.5 : " + arr[5]);
        } catch (ArithmeticException e) {
            System.out.println("Exception caught : Division by zero not allowed.");
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Exception caught : Array index is out of bound.");
        }catch(Exception e){
            System.out.println("Exception caught : General exception occured.");
        }finally{
            System.out.println("Execution successfully completed.");
        }
    }
}
