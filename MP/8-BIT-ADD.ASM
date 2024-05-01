data SEGMENT
a db ?
msg db "Enter the 1st no $"
msg1 db "Enter the 2nd no $"
msg2 db "the result of the addition is $"
data ends

code SEGMENT
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax

mov dx,OFFSET msg
mov ah,09h
int 21h

call input
mov a,bl

mov dx,OFFSET msg1
mov ah,09h
int 21h

call input

mov dx,OFFSET msg2
mov ah,09h
int 21h

mov cl,00

add bl,a
JNC l3
inc cl

l3:  mov dh,bl
     mov bl,cl
     and bl,0Fh
     call convert
     mov dl,bl
     mov ah,02h
     int 21h

     mov bl,dh
     and bl,0F0h
     ror bl,04h

     call convert
     mov dl,bl
     mov ah,02h
     int 21h

     mov bl,dh
     and bl,0Fh
     call convert

     mov dl,bl
     mov ah,02h
     int 21h


mov ah,4ch
int 21h

input proc
mov ah,01h
int 21h

call ascii2hex
mov bl,al
rol bl,4

mov ah,01h
int 21h
call ascii2hex
add bl,al
ret
endp


ascii2hex proc
cmp al,41h
jc num
sub al,07h
num: sub al,30h
ret
endp

convert proc
       cmp bl,0Ah
       jc l1
       add bl,37h
       jmp l2
        l1:add bl,30h
        l2:ret

endp


code ends
end start
