.ORIG x3000



STRCPY

;PRE-call, R5, R6 points to parameters


    ADD R6, R6, #2 ; SAVE R5
    STR R5, R6, #0 ; 

    LDR R5, R6, #-3 ; LOAD SOURCE

    ADD R6, R6, #1 ; SAVE R7
    STR R7, R6, #0 ;

    ADD R6, R6, #1 ;set up var
    ADD R6, R6, #1 ;set up var
    STR R5, R6, #0 ;load strings pointer
    ADD R5, R5, #1 
    STR R5, R6, #1 ;load stringd

    AND R2, R2, #0 ; setup counter   
    STR R2, R6, #-1 ; clear var

WORK
    LDR R1, R6, #0 ; load source string
    LDR R0, R1, #0
    BRz DONE
    
    LDR R1, R6, #1 ;loads dest string
    STR R0, R1 , #0 ;overrides the string
 
    LDR R2, R6, #-1 ;load counter
    ADD R2, R2, #1 ; counter++
    STR R2, R6, #-1
 
    BRnzp WORK

    
DONE 
    LDR R2, R6, #-1 ;load counter
    ADD R6, R6, #-2 ;REstore r7
    LDR R7, R6, #0
    ADD R6, R6, #-1 ;restore R5
    LDR R5, R6, #0 
    ADD R6, R6, #-1 ;point to retval

    STR R2, R6, #0 ;pass retval






RET
.END
