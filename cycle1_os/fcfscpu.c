#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
typedef struct{
    int pid;
    int arrival;
    int burst;
    int comp;
    int turn;
    int wait;
    int finish;
}process;
process p[10];
int time=0;
void sort(process p[]){
    int small;
    process temp;
    for(int i=0;i<n-1;i++){
        small=i;
        for(int j=i+1;j<n;j++){
            if(p[j].arrival<p[small].arrival){
                small=j;
            }
        }
        if(small!=i){
            temp=p[i];
            p[i]=p[small];
            p[small]=temp;
        }
    }
}
void fcfs(process p[]){
    for(int i=0;i<n;i++){
        if(p[i].arrival>time && p[i].finish==0){
            time=p[i].arrival;
        }
        time+=p[i].burst;
        p[i].comp=time;
        p[i].finish=1;
        p[i].turn=p[i].comp-p[i].arrival;
        p[i].wait=p[i].turn-p[i].burst;            
        printf("P%d|%d|",p[i].pid,p[i].comp);
    }
}
void avg(process p[]){
    float tta=0,twt=0;
    for(int i=0;i<n;i++){
        tta+=p[i].turn;
        twt+=p[i].wait;
    }
    printf("avg turn : %.2f\n",tta/n);
    printf("avg wait : %.2f\n",twt/n);
}
void main(){
    printf("no of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&p[i].pid,&p[i].arrival,&p[i].burst);
        p[i].finish=0;
    }
    sort(p);
    fcfs(p);
    avg(p);
}