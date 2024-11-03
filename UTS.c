#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 20

typedef struct Node {
    char name[50];
    char gender; 
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
int count = 0;

// Fungsi untuk membuat node baru
Node* createNode(char name[], char gender) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->gender = gender;
    newNode->next = newNode->prev = newNode; 
    return newNode;
}


void addNode(char name[], char gender) {
    if (count >= MAX_DATA) {
        printf("Data sudah penuh!\n");
        return;
    }

 
    if (strcmp(name, "Cindy") == 0) {
        Node* temp = head;
        int hasFemale = 0;
        
     
        if (head != NULL) {
            do {
                if (temp->gender == 'P') {
                    hasFemale = 1;
                    break;
                }
                temp = temp->next;
            } while (temp != head);
        }

        if (!hasFemale) {
            printf("Tidak ada perempuan dalam list, Cindy tidak bisa ditambahkan!\n");
            return;
        }
    }

    // Menambahkan node biasa
    Node* newNode = createNode(name, gender);
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    count++;
}


void addIrsyadArsyad() {
    if (count + 2 > MAX_DATA) {
        printf("Tidak cukup ruang untuk menambah Irsyad dan Arsyad!\n");
        return;
    }
    
   
    addNode("Irsyad", 'L');
    addNode("Arsyad", 'L');
}


void deleteNode(char name[]) {
    if (head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus!\n");
        return;
    }

    Node* temp = head;
    Node* toDelete = NULL;
    do {
        if (strcmp(temp->name, name) == 0) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (toDelete == NULL) {
        printf("Nama %s tidak ditemukan di list!\n", name);
        return;
    }
    if (strcmp(toDelete->name, "Irsyad") == 0 || strcmp(toDelete->name, "Arsyad") == 0) {
        printf("Irsyad dan Arsyad tidak bisa dipisahkan!\n");
        return;
    }

    if (toDelete == head && head->next == head) {
        head = NULL;
    } else {
        if (toDelete == head) {
            head = head->next;
        }
        Node* prevNode = toDelete->prev;
        Node* nextNode = toDelete->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    free(toDelete);
    count--;
    printf("Nama %s telah dihapus.\n", name);
}


void displayByGender(char gender) {
	system("cls");
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    Node* temp = head;
    int found = 0;

    printf("Daftar Mahasiswa dengan gender %c:\n", gender);
    do {
        if (temp->gender == gender) {
            printf("%s (%c) -> ", temp->name, temp->gender);
            found = 1;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found) {
        printf("Tidak ada mahasiswa dengan gender %c.\n", gender);
    }
    printf("NULL\n");
    getch();
}


void displayAll() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    Node* temp = head;
    printf("Daftar Semua Mahasiswa:\n");
    do {
        printf("%s (%c) -> ", temp->name, temp->gender);
        temp = temp->next;
    } while (temp != head);
    printf("NULL\n");
}


void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah mahasiswa/mahasiswi\n");
        printf("2. Tambah Irsyad dan Arsyad\n");
        printf("3. Hapus mahasiswa\n");
        printf("4. Tampilkan mahasiswa laki-laki\n");
        printf("5. Tampilkan mahasiswi perempuan\n");
        printf("6. Tampilkan semua mahasiswa\n");
        printf("7. Keluar\n");
        printf("\nPilih opsi: ");
        scanf("%d", &choice);

        char name[50], gender;
        switch (choice) {
            case 1:
                if (count >= MAX_DATA) {
                    printf("Data sudah penuh!\n");
                } else {
                    printf("Masukkan nama: ");
                    scanf("%s", name);
                    printf("Masukkan gender (L/P): ");
                    scanf(" %c", &gender);
                    addNode(name, gender); 
                } 
                break;
            case 2:
                addIrsyadArsyad(); 
                break;
            case 3:
            	system("cls");
                printf("Masukkan nama yang ingin dihapus: ");
                scanf("%s", name);
                deleteNode(name);
                getch();
                break;
            case 4:
                displayByGender('L');
                break;
            case 5:
                displayByGender('P');
                break;
            case 6:
                displayAll();
                break;
            case 7:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}
