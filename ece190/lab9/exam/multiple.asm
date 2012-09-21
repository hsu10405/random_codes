; This program checks whether the positive integer in R1 divides the positive integer in R0. 
; This is to say that R0 ÷ R1 has no remainder. 
; If the condition is true, the subroutine must set R2 to 1; otherwise it must set it to 0.

; This program primarily uses registers in the following manner:
; R0 contains first number 
; R1 contains second number
; R2 should contains 1 or 0 after the subroutine call

            .ORIG x4300                     ; code starts here by using the .orig directive
                                   
REMAINDER                             ; your subroutine goes here

ST R7, TEMPPC 
ST R0, TEMP0
ST R1, TEMP1
ST R3, TEMP2

INIT

AND R1, R1, #0
AND R0, R0, #0
ADD R1, R1, #3
ADD R0, R0, #8

AND R2, R2, #0 ;clear R2
AND R3, R3, #0 
NOT R1, R1
ADD R1, R1, #1 ;2's complement

LOOP
ADD R0, R0, R1 
ADD R3, R3, #1
ADD R0, R0, #0
BRp LOOP
BRz RETF
AND R2, R2, #0
ADD R2, R2, #1
LD R0,TEMP0
LD R1,TEMP1
LD R3,TEMP2
LD R7,TEMPPC
RET

RETF
AND R2, R2, #0
LD R0,TEMP0
LD R1,TEMP1
LD R3,TEMP2
LD R7,TEMPPC

RET

TEMPPC .FILL x0000
TEMP0 .FILL x0000
TEMP1 .FILL x0000
TEMP2 .FILL x0000
             .END

