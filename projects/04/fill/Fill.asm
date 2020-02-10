// Fills screen according to key input
// If key pressed then turn screen black
// else turn screen white

(MAIN_LOOP)
// variables that we need and initializing them

@SCREEN
D = A

@address
M = D

@8192
D = A

@n
M = D

// check to see if keyboard is pressed

@KBD
D = M

@POSITIVE
D;JGT // that is jump to new " on " status if pressed

@NEGATIVE
0;JLE

@MAIN_LOOP
0;JMP
(NEGATIVE)
// initialize i
@i
M = 0

(LOOP_NEGATIVE)

@i
D = M

@n
D = D - M
@MAIN_LOOP
D;JGE

//white address and increment it
@0
D = A
@address
A = M
M = D
//else increment i
@i
M = M + 1

@1
D = A

@address
M = M + D

// loop back to beginning of LOOP_NEGATIVE

@LOOP_NEGATIVE
0;JMP


(POSITIVE)
// initialize i
@i
M = 0
(LOOP_POSITIVE)
// check to see if i == n

@i
D = M

@n
D = D - M
@MAIN_LOOP
D ;JGE

//blacken address and increment it
@address
A = M
M = -1
// else increment i
@i
M = M + 1

@1
D = A

@address
M = M + D

// loop back to beginning of LOOP_POSITIVE

@LOOP_POSITIVE
0;JMP
