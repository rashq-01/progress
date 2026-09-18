package oops;
import java.lang.*;
import java.util.*;
public class EmployeeBonusSystem {
    static class employee{
        String name;
        double baseSalary;

        employee(String n,double s){
            this.name = n;
            this.baseSalary = s;
        }
        double calculateBonus(int n){
            if(n>=5){
                return (baseSalary + (baseSalary/5));
            }
            else if(n==4){
                return (baseSalary + (baseSalary/10));
            } else if (n == 3) {
                return (baseSalary + (baseSalary/20));
            }
            return baseSalary;
        }
    }


    public static void main(String[] args) {
        employee e1 = new employee("Rajesh",50000);
        employee e2 = new employee("Sanjog",60000);
        employee e3 = new employee("Suraj",70000);
        System.out.println(e1.calculateBonus(5));
        System.out.println(e2.calculateBonus(4));
        System.out.println(e3.calculateBonus(1));
    }
}
