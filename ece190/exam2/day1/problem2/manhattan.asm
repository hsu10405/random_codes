; Problem 2: Manhattan Distance
.ORIG x4000

          ;R0 contains a1
          ;R1 contains b1
          ;R2 contains a2
          ;R3 contains b2
          ;return solution in R5

MANHATTAN ;start your subroutine at this line
SAVE 
     ST R0, TEMP0
     ST R1, TEMP1
     ST R2, TEMP2
     ST R3, TEMP3
     ST R4, TEMP4
     ST R6, TEMP5

WORK NOT R2, R2
     ADD R2, R2, #1
     ADD R0, R0, R2
RETA BRn INVERTA
     NOT R3, R3
     ADD R3, R3, #1
     ADD R1, R1, R3
RETB BRn INVERTB
     ADD R5, R1, R0
     LD R0, TEMP0
     LD R1, TEMP1
     LD R2, TEMP2
     LD R3, TEMP3
     LD R4, TEMP4
     LD R6, TEMP5
     RET

INVERTA ADD R0, R0, #-1
        NOT R0, R0
        BRnzp RETA

INVERTB ADD R1, R1, #-1
        NOT R1, R1
        BRnzp RETB

     
          ;subroutine code goes here


TEMP0 .FILL x0000
TEMP1 .FILL x0000
TEMP2 .FILL x0000
TEMP3 .FILL x0000
TEMP4 .FILL x0000
TEMP5 .FILL x0000




.END
