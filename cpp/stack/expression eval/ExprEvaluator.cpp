//
// Created by vivekdagar on 03/05/24.
//

#include "ExprEvaluator.h"
#include <cmath>
#include <utility>
#include <cstdint>

bool ExprEvaluator::isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool ExprEvaluator::isBalancedExpression() {
    std::stack<char> stk;

    for (char bracket: this->infix) {
        if (bracket == '(' or bracket == '[' or bracket == '{') {
            stk.push(bracket);
        } else if (bracket == ')' or bracket == ']' or bracket == '}') {
            if (stk.empty() or not isMatchingPair(stk.top(), bracket))
                return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int ExprEvaluator::inStackPrecedence(char op) {
    if (op == '^')
        return 4;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0; // Parentheses
}

int ExprEvaluator::outStackPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

void ExprEvaluator::infixToPostfix() {
    std::stack<char> opStack;

    for (char c: infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Pop '('
        } else {
            while (!opStack.empty() && outStackPrecedence(c) <= inStackPrecedence(opStack.top())) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }
}

bool ExprEvaluator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int ExprEvaluator::applyOperator(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return static_cast<int>(pow(operand1, operand2));
        default:
            return 0; // Invalid operator
    }
}

int ExprEvaluator::evaluatePostfix() {
    std::stack<int> operandStack;

    for (char c: postfix) {
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else if (isOperator(c)) {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = applyOperator(operand1, operand2, c);
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int ExprEvaluator::evaluate() {
    if (not this->isBalancedExpression())
        return INT32_MIN;

    this->infixToPostfix();

    return evaluatePostfix();
}

ExprEvaluator::ExprEvaluator(std::string infix) : infix(std::move(infix)) {}