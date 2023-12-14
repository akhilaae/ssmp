#include <stdio.h>
#include <stdlib.h>
int head,queue[100],n,sum;
void main(){
    printf("enter head : ");
    scanf("%d",&head);
    printf("no of disks : ");
    scanf("%d",&n);
    sum=head;
    printf("enter sequence : ");
    scanf("%d",&queue[0]);
    sum=abs(head-queue[0]);
    for (int i=1;i<n;i++){
        scanf("%d",&queue[i]);
        sum+=abs(queue[i-1]-queue[i]);
    }
    printf("headturn : %d",sum);
}