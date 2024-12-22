#include<stdio.h>
int main(){
    float f,c,result;
    printf("Enter temperature in Celcius: ");
    scanf("%f",&c);
    result=(c*9/5)+32;
    printf("The result temperature in Fahrenheit is %f\n",result);
    printf("\nEnter the temperature in Fahrenheit: ");
    scanf("%f",&f);
    result=(f-32)*5/9;
    printf("The result temperature in Celcius is %f",result);
    return 0;
}