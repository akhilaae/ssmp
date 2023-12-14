;16bit addition 4f32h and 2ecah store ate 2000h in data segment 3000h.
mov ax,3000h
mov ds,ax
mov ax,4f32h
mov bx,2ecah
add ax,bx
mov [2000h],ax
mov ax,4ch
int 21h