#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
 
#define MAX 200000

struct Grafo { int x, y, z; };

int c;
int fat[MAX];
Grafo grafo[MAX];

int cmp(const void *a, const void *b) {
    return (*(struct Grafo *)a).z - (*(struct Grafo *)b).z;
}

void makeset(int n) {
    for (int i = 0; i < n; i++)
        fat[i] = i;
}

int find(int n) {
    if(fat[n] != n)
        fat[n] = find(fat[n]);
    return fat[n];
}

int unionp(int x, int y, int p) {
    int i = find(x), j = find(y);

    if(i != j) {
        c -= grafo[p].z;
        if(i > j) fat[i] = j;
        else fat[j] = i;
        return 1;
    }

    return 0;
}

int main(int argc, char const *argv[]) {
    int m, n, i;

    while( scanf("%d %d", &m, &n) && (m != 0)) {
        c = 0;
        memset(&grafo, 0, sizeof(grafo));

        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &grafo[i].x, &grafo[i].y, &grafo[i].z);
            c += grafo[i].z;
        }

        makeset(m);
        qsort(grafo, n, sizeof(grafo[0]), cmp);
        for (i = 0; i < n; ++i)
            unionp(grafo[i].x, grafo[i].y, i);
        printf("%d\n", c);
    }

    return 0;
}