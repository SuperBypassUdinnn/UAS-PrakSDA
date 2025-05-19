#include <stdio.h>

int main()
{
    int n;
    printf("Masukkan banyak bebek (1-100000): ");
    scanf("%d", &n);

    if (n < 1 || n > 100000)
    {
        printf("Input tidak valid, keluar program...\n");
        return 1;
    }
    
    int tinggiBebek[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Masukkan tinggi bebek ke-%d (1-100000): ", i);
        scanf("%d", &tinggiBebek[i]);

        if (tinggiBebek[i] < 1 || tinggiBebek[i] > 100000)
        {
            printf("Input tidak valid, keluar program...\n");
            return 1;
        }

    }

    return 0;
}