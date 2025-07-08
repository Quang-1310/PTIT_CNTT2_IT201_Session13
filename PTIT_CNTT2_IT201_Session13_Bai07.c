#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s -> top = -1;
}

int isFull(Stack* s) {
    return s -> top == MAX - 1;
}

void push(Stack* s, char x) {
    if (isFull(s)) {
        return;
    }
    s -> top += 1;
    s -> data[s -> top] = x;
}

char pop(Stack* s) {
    if (s -> top == -1) {
        return '\0';
    }
    return s -> data[s -> top--];
}

int isMathPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

int check(Stack* s, char arr[]) {
    for (int i = 0; i < strlen(arr); i++) {
        char c = arr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(s, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s->top == -1) {
                return 0;
            }
            char top = pop(s);
            if (!isMathPair(top, c)) {
                return 0;
            }
        }
    }
    return s -> top = -1;
}


int main() {
    Stack s;
    initStack(&s);
    char arr[100];
    printf("Nhap 1 chuoi: ");
    fgets(arr, 100, stdin);
    arr[strcspn(arr, "\n")] = '\0';
    if (check(&s, arr)) {
        printf("True");
    }
    else {
        printf("False");
    }
    return 0;
}