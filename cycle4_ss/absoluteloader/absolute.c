#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    FILE *f1,*f2;
    char rectype[1],name[10],opcode[10],objcode[10],new[3];
    int length,start,locctr,offset;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    fscanf(f1,"%s %s %x %x",rectype,name,&start,&length);
    offset=start;
    fscanf(f1,"%s",rectype);
    while(!feof(f1)){
        int flag=0;
        fscanf(f1,"%x %x",&start,&length);
        if(strcmp(rectype,"T")==0){
            locctr=start;
            for(int i=0;i<length;i++){
                fscanf(f1,"%s",opcode);
                if(strcmp(opcode,"T")==0||strcmp(opcode,"E")==0){
                    flag=1;
                    break;
                }
                fprintf(f2,"%x\t%s\n",locctr,opcode);
                locctr+=1;
                fscanf(f1,"%s",objcode);
                for(int j=0;j<strlen(objcode);j=j+2){
                    fprintf(f2,"%x\t%c%c\n",locctr,objcode[j],objcode[j+1]);
                    locctr+=1;
                }
            }
        }
        if(flag==1){
            strcpy(rectype,opcode);
        }
        else{
            fscanf(f1,"%s",rectype);
        }
    }
    fclose(f1);
    fclose(f2);
}