#include<stdio.h>
int fact(int n){
    if(n<=1){
        return n;
    }
    else{
        return n * fact(n-1);
    }
}
int main(){
    int n,c,r;
    printf("Enter the value of n and r respectively: ");
    scanf("%d%d",&n,&r);
    printf("The nCr value is %d",(fact(n)/(fact(n-r)*fact(r))));
    return 0;

}