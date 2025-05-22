#include <stdio.h>

int main() {
    int T;
    int count = 0;

    //Menginput panjang array
    printf("Masukkan input :\n");
    scanf("%d", &T);        // inputan pertama untuk menentukan jumlah baris berikutnya 
    
    if(T < 1 || T > 1000) //batasan
    {
        printf("Input tidak valid\n1 <= bilangan yang diinput <= 1000");
        return 1;
    }
    //deklarasi array N untuk simpan bil.n
    int N[T];
    
    for(int i = 0; i < T; i++){ //menerima dan memasukkan setiap nilai n ke array N
        scanf("%d", &N[i]); 
        if(N[i] < 1 || N[i] > 1000) 
        {
            printf("Input tidak valid\n1 <= bilangan yang diinput <= 1000");
            return 1;
        }
    } 
    
    printf("\noutput :\n");

    //uji setiap nilai n yang ada di dalam array N
    for (int j = 0; j < T ; j++) {  

        for (int i = 1 ; i <= N[j]; i++) { //untuk menghitung banyak faktor dari N[j]
            if(N[j] % i == 0 ) { //jika nilai N[j] habis dibagi i --> (1 <= i <= n)
            count++; //count tambah 1
            } 
            if (N[j] == 1) { //jika nilai N[j] adalah 1 , count tambah 1
            count++; }
        }

        if ( count >= 2 && count <= 4) { // jika jumlah faktornya (count) diantara 2-4, cetak 'YA' 
        printf ("YA\n", count);
        } else {
        printf ("BUKAN\n", count);    
        }
    count = 0; //reset lagi count jadi = 0
    }
}
