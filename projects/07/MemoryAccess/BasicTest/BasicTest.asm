//instruction: pushconstant10
@10
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: poplocal0
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
//instruction: pushconstant21
@21
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant22
@22
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: popargument2
@2
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
//instruction: popargument1
@1
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
//instruction: pushconstant36
@36
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: popthis6
@6
D = A
@THIS
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
//instruction: pushconstant42
@42
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant45
@45
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: popthat5
@5
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
//instruction: popthat2
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
//instruction: pushconstant510
@510
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: poptemp6
@SP
M = M - 1
@SP
A = M
D = M 
@11
M = D
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
//instruction: pushthat5
@THAT
D = M 
@5
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
//instruction: pushthis6
@THIS
D = M 
@6
D = D + A
A = D 
D = M 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushthis6
@THIS
D = M 
@6
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
//instruction: pushtemp6
@11
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
