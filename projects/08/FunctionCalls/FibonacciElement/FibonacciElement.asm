// THIS IS BOOTING UP
@256
D = A
@SP
M = D
@RETURNSys.init
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
D = M
@0
D = D - A
@5
D = D - A
@SP
D = M
@LCL
M = D
@Sys.init
0;JMP
(RETURNSys.init)
//instruction: functionSys.init0
(Sys.init)
//instruction: pushconstant4
@4
D = A
@SP
A = M
M = D
@SP
M = M + 1
//instruction: callMain.fibonacci1//computesthe4'thfibonaccielement
@returnMain.fibonacci
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
D = M
@1
D = D - A
@5
D = D - A
@SP
D = M
@LCL
M = D
@Main.fibonacci
0;JMP
(returnMain.fibonacci)
//instruction: labelWHILE
(Sys$WHILE)
//instruction: gotoWHILE//loopsinfinitely
@Sys$WHILE
0;JMP
//instruction: functionMain.fibonacci0
(Main.fibonacci)
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
//instruction: lt//checksifn<2
@SP
M = M - 1
@SP
A = M
D = M
@digit18
M = D
@SP
M = M - 1
@SP
A = M
D = M
@digit28
M = D
@digit28
D = M
@digit18
M = D - M
@digit18
D = M
@True8
D;JLT
@digit18
M = 0
D = M
@SP
A = M
M = D
@END8
0;JMP
(True8)
@digit18
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
//instruction: if-gotoIF_TRUE
@SP
M = M - 1
@SP
A = M
D = M
@Main$IF_TRUE
D;JGT
//instruction: gotoIF_FALSE
@Main$IF_FALSE
0;JMP
//instruction: labelIF_TRUE//ifn<2,returnn
(Main$IF_TRUE)
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
//instruction: return
@LCL
D = M
@FRAME
M=D
@FRAME
D = M
@new
M=D
@5
D = A
@new
M = M - D
@new
A = M
D = M
@ret
M = D
@SP
M = M - 1
@SP
A = M
D = M
@ARG
A=M
M=D
@ARG
M = M + 1
@ARG
D = M
@SP
M = D
@FRAME
D = M
@new
M=D
@1
D = A
@new
M = M - D
@new
A = M
D = M
@THAT
M = D
@FRAME
D = M
@new
M=D
@2
D = A
@new
M = M - D
@new
A = M
D = M
@THIS
M = D
@FRAME
D = M
@new
M=D
@3
D = A
@new
M = M - D
@new
A = M
D = M
@ARG
M = D
@FRAME
D = M
@new
M=D
@4
D = A
@new
M = M - D
@new
A = M
D = M
@LCL
M = D
@ret
0;JMP
//instruction: labelIF_FALSE//ifn>=2,returnsfib(n-2)+fib(n-1)
(Main$IF_FALSE)
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
@digit117
M = D
@SP
M = M - 1
@SP
A = M
D = M
@digit217
M = D
@digit217
D = M
@digit117
M = D - M
@digit117
D = M
@SP
A = M
M = D
@SP
M = M + 1
//instruction: callMain.fibonacci1//computesfib(n-2)
@returnMain.fibonacci
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
D = M
@1
D = D - A
@5
D = D - A
@SP
D = M
@LCL
M = D
@Main.fibonacci
0;JMP
(returnMain.fibonacci)
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
@digit121
M = D
@SP
M = M - 1
@SP
A = M
D = M
@digit221
M = D
@digit221
D = M
@digit121
M = D - M
@digit121
D = M
@SP
A = M
M = D
@SP
M = M + 1
//instruction: callMain.fibonacci1//computesfib(n-1)
@returnMain.fibonacci
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
D = M
@1
D = D - A
@5
D = D - A
@SP
D = M
@LCL
M = D
@Main.fibonacci
0;JMP
(returnMain.fibonacci)
//instruction: add//returnsfib(n-1)+fib(n-2)
@SP
M = M - 1
@SP
A = M
D = M
@digit123
M = D
@SP
M = M - 1
@SP
A = M
D = M
@digit223
M = D
@digit223
D = M
@digit123
M = D + M
@digit123
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
M=D
@FRAME
D = M
@new
M=D
@5
D = A
@new
M = M - D
@new
A = M
D = M
@ret
M = D
@SP
M = M - 1
@SP
A = M
D = M
@ARG
A=M
M=D
@ARG
M = M + 1
@ARG
D = M
@SP
M = D
@FRAME
D = M
@new
M=D
@1
D = A
@new
M = M - D
@new
A = M
D = M
@THAT
M = D
@FRAME
D = M
@new
M=D
@2
D = A
@new
M = M - D
@new
A = M
D = M
@THIS
M = D
@FRAME
D = M
@new
M=D
@3
D = A
@new
M = M - D
@new
A = M
D = M
@ARG
M = D
@FRAME
D = M
@new
M=D
@4
D = A
@new
M = M - D
@new
A = M
D = M
@LCL
M = D
@ret
0;JMP
