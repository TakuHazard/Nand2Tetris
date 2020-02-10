//instruction: pushconstant0
@0
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: poplocal0//initializessum=0
@00
D = A
@LCL
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
//instruction: labelLOOP_START
(BasicLoop$LOOP_START)
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
//instruction: pushlocal0
@LCL
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
//instruction: poplocal0	//sum=sum+counter
@0
D = A
@LCL
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
//instruction: popargument0//counter--
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
//instruction: if-gotoLOOP_START//Ifcounter>0,gotoLOOP_START
@SP
M = M - 1
@SP
A = M 
D = M
@BasicLoop$LOOP_START
D;JGT
//instruction: pushlocal0
@LCL
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
