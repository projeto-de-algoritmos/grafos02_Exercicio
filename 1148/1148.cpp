#include <string.h>
#include <stdio.h>
#include <iostream>
#define Vertices int

struct Grafo {
    int v;
    int x;
    int rota[501][501];
};

Grafo grafo;

void dijkstra (int origem, int destino)
{
    int aux0, aux1;
    int fr[501], parente[501];
    int ref[501];
    
    memset (parente, -1, sizeof(parente));
    memset (ref, 999999, sizeof(ref));
    
    fr[origem] = origem;
    ref[origem] = 0;
    
    while(1){
             int min = 999999;
             for(aux0 = 0; aux0 < grafo.v; aux0++){
                   if(parente[aux0] == -1 && min > ref[aux0]){
                               min = ref[aux1=aux0];
                   }
             }
             if(min == 999999) break;
             parente[aux1] = fr[aux1];     
             
             for(aux0 = 0; aux0 < grafo.v; aux0++){
                   if(ref[aux0] > ref[aux1] + grafo.rota[aux1][aux0]){
                               ref[aux0] = ref[aux1] + grafo.rota[aux1][aux0];
                               fr[aux0]= aux1;
                   }
             }
    }
             
             if(ref[destino] <  999999) printf("%d\n", ref[destino]);
             else printf("Nao e possivel entregar a carta\n");
}



int main()
{
	memset(&grafo, 0, sizeof(grafo));
	int n,e,k,o,d,i, j, x,y,z;
	    
    while(1){
             scanf("%d %d", &n, &e);
             if(n == 0 && e == 0) break;
             for(i = 0; i <= n; i++)
                   for(j = 0; j <= n; j++)
                         grafo.rota[i][j] = 999999;
             for (i = 0; i < e; ++i){
                     scanf("%d %d %d",&x, &y, &z);
                     if(grafo.rota[y][x] != 999999){
                                    grafo.rota[x][y] = 0;
                                    grafo.rota[y][x] = 0;
                     }else{
                           grafo.rota[x][y] = z;
                     }
             }
             grafo.v = n+1;
             grafo.x = e;
             scanf("%d", &k);
             for (i = 0; i < k; ++i){
                     scanf("%d %d",&o, &d);
                               dijkstra(o, d);
             }
             printf("\n");
    }
	return 0;
}