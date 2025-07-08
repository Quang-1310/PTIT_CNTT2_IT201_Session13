#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef  struct {
    Node* top;
} Stack;

void initStack(Stack *s) {
    s -> top = NULL;
}

void push(Stack *s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = s->top;
    s->top = newNode;
}

void printStack(Stack* s) {
    Node* current = s->top;
    while (current != NULL) {
        printf("%d ", current -> data);
        current = current -> next;
    }
}

int main() {
    Stack s;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    printStack(&s);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;      // Mảng động chứa phần tử stack
    int top;       // Vị trí đỉnh stack
    int cap;       // Dung lượng tối đa
} Stack;

// Hàm khởi tạo stack
Stack* createStack(int capacity) {
    Stack stack = (Stack) malloc(sizeof(Stack));
    if (!stack) {
        printf("Không cấp phát được bộ nhớ cho stack\n");
        exit(1);
    }

    stack->cap = capacity;
    stack->top = -1;
    stack->arr = (int*) malloc(capacity * sizeof(int));
    if (!stack->arr) {
        printf("Không cấp phát được bộ nhớ cho mảng\n");
        exit(1);
    }

    return stack;
}

// Hàm kiểm tra stack có đầy không
int isFull(Stack *stack) {
    return stack->top == stack->cap - 1;
}

// Hàm kiểm tra stack có rỗng không
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Hàm thêm phần tử vào stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack đầy!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Hàm lấy phần tử ra khỏi stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rỗng!\n");
        return -1; // hoặc exit(1);
    }
    return stack->arr[stack->top--];
}

// Hàm xem phần tử đỉnh mà không lấy ra
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rỗng!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Giải phóng bộ nhớ
void freeStack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

// Ví dụ sử dụng
int main() {
    Stack *s = createStack(5);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Đỉnh stack: %d\n", peek(s));

    printf("Pop: %d\n", pop(s));
    printf("Pop: %d\n", pop(s));

    freeStack(s);

    return 0;
}
