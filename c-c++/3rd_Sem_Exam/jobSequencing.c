#include<stdio.h>

struct Job{
    char ID;
    int deadline;
    int profit;
};

void jobSequencing(struct Job jobs[],int n){
    int Deadline = jobs[0].deadline;

    for(int i=1;i<n;i++){
        Deadline = (Deadline<jobs[i].deadline)?jobs[i].deadline:Deadline;
    }
    //Sorting
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(jobs[i].profit < jobs[j].profit){
                struct Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    int slot[Deadline];
    char result[Deadline];
    int totalProfit = 0;
    for(int i=0;i<Deadline;i++){
        slot[i] = 0;
    }

    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline-1;j>=0;j--){
            if(slot[j]==0){
                slot[j] = 1;
                result[j] = jobs[i].ID;
                totalProfit +=jobs[i].profit;
                break;
            }
        }
    }

    //Display
    printf("\nJob Sequence : ");
    for(int i=0;i<Deadline;i++){
        printf("%c ",result[i]);
    }
    printf("\nTotal Profit : %d",totalProfit);
}


void main() {
    int n, i;
    struct Job jobs[10];
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter Job ID, Deadline, and Profit for Job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].ID, &jobs[i].deadline, &jobs[i].profit);
    }

    printf("\n--- Job Sequencing with Deadlines (Greedy Strategy) ---\n");
    jobSequencing(jobs, n);
    printf("\n\nProgram executed successfully!");

}