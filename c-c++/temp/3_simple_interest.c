#include<stdio.h>
int main(){
    float p,t,r,si;
    printf("Enter Princple, Time, Rate respectively: ");
    scanf("%f%f%f",&p,&t,&r);
    printf("The simple interest is %f",(p*t*r)/100);
    return 0;
}