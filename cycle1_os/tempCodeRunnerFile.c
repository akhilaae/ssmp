#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int head,queue[10],n,l1,l2,head_index,small,j;
void main(){
    printf("enter head : ");
    scanf("%d",&head);
    printf("no of disks : ");
    scanf("%d",&n);
    printf("enter limits : ");
    scanf("%d %d",&l1,&l2);
    int sum=abs(l2-head)+abs(l2-l1);
    printf("enter sequence : ");
    for (int i=0;i<n;i++){
        scanf("%d",&queue[i]);