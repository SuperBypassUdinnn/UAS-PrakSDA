#include <stdio.h>

int main() {
    int Q;
    printf("Masukkan jumlah command: ");
    scanf("%d", &Q);
    
    new();
    
    char command[10];
    for (int i; i<=Q; i++){
        scanf("%s", command);
        
        // if (command == 'add') {  
        //     int l, x, y;
        //     scanf("%d %d %d", &l, &x, &y);
        //     add(l, x, y);
        // } 
        // else if (command == 'new') {  
        //     new();
        // } 
        // else if (command == 'out') {  
        //     int l, z;
        //     scanf("%d %d", &l, &z);
        //     out(l, z);
        // }
    }
    
    return 0;
}