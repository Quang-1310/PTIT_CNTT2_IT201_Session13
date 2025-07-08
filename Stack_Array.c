#include <stdio.h>
#define MAX 100

typedef  struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s -> top = -1;
}

int isFull(Stack* s) {
    return s -> top == MAX - 1;
}

void push(Stack* s, int x) {
    if (isFull(s)) {
        return;
    }
    s -> top += 1;
    s -> data[s -> top] = x;
}

int isEmpty(Stack* s) {
    return s -> top == -1;
}

int top(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s -> data[s -> top];
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s -> data[s -> top--];
}

void printStack(Stack* s) {
    for (int i = s -> top; i >= 0; i--) {
        printf("%d ", s -> data[i]);
    }
}

int main() {
    Stack s;
    initStack((&s));
    push(&s, 5);
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    printStack(&s);
    printf("\nPhan tu tren dinh %d", top(&s));
    printf("\n");
    pop(&s);
    printStack(&s);
    return 0;
}