.ORIG x3000

   ;Dummy Subroutine, DO NOTHING TO THIS CODE!  This code simply 
   ;increases the parameter by 1 and returns it. WARNING: Correct 
   ;activiation record implementation and stack implementation are NOT 
   ;done in this subroutine, so do not use this to infer how to do the 
   ;correct implementation (it is actually quite incorrect how it is 
   ;currently written).  It will, however, give the correct output at the 
   ;end of the subroutine as though the correct implementation was done.

   ;PLEASE NOTE: This dummy subrountine may be replaced by other dummy 
   ;subroutines during the grading process (for example, a subroutine 
   ;that always returns a 4 no matter what).  This will not affect your 
   ;main.asm program as long as you have done correct activiation 
   ;record/stack implementation.

   ADD R0, R0, #1
   ADD R6, R6, #-1
   STR R0, R6, #0

   RET



.END
