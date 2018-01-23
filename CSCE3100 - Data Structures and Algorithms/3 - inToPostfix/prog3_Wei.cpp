/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 3110
Instructor: Robert Renka
Date: 10/3/17



                        CSCE 3110  Program 3


        Due date:  Tuesday, 10/17/2017


        Write a program in which the driver simply calls a function
        named inToPostfix which reads an infix expression from
        standard input and writes the equivalent postfix expression
        to standard output.  The infix expression includes operands,
        parentheses, and operators, where the operands are single
        lowercase characters, and the operators are +, -, *, /, and
        ^ (exponentiation).

        Include error checks in the code.


        Your program should be implemented in a single file named
        prog3_Name.cpp, where Name is your last name, and submitted
        via Blackboard.


*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int order(char a) {

  switch(a) {
    case '(':
    case ')':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return  3;
    case '^':
      return  4;
  }
  return 0;
}
void inToPostfix() {
  cout << "Please enter an infix expression: \n";
  string infix_str;
  getline(cin, infix_str);

  stack<char> stack;
  string postfix = "";

  for(char op : infix_str) {
    if(isspace(op)) { continue; }
    if(isalpha(op)) {
      postfix += op;
    } else {
      if(op == '(') {
        stack.push(op);
      }
      else if(op == ')') {
        while(!stack.empty()) {
          char paren_op = stack.top();
          stack.pop();
          if(paren_op == '(') {
            break;
          }
          postfix += paren_op;
        }
      } else if(order(op)) {
        // pop all expressions with order equal or above operator first until we reach an expression that is lower
        while(!stack.empty() && order(stack.top()) >= order(op)) {

          // exponents are evaluated from right to left!
          if(stack.top() == '^' && op == '^') {
            break;
          }
          postfix += stack.top();
          stack.pop();
        }
        stack.push(op);
      }
      else {
        cout << op << " is not an operator (+, -, *, /, ^) nor an operand (a single lowercase character)!";
        return;
      }
    }
  }

  // Empty the stack if there are no more values in the infix expression
  while(!stack.empty()) {
    postfix += stack.top();
    stack.pop();
  }

  // print postfix expression
  for(char x : postfix) {
    cout << x << " ";
  }
}

int main() {
  inToPostfix();
  return 0;
}
