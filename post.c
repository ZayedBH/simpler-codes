#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    char stack[100];
    int top = -1, i = 0, j = 0;

    while (infix[i]) {
        if (isdigit(infix[i])) {  // Operand
            while (isdigit(infix[i])) 
                postfix[j++] = infix[i++];
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {  // Left parenthesis
            stack[++top] = infix[i++];
        } else if (infix[i] == ')') {  // Right parenthesis
            while (top >= 0 && stack[top] != '(') 
                postfix[j++] = stack[top--];
            top--;  // Pop the '(' from the stack
            i++;
        } else {  // Operator
            while (top >= 0 && precedence(infix[i]) <= precedence(stack[top])) 
                postfix[j++] = stack[top--];
            stack[++top] = infix[i++];
        }
    }

    // Pop remaining operators from the stack
    while (top >= 0) 
        postfix[j++] = stack[top--];
    
    postfix[j] = '\0';  // Null-terminate the postfix string
}

// Function to evaluate a postfix expression
double evaluatePostfix(char postfix[]) {
    double stack[100];
    int top = -1, i = 0;

    while (postfix[i]) {
        if (isdigit(postfix[i])) {  // Operand
            double num = 0;
            while (isdigit(postfix[i])) 
                num = num * 10 + (postfix[i++] - '0');
            stack[++top] = num;
        } else if (postfix[i] != ' ') {  // Operator
            double b = stack[top--], a = stack[top--];
            if (postfix[i] == '+') 
                stack[++top] = a + b;
            else if (postfix[i] == '-') 
                stack[++top] = a - b;
            else if (postfix[i] == '*') 
                stack[++top] = a * b;
            else if (postfix[i] == '/') 
                stack[++top] = a / b;
            else if (postfix[i] == '^') 
                stack[++top] = pow(a, b);
        }
        i++;
    }

    return stack[top];  // Return the result from the stack
}

int main() {
    char infix[100], postfix[100];

    // Input the infix expression
    printf("Enter Infix: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    // Evaluate the postfix expression
    printf("Result: %lf\n", evaluatePostfix(postfix));

    return 0;
}
