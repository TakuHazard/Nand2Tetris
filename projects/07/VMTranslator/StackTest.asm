//instruction: pushconstant17
@17
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant17
@17
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: eq
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
@True2
D;JEQ
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END2
0;JMP
(True2)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END2
0;JMP
(END2)
@SP
 M = M + 1
//instruction: pushconstant17
@17
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant16
@16
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: eq
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
@True5
D;JEQ
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END5
0;JMP
(True5)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END5
0;JMP
(END5)
@SP
 M = M + 1
//instruction: pushconstant16
@16
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant17
@17
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: eq
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
@True8
D;JEQ
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END8
0;JMP
(True8)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END8
0;JMP
(END8)
@SP
 M = M + 1
//instruction: pushconstant892
@892
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant891
@891
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: lt
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
@True11
D;JLT
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END11
0;JMP
(True11)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END11
0;JMP
(END11)
@SP
 M = M + 1
//instruction: pushconstant891
@891
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant892
@892
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: lt
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
@True14
D;JLT
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END14
0;JMP
(True14)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END14
0;JMP
(END14)
@SP
 M = M + 1
//instruction: pushconstant891
@891
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant891
@891
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: lt
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
@True17
D;JLT
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END17
0;JMP
(True17)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END17
0;JMP
(END17)
@SP
 M = M + 1
//instruction: pushconstant32767
@32767
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant32766
@32766
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: gt
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
@True20
D;JGT
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END20
0;JMP
(True20)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END20
0;JMP
(END20)
@SP
 M = M + 1
//instruction: pushconstant32766
@32766
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant32767
@32767
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: gt
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
@True23
D;JGT
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END23
0;JMP
(True23)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END23
0;JMP
(END23)
@SP
 M = M + 1
//instruction: pushconstant32766
@32766
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant32766
@32766
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: gt
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
@True26
D;JGT
@R13
M = 0
D = M 
@SP
A = M 
M = D 
@END26
0;JMP
(True26)
@R13
M = -1
D = M
@SP
A = M 
M = D 
@END26
0;JMP
(END26)
@SP
 M = M + 1
//instruction: pushconstant57
@57
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant31
@31
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: pushconstant53
@53
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
//instruction: pushconstant112
@112
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
//instruction: neg
@SP
M = M - 1
@SP
A = M 
D = M 
@R13
M = D 
@R14
M = D 
@R14
D =  M
@R13
M = M - D 
@R14
D =  M 
@R13
M = M - D
@R13
D = M
@SP
A = M 
M = D 
@SP
M = M + 1 
//instruction: and
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
M = D & M
@R13
D = M
@SP
A = M 
M = D 
@SP
M = M + 1
//instruction: pushconstant82
@82
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: or
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
M = D|M
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
