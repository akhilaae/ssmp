#include <stdio.h>
int allocation[10][10],max[10][10],available[10],need[10][10];
void main(){
    int m,n;
    printf("no of processes : ");
    scanf("%d",&n);
    printf("no of resources : ");
    scanf("%d",&m);
    printf("allocation : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("max : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    printf("available : \n");
    for(int i=0;i<m;i++){
        scanf("%d",&available[i]);
    }
    int finish[10],z=0,safeseq[10];
    for(int i=0;i<n;i++){
        finish[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int flag=0;
            if(finish[j]==0){
                for(int k=0;k<m;k++){
                    if(need[j][k]>available[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safeseq[z++]=j;
                    for(int y=0;y<m;y++){
                        available[y]+=allocation[j][y];
                    }
                    finish[j]=1;
                }
            }
        }
    }
    printf("Safe sequence!\n");
    for(int i=0;i<n-1;i++){
        printf("%d ",safeseq[i]);
    }
    printf("%d ",safeseq[n-1]);
}