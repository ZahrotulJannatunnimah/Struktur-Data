#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void enqueue(Node **front, Node **rear, int value);
void dequeue(Node **front, Node **rear);
void queueFront(Node *front);
void queueRear(Node *rear);
int isEmptyQueue(Node *front);
int queueCount(Node *front);
void listQueue(Node *front);
void destroyQueue(Node **front, Node **rear);

int main() {
    Node *front = NULL, *rear = NULL;
    int choice, value;

    do {
        printf("==========Menu Queue:==========\n");
        printf("\n1.  Enqueue (Tambah data)\n");
        printf("2.  Dequeue (Hapus data)\n");
        printf("3.  Queue Front (Queue paling depan)\n");
        printf("4.  Queue Rear (Queue paling belakang)\n");
        printf("5.  Empty Queue\n");
        printf("6.  Full Queue\n");
        printf("7.  Queue Count (Menghitung data)\n");
        printf("8.  List Queue (Urutan Queue)\n");
        printf("9.  Destroy Queue (Menghapus seluruh data)\n");
        printf("10. Exit\n");
        printf("\nPilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                printf("Masukkan nilai untuk enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                getch();
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                queueFront(front);
                break;
            case 4:
                queueRear(rear);
                break;
            case 5:
            	system("cls");
                if (isEmptyQueue(front)) {
                    printf("Antrian kosong.\n\n");
                } else {
                    printf("Antrian tidak kosong.\n\n");
                }
                getch();
                break;
            case 6:
            	system("cls");
                printf("Antrian tidak memiliki batasan penuh karena berbasis linked list.\n\n");
                getch();
                break;
            case 7:
            	system("cls");
                printf("Jumlah elemen dalam antrian: %d\n\n", queueCount(front));
                getch();
                break;
            case 8:
                listQueue(front);
                break;
            case 9:
            	system("cls");
                destroyQueue(&front, &rear);
                printf("Semua data dalam antrian telah dihapus.\n\n");
                getch();
                break;
            case 10:
                printf("Keluar dari program.\n");
                destroyQueue(&front, &rear);
                break;
            default:
            	system("cls");
                printf("Pilihan tidak valid.\n\n");
                getch();
        }
    } while (choice != 10);

    return 0;
}

void enqueue(Node **front, Node **rear, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori.\n\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }

    printf("Data %d berhasil ditambahkan ke antrian.\n\n", value);
}

void dequeue(Node **front, Node **rear) {
	system("cls");
    if (*front == NULL) {
        printf("Antrian kosong, tidak ada data untuk dihapus.\n\n");
        return;
    }

    Node *temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL; 
    }

    printf("Data %d berhasil dihapus dari antrian.\n\n", temp->data);
    free(temp);
    getch();
}

void queueFront(Node *front) {
	system("cls");
    if (front == NULL) {
        printf("Antrian kosong.\n\n");
    } else {
        printf("Data di depan antrian: %d\n\n", front->data);
    }
    getch();
}

void queueRear(Node *rear) {
	system("cls");
    if (rear == NULL) {
        printf("Antrian kosong.\n\n");
    } else {
        printf("Data di belakang antrian: %d\n\n", rear->data);
    }
    getch();
}

int isEmptyQueue(Node *front) {
    return front == NULL;
}

int queueCount(Node *front) {
    int count = 0;
    Node *temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void listQueue(Node *front) {
    system("cls");
    if (front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    printf("Isi antrian: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n\n");
    getch();
}

void destroyQueue(Node **front, Node **rear) {
    Node *temp;
    while (*front != NULL) {
        temp = *front;
        *front = (*front)->next;
        free(temp);
    }
    *rear = NULL;
}
