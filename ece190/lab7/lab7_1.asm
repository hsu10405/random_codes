.ORIG x3000

AND R0,R0,#0
AND R1,R1,#0

LD R0, INPUT ;load input into R0
JSR FUCT

TRAP x25

FUCT ST R0,TEMPR0 ;PUSH all registers to temp
     ST R2,TEMPR2 ;R1 is not present because we will use it as output
     ST R3,TEMPR3
     ST R4,TEMPR4
     ST R5,TEMPR5
     ST R6,TEMPR6
     ST R7,TEMPR7
     AND R2,R2,#0 ;clear counter
     LD R2, COUNT ;load counter

MULT ADD R1,R0,R1 ;Multipilication
     ADD R2,R2,#-1 ;decrement counter
     BRp MULT ;loop MULT
     ADD R1,R1,#4 ;Complete function

LOAD LD R0,TEMPR0 ;Restores Registers
     LD R2,TEMPR2
     LD R3,TEMPR3
     LD R4,TEMPR4
     LD R5,TEMPR5
     LD R6,TEMPR6
     LD R7,TEMPR7
    
     RET ;return to main function
INPUT .FILL x0008 
COUNT .FILL x0003

TEMPR0 .FILL x0000 ;temp for registers 
TEMPR2 .FILL x0000 
TEMPR3 .FILL x0000 
TEMPR4 .FILL x0000 
TEMPR5 .FILL x0000 
TEMPR6 .FILL x0000 
TEMPR7 .FILL x0000 

.END ;END OF PROGRAM
