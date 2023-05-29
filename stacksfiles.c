
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the stack structure
struct stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int is_empty(struct stack* s) {
    return s->top == -1;
}

// Check if the stack is full
int is_full(struct stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Push an item onto the stack
void push(struct stack* s, int item,FILE *fp) {
    if (is_full(s))
    {
        printf("Error: Stack overflow\n");
        return;
    }
    s->items[++s->top] = item;
    fp = fopen("num.txt", "a");
     if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }


    fprintf(fp, "%d ", item);
}

// Pop an item from the stack
int pop(struct stack* s) {
    if (is_empty(s))
    {
        printf("Error: Stack underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Peek at the top item of the stack
int peek(struct stack* s) {
    if (is_empty(s)) {
        printf("Error: Stack empty\n");
        return -1;
    }
    return s->items[s->top];
}

// Print the contents of the stack
void print_stack(struct stack* s) {
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct stack s;
    initialize(&s);

    int choice = 0;
    int item = 0;
     FILE *fp;

    while (1) {
        // Display menu
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push operation
                printf("Enter the value to be pushed: ");
                scanf("%d", &item);
                push(&s, item,fp);
                break;

            case 2:
                // Pop operation
                item = pop(&s);
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;

            case 3:
                // Display operation
                print_stack(&s);
                break;

            case 4:
                // Exit program
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


