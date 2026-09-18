package oops;

    class Account{
        String name;
        double balance;

        static String bankName = "Rashq Bank";
        final String bankCode = "2478A05325";

        Account(String name){
            this(name,0);
        }
        Account(String name,double b){
            this.name = name;
            this.balance = b;
        }
    }
public class BankAccountSystem {
    public static void main(String[] args) {
        Account a1 = new Account("Rajesh Pandit");
        Account a2 = new Account("Naresh Pandit",1000000);
        System.out.println(Account.bankName);
        System.out.println(a1.bankCode);
        System.out.println(a1.balance);
    }

}
