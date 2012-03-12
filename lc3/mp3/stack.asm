.ORIG x4000
PUSH
        ; put your code for the PUSH subroutine here
        ; Assuming we are not loading with more ten numbers,
        ; We set R6  ;Set R5 to be the stack pointer, and initial a memory for stack size
        ; When we push we decrement the pointer and compare to 2's complement of the top stack memory address
        ; since we can't go beyond that
        ST R6, TEMP1  ;Backup R6
        ST R7, TEMPPC ;Backup PC
        LD R6, POINTER ;Get pointer to R6
        LEA R5, STACK ;Get the top address value for STACK
        NOT R5, R5 ;Invert number
        ADD R5, R5, #1 ;2'S complement
        ADD R5, R5, R6; Check overflow
        BRz OVER ;Branch to overflow if true
        AND R5, R5, #0 ;Setup SUCCESS flag
        ADD R6, R6, #-1 ;Decrement pointer
        STR R0, R6, #0 ;Store R0 using pointer
        ST R6, POINTER ;Store new pointer to POINTER
        LD R6, TEMP1 ;Restore R6
        LD R7, TEMPPC ;Restore PC
        RET

OVER    ADD R5,R5,#1 ;Setup FAIL flag
        LEA R0, ERR4 ;Load OVERFLOW
        PUTS ;Display string
        LD R6, TEMP1 ;Restore R6
        LD R7, TEMPPC ;restore PC
        RET
TEMP1   .FILL x0000 ;TEMP for R6
TEMPPC  .FILL x0000 ;TEMP for PC 
STACK   .BLKW #30  ;reserve the next 30 memory locations
POINTER .FILL POINTER ;Pointer starts here, below the stack

; pop a number off of the stack and put it into R0.  on success, set R5 to 0.
; on fail, set R5 to 1.
POP
        ; put your code for the POP subroutine here
        ; Same thing with PUSH, we keep the size at 30
        ; To prevent underflow, we compare to the memory address of the pointer
        
        ST R6, TEMP2 ;Backup R6
        ST R7, TEMPPC ;Backup R5
        LD R6, POINTER ;Load pointer (value inside pointer) to R6
        LEA R5, POINTER ;Load address of POINTER to R5
        NOT R5, R5 ;Invert R5
        ADD R5, R5, #1 ;2's complement
        ADD R5, R6, R5 ;Check underflow
        BRz UNDER ;Branch to underflow if true
        LDR R0, R6, #0 ;Dump data from stack to R0
        ADD R6, R6, #1 ;Increment Pointer
        ST R6, POINTER ;Store new pointer to POINTER
        AND R5, R5, #0 ;Setup SUCCESS flag
        LD R6, TEMP2 ;Restore R6
        LD R7, TEMPPC ;Restore PC
        RET
UNDER   ADD R5, R5, #1 ;Setup FAIL flag
        LEA R0, ERR1 ;Load UNDERFLOW string
        PUTS ;Display UNDERFLOW
        LD R6, TEMP2 ;Restore R6
        LD R7, TEMPPC ;Restore PC
        RET
TEMP2   .FILL x0000 ;Temp for R6


        

; Feel free to move these error messages to elsewhere in the file.
ERR1    .STRINGZ "ERR1: Stack underflow.\n"
ERR2    .STRINGZ "ERR2: Incomplete expression.\n"
ERR3    .STRINGZ "ERR3: Division by zero.\n"
ERR4    .STRINGZ "ERR4: Stack overflow.\n"



.END

