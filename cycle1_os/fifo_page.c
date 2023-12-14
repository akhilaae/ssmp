#include <stdio.h>
int max,len,seq[10],frame[5],pagefault=0,i,j,count=0;
int f=-1,r=-1;
int present(int x){
    for(j=0;j<max;j++){
        if(frame[j]==x){
            return 1;
        }
    }
    return 0;
}
void push(int x){
    if(r==-1 && f==-1){
        f=r=0;
    }
    else 
        r=(r+1)%max;
    frame[r]=x;
}
void pop(){
    f=(f+1)%max;
}
void fcfs(){
    for(i=0;i<len;i++){
        if(present(seq[i])==0){
            if(count==max){
                pop();
                count--;
            }
            push(seq[i]);
            count++;
            pagefault++;
        }
    }
    
}
void main(){
    printf("max no of frames : ");
    scanf("%d",&max);
    for(i=0;i<max;i++){
        frame[i]=-1;
    }
    printf("length of string : ");
    scanf("%d",&len);
    printf("enter sequence : ");
    for(int i=0;i<len;i++){
        scanf("%d",&seq[i]);
    }
    fcfs();
    printf("count : %d",pagefault);
}