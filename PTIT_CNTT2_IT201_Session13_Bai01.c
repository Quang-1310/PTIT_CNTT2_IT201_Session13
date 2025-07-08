#include <stdio.h>
#define MAX 5
typedef  struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s -> top = -1;
}

int main() {
    Stack s;
    initStack((&s));
    return 0;
}