.ORIG x6000

;structure of a root pointer
;value
;pointer to left
;pointer to right

;stack structure
;local var
;R7,
;R5
;Ret value
;parameter 2
;parameter 1

;save R5, R7

STR R5, R6, #-3 ;save R5
STR R7, R6, #-4 ;save R7
ADD R5, R6, #0 ;set R5 at bottom
ADD R6, R6, #-5

TOP_OF_LOOP
LDR R2, R5, #0 ;load parameter
LDR R1, R5, #-1
BRz NOT_FOUND
LDR R3, R1, #0 ;load root->value

NOT R2, R2
ADD R2, R2, #1


ADD R3, R2, R3
BRn LEFT
BRp RIGHT

ADD R3, R3, #1
STR R3, R5, #-2
BRnzp DONE

LEFT
;shift the parameter to the left of the node
LDR R1, R5, #-1 ;loads pointer address
ADD R1, R1, #1 ;point to left
STR R1, R5, #-1 
BRnzp TOP_OF_LOOP

RIGHT
;shift the parameter to the right
LDR R1, R5, #-1
ADD R1, R1, #2
STR R1, R5, #-1
BRnzp TOP_OF_LOOP

NOT_FOUND
AND R1, R1, #0
STR R1, R5, #-2
BRnzp DONE

DONE
;Restore R5, R7
ADD R6, R6, #1
LDR R7, R6, #0
ADD R6, R6, #1
LDR R6, R6, #0
ADD R6, R6, #1 ;point to Return Value

JSR

.END
