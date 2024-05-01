data segment
msg1 db 0dh,0ah,"min-$"
msg2 db 0dh,0ah,"max-$"
newl db 0dh,0ah,"$"
arr db 1,2,3,4,5
min db ?
max db ?
data ends

code segment
assume cs:code, ds:data
start:
MOV AX,data
MOV DS,AX

MOV CL,4
MOV SI,OFFSET arr
MOV AL,[SI]
MOV min,AL
MOV max,AL

l2:
INC SI
MOV AL,[SI]
CMP min,AL
JC l1
MOV min,AL
l1:
CMP max,AL
JNC l3
MOV max,AL
l3:
DEC CL
JNZ l2

MOV DX,OFFSET msg1
MOV AH,09H
INT 21h

ADD min,30H
MOV DL,min
MOV AH,02H
INT 21H

MOV DX,OFFSET newl
MOV AH,09H
INT 21h


MOV DX,OFFSET msg2
MOV AH,09H
INT 21h

ADD max,30H
MOV DL,max
MOV AH,02H
INT 21H

MOV AH,4ch
INT 21h

code ends
end start
