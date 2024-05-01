DATA SEGMENT
    NUM1 DB 01H
    NUM2 DB 02H
DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE,DS:DATA
        START:


        MOV AX,DATA
        MOV DS,AX

        MOV AL,NUM1
        MOV AH,NUM2
        ADD AL,AH

        MOV AH,4CH
       INT 21H

        CODE ENDS
 END START
