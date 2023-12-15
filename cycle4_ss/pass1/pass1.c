#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int start,optab_operand,operand_add,locctr;
char label[10],opcode[10],operand[10],optab_opcode[10];
void main(){
    FILE *f1,*f2,*f3,*f4;
    f1=fopen("input.txt","r");
    f3=fopen("symtab.txt","w");
    f4=fopen("intermediary.txt","w");
    fscanf(f1,"%s\t%s\t%d",label,opcode,&start);
    if (strcmp(opcode,"START")==0){
        locctr=start;
        fprintf(f4,"\t\t%s\t%s\t%d\n",label,opcode,start);
    }
    else locctr=0;
    fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
    while(!feof(f1)){
        fprintf(f4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"-")!=0){
            fprintf(f3,"%s\t%d\n",label,locctr);
        }
        f2=fopen("optab.txt","r");
        fscanf(f2,"%s\t%d",optab_opcode,&optab_operand);
        while(!feof(f2)){
            if(strcmp(opcode,optab_opcode)==0){
                locctr+=3;
                break;
            }
            fscanf(f2,"%s\t%d",optab_opcode,&optab_operand);
        }
        fclose(f2);
        if(strcmp(opcode,"WORD")==0){
            locctr+=3;
        }
        else if(strcmp(opcode,"RESW")==0){
            operand_add=atoi(operand);
            locctr+=3*operand_add;
        }
        else if(strcmp(opcode,"RESB")==0){
            operand_add=atoi(operand);
            locctr+=operand_add;
        }
        else if(strcmp(opcode,"BYTE")==0){
            if(operand[0]=='X'){
                locctr+=1;
            }
            else{
                int len=strlen(operand)-2;
                locctr+=len;
            }
        }
        fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
    }
    printf("length : %d",locctr-start);
    FILE *f5=fopen("length.txt","w");
    fprintf(f5,"%d",locctr-start);
    fclose(f5);
    fclose(f1);
    fclose(f3);
    fclose(f4);
}