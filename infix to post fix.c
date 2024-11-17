#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return -1;
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void infixToPostfix(char *exp) {
    char *e = exp;
    char x;
    
    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c ", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c ", x);
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) {
                printf("%c ", pop());
            }
            push(*e);
        }
        e++;
    }
    
    while (top != -1) {
        printf("%c ", pop());
    }
}

int main() {
    char exp[MAX];
    printf("Masukkan ekspresi infix: ");
    scanf("%s", exp);
    printf("Ekspresi Postfix: ");
    infixToPostfix(exp);
    printf("\n");
    return 0;
}
