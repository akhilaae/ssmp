data segment
    n1 dw 0001h
    n2 dw 3453h
    n3 dw 1234h
data ends
code segment
    start:
    mov ax,data
    mov ds,ax
    mov dx,n1
    mov ax,n2
    mov bx,n3
    idiv bx
    mov [0030h],ax
    mov [0040h],dx 
    mov ax,4ch
    int 21h 
code ends
end start