;Register 1 is to load the current number
;Register 2 is for the 2's complement converter
;Register 3 is for addition.
;Register 4 is used as a counter for the 12 values
;Register 6 is used to count the number of presence for the value.
;Register 7 is used to store the smallest number of the list.

.ORIG x3100 ; Program starts at this location

AND R1,R1,#0 ;Clear R1
AND R2,R2,#0 ;Clear R2
AND R3,R3,#0 ;Clear R3
AND R4,R4,#0 ;Clear R4
AND R5,R5,#0 ;Clear R5
AND R6,R6,#0 ;Clear R6
AND R7,R7,#0 ;Clear R7

ADD R4,R4,#13 ;ADD 12 to R4

LDI R5,START ;R5 Loads the value at x3132

;Storing the comparision value
COMPARATOR ADD R7,R5,#0 ;Load R5 to R7
ADD R6,R6,#1 ;include the first value
ADD R4,R4,#-1 ;Subtract the counter
LD  R5,START  ; LOAD x3132 into R5
;Load input
INPUT AND R3,R3,#0 ;Clear Temp
      ADD R5,R5,#1 ;Increment the address by 1
      LDR R1,R5,#0  ;Load R5 to R1
      NOT R2,R7
      ADD R2,R2,#1
      ADD R3,R1,R2

      BRn LESS

      BRz EQUAL

;If Input>Previous
;Go Back to Load input
;Counter -1
GREAT ADD R4,R4,#-1	
      BRp INPUT
      TRAP X25

;If input<Previous
LESS AND R7,R7,#0 ;Clear R7
     AND R6,R6,#0 ;Clear R6
     ADD R7,R1,#0 ;Insert R1 to R7
     ADD R6,R6,#1
     ADD R4,R4,#-1 ;Counter -1
     BRp INPUT
;If equal
EQUAL ADD R6,R6,#1
ADD R4,R4,#-1
BRp INPUT

TRAP X25

START .FILL x3132 ;R5 should point to this address and increment itself by 1 to load the next data.

.END
