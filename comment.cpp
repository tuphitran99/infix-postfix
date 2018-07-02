/*
   Tu Tran
   Programming II
   Due: July 2, 18
   Infix-Posfix
   Read math formula from file -> Print out infix-postfix
 */

//Read in 1 line into a string
//Print the string
//while there are characters left to process in the string
//   -----
//  | get a token (skip over blanks)
//  | if the token is a digit then output(token)
//  | else
//  |    -----
//  |   | if the token is '(' then push(token)
//  |   | else
//  |   |    -----
//  |   |   | if the token is ')' then
//  |   |   |    -----
//  |   |   |   | while the top item is not '('
//  |   |   |   |    pop(temp) and output(temp);
//  |   |   |   | pop(temp)
//  |   |   |    -----
//  |   |   | else
//  |   |   |    -----
//  |   |   |   |  if the stack is empty then push(token)
//  |   |   |   |  else
//  |   |   |   |     -----
//  |   |   |   |    | while the stack is not empty
//  |   |   |   |    | and the priority (token) <= priority (top item on the stack)
//  |   |   |   |    |     pop(temp) and output(temp)
//  |   |   |   |    | push(token)
//  |   |   |   |     -----
//  |   |   |    -----
//  |   |    ----
//  |   -----
//   -----
//while the stack is not empty do pop(temp) and output(temp)



//Precedence of the Operators:

//  operators : ^ * / + - (
//  precedence: 3 2 2 1 1 0
