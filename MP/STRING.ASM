data Segment
 chc db 0dh,0ah,"Choose Operation: $"
 chc1 db 0dh,0ah," 1. Accept String $"
 chc2 db 0dh,0ah," 2. Display String $"
 chc3 db 0dh,0ah," 3. Display Length $"
 chc4 db 0dh,0ah," 4. Display Reverse $"
 chc5 db 0dh,0ah," 5. Check Palindrome $"
 chc6 db 0dh,0ah," 6. Exit $"
 len db ?
 msg db 0dh,0ah,"Please enter the String: $"
 msg1 db 0dh,0ah,"The length of the entered String is: $"
 msg2 db 0dh,0ah,"The entered String is: $"
 msg3 db 0dh,0ah,"The reverse of the entered String is: $"
 pal db 0dh,0ah,"The String is a Palindrome. $"
 npal db 0dh,0ah,"The String is not a Palindrome. $"
 newl db 0dh,0ah," $"
Data ends
Code Segment
 assume DS:Data,CS:Code
Start:
 mov ax,Data
 mov DS,ax

 call AcceptString

l: mov dx,offset chc
 mov ah,09h
 int 21h
 mov dx,offset chc1
 mov ah,09h
 int 21h
 mov dx,offset chc2
 mov ah,09h
 int 21h
 mov dx,offset chc3
 mov ah,09h
 int 21h
 mov dx,offset chc4
 mov ah,09h
 int 21h
 mov dx,offset chc5
 mov ah,09h
 int 21h
 mov dx,offset chc6
 mov ah,09h
 int 21h

 mov dx,offset newl
 mov ah,09h
 int 21h

 mov ah,01h
 int 21h
 sub al,30h

 cmp al,06h
 jz ex

 cmp al,05h
 jne n1
 call CheckPal

n1: cmp al,04h 
 jne n2
 call DisplayRev

n2: cmp al,03h 
 jne n3
 call DisplayLength

n3: cmp al,02h 
 jne n4
 call DisplayString

n4: cmp al,01h
 jne l
 call AcceptString 
 jmp l

ex: mov ah,4ch
 int 21h
AcceptString proc
 mov si,1000h
 mov di,1000h
 mov cx,0000h

 mov dx,offset msg
 mov ah,09h
 int 21h

    back: 
 mov ah,01h
 int 21h
 
 cmp al,0dh
 je comp
 inc cx
 mov [si],al
 mov [di],al
 inc si
 inc di
 jmp back
comp: mov len,cl
 ret
endp
DisplayString proc
 mov dx,offset msg2
 mov ah,09h
 int 21h

 mov cl,len
 mov ch,00h
 mov si,1000h

    disp: 
 mov dl,[si]
 mov ah,02h
 int 21h
 
 inc si
 loop disp
 ret
endp
DisplayLength proc
 mov dx,offset msg1
 mov ah,09h
 int 21h

 mov bl,len
 call DispNum
 ret
endp
DispNum proc
 mov al,bl
 and al,0f0h
 ror al,4

 mov dl,al
 call HexDisp
 mov ah,02h
 int 21h

 mov al,bl
 and al,0fh
 
 mov dl,al
 call HexDisp
 mov ah,02h
 int 21h
endp
HexDisp proc
 cmp dl,0ah
 jc nothex
 add dl,07h
 nothex: add dl,30h
 ret
endp
DisplayRev proc
 mov dx,offset msg3
 mov ah,09h
 int 21h

 mov cl,len
 mov ch,00h
 mov si,1000h
 add si,cx
 dec si

     dispr: 
 mov dl,[si]
 mov ah,02h
 int 21h
 
 dec si
 loop dispr
 ret
endp
CheckPal proc
 mov al,len
 mov ah,00h
 mov bl,02h
 div bl
 mov cl,len
 dec cl
 mov ch,00h
 mov di,1000h
 mov si,1000h
 add di,cx
 mov cl,al
 mov ch,00h
 
     pchk: 
 mov al,[si]
 cmp al,[di]
 jnz np
 inc si
 dec di
 loop pchk

 mov dx,offset pal
 mov ah,09h
 int 21h
 ret
 
      np: 
 mov dx,offset npal
 mov ah,09h
 int 21h
 ret
endp
Code ends
end Start
