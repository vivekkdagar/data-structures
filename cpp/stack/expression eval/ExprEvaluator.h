//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_EXPREVALUATOR_H
#define CPP_EXPREVALUATOR_H


#include <string>
#include <stack>

class ExprEvaluator {
private:
    std::string infix;   // The infix expression to be evaluated
    std::string postfix; // The postfix expression after conversion

    // Private utility functions for expression evaluation
    static bool isOperator(char c);                   // Check if a character is an operator
    static bool isMatchingPair(char opening, char closing); // Check if a pair of parentheses, brackets, or braces match
    static int inStackPrecedence(char op);           // Determine precedence of an operator inside the stack
    static int outStackPrecedence(char op);          // Determine precedence of an operator outside the stack
    static int applyOperator(int operand1, int operand2, char op); // Apply an operator to two operands
    void infixToPostfix();                           // Convert infix expression to postfix
    bool isBalancedExpression();                     // Check if the parentheses, brackets, and braces in the expression are balanced
    int evaluatePostfix();                           // Evaluate the postfix expression

public:
    explicit ExprEvaluator(std::string infix);

    int evaluate();
};


#endif //CPP_EXPREVALUATOR_H
