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
    for (int i = 0; i < 5; i++) {
        int number;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &number);
        push(&s, number);
    }
    printStack(&s);
    printf("\n");
    printf("Phan tu duoc lay ra la: %d", pop(&s));
    printf("\n");
    printStack(&s);
    return 0;
}