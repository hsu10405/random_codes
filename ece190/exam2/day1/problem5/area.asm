; Problem 5: Area of a Triangle
.ORIG x4000

; compute the area of a triangle.  R0 contains the base width;
; R1 contains the height.  put the area in R3.
AREA

SAVE
     ST R0, TEMP0
     ST R1, TEMP1
     ST R2, TEMP2
     ST R4, TEMP3
     ST R5, TEMP4
     ST R6, TEMP5

     AND R4, R4, #0 ;clear temp
TOP_LOOP
     ADD R4, R1, R4
     ADD R0, R0, #-1
     BRp TOP_LOOP
     AND R5, R5, #0 ;clear temp
DIVIDE
     ADD R4, R4, #-2
     ADD R5, R5, #1
     ADD R4, R4, #0 ;condition
     BRp DIVIDE
     ADD R3, R5, #0

LOAD
     LD R0, TEMP0
     LD R1, TEMP1
     LD R2, TEMP2
     LD R4, TEMP3
     LD R5, TEMP4
     LD R6, TEMP5


        RET

TEMP0 .FILL x0000
TEMP1 .FILL x0000
TEMP2 .FILL x0000
TEMP3 .FILL x0000
TEMP4 .FILL x0000
TEMP5 .FILL x0000

.END
