#include <stdio.h>
int max,len,seq[10],frame[5],pagefault=0,i,j,k,count=0,a[10];
int f=-1,r=-1;
int present(int x){
    for(j=0;j<max;j++){
        if(frame[j]==x){
            return j;
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
int least_frequent(int index){
    int small=-1,s;
    for(j=0;j<max;j++){
        int c=0;
        for(k=index-1;k>0;k--){
            if(seq[k]==frame[j]){
                c++;
            }
        }
        a[j]=c;
    }
    for(int p=0;p<max;p++){
        if(a[small]>=a[p]){
            small=p;
        }
    }
    return small;
}
void lfu(){
    for(i=0;i<len;i++){
        if(present(seq[i])==0){
            if(count!=max){
                push(seq[i]);
                count++;
                pagefault++;
            }
            else{
                int index=least_frequent(i);
                if(index==-1){
                    pop();
                    push(seq[i]);
                    pagefault++;

                }
                else{
                    frame[index]=seq[i];
                    r=index;
                    pagefault++;
                }
                
            }
        }
        else{
            r=(r+1)%max;
        }
    }
}
void main(){
    printf("max no of frames : ");
    scanf("%d",&max);
    for(int i=0;i<max;i++){
        frame[i]=-1;
    }
    printf("length of string : ");
    scanf("%d",&len);
    printf("enter sequence : ");
    for(int i=0;i<len;i++){
        scanf("%d",&seq[i]);
    }
    lfu();
    printf("count : %d",pagefault);
}
//7 0 1 2 0 3 0 4 2 3 0 3 2