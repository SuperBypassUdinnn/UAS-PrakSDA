#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 8
// 8! = 40320, jumlah maksimum permutasi
#define FAKTORIAL_8 40320  

typedef struct {
    int data[MAX_N];
    int langkah;
} State;

// Fungsi untuk mengecek apakah array sudah terurut
int sudahUrut(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i-1] > arr[i]) return 0;
    }
    return 1;
}

// Fungsi untuk copy array
void salin(int* dest, int* src, int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

// Fungsi untuk membalik sebagian array
void balik(int* arr, int posisi, int k) {
    for (int i = 0; i < k/2; i++) {
        int temp = arr[posisi + i];
        arr[posisi + i] = arr[posisi + k - 1 - i];
        arr[posisi + k - 1 - i] = temp;
    }
}

// Fungsi hash array untuk dipakai sebagai key (unik untuk tiap permutasi)
int hash(int* arr, int n) {
    int i, j, h = 0, used[MAX_N] = {0};
    for (i = 0; i < n; i++) {
        int kecil = 0;
        for (j = 0; j < arr[i] - 1; j++) {
            if (!used[j]) kecil++;
        }
        h = h * (n - i) + kecil;
        used[arr[i] - 1] = 1;
    }
    return h;
}

// Queue untuk BFS
State queue[FAKTORIAL_8];
int depan = 0, belakang = 0;

void enqueue(State s) {
    queue[belakang++] = s;
}

State dequeue() {
    return queue[depan++];
}

int kosong() {
    return depan == belakang;
}

int main() {
    int N, K;
    int awal[MAX_N];

    printf("Masukkan nilai N (jumlah elemen dalam permutasi): ");
    scanf("%d", &N);

    printf("Masukkan %d angka (permutasi dari 1 sampai %d): ", N, N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &awal[i]);
    }

    printf("Masukkan nilai K (jumlah elemen yang dibalik dalam satu langkah): ");
    scanf("%d", &K);

    // Array untuk menandai state yang sudah pernah dikunjungi
    char visited[FAKTORIAL_8] = {0};

    // Inisialisasi BFS
    State start;
    salin(start.data, awal, N);
    start.langkah = 0;

    enqueue(start);
    visited[hash(start.data, N)] = 1;

    while (!kosong()) {
        State now = dequeue();

        if (sudahUrut(now.data, N)) {
            printf("%d\n", now.langkah);
            return 0;
        }

        for (int i = 0; i <= N - K; i++) {
            State next;
            salin(next.data, now.data, N);
            balik(next.data, i, K);
            next.langkah = now.langkah + 1;

            int h = hash(next.data, N);
            if (!visited[h]) {
                visited[h] = 1;
                enqueue(next);
            }
        }
    }

    // Kalau tidak bisa diurutkan
    printf("-1\n");
    return 0;
}
