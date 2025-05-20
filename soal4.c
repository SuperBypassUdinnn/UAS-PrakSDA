#include <stdio.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int top = -1;

// Tambahkan X sebanyak Y kali
void add(int X, int Y) {
    for (int i = 0; i < Y; i++) {
        top++;
        stack[top] = X;
    }
}

// Hapus Y elemen dari atas dan tampilkan elemen terbawah yang dihapus
void del(int Y) {
    if (top - Y + 1 < 0) {
        printf("Gagal hapus %d elemen. Stack tidak cukup.\n", Y);
        return;
    }
    printf("Elemen terbawah dari yang dihapus: %d\n", stack[top - Y + 1]);
    top -= Y;
}

// Tambahkan X ke semua elemen
void adx(int X) {
    for (int i = 0; i <= top; i++) {
        stack[i] += X;
    }
}

// Kurangi X dari semua elemen
void dex(int X) {
    for (int i = 0; i <= top; i++) {
        stack[i] -= X;
    }
}

// Tampilkan isi stack
void printStack() {
    printf("Isi stack sekarang (bawah ke atas): ");
    if (top < 0) {
        printf("[kosong]");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main() {
    int Q;
    char cmd[4];
    int X, Y;

    // Intro
    printf("=== SELAMAT DATANG DI PROGRAM STACK INTERAKTIF ===\n");
    printf("Perintah yang bisa digunakan:\n");
    printf("  add X Y  Tambahkan angka X sebanyak Y kali ke stack\n");
    printf("  del Y    Hapus Y elemen dari atas, tampilkan elemen terbawah dari yang dihapus\n");
    printf("  adx X    Tambahkan X ke semua elemen di stack\n");
    printf("  dex X    Kurangi X dari semua elemen di stack\n");
    printf("----------------------------------------------------\n");

    // Minta jumlah perintah
    printf("Berapa banyak perintah yang ingin kamu jalankan? ");
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        printf("\n[%d/%d] Masukkan perintahmu (add/del/adx/dex): ", i + 1, Q);
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            printf("   Masukkan angka yang ingin ditambahkan: ");
            scanf("%d", &X);
            printf("   Ingin ditambahkan berapa kali? ");
            scanf("%d", &Y);
            add(X, Y);
        } else if (strcmp(cmd, "del") == 0) {
            printf("   Ingin menghapus berapa elemen dari atas? ");
            scanf("%d", &Y);
            del(Y);
        } else if (strcmp(cmd, "adx") == 0) {
            printf("   Ingin menambahkan berapa ke semua elemen? ");
            scanf("%d", &X);
            adx(X);
        } else if (strcmp(cmd, "dex") == 0) {
            printf("   Ingin mengurangi berapa dari semua elemen? ");
            scanf("%d", &X);
            dex(X);
        } else {
            printf("    Perintah tidak dikenali! Silakan coba lagi.\n");
            i--; // ulangi perintah ini
            continue;
        }

        printStack();
    }

    printf("\nSemua perintah selesai dijalankan. Terima kasih!\n");
    return 0;
}
