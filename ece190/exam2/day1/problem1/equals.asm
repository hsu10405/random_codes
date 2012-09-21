; Problem 1: Equality Check
.ORIG x4000

; checks whether R0 == R1. if so, set R2 to 1; else set R2 to 0.
EQUALS
        
        ; write your code for the subroutine here

SAVE 
     ST R0, TEMP0
     ST R1, TEMP1
     ST R6, TEMP2
     ST R3, TEMP3
     ST R4, TEMP4
     ST R5, TEMP5

WORK
    NOT R0, R0
    ADD R0, R0, #1
    ADD R1, R0, R1
    BRz DONE
    AND R2, R2, #0
     LD R0, TEMP0
     LD R1, TEMP1
     LD R6, TEMP2
     LD R3, TEMP3
     LD R4, TEMP4
     LD R5, TEMP5
    RET
DONE AND R2, R2, #0
     ADD R2, R2, #1    
     LD R0, TEMP0
     LD R1, TEMP1
     LD R6, TEMP2
     LD R3, TEMP3
     LD R4, TEMP4
     LD R5, TEMP5
        RET

TEMP0 .FILL x0000
TEMP1 .FILL x0000
TEMP2 .FILL x0000
TEMP3 .FILL x0000
TEMP4 .FILL x0000
TEMP5 .FILL x0000

.END
