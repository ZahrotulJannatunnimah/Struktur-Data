#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(capacity * sizeof(char));
    return stack;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char ch) {
    stack->data[++stack->top] = ch;
}

char pop(Stack *stack) {
    return isEmpty(stack) ? '\0' : stack->data[stack->top--];
}

char peek(Stack *stack) {
    return isEmpty(stack) ? '\0' : stack->data[stack->top];
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']') ||
           (open == '<' && close == '>');
}

bool isValidBrackets(const char *code) {
    int length = strlen(code);
    Stack *stack = createStack(length);
    for (int i = 0; i < length; i++) {
        char ch = code[i];
        if (ch == '(' || ch == '{' || ch == '[' || ch == '<') {
            push(stack, ch); 
        } else if (ch == ')' || ch == '}' || ch == ']' || ch == '>') {
            if (isEmpty(stack) || !isMatchingPair(pop(stack), ch)) {
                free(stack->data);
                free(stack);
                return false; 
            }
        }
    }
    bool isValid = isEmpty(stack); 
    free(stack->data);
    free(stack);
    return isValid;
}

int main() {
    const char *testCases[] = {
        " Object obj (in inputParams, out outParams){<Blob> myInf = new Blob(function(){data : [{type: image,size: 100,bg: transparent)]})run process_img(){this.myInf.blobToImage({type: jpg})}}",
        "Object obj (in inputParams, out outParams){<Blob> myInf = new Blob(function(){data : [{type: image,size: 100,bg: transparent}]})run process_img(){this.myInf.blobToImage({type: jpg})}}"
    };
    int numCases = sizeof(testCases) / sizeof(testCases[0]);

    printf("Hasil validasi :\n");
    for (int i = 0; i < numCases; i++) {
        printf("Kode: %-10s -> %s\n", testCases[i],
               isValidBrackets(testCases[i]) ? "Valid\n" : "Tidak valid\n");
    }

    return 0;
}
