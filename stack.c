#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

struct Stack {
    node *top;
    int count;
};
typedef struct Stack Stack;

//stack kosong
void initStack(Stack *stack) {
	stack->top = NULL;
	stack->count = 0;
}

bool push(Stack *stack, int value) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        printf("Alokasi memori gagal\n");
        return false;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
    return true;
}

bool pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack kosong\n");
        return false;
    }
    node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->count--;
    return true;
}

bool stackTop(Stack *stack, int *topValue) {
    if (stack->top == NULL) {
    	system("cls");
        printf("Stack kosong\n\n");
        return false;
    }
    *topValue = stack->top->data;
    return true;
}

bool isEmpty(Stack *stack) {
    return stack->top == NULL;
}

bool isFull() {
    node *temp = (node *)malloc(sizeof(node));
    if (temp) {
        free(temp);
        return false;
    }
    return true;
}

int stackCount(Stack *stack) {
    return stack->count;
}

void destroyStack(Stack *stack) {
    node *temp;
    while (stack->top != NULL) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->count = 0;
    system("cls");
    printf("Stack berhasil dihancurkan\n\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    int pilihan, value;

    do {
        printf("======Menu Operasi Stack======\n");
        printf("1. Push Stack\n");
        printf("2. Pop Stack\n");
        printf("3. Stack Top\n");
        printf("4. Empty Stack\n");
        printf("5. Full Stack\n");
        printf("6. Stack Count\n");
        printf("7. Destroy Stack\n");
        printf("0. Keluar\n");
        printf("\nPilih operasi : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
            	system("cls");
                printf("Masukkan nilai yang akan di-push: ");
                scanf("%d", &value);
                if (push(&stack, value)) {
                    printf("Nilai %d berhasil ditambahkan ke stack\n\n", value);
                }
                break;

            case 2:
                if (pop(&stack)) {
                	system("cls");
                    printf("Nilai teratas berhasil di-pop dari stack\n\n");
                }
                break;

            case 3:
                if (stackTop(&stack, &value)) {
                	system("cls");
                    printf("Nilai teratas stack adalah: %d\n\n", value);
                }
                break;

            case 4:
                if (isEmpty(&stack)) {
                	system("cls");
                    printf("Stack kosong\n\n");
                } else {
                	system("cls");
                    printf("Stack tidak kosong\n\n");
                }
                break;

            case 5:
                if (isFull()) {
                	system("cls");
                    printf("Stack penuh\n\n");
                } else {
                	system("cls");
                    printf("Stack tidak penuh\n\n");
                }
                break;

            case 6:
            	system("cls");
                printf("Jumlah elemen di stack: %d\n\n", stackCount(&stack));
                break;

            case 7:
                destroyStack(&stack);
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}
