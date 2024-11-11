#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initialize(Stack *s) {
    s->top = NULL;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed. Cannot push %d\n", item);
        return;
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
    printf("Pushed %d onto the stack.\n", item);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        Node *temp = s->top;
        printf("Popped %d from the stack.\n", temp->data);
        s->top = s->top->next;
        free(temp);
    }
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
    } else {
        printf("Top item is %d.\n", s->top->data);
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        Node *current = s->top;
        printf("Stack contents:\n");
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

int main() {
    Stack s;
    initialize(&s);
    int choice, item;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the item to push: ");
            scanf("%d", &item);
            push(&s, item);
        } else if (choice == 2) {
            pop(&s);
        } else if (choice == 3) {
            peek(&s);
        } else if (choice == 4) {
            display(&s);
        } else if (choice == 5) {
            printf("Exiting the program.\n");
            exit(0);
        } else {
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
        }
    }

    return 0;
}

