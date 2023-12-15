#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    FILE *f1,*f2,*f3,*f4,*f5;
    char label[10],opcode[10],operand[10],opt_opcode[10],sym_label[10];
    char start[10],length[10],loc[10],opt_operand[10],sym_loc[10];
    f1=fopen("intermediary.txt","r");
    f4=fopen("length.txt","r");
    f5=fopen("machinecode.txt","w");
    fscanf(f1,"\t\t%s\t%s\t%s",label,opcode,start);
    fscanf(f4,"%s",length);
    printf("H^%s^%s^%s\n",label,start,length);
    printf("T^%s^%s",start,length);
    int flag1,flag2;
    fscanf(f1,"%s\t%s\t%s\t%s",loc,label,opcode,operand);
    while(!feof(f1)){
        flag1=0;
        f2=fopen("optab.txt","r");
        fscanf(f2,"%s\t%s",opt_opcode,opt_operand);
        while(!feof(f2)){
            if(strcmp(opcode,opt_opcode)==0){
                flag1=1;
                break;
            }
            fscanf(f2,"%s\t%s",opt_opcode,opt_operand);
        }
        fclose(f2);
        if(flag1==1){
            if(strcmp(operand,"-")!=0){
                flag2=0;
                f3=fopen("symtab.txt","r");
                fscanf(f3,"%s\t%s",sym_label,sym_loc);
                while(!feof(f3)){
                    if(strcmp(operand,sym_label)==0){
                        flag2=1;
                        break;
                    }
                    fscanf(f3,"%s\t%s",sym_label,sym_loc);
                }
                if(flag2==1){
                    printf("^%s%s",opt_operand,sym_loc);
                }
            }
        }
        else{
            if(strcmp(opcode,"WORD")==0||strcmp(opcode,"BYTE")==0){
                if(strcmp(opcode,"WORD")==0){
                    printf("^%s",operand);
                }
                else{
                    int len=strlen(operand);
                    printf("^");
                    for(int i=2;i<len;i++){
                        printf("%d",operand[i]);
                    }
                }
            }
        }
        fscanf(f1,"%s\t%s\t%s\t%s",loc,label,opcode,operand);
    }
}