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
