#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
typedef struct{
    int pid;
    int arrival;
    int burst;
    int priority;
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
void sjf(process p[]){
    int min,flag,pos,j,num=n;
    while (num>0){
        min=100;
        flag=0;
        for(int i=0;i<n;i++){
            if(p[i].arrival<=time && p[i].finish==0){
                if(p[i].priority<min){
                    min=p[i].priority;
                    flag=1;
                    pos=i;
                }
            }
        }
        if(flag==1){
            time+=p[pos].burst;
            p[pos].comp=time;
            p[pos].finish=1;
            p[pos].turn=p[pos].comp-p[pos].arrival;
            p[pos].wait=p[pos].turn-p[pos].burst;            
            printf("P%d|%d|",p[pos].pid,p[pos].comp);
            num--;
        }
        else{
            time+=1;
        }
    }
}
void avg(process p[]){
    float tta=0,twt=0;
    for(int i=0;i<n;i++){
        tta+=p[i].turn;
        twt+=p[i].wait;
    }
    printf("\navg turn : %.2f\n",tta/n);
    printf("avg wait : %.2f\n",twt/n);
}
void main(){
    printf("no of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&p[i].pid,&p[i].arrival,&p[i].burst,&p[i].priority);
        p[i].finish=0;
    }
    sort(p);
    sjf(p);
    avg(p);
}