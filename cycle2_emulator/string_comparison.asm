data segment
    string1 db "halaa$"
    string2 db "halas$"
    count dw 05h
    string3 db "same$"
    string4 db "diff$"
data ends
code segment
    start:
    mov ax,data
    mov ds,ax
    mov es,ax
    lea si,string1
    lea di,string2
    mov cx,count
    repe cmpsb
    cmp cx,0
    je same
    jmp diff
same:
    lea dx,string3
    mov ah,09h
    int 21h
    jmp stop
diff:
    lea dx,string4
    mov ah,09h
    int 21h  
    jmp stop
stop: 
    mov ah,4ch
    int 21h