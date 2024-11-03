#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head, int key);
void hapusAkhir(node **head);
void cariData(node *head, int key);
void jumlahData(node *head);
void jumlahkanSemua(node *head);
void tranverse(node *head);

//========================================================

int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data awal\n");
        printf("2. Tambah data tengah\n");
        printf("3. Tambah data akhir\n");
        printf("4. Hapus data awal list\n");
        printf("5. Hapus data tengah list\n");
        printf("6. Hapus data akhir list\n");
        printf("7. Pencarian data dalam list\n");
        printf("8. Tampilkan informasi jumlah data\n");
        printf("9. Tampilkan hasil penjumlahan\n");
        printf("0. Cetak isi list\n");
        printf("\n\nMASUKKAN PILIHAN (tekan q untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);

        switch (pilih) {
            case '1': 
				tambahAwal(&head); 
				break;
            case '2': 
				tambahData(&head); 
				break;
            case '3': 
				tambahAkhir(&head); 
				break;
            case '4': 
				hapusAwal(&head); 
				break;
            case '5': {
                int key;
                system("cls");
                printf("Masukkan data yang ingin dihapus: ");
                scanf("%d", &key);
                hapusTengah(&head, key);
                break;
            }
            case '6': 
				hapusAkhir(&head); 
				break;
            case '7': {
                int key;
                system("cls");
                printf("Masukkan data yang ingin dicari: ");
                scanf("%d", &key);
                cariData(head, key);
                getch();
                break;
            }
            case '8': 
				jumlahData(head); 
				break;
            case '9': 
				jumlahkanSemua(head); 
				break;
            case '0': {
            	system("cls");
                tranverse(head);
                getch();
                break;
            }
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->left = NULL;
        pNew->right = *head;

        if (*head != NULL) {
            (*head)->left = pNew;  
        }
        *head = pNew;  
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    scanf("%d", &pos);
    printf("Bilangan: ");
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->right;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("\nAlokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->left = pCur;
        pNew->right = pCur->right;

        if (pCur->right != NULL) {
            pCur->right->left = pNew;  
        }
        pCur->right = pNew;
    }
}

//========================================================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->left = NULL;
        pNew->right = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->right != NULL) {
                pCur = pCur->right;
            }
            pCur->right = pNew;
            pNew->left = pCur;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head) {
    node *pDel;

    system("cls");
    if (*head != NULL) {
        pDel = *head;
        *head = (*head)->right;

        if (*head != NULL) {
            (*head)->left = NULL;
        }

        free(pDel);
        printf("Data awal berhasil dihapus\n");
    } else {
        printf("List kosong\n");
    }
    getch();
}

//========================================================

void hapusTengah(node **head, int key) {
    node *pCur = *head;

    while (pCur != NULL && pCur->data != key) {
        pCur = pCur->right;
    }

    system("cls");
    if (pCur == NULL) {
        printf("Data tidak ditemukan\n");
    } else {
        if (pCur->left != NULL) {
            pCur->left->right = pCur->right;
        } else {
            *head = pCur->right;
        }

        if (pCur->right != NULL) {
            pCur->right->left = pCur->left;
        }

        free(pCur);
        printf("Data berhasil dihapus\n");
    }
    getch();
}

//========================================================

void hapusAkhir(node **head) {
    node *pCur = *head;

    system("cls");
    if (*head == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    while (pCur->right != NULL) {
        pCur = pCur->right;
    }

    if (pCur->left != NULL) {
        pCur->left->right = NULL;
    } else {
        *head = NULL;
    }

    free(pCur);
    printf("Data di akhir berhasil dihapus\n");
    getch();
}

//========================================================

void cariData(node *head, int key) {
    node *pCur = head;
    int found = 0;

    while (pCur != NULL) {
        if (pCur->data == key) {
            printf("Data %d ditemukan\n", key);
            found = 1;
            break;
        }
        pCur = pCur->right;
    }

    if (!found) {
        printf("Data %d tidak ditemukan\n", key);
    }
}

//========================================================

void jumlahData(node *head) {
    int count = 0;
    node *pCur = head;

    system("cls");
    while (pCur != NULL) {
        count++;
        pCur = pCur->right;
    }

    printf("Jumlah data dalam list: %d\n", count);
    getch();
}

//========================================================

void jumlahkanSemua(node *head) {
    int sum = 0;
    node *pCur = head;

    system("cls");
    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->right;
    }

    printf("Hasil penjumlahan semua data: %d\n", sum);
    getch();
}

//========================================================

void tranverse(node *head) {
    node *pWalker = head;

    while (pWalker != NULL) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->right;
    }
    printf("NULL\n");
}
