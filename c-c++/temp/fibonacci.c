#include<stdio.h>
int fibbo(int n){
    if(n<=1){
        return n;
    }
    else{
        return n + fibbo(n-1);
    }
}

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d ",fibbo(i));
    }
    return 0;

}