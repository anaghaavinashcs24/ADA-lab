#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void print(int *perm, int n) {
    for (int i = 0; i < n; i++) printf("%d ", perm[i]);
    printf("\n");
}

int getMobile(int *perm, int *dir, int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        int next = i + dir[perm[i]-1];
        if (next >= 0 && next < n && perm[i] > perm[next] && perm[i] > mobile)
            mobile = perm[i];
    }
    return mobile;
}

void johnsonTrotter(int n) {
    int perm[n], dir[n];
    for (int i = 0; i < n; i++) { perm[i] = i+1; dir[i] = LEFT; }

    print(perm, n);

    while (1) {
        int mobile = getMobile(perm, dir, n);
        if (mobile == 0) break;

        int pos;
        for (pos = 0; pos < n; pos++) if (perm[pos] == mobile) break;

        int next = pos + dir[mobile-1];
        int tmp = perm[pos]; perm[pos] = perm[next]; perm[next] = tmp;

        for (int i = 0; i < n; i++)
            if (perm[i] > mobile) dir[perm[i]-1] = -dir[perm[i]-1];

        print(perm, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}

