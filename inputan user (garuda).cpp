#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return '\0'; 
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

bool isValidBrackets(const char *code) {
    Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(code); i++) {
        char c = code[i];

        if (c == '(' || c == '[' || c == '{' || c == '<') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), c)) {
                return false; 
            }
        }
    }

    return isEmpty(&s);
}

int main() {
    char code[MAX];

    printf("Masukkan kode untuk diuji: ");
    scanf("%s", code);

    if (isValidBrackets(code)) {
        printf("Kode valid.\n");
    } else {
        printf("Kode tidak valid.\n");
    }

    return 0;
}
