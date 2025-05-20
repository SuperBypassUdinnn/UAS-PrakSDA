#include <stdio.h>
#include <string.h>

#define MAX 100000

int stack[MAX];
int top = -1;
int delta = 0;

void add(int X, int Y) {
    for (int i = 0; i < Y; i++) {
        stack[++top] = X - delta;
    }
    printf("%d\n", top + 1);
}

void del(int Y) {
    if (top - Y + 1 >= 0) {
        int value = stack[top] + delta;
        printf("%d\n", value);
        top -= Y;
    }
}

void adx(int D) {
    delta += D;
}

void dex(int D) {
    delta -= D;
}

int main() {
    int Q;
    scanf("%d", &Q);

    char cmd[4];
    int X, Y, D;

    for (int i = 0; i < Q; i++) {
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf("%d %d", &X, &Y);
            add(X, Y);
        } else if (strcmp(cmd, "del") == 0) {
            scanf("%d", &Y);
            del(Y);
        } else if (strcmp(cmd, "adx") == 0) {
            scanf("%d", &D);
            adx(D);
        } else if (strcmp(cmd, "dex") == 0) {
            scanf("%d", &D);
            dex(D);
        }
    }

    return 0;
}
