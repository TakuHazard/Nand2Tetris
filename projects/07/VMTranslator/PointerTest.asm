//instruction: pushconstant3030
@3030
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: poppointer0
@SP
M = M - 1
@SP
A = M 
D = M 
@THIS
M = D 
//instruction: pushconstant3040
@3040
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: poppointer1
@SP
M = M - 1
@SP
A = M 
D = M 
@THAT
M = D 
//instruction: pushconstant32
@32
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: popthis2
@2
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
//instruction: pushconstant46
@46
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: popthat6
@6
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
//instruction: pushpointer0
@THIS
D = M
@SP
A = M
M = D 
@SP
M = M + 1
//instruction: pushpointer1
@THAT
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
//instruction: pushthis2
@THIS
D = M 
@2
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
//instruction: pushthat6
@THAT
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
