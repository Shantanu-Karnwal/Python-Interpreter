# Python-Interpreter

The interpreter is exactly like the python interpreter which takes as input an assignment statement or a print statement consisting of arithmetic expression (add, subtract, multiply and divide) and even integers.

The input is given in the form - 

statements  s ::=  x = e  |   print e  
expressions e ::=  x  |  n  |  e + e  |  e - e  |  e * e  | e / e
variables   x
integers    n
  
The first step in the process is to remove any whitespaces from the input string to make the computation easier.
Then we need to check whether the entered string is an assignment statement or a print statement. 
Also the program will work for any n-digit integer but the variable name should be a lower case single character.

If the string entered is an assignment statement, then the program computes the value on the right hand side of the equation by converting the expression into postfix form and then evaluating the postfix expression. If the expression contains a variable, the program replaces the variable by computing its integer value(since the variable's value would have been defined earlier in the program).
After evaluating the postfix expression on the right hand side, the program equates the value to the variable on the left hand side by making use of an array and the ASCII value of the variable - ASCII value of 'a' as the index of the array.


If the string entered is a print statement, then the program computes the value after the print keyword, in a similar way, by converting the expression into postfix form and then evaluating the postfix expression. If the expression contains a variable, the program replaces the variable by computing its integer value(since the variable's value would have been defined earlier in the program).
After evaluating the postfix expression after the print keyword, the program will simply print the value computed in the expression.

The program requires to enter a quit() or exit() to exit the interpreter.


# Assessment Exercise

To assess the student's mastery over the core concept behind the implementation.

The student should be asked some basic questions in the beginning like what are tokens and what is lexical analysis and also the stages of a compiler which convert the high level language code into an assembly language code. The student should also know the fundamental difference between a compiler and an interpreter.

With respect to this exercise, the student should be asked how they designed the interpreter to evaluate the expression phase. If they answer using the correct parsing method and convert to postfix before evaluating, and that reflects in the program as well, then it can be inferred that they have mastered the concept.

If the student could not tell about the correct parsing method used in the program and somehow completed the program but could not cover all kind of test cases, then it can be inferred that they have insufficient knowledge of the concept.

# Abstract Syntax Tree - Type Checker

For this program, I have assumed that my parser returns the following block after parsing the input. The block contains the following data types - 

1) A symbol of character data type - which can be any artihmetic, logical or branching operator - denoted by a single character. example- '+', '-', '*', '/', '>', '<', '!', etc.
2) A number of integer data type - and this can be either a decimal or a binary number
3) A boolean variable that checks whether the block contains a number(decimal or binary) or a character(operator).
4) A boolean variable that checks whether the block conatins a decimal number or a binary number, if the block conatains a number.

The program conatins functions for input and output of the tree.

The typecheck function returns an integer value with the following significance - 

Returns 0 - Type Mismatch - throw an exception
Returns 1 - Type Matches and is of an decimal number
Returns 2 - Type Matches and is of a binary number

First it checks whether the block is of a character(operator) or not. If it is, it checks what type. So if it is a binary operator like '+' or '>', it will do the corresponding subtree check and find out whether its both operands are integers for the '+' case, and integer or binary for the '>' case. If it mismatches, it will return 0 (i.e throw the exception).
If the operator is unary, like '!', it will just check the right subtree and check whether the value in the right subtree is a binary value or not. If it is binary, it returns 2 otherwise it returns 0.

If the block is of a number, it checks whether the number is decimal or binary. If the number is decimal, the function returns 1 and if binary, the function returns 2.
Hence in this way, the typechecker function clearly finds out the proper type of the expression given in the input in the form of abstract syntax tree.
