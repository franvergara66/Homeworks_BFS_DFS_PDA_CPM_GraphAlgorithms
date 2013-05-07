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
using namespace std;


vector<int> adyacencia[10000]; ///matriz de adyacencia del grafo
bool visitado[10000]; ///arreglo exageradamente grande xD para marcar los nodos visitados
/// Header del BFS a usar
void BFS( int);

int main(int argc, char *argv []){

/// //////////////////////////////////
#ifndef ONLINE_JUDGE
#pragma warning(disable: 4996)
	freopen("tarea1.in", "r", stdin); ///entrada y salida standard se redirige a un archivo
   // freopen("tarea1.out", "w", stdout);
/// //////////////////////////////////
#endif

     ///enumerar vertices desde 1 hasta V
    int numeroVertices, numeroAristas;
    int nodoOrigen ,nodoDestino, i, j, k, contCasos=1;
    ///numero de casos de prueba
    int casosPrueba;
    int totalComponentes;
    scanf ("%d", &casosPrueba);

    for (i=0; i<casosPrueba; i++){
    memset( visitado , 0 , sizeof(visitado)); ///se setea en 0 la matriz de adyacencia
    scanf("%d %d" , &numeroVertices , &numeroAristas );

    int nodosVertices [numeroVertices]; ///arreglo para almacenar los nodos
    int nodosComponentes [numeroVertices]; ///arreglo para almacenar el numero de componentes


    for (j=0; j<numeroAristas; j++){
        scanf("%d %d" , &nodoOrigen ,&nodoDestino );
        adyacencia[nodoOrigen].push_back(nodoDestino); ///se llena la matriz de adyacencia (u,v) = (v,u)
        adyacencia[nodoDestino].push_back(nodoOrigen);
    }



        totalComponentes=0; ///se inicializa el total de componentes del grafo en 0 para cada caso de prueba

        for( int i = 0 ; i < numeroVertices ; ++i ) ///iteramos en todos los vertices
        {
                nodosVertices[i]=i; ///se llena el arreglo con los vertices del grafo
            if( !visitado[ i ] )
            { ///si algun nodo no es visitado llamamos a DFS
                    BFS(i);
                totalComponentes++; ///incrementamos cantidad de componentes
            }
            nodosComponentes[i]=totalComponentes; ///se almacena a que componente pertenece cada nodo
        }
        printf("Caso %d: %d componente(s) conectada(s)\n" ,contCasos++, totalComponentes); ///se imprime el caso de prueba el nro de componentes


            int flag = nodosComponentes[0]; ///se crea una bandera con el valor de la primera componente
            for (k=0; k <numeroVertices; ++k) ///hacemos un ciclo de tamaño del nro de componentes
            {
                if (flag == nodosComponentes [k] ) ///verificamos si el vertice pertenece a la primera componente
                {
                    printf ("%d ", nodosVertices[k]); ///imprimimos en la misma linea si pertenece a la misma componente
                }else {
                    printf ("\n"); ///sino hacemos salto de linea y actualizamos la bandera con la siguiente componente
                    flag = nodosComponentes[k];
                    printf ("%d ", nodosVertices[k]);///e imprimimos los vertices de la nueva componente conexa
                }
            }
    printf ("\n\n");

    memset( adyacencia , 0 , sizeof( adyacencia ) ); ///se setea en 0 la nueva matriz de adyacencia del siguiente caso
    }
return 0;
}

/// @param algoritmo estandar de DFS
void BFS( int verticeInicial ){ ///se le pasa el vertice del cual partiremos (vertice 0)
    visitado[verticeInicial] = true; ///se marca ese vertice como visitado
    int verticeComparar = 0;
    int comp = adyacencia[verticeInicial].size();
    while (verticeComparar<comp){ ///
        if( !visitado[adyacencia[verticeInicial][verticeComparar]] ){///si el vertice adyacente al vertice inicial no ha sido visitado
   ///hacemos backtracking con el nuevo vertice adyacente para inundar
   ///todo el grafo y recorrer todos los nodos
             BFS( adyacencia[verticeInicial][verticeComparar]);
        }
    verticeComparar++;
    }
}
//Referencia-->http://www.lsi.upc.edu/~edelmira/Grafos-Recorridos.pdf


