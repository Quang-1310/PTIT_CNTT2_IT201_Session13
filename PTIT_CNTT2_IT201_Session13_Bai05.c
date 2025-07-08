#include <stdio.h>
#define MAX 100

typedef struct {
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

void printStack(Stack* s) {
    for (int i = s -> top; i >= 0; i--) {
        printf("%d ", s -> data[i]);
    }
}

int main() {
    Stack s;
    initStack(&s);
    int arr[100];
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d", i + 1);
        scanf("%d", &arr[i]);
        push(&s, arr[i]);
    }
    printStack((&s));
    return 0;
}