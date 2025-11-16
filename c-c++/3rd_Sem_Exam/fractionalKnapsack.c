#include<stdio.h>

struct Item{
    int weight;
    int profit;
    char ID;
};

void fractionalKnapsack(struct Item items[],int n,int W){
    //Initialization
    float fract[n];
    //Assigning fractionally
    for(int i=0;i<n;i++){
        fract[i] = (float)(items[i].profit)/(items[i].weight);
    }

    //Sorting
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(fract[j] > fract[i]){
                struct Item temp = items[j];
                items[j] = items[i];
                items[i] = temp;
                
                float t = fract[i];
                fract[i] = fract[j];
                fract[j] = t;
            }
        }
    }
    float maxProfit = 0;
    char result[n];
    for(int i=0;i<n;i++){
        result[i] = '0';
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(W>items[i].weight){
            maxProfit += fract[i]*items[i].weight;
            W-=items[i].weight;
            result[j++] = items[i].ID;
        }
        else{
            maxProfit+=fract[i]*W;
            result[j++] = items[i].ID;
            break;
        }
    }
    printf("\n-------Result-------");
    printf("\nTotal Profit : %.2f ",maxProfit);
    printf("\nSelected Items : ");
    for(int i=0;i<j;i++){
        printf(" %c ,",result[i]);
    }

}


int main(){

    struct Item items[4];
    int W;
    for(int i=0;i<4;i++){
        printf("\nEnter ID , Profit , Weight for Item %d : ",i+1);
        scanf(" %c%d%d",&items[i].ID,&items[i].profit,&items[i].weight);
    }
    printf("\nEnter the Capacity : ");
    scanf("%d",&W);
    fractionalKnapsack(items,4,W);



    return 0;
}