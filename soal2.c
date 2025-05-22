#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;     //pointer ke elemen array
    int size;     //jumlah elemen di array 
}array;

array *groupArray = NULL;  //array dinamis dari semua group
int *outputArray = NULL;   //array untuk meyimpan output
int groupCount = 0;        //jumlah group yang ada
int outputCount = 0;       //jumlah output yang disimpan

//deklarasi fungsi
void new();
void add(int l, int x, int y);
void out(int l, int z);

int main() {
    int Q; //total command yang akan diterima
    do {
        printf("Masukkan jumlah command (1-1000): ");
        scanf("%d", &Q);
        if (Q < 1 || Q > 1000) {
            printf("Jumlah command harus antara 1 dan 1000.\n");
        }
    } while (Q < 1 || Q > 1000);
    
    
    new(); // buat group array kosong pertama
    
    printf("Masukkan %d command\n", Q);
    char command[10];
    for (int i=0; i<Q; i++){
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            int l, x, y;
            scanf("%d %d %d", &l, &x, &y);

            if (x < 1 || x > 10000 || y < 1 || y > 10000) {
                printf("Nilai x dan y harus dalam rentang 1 hingga 10000.\n");
                i--; 
                continue;
            }

            add(l, x, y);
        }
        else if (strcmp(command, "new") == 0) {  
            new();
        } 
        else if (strcmp(command, "out") == 0) {  
            int l, z;
            scanf("%d %d", &l, &z);
            out(l, z);
        }
        else{
            printf("Input tidak valid.\n");
            i--;
            continue;
        }
    }

    //cetak output
    for (int i = 0; i < outputCount; i++) {
    printf("%d\n", outputArray[i]);
    }
 
    //membersihkan memori outputarray
    free(outputArray);
    
    //membersihkan memori grouparray
    for (int i = 0; i < groupCount; i++) {
        free(groupArray[i].data);
    }
    free(groupArray);

    return 0;
}

//fungsi untuk menambahkan group array baru
void new(){
    groupArray = realloc(groupArray, (groupCount + 1) * sizeof(array));
    groupArray[groupCount].data = NULL;
    groupArray[groupCount].size = 0;
    groupCount++;
}

//fungsi untuk menambahkan elemen ke array yang sudah ditambah
void add(int l, int x, int y) {
    int i = l - 1; 
    //mengecek group ada atau tidak
    if (i >= groupCount || i < 0) {
        printf("Group %d tidak ditemukan.\n", l);
        return;
    }
    
    groupArray[i].data = realloc(groupArray[i].data, (groupArray[i].size + y) * sizeof(int));
    for (int j = 0; j < y; j++) {
        groupArray[i].data[groupArray[i].size + j] = x;
    }
    groupArray[i].size += y;
}

//fungsi untuk menyimpan nilai yang akan diprint
void out(int l, int z) {
    int i = l - 1;
    //mengecek group ada atau tidak
    if (i >= groupCount || i < 0) {
        printf("Group %d tidak ditemukan.\n", l);
        return;
    }

    //cek indeks
    if (i >= groupCount || i < 0 || z < 1 || z > groupArray[i].size) {
        printf("Index tidak valid.\n");
        return;
    }

    outputArray = realloc(outputArray, (outputCount + 1) * sizeof(int));
    outputArray[outputCount] = groupArray[i].data[z - 1];
    outputCount++;
}