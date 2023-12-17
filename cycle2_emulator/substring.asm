data segment
    str db 'HILL$'
    substr db 'LL$'
    len1 dw 04
    len2 dw 02 
    msg1 db 'string found$'
    msg2 db 'string not found$'
data ends
code segment
    start:
        mov ax,data
        mov ds,ax 
        ;mov es,ax
        mov dx,len1 
        mov cx,len2
        lea si,str
        lea di,substr 
      x:
        mov al,[si]                                                                      
        mov ah,[di]
        cmp al,ah
        je innerloop
        inc si
        dec dx
        cmp dx,00h
        jnz x
        jmp not_found
      innerloop:
        inc di
        inc si
        dec cx
        dec dx
        cmp cx,00h
        jnz x 
        jmp found 
      found:
        lea dx,msg1
        mov ah,09h
        int 21h   
        jmp exit
      not_found:  
        lea dx,msg2
        mov ah,09h
        int 21h
      exit:
        mov ah,4ch
        int 21h
code ends
end start
        
        
        
        
    
            
    
        