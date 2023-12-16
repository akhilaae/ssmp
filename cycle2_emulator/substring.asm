data segment
    str db 'HILL'
    substr db 'AK'
    len1 dw $-str
    len2 dw $-substr 
    msg1 db 'string found$'
    msg2 db 'string not found$'
data ends
code segment
    start:
        mov ax,data
        mov ds,ax 
        mov es,ax
        mov cx,len2
        mov dx,len1
        lea si,str
        mov bx,cx            
        
      x:  
        lea di,substr
        xor cx,cx
        mov cx,len2
        cld
        repe cmpsb  
        ;inc si   
        jz found
        dec dx
        cmp dx,bx
        jl not_found
        jmp x 
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
        
        
        
        
    
        