mov ax,3000h
mov ds,ax            
mov ax,4f32h
mov bx,0FECAh
add ax,bx
mov [2000h],ax
mov ax,7255h
mov bx,2210h
adc ax,bx 
mov [2002h],ax
mov ax,4ch
int 21h

