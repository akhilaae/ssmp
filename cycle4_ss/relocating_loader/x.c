#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    FILE *f1,*f2;
    char type[1],name[10],rectype[1],mask[12]={0},maskbit[3],opcode[2],len[6];
    int offset,newloc,add;
    int start,length,objcode,flag;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    fscanf(f1,"%s %s %x %x",type,name,&start,&length);
    printf("Enter new loc : ");
    scanf("%x",&newloc);
    offset=newloc-start;
    while(!feof(f1)){
        flag=0;
        fscanf(f1,"%s %x %x",rectype,&add,&length);
        newloc=add+offset;
        if(strcmp(rectype,"T")==0){
            fscanf(f1,"%s",maskbit);
            for(int i=0;i<3;i++){
                switch(maskbit[i]){
                    case '0':{
                        strcat(mask,"0000");
                        break;
                    }
                    case '1':{
                        strcat(mask,"0001");
                        break;
                    }
                    case '2':{
                        strcat(mask,"0010");
                        break;
                    }
                    case '3':{
                        strcat(mask,"0011");
                        break;
                    }
                    case '4':{
                        strcat(mask,"0100");
                        break;
                    }
                    case '5':{
                        strcat(mask,"0101");
                        break;
                    }
                    case '6':{
                        strcat(mask,"0110");
                        break;
                    }
                    case '7':{
                        strcat(mask,"0111");
                        break;
                    }
                    case '8':{
                        strcat(mask,"1000");
                        break;
                    }
                    case '9':{
                        strcat(mask,"1001");
                        break;
                    }
                    case 'A':{
                        strcat(mask,"1010");
                        break;
                    }
                    case 'B':{
                        strcat(mask,"1011");
                        break;
                    }
                    case 'C':{
                        strcat(mask,"1100");
                        break;
                    }
                    case 'D':{
                        strcat(mask,"1101");
                        break;
                    }
                    case 'E':{
                        strcat(mask,"1110");
                        break;
                    }
                    case 'F':{
                        strcat(mask,"1111");
                        break;
                    }
                }
            }
            for(int i=0;i<12;i++){
                fscanf(f1,"%s",opcode);
                if(strcmp(rectype,"T")==0||strcmp(rectype,"E")==0){
                    flag=1;
                    break;
                }
                fscanf(f1,"%x",&objcode);
                if(mask[i]=='1'){
                    objcode+=offset;
                }
                fprintf(f2,"%x\t%s%x\n",newloc,opcode,objcode);
                sprintf(len,"%d",objcode);
                newloc+=1+strlen(len)/2;
            }
        }
        if(flag==1){
            strcpy(rectype,opcode);
        }
    }
    fclose(f1);
    fclose(f2);
}