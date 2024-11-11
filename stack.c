#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void initialize() {
    top = -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack is full. Cannot push %d\n", item);
    } else {
        stack[++top] = item;
        printf("Pushed %d onto the stack.\n", item);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        int item = stack[top];
        top--;
        printf("Popped %d from the stack.\n", item);
        return item;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void clearConsole() {
    printf("\e[1;1H\e[2J");
}

void menu() {
    int choice, item;

    initialize();

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Clear Console\n");
        printf("6. Exit\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the item to push: ");
            scanf("%d", &item);
            push(item);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            printf("Top item is %d.\n", peek());
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            clearConsole();
        } else if (choice == 6) {
            printf("Exiting the program.\n");
            exit(0);
        } else {
            printf("Invalid choice. Please choose a number between 1 and 6.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
