#include <stdio.h>

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void convert(char infix[], char postfix[]) {
    char stack[100];
    int top = -1, i = 0, j = 0;

    while (infix[i]) {
        if (infix[i] >= 'A' && infix[i] <= 'Z')  // Operand
            postfix[j++] = infix[i];
        else if (infix[i] == '(')  // Left parenthesis
            stack[++top] = infix[i];
        else if (infix[i] == ')') {  // Right parenthesis
            while (top >= 0 && stack[top] != '(') 
            postfix[j++] = stack[top--];
            top--;
        } else {  // Operator
            while (top >= 0 && precedence(infix[i]) <= precedence(stack[top]) && stack[top] != '(')
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
        i++;
    }

    while (top >= 0)  // Pop remaining operators
        postfix[j++] = stack[top--];

    postfix[j] = '\0';  // Null-terminate the postfix string
}

int main() {
    char infix[100], postfix[100];
    scanf("%s", infix);
    convert(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}
