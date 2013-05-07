/// /////////////////////////////////////////
///Francisco Vergara seccion: Elizer
///C.I 17.389.551
///Matemáticas Discretas iii tarea º1
/// /////////////////////////////////////////


#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include<stack>


using namespace std;

int q[20000];
int vis[20000];
bool visitado[10000]; ///arreglo exageradamente grande xD para marcar los nodos visitados
vector<int> adyacencia[10000]; ///matriz de adyacencia del grafo

int main(int argc, char *argv []){

    /// //////////////////////////////////
#ifndef ONLINE_JUDGE
#pragma warning(disable: 4996)
	freopen("tarea3.in", "r", stdin); ///entrada y salida standard se redirige a un archivo
   // freopen("tarea1.out", "w", stdout);
/// //////////////////////////////////
#endif


    int numeroVertices, numeroAristas;
    int ordenamientoSeguir;
    int nodoOrigen ,nodoDestino, i, j, k, contCasos=1;
    ///numero de casos de prueba
    int casosPrueba;
    scanf ("%d", &casosPrueba);
    for (i=0; i<casosPrueba; i++){
    scanf("%d %d" , &numeroVertices , &numeroAristas );
    printf ("%d %d\n", numeroVertices, numeroAristas);
    int nodosVertices [numeroVertices]; ///arreglo para almacenar los nodos
    int  OrdenVertices [numeroVertices]; ///arreglo para almacenar el orden

        for (j=0; j<numeroAristas; j++){
        scanf("%d %d" , &nodoOrigen ,&nodoDestino );
        printf ("%d %d\n", nodoOrigen, nodoDestino);

        } //fin lectura de nodos
    for (j=0; j<numeroAristas;j++){
        scanf ("%d ", &ordenamientoSeguir);
        printf ("%d ", ordenamientoSeguir);
        }
        printf ("\n");
    } //fin casos prueba

return 0;
}

/// @param algoritmo estandar de DFS
void DFS( int verticeInicial ){ ///se le pasa el vertice del cual partiremos (vertice 0)
    visitado[verticeInicial] = true; ///se marca ese vertice como visitado
    int verticeComparar = 0;
    int comp = adyacencia[verticeInicial].size();
    while (verticeComparar<comp){ ///
        if( !visitado[adyacencia[verticeInicial][verticeComparar]] ){///si el vertice adyacente al vertice inicial no ha sido visitado
   ///hacemos backtracking con el nuevo vertice adyacente para inundar
   ///todo el grafo y recorrer todos los nodos
             DFS( adyacencia[verticeInicial][verticeComparar]);
        }
    verticeComparar++;
    }
}

//Referencia-->http://www.lsi.upc.edu/~edelmira/Grafos-Recorridos.pdf
