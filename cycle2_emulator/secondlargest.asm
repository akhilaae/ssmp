data segment
    list db 03h,04h,05h
    count db 03h
data ends
code segment
    start:
        mov ax,data
        mov ds,ax
        lea si,list
        mov cl,count
        mov al,00h
        mov bl,00h
    check_largest:
        mov ah,[si]
        cmp al,ah
        jnc check_second
        mov bl,al
        mov al,ah  
        jmp common
    check_second:
        cmp bl,ah
        jnc exit
        mov bl,ah 
    common:
        dec cl
        inc si
        cmp cl,00h
        jnz check_largest
    exit:
        mov [2000h],bl
        mov ah,4ch
        int 21h
code ends
end start
    