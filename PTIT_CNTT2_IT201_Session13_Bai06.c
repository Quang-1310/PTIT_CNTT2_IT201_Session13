#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[100];
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

int compare(Stack* s, char arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        if (s -> data[i] != arr[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Stack s;
    initStack(&s);
    char arr[100];
    printf("Nhap 1 chuoi: ");
    fgets(arr, 100, stdin);
    arr[strcspn(arr, "\n")] = '\0';
    int length = strlen(arr);
    for (int i = length - 1; i >= length / 2; i--) {
        push(&s, arr[i]);
    }
    if (compare(&s, arr,length)) {
        printf("true");
    }
    else {
        printf("false");
    }
    return 0;
}