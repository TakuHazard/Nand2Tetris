//instruction: functionSys.init0
(Sys.init)
@0
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
(endloop0)//instruction: callSys.main0
@return_address1
D = A
@SP
A = M 
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M 
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M 
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M 
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M 
M = D
@SP
M = M + 1
@SP
D = M
@0
D = D - A
@5
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Sys.main
0;JMP
(return_address1)
//instruction: poptemp1
@SP
M = M - 1
@SP
A = M
D = M 
@6
M = D
//instruction: labelLOOP
(Sys$LOO)
//instruction: gotoLOOP
@Sys$LOO
0;JMP
//instruction: functionSys.main0
(Sys.main)
@0
D = A
@R13
M = D
@R14
M = 0
(LOOP5)
@R14
D = M
@R13
D = D - M
@endloop5
D;JGT
@SP
A = M
M = 0
@SP
M = M + 1
@R14
M = M + 1
@LOOP5
0;JMP
(endloop5)//instruction: pushconstant123
@123
D = A 
@SP
A = M 
M = D
@SP
M = M + 1
//instruction: callSys.add121
@return_address7
D = A
@SP
A = M 
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M 
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M 
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M 
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M 
M = D
@SP
M = M + 1
@SP
D = M
@121
D = D - A
@5
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Sys.add
0;JMP
(return_address7)
//instruction: poptemp0
@SP
M = M - 1
@SP
A = M
D = M 
@5
M = D
//instruction: pushconstant246
@246
D = A 
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
//instruction: functionSys.add123
(Sys.add)
@123
D = A
@R13
M = D
@R14
M = 0
(LOOP11)
@R14
D = M
@R13
D = D - M
@endloop11
D;JGT
@SP
A = M
M = 0
@SP
M = M + 1
@R14
M = M + 1
@LOOP11
0;JMP
(endloop11)//instruction: pushargument0
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
//instruction: pushconstant12
@12
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
