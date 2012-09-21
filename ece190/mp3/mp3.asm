;;; DO NOT MODIFY THIS SECTION
         .ORIG x4000
         .FILL HANDLE_NUM ; x4000
         .FILL HANDLE_OP  ; x4001
         .FILL HANDLE_END ; x4002
         .FILL MULT       ; x4003
         .FILL DIV        ; x4004
         .FILL PUSH       ; x4005
         .FILL POP        ; x4006
RESET    .FILL x3000
PRINTNUM .FILL x3001
;;; DO NOT MODIFY ABOVE THIS LINE

; ECE190 Machine Problem 3
; Spring 2012
; Name: Alexander Hsu
; NetID: awhsu2

; HANDLE_NUM will be called when a number is encountered in the Reverse
; Polish Notation expression.  The signed 2's complement number will be
; stored in R1.
HANDLE_NUM

        ; When a number is entered to the calculator, the number is pushed into the stack
        ; So for each number we receive, we push it into the stack
        ; we need to check for overflow here because we can push too much numbers
        
        ST R7, TEMPPCNUM
        ADD R0, R1, #0 ;Copies R1 to R0
        JSR PUSH       ;Jumps to PUSH subroutine 
        ADD R5, R5, #0 ;check overflow
        BRp OVERF ;Display overflow if R5 = 1
        LD R7, TEMPPCNUM
        RET

OVERF   LEA R0, ERR4     ;Load OVERFLOW
        PUTS             ;Display string
        LD R6, RESET ;load reset
        JMP R6 ;reset the calculator
        
    
ERR4    .STRINGZ "ERR4: Stack overflow.\n"
TEMPPCNUM .FILL x0000    
; HANDLE_OP will be called when an operator is encountered in the Reverse
; Polish Notation expression.  Stored in R1 will be a number which identifies
; which operator was encountered.  0 means +; 1 means -; 2 means *; 3 means /.
HANDLE_OP
        
        ; Operation requires the stack to pop the data out
        ; Then we need to jump to operation
        ; Let R3 be temp sum
        ; R1 and R2 are operands
        ; R0 is result
        ; R5 needs to be check to prevent weird breakdown

        ST R7, TEMPPCOP    ;stores whatever register used
        ST R3, HAND_TEMP1
        ST R2, HAND_TEMP2
        ST R0, HAND_TEMP3
        ADD R3, R1, #-3    ;determines which operation is used
        BRz DIVIDE
        ADD R3, R1, #-2
        BRz MULTI
        ADD R3, R1, #-1
        Brz SUBT
        ADD R3, R1, #0
        BRz ADDI
                
        RET

DIVIDE  JSR DIV
        LD R3, HAND_TEMP1  ;restores value
        LD R2, HAND_TEMP2
        LD R0, HAND_TEMP3
        LD R7, TEMPPCOP
        
        RET

MULTI   JSR MULT 
        LD R3, HAND_TEMP1 ;restores value
        LD R2, HAND_TEMP2
        LD R0, HAND_TEMP3
        LD R7, TEMPPCOP
        RET

ADDI    JSR POP
        ADD R5, R5, #0 ;Check R5
        BRp RESTART    ;RESET if R5=1
        ADD R2, R0, #0 ;Load first operand
        JSR POP
        ADD R5, R5, #0 ;Check R5
        BRp RESTART    ;RESET if R5=1
        ADD R0, R0, R2 ;Combine with first operand
        JSR PUSH       ;Put back to stack
        LD R7, TEMPPCOP ;restores registers
        LD R3, HAND_TEMP1 
        LD R2, HAND_TEMP2
        LD R0, HAND_TEMP3
        RET

SUBT    JSR POP        ;First number will be inverted
        ADD R5, R5, #0 ;Check R5
        BRp RESTART    ;RESET if R5=1
        ADD R2, R0, #0
        NOT R2, R2
        ADD R2, R2, #1 ;2's complement
        JSR POP        ;Load the other number
        ADD R5, R5, #0 ;Check R5
        BRp RESTART    ;RESET if R5=1
        ADD R0, R2, R0 ;Subtraction
        JSR PUSH
        LD R3, HAND_TEMP1 ;restores registers
        LD R2, HAND_TEMP2
        LD R0, HAND_TEMP3
        LD R7, TEMPPCOP
        RET

RESTART LEA R0, ERR1   ;load error "undrerflow"
        PUTS
        LD R6, RESET   ;loads reset
        JMP R6 ;       reset the calculator

HAND_TEMP1 .FILL x0000 ;Holds R3
HAND_TEMP2 .FILL x0000 ;Holds R2
HAND_TEMP3 .FILL x0000 ;Holds R0
TEMPPCOP .FILL x0000
; HANDLE_END will be called when the end of the Reverse Polish Notation
; expression is encountered.        
HANDLE_END
        ; put your code for the HANDLE_END subroutine here
        ; Assume the last operation pop the last value off the stack.
        ; need to check the stack pointer pointing to the memory below the stack (that way we know that we have pop all data)
        ; if there still data inside, then we have incomplete expression since not all number was used
        
        ST R7, TEMPPC
        JSR POP            ;loads the last value out and load into R0
        ADD R3, R0, #0     ;back up R0
        LD R6, POINTER     ;Load value of pointer (which should be 0 by now) to R6
        LEA R5, POINTER    ;Load address of POINTER to R5
        NOT R5, R5         ;Invert R5
        ADD R5, R5, #1     ;2's complement
        ADD R5, R6, R5     ;Check for empty stack
        BRnp INCOMP        ;Branch to incomplete if the sum is not zero
        LEA R0, ANSWER     ;load the string
        PUTS
        ADD R0, R3, #0     ;restore R0
        LD R6, PRINTNUM    ;load PRINTNUM
        JSRR R6            ;output R0
        LEA R0, SPACE
        PUTS
        LD R6, RESET       ;load reset
        JMP R6             ;reset the calculator

INCOMP  LEA R0, ERR2       ;load string error "incomplete expression"
        PUTS
        LEA R5, POINTER    ;loads the memory location of POINTER
        STR R5, R5, #0     ;store memory location of POINTER into POINTER
        LD R6, RESET       ;load reset
        JMP R6             ;reset the calculator
        
ANSWER .STRINGZ "Answer : "
SPACE  .STRINGZ " \n"
; multiply R1*R2 and put the result in R0.
MULT
        ;We set R1 as our primary number and R2 as our counter
        ;treat both of them as positive and multiply them together
        ;R1 loads first value, R2 holds the second value, R6 is sign flag.
        ;Answer will be loaded to R0 and pushed to stack
        ;no need to check overflow since the stack decreases.

        ST R7, TEMPPCMULT     ;store PC
        ST R6, TEMPMUL1       ;backup all registers used
        ST R3, TEMPMUL2
        ST R2, TEMPMUL3
        ST R1, TEMPMUL4 
        AND R6, R6, #0        ;setup flag
        JSR POP               ;load the first value out from stack
        ADD R5, R5, #0        ;Check R5
        BRp RESTART           ;RESET if R5=1
        ADD R1, R0, #0        ;load first value
        BRz ZERO              ;to zero if the value is 0.
RETURNM BRn INVERTX           ;invert if it's negative
        JSR POP               ;load second value
        ADD R5, R5, #0        ;Check R5
        BRp RESTART           ;RESET if R5=1
        ADD R2, R0, #0        ;load second value
        BRz ZERO              ;to zero if value is 0.
        BRn INVERTY           ;invert if it's negative
        AND R3, R3, #0
MULTIN  ADD R3, R2, R3        ;R1 get multiplied once
        ADD R1, R1, #-1       ;Counter subtract counter
        BRp MULTIN            ;Keep looping until counter is 0
        ADD R6, R6, #0        ;check sign flag
        BRnp INVANS           ;flip answer if the sign flag is positive or negative 
LOAD    ADD R0, R3, #0        ;load answer to R0
        JSR PUSH              ;Push output to stack
        LD R6, TEMPMUL1       ;restore all registers used
        LD R3, TEMPMUL2
        LD R2, TEMPMUL3
        LD R1, TEMPMUL4 
        LD R7, TEMPPCMULT     ;loads PC back

        RET

INVERTX ADD R1, R1, #-1       ;Converts from negative to positive
        NOT R1, R1            ;Reverse 2's complement
        ADD R6, R6, #-1       ;setup sign flag for first value
        BRnzp RETURNM

INVERTY ADD R2, R2, #-1       ;converts from negative to positive
        NOT R2, R2            ;reverse 2's complement
        ADD R6, R6, #1        ;setup sign flag for second value
        BRnzp MULTIN          ;jumps to multin since the first number is inverted.

ZERO    ADD R0, R6, #0        ;load zero to R0
        JSR PUSH              ;push back to stack
        LD R6, TEMPMUL1       ;restore all registers used
        LD R3, TEMPMUL2
        LD R2, TEMPMUL3
        LD R1, TEMPMUL4 
        LD R7, TEMPPCMULT     ;loads PC back
        RET

INVANS  NOT R3, R3            ;invert number
        ADD R3, R3, #1        ;2's complement
        BRn LOAD              ;branch back to LOAD

TEMPPCMULT .FILL x0000
TEMPMUL1   .FILL x0000
TEMPMUL2   .FILL x0000
TEMPMUL3   .FILL x0000
TEMPMUL4   .FILL x0000
; divide R1/R2 and put the result in R0.  on success, set R5 to 0. on fail, set R5
; to 1.
DIV     
        ; put your code for the DIV subroutine here
        ; the process is similar to multiplication
        ; but instead of adding we subtract and the final output
        ; from the counter
        ; Second value is divided by the first value
        ; R3 is temp storage
        ; R6 is sign flag
        ST R7, TEMPPCDIV ;Backup PC
        ST R6, TEMPDIV1
        ST R3, TEMPDIV2
        ST R2, TEMPDIV3
        ST R1, TEMPDIV4

        JSR POP ;load first value
        ADD R5, R5, #0     ;Check R5
        BRp RESTART        ;RESET if R5=1
        ADD R0, R0, #0     ;check if divisor is 0 (divide by 0 error)
        BRz DIVZ
        AND R6, R6, #0
        ADD R6, R6, #-1    ;setup flag 
        ADD R1, R0, #0     ;load value to R1
RETURNY BRp INVDIVY        ;Branch to invert number (from positive to negative since we are stubracting it)
        JSR POP            ;load second value
        ADD R5, R5, #0     ;Check R5
        BRp RESTART        ;RESET if R5=1
        ADD R2, R0, #0     ;load value to R2
        BRz ZERODIV ;      if dividend is 0, output 0 to monitor
RETURNX BRn INVDIVX        ;branch to invert number (from negative to positive)
        AND R3, R3, #0     ;clear counter
DIVLOOP ADD R2, R1, R2     ;subtraction
        BRn ENDLOOP
        ADD R3, R3, #1     ;increment counter
        BRp DIVLOOP
        RET


INVDIVY NOT R1, R1     ;invert
        ADD R1, R1, #1 ;2's complement
        ADD R6, R6, #1 ;Clear sign flag
        BRnzp RETURNY

INVDIVX ADD R2, R2, #-1 ;subract 1
        NOT R2, R2      ;undo 2's complement
        ADD R6, R6, #1  ;set up flag
        BRnzp RETURNX

DIVZ    LEA R0, ERR3    ;load divide by 0 error
        PUTS
        LD R6, RESET    ;reset calculator
        JMP R6

ZERODIV AND R0, R0, #0
        JSR PUSH
        LD R6, TEMPDIV1
        LD R3, TEMPDIV2
        LD R2, TEMPDIV3
        LD R1, TEMPDIV4
        LD R7, TEMPPCDIV
        RET
        
ENDLOOP ADD R6, R6, #0   ;check sign flag
        Brnp INVQUO      ;flip the answer if the sign flag is on
RETANS  ADD R0, R3, #0   ;load output to R0
        JSR PUSH         ;push data back to stack
        LD R6, TEMPDIV1
        LD R3, TEMPDIV2
        LD R2, TEMPDIV3
        LD R1, TEMPDIV4
        LD R7, TEMPPCDIV ;restore PC
        RET   

INVQUO  NOT R3, R3
        ADD R3, R3, #1   ;2's complement
        BRnzp RETANS     ;jump back to end loop

TEMPPCDIV .FILL x0000 
TEMPDIV1  .FILL x0000
TEMPDIV2  .FILL x0000
TEMPDIV3  .FILL x0000
TEMPDIV4  .FILL x0000
; push contents of R0 onto the stack.  on success, set R5 to 0. on fail, set R5 to 1.
PUSH  

        ; We set R6 as our temporary pointer storage
        ;Set R5 to be the stack pointer, and initial a memory for stack size
        ; When we push we decrement the pointer and compare to 2's complement of the top stack memory address

        ST R6, TEMP1     ;Backup R6
        ST R7, TEMPPC    ;Backup PC
        LD R6, POINTER   ;Get pointer to R6
        LEA R5, STACK    ;Get the top address value for STACK
        NOT R5, R5       ;Invert number
        ADD R5, R5, #1   ;2'S complement
        ADD R5, R5, R6   ;Check overflow
        BRz OVER         ;Branch to overflow if true
        AND R5, R5, #0   ;Setup SUCCESS flag
        ADD R6, R6, #-1  ;Decrement pointer
        STR R0, R6, #0   ;Store R0 using pointer
        ST R6, POINTER   ;Store new pointer to POINTER
        LD R6, TEMP1     ;Restore R6
        LD R7, TEMPPC    ;Restore PC
        RET

OVER    ADD R5,R5,#1     ;Setup FAIL flag
        LD R6, TEMP1     ;Restore R6
        LD R7, TEMPPC    ;restore PC
        RET
TEMP1   .FILL x0000      ;TEMP for R6
TEMPPC  .FILL x0000      ;TEMP for PC 
STACK   .BLKW #30        ;reserve the next 30 memory locations
POINTER .FILL POINTER    ;Pointer starts here, below the stack

; pop a number off of the stack and put it into R0.  on success, set R5 to 0.
; on fail, set R5 to 1.
POP
        
        ; Same thing with PUSH, but we increment the pointer and load the value
        ; To prevent underflow, we compare to the memory address of the pointer
        
        ST R6, TEMP2     ;Backup R6
        ST R7, TEMPPC    ;Backup R5
        LD R6, POINTER   ;Load pointer (value inside pointer) to R6
        LEA R5, POINTER  ;Load address of POINTER to R5
        NOT R5, R5       ;Invert R5
        ADD R5, R5, #1   ;2's complement
        ADD R5, R6, R5   ;Check underflow
        BRz UNDER        ;Branch to underflow if true
        LDR R0, R6, #0   ;Dump data from stack to R0
        ADD R6, R6, #1   ;Increment Pointer
        ST R6, POINTER   ;Store new pointer to POINTER
        AND R5, R5, #0   ;Setup SUCCESS flag
        LD R6, TEMP2     ;Restore R6
        LD R7, TEMPPC    ;Restore PC
        RET
UNDER   ADD R5, R5, #1   ;Setup FAIL flag
        LD R6, TEMP2     ;Restore R6
        LD R7, TEMPPC    ;Restore PC
        RET
TEMP2   .FILL x0000      ;Temp for R6


        

;error output
ERR1    .STRINGZ "ERR1: Stack underflow.\n"
ERR2    .STRINGZ "ERR2: Incomplete expression.\n"
ERR3    .STRINGZ "ERR3: Division by zero.\n"



.END
