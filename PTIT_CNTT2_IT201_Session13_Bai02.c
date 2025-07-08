#include <stdio.h>
#define MAX 5

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

    return 0;
}