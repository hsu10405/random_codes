; Problem 4: Compute the Sum
.ORIG x4000

FINDSUM

SAVE
    ST R0, TEMP0
    ST R1, TEMP1
    ST R2, TEMP2
    ST R3, TEMP3
    ST R4, TEMP4
    ST R5, TEMP5
    ST R6, TEMP6
        
    LD R0, POINTER
    AND R4, R4, #0 ;clear temp
TOP_LOOP
    LD R1, MAX
    NOT R1, R1     ;2's complement
    ADD R1, R1, #1 
    ADD R3, R0, R1 ;checking
    BRp DONE
    LDR R5, R0, #0
    ADD R4, R5, R4 ;put into sum
    ADD R0, R0, #1 ;increment pointer
    BRnzp TOP_LOOP

DONE STR R4, R0, #0
     
    LD R0, TEMP0
    LD R1, TEMP1
    LD R2, TEMP2
    LD R3, TEMP3
    LD R4, TEMP4
    LD R5, TEMP5
    LD R6, TEMP6
    
    

        RET         ; stop execution

POINTER .FILL x3100
MAX .FILL x310C

TEMP0 .FILL x0000
TEMP1 .FILL x0000
TEMP2 .FILL x0000
TEMP3 .FILL x0000
TEMP4 .FILL x0000
TEMP5 .FILL x0000
TEMP6 .FILL x0000
.END    
