data segment
    list db 03h,02h,04h
    len equ $-list
data ends
code segment
    start:
        mov ax,data
        mov ds,ax
        mov cl,len
        dec cl
    outerloop:
        lea si,list
        mov ch,len
        dec ch
    innerloop:
        mov ah,[si]
        mov al,[si+1]
        cmp ah,al
        jc noswap
        mov [si],al
        mov [si+1],ah
    noswap:
        inc si
        dec ch
        cmp ch,00h
        jnz innerloop
        dec cl
        cmp cl,00h
        jnz outerloop
        mov ah,4ch
        int 21h
code ends
end start