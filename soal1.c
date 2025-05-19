#include <stdio.h>

int main()
{
    int n; // jumlah bebek
    // Input jumlah bebek
    printf("Masukkan banyak bebek (1-100000): ");
    if (!scanf("%d", &n))
    {
        printf("Input tidak valid, keluar program...\n");
        return 1;
    }

    // Membatasi nilai input
    if (n < 1 || n > 100000)
    {
        printf("Angka di luar interval, keluar program...\n");
        return 1;
    }
    
    int h[n]; // tinggi bebek
    int a[n]; // banyak bebek yang bisa diintip
    
    for (int i = 0; i < n; i++)
    {
        // Input masing2 tinggi bebek
        printf("Masukkan tinggi bebek ke-%d (1-100000): ", i + 1);
        if (!scanf("%d", &h[i]))
        {
            printf("Input tidak valid, keluar program...\n");
            return 1;
        }

        if (h[i] < 1 || h[i] > 100000)
        {
            printf("Angka di luar interval, keluar program...\n");
            return 1;
        }

        // Menghitung banyak bebek yang bisa diintip masing2 bebek
        a[i] = 1; // masing2 bebek bisa mengintip diri sendiri
        for (int j = i - 1; j >= 0; j--)
        {
            if (h[j] <= h[i]) a[i]++;
            else break;
        }
        printf("%d\n", a[i]);
    }

    // Menjumlahkan nilai bebek yang bisa diintip
    int jumlah_a = 0;
    for (int i = 0; i < n; i++)
        jumlah_a += a[i];

    printf("Total banyak bebek yang bisa diintip: %d\n", jumlah_a);

    return 0;
}