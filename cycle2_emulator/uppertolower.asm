data segment
    string db "HAHA$"
    count dw 04h
data ends
code segment
    start:
    mov ax,data
    mov ds,ax      
    mov es,ax ;important    
    lea di,string
    mov cx,count
    l1:
    xor ax,ax
    lodsb
    sub ax,"A"
    add ax,"a"
    stosb
    dec cx
    jz next
    jmp l1
    next:
    lea dx,string
    mov ah,09h
    int 21h
    mov ah,4ch
    int 21h
code ends
end start
    