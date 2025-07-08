#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int x) {
    if (isFull(s)) return;
    s->data[++s->top] = x;
}

int pop(Stack* s) {
    if (isEmpty(s)) return 0;
    return s->data[s->top--];
}

int calculatePostfix(Stack* s , char arr[]) {
    for (int i = 0; i < strlen(arr); i++) {
        char ch = arr[i];
        if (isdigit(ch)) {
            push(s, ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = pop(s);
            int a = pop(s);
            int result;
            if (ch == '+') {
                result = a + b;
            }
            else if (ch == '-') {
                result = a - b;
            }
            else if (ch == '*') {
                result = a * b;
            }
            else if (ch == '/') {
                result = a / b;
            }
            push(s, result);
        }
    }
    return pop(s);
}

int main() {
    Stack s;
    initStack(&s);
    char arr[100];
    printf("Nhap bieu thuc postfix: ");
    fgets(arr, 100, stdin);
    arr[strcspn(arr, "\n")] = '\0';
    int result = calculatePostfix(&s, arr);
    printf("Ket qua la: %d\n", result);
    return 0;
}
