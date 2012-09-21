.ORIG x2000

;setting up stack
    LD R6, PREVIOUS ;Setup pointer
    LD R5, PREVIOUS
;initialize main
; R0, R1 = mynum, copy

    ADD R6, R6, #0 ;push vars
    AND R0, R0, #0
    ADD R0, R0, #7 ;load mynum
    STR R0, R6, #0 ;push mynum
    ADD R6, R6, #1 ;make space for copy
    LD R2, NUMBERS

    JSRR R2; jumps to Numbers

    ;R6 points at retval
    ;R5 points at the bottom of the stack
    
    LDR R0, R6, #0 ;Loads Retval to a reg
    STR R0, R5, #3 ;Stores in copy

    ;OUTPUT copy
    LDR R0, R5, #2; LOAD copy
    PUTS
    AND R0, R0, #0 ; clear R0
    ADD R0, R0, #10; add next line
    PUTS
    
    









HALT

NUMBERS	 .FILL x3000
PREVIOUS .FILL x1FFA
.END
