
.ORIG x2000

	LD R6, STCKPTR

    LEA R0, MESSAGE
	STR R0, R6, #-1 ; push the pointer to "source"
    ADD R6, R6, #-1

    LEA R0, SPACE    
	STR R0, R6, #-1 ; push the pointer to "destination"
    ADD R6, R6, #-1

    LD R2, STRCPY
	JSRR R2

    LDR R0, R6, #0 ; load the return value into R0
    ADD R6, R6, #3 ; pop the return value and parameters

	HALT	
	
STCKPTR .fill x2F00
STRCPY	.fill x3000

MESSAGE .STRINGZ "This is a message to be copied to some other place."

SPACE   .BLKW #100 ; Some space to store a copy.

.END
