#include <stdio.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int top = -1;

// fungsinya add(push) ditambahin nanti
void add(int X, int Y) {
    for (int i = 0; i < Y; i++) {
        stack[++top] = X;}
    printf("%d\n", top + 1);
}

void del(int Y) {
    if (top - Y + 1 >= 0) {
        printf("%d\n", stack[top - Y + 1]);
        top -= Y;
    } else {
        printf("0\n");
        top = -1;
    }
}

void adx(int D) {} // fungsinya ditambahin nanti
void dex(int D) {} // fungsinya ditambahin nanti

int main() {
    int Q;
    scanf("%d", &Q);

    char cmd[10];
    int X, Y;

    for (int i = 0; i < Q; i++) {
        scanf("%s", cmd);
        
        if (strcmp(cmd, "add") == 0) {
            scanf("%d %d", &X, &Y);
            add(X, Y); 
        } else if (strcmp(cmd, "del") == 0) {
            scanf("%d", &Y);
            del(Y);
        }
    }
        return 0;
}
