//instruction: pushargument1
@ARG
D = M 
@1
D = D + A
A = D 
D = M 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: poppointer1//that=argument[1]
@SP
M = M - 1
@SP
A = M 
D = M 
@THAT
M = D 
//instruction: pushconstant0
@0
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: popthat0//firstelementintheseries=0
@0
D = A
@THAT
D = D + M
@R13
M = D
@SP
M = M - 1
@SP
A = M
D = M 
@R13
A = M
M = D 
//instruction: pushconstant1
@1
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: popthat1//secondelementintheseries=1
@1
D = A
@THAT
D = D + M
@R13
M = D
@SP
M = M - 1
@SP
A = M
D = M 
@R13
A = M
M = D 
//instruction: pushargument0
@ARG
D = M 
@0
D = D + A
A = D 
D = M 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant2
@2
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: sub
@SP
M = M - 1
@SP
A = M 
D = M 
@R13
M = D 
@SP
 M = M - 1 
@SP
A = M
D = M
@R14
M = D 
@R14
D = M 
@R13
M = D - M 
@R13
D = M 
@SP
A = M 
M = D 
@SP
 M = M + 1
//instruction: popargument0//num_of_elements-=2(first2elementsareset)
@0
D = A
@ARG
D = D + M
@R13
M = D
@SP
M = M - 1
@SP
A = M
D = M 
@R13
A = M
M = D 
//instruction: labelMAIN_LOOP_START
(FibonacciSeries$MAIN_LOOP_START)
//instruction: pushargument0
@ARG
D = M 
@0
D = D + A
A = D 
D = M 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: if-gotoCOMPUTE_ELEMENT//ifnum_of_elements>0,gotoCOMPUTE_ELEMENT
@SP
M = M - 1
@SP
A = M
D = M
@FibonacciSeries$COMPUTE_ELEMENT
D;JGT
//instruction: gotoEND_PROGRAM//otherwise,gotoEND_PROGRAM
@FibonacciSeries$END_PROGRAM
0;JMP
//instruction: labelCOMPUTE_ELEMENT
(FibonacciSeries$COMPUTE_ELEMENT)
//instruction: pushthat0
@THAT
D = M 
@0
D = D + A
A = D 
D = M 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushthat1
@THAT
D = M 
@1
D = D + A
A = D 
D = M 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: add
@SP
M = M - 1
@SP
A = M 
D = M 
@R13
M = D 
@SP
 M = M - 1 
@SP
A = M
D = M
@R14
M = D 
@R14
D = M 
@R13
M = D + M 
@R13
D = M 
@SP
A = M 
M = D 
@SP
 M = M + 1
//instruction: popthat2//that[2]=that[0]+that[1]
@2
D = A
@THAT
D = D + M
@R13
M = D
@SP
M = M - 1
@SP
A = M
D = M 
@R13
A = M
M = D 
//instruction: pushpointer1
@THAT
D = M
@SP
A = M
M = D 
@SP
M = M + 1
//instruction: pushconstant1
@1
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: add
@SP
M = M - 1
@SP
A = M 
D = M 
@R13
M = D 
@SP
 M = M - 1 
@SP
A = M
D = M
@R14
M = D 
@R14
D = M 
@R13
M = D + M 
@R13
D = M 
@SP
A = M 
M = D 
@SP
 M = M + 1
//instruction: poppointer1//that+=1
@SP
M = M - 1
@SP
A = M 
D = M 
@THAT
M = D 
//instruction: pushargument0
@ARG
D = M 
@0
D = D + A
A = D 
D = M 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant1
@1
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: sub
@SP
M = M - 1
@SP
A = M 
D = M 
@R13
M = D 
@SP
 M = M - 1 
@SP
A = M
D = M
@R14
M = D 
@R14
D = M 
@R13
M = D - M 
@R13
D = M 
@SP
A = M 
M = D 
@SP
 M = M + 1
//instruction: popargument0//num_of_elements--
@0
D = A
@ARG
D = D + M
@R13
M = D
@SP
M = M - 1
@SP
A = M
D = M 
@R13
A = M
M = D 
//instruction: gotoMAIN_LOOP_START
@FibonacciSeries$MAIN_LOOP_START
0;JMP
//instruction: labelEND_PROGRAM
(FibonacciSeries$END_PROGRAM)
