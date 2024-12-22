#include<stdio.h>
int main(){
    float a,b,c,sum,average;
    printf("Enter three number: ");
    scanf("%f%f%f",&a,&b,&c);
    sum=a+b+c;
    average=sum/3;
    printf("The Sum is %f\n",sum);
    printf("The average is %f",average);
    return 0;
}