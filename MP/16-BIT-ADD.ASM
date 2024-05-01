Data Segment
 msg db 0dh,0ah,"Enter a 16-bit number: $"
 result db 0dh,0ah,"The Result is: $"
 newl db 0dh,0ah," $"
Data ends
Code Segment
assume CS:Code,DS:Data
Start:
 mov ax,Data
 mov DS,ax
 
 mov dx,offset msg;add16
 mov ah,09h
 int 21h
 
 call AcceptNum
 mov bh,bl
 
 call AcceptNum
 mov cx,bx

 mov dx,offset msg
 mov ah,09h
 int 21h
 
 call AcceptNum
 mov bh,bl
 
 call AcceptNum

 add cx,bx

 mov dx,offset result
 mov ah,09h
 int 21h
 
 mov bl,ch
 call DispNum

 mov bl,cl
 call DispNum

 mov ah,4ch
 int 21h
AcceptNum proc
 mov ah,01h
 int 21h
 
 call HexAccept
 
 mov bl,al
 rol bl,4
 
 mov ah,01h
 int 21h
 
 call HexAccept
 add bl,al
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
HexAccept proc
 cmp al,41h
 jc norm
 sub al,07h
 norm: sub al,30h
 ret
endp

HexDisp proc
 cmp dl,0ah
 jc nothex
 add dl,07h
 nothex: add dl,30h
 ret
endp
Code ends
end Start
