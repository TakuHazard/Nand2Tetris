//instruction: pushconstant111
@111
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant333
@333
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant888
@888
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: popstatic8
@SP
M = M - 1
@SP
A = M
D = M 
@StaticTest.8
 M = D 
//instruction: popstatic3
@SP
M = M - 1
@SP
A = M
D = M 
@StaticTest.3
 M = D 
//instruction: popstatic1
@SP
M = M - 1
@SP
A = M
D = M 
@StaticTest.1
 M = D 
//instruction: pushstatic3
@StaticTest.3
D = M 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushstatic1
@StaticTest.1
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
//instruction: pushstatic8
@StaticTest.8
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
