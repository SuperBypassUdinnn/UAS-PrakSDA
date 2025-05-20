#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;      
    int size;      
}array;

array *groupArray = NULL;  
int *outputArray = NULL;
int count = 0;  
int outputCount = 0; 

void new();
void add(int, int, int);
void out(int, int);

int main() {
    int Q;
    printf("Masukkan jumlah command: ");
    scanf("%d", &Q);
    
    new();
    
    printf("Masukkan %d command\n", Q);
    char command[10];
    for (int i=0; i<Q; i++){
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {  
            int l, x, y;
            scanf("%d %d %d", &l, &x, &y);
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
            printf("Input tidak valid");
            Q += 1;
            continue;
        }
    }
    
    for (int i = 0; i < outputCount; i++) {
        printf("%d\n", outputArray[i]);
    }
    free(outputArray);


    return 0;
}

void new(){
    groupArray = realloc(groupArray, (count + 1) * sizeof(array));
    groupArray[count].data = NULL;
    groupArray[count].size = 0;
    count++;
}

void add(int l, int x, int y) {
    int i = l - 1;

    if (i >= count || i < 0) {
        printf("Group %d tidak ditemukan.\n", l);
        return;
    }

    groupArray[i].data = realloc(groupArray[i].data, (groupArray[i].size + y) * sizeof(int));
    
    for (int j = 0; j < y; j++) {
        groupArray[i].data[groupArray[i].size + j] = x;
    }
    groupArray[i].size += y;
}

void out(int l, int z) {
    int i = l - 1;
    if (i >= count || i < 0 || z < 1 || z > groupArray[i].size) {
        printf("Index tidak valid.\n");
        return;
    }

    outputArray = realloc(outputArray, (outputCount + 1) * sizeof(int));
    outputArray[outputCount] = groupArray[i].data[z - 1];
    outputCount++;
}