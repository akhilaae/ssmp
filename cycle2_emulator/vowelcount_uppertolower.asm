data segment
    string db "AKHILA$"
    counter dw 06h 
    sum dw 00h
data ends
code segment
    start:
    mov ax,data
    mov ds,ax
    mov es,ax
    lea si,string
    mov cx,counter  
    mov bx,sum
    next:  
    xor ax,ax
    lodsb 
    sub ax,"A"
    add ax,"a"
    stosb
    cmp al,"A"
    je count
    cmp al,"a"
    je count    
    cmp al,"E"
    je count
    cmp al,"e"
    je count
    cmp al,"I"
    je count
    cmp al,"i"
    je count
    cmp al,"O"
    je count
    cmp al,"o"
    je count
    cmp al,"U"
    je count 
    cmp al,"u"
    je count 
    dec cx
    jnz next
    end:   
    lea dx,string
    mov ah,09h
    int 21h   
    mov [2000h],bx
    mov ah,4ch
    int 21h
    count:
    inc bx
    dec cx 
    jnz next
    jmp end 
code ends
end start