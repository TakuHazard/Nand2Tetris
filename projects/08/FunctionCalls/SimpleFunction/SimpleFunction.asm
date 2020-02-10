//instruction: functionSimpleFunction.test2
(SimpleFunction.test)
@2
D = A
@R13
M = D
@R14
M = 0
(LOOP0)
@R14
D = M
@R13
D = D - M
@endloop0
D;JGT
@SP
A = M
M = 0
@SP
M = M + 1
@R14
M = M + 1
@LOOP0
0;JMP
(endloop0)//instruction: pushlocal0
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
//instruction: pushlocal1
@LCL
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
//instruction: not
@SP
M = M - 1
@SP
A = M 
D = M 
@R13
M = D 
@R13
D = M
@R13
M = !D
@R13
D = M
@SP
A = M 
M = D
@SP
M = M + 1
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
//instruction: return
@LCL
D = M
@FRAME
M = D
@5
D = A
@FRAME
D = M - D
A = D
D = M
@RET
M = D
@SP
M = M - 1
@SP
A = M
D = M
@ARG
A = M
M = D
@ARG
D = M
D = D + 1
@SP
M = D
@FRAME
D = M
@1
D = D - A
A = D
D = M
@THAT
M = D
@FRAME
D = M
@2
D = D - A
A = D
D = M
@THIS
M = D
@FRAME
D = M
@3
D = D - A
A = D
D = M
@ARG
M = D
@FRAME
D = M
@4
D = D - A
A = D
D = M
@LCL
M = D
@RET
0;JMP
