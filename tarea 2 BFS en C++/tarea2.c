/*//////////////////////////////////////////
//Francisco "Pancho" Vergara
//C.I 17.389.551
//José "Pascual" Rodríguez
//C.I. 17.428.239
//Discretas iii tarea º2
//Prof: Maria Carrasco
///////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct dataNodes{
   int origen;
   int destino;
   int peso;
   dataNodes *next;
} nodosGrafo;

/*///////////////////////////////////////////////////////////
*Funcion de Comparacion para usar en qsort y ordenar el arreglo
de struct nodosGrafo, recibe como parametro dos void que se les
hace casteo a el struct para usarlo, se usan comparaciones basicas
entre los origenes y destinos para ordenar
*///////////////////////////////////////////////////////////
int funcionSort(const void * arregloA, const void * arregloB)
{
    nodosGrafo *arregloAPointer = (nodosGrafo*)arregloA;
    nodosGrafo *arregloBPointer = (nodosGrafo*)arregloB;
    if( arregloAPointer->origen < arregloBPointer->origen )
        return -1;
    else if( arregloAPointer->origen > arregloBPointer->origen )
        return 1;
    else if( arregloAPointer->destino < arregloBPointer->destino )
        return -1;
    else if( arregloAPointer->destino > arregloBPointer->destino )
        return 1;
    else
        return 0;
 }

/*////////////////////////////////////////////////////
Variables globales para numero de vertices y numero
de aristas del grafo de entrada.
*/////////////////////////////////////////////////////
int numeroVertices;
int numeroAristas;


/*////////////////////////////////////////////////////
//matriz para almacenar los pesos entre cada nodo i y j del grafo,
//se lee el peso y se almacena tanto en la posicion i,j como en la j,i
//ya que el grafo es no dirigido, si no hay camino entre i->j
matrizPesos [i][j]==matrizPesos [j][i]==0
*////////////////////////////////////////////////////
int matrizPesos[1000][1000];



/*///////////////////////////////////////////////////
//Arreglo para marcar si el nodo pertenece o no al arbol
//recubridor minimal, 1 si el nodo i ya está en el arbol recubridor
//cero si no está
*///////////////////////////////////////////////////
char arbolMinimal[1000];

/*////////////////////////////////////////////////////
//el arreglo distancia[i] es ladistancia entre el nodo i y arbol de
//expansion minima, en un principio infinito (99999); si ya se encuentra en
//el árbol, entonces distancia[i] no está definido;esto es sólo una variable
// temporal.No es necesario, pero reduce el orden de ejecucion a orden N
//hasta la ejecución considerablemente (en un factor de n)
/////////////////////////////////////////////////////*/
int distancia[99999];


/*////////////////////////////////////////////////////
/* arreglo que contiene el índice del nodo i para obtener la distancia distacia [i]
relacionado con el fin de obtener una distancia de Distancia[i]
/////////////////////////////////////////////////////*/
int linkeoNodos[1000];

//Header para la funcion definida mas adelante.
void actualizarDistancias(int);

int main (int argc, char ** argv){

int casosPrueba; //numero de casos de prueba


#ifndef ONLINE_JUDGE
#pragma warning(disable: 4996)
    freopen("entradaA.in", "r", stdin);
   // freopen("salidaA.out", "w", stdout);
/////////////////////////////////////
#endif

int i, j,k, cont=1;
int m;
scanf ("%d", &casosPrueba);

    for (i=0; i<casosPrueba; ++i)
    {
    scanf ("%d %d", &numeroVertices, &numeroAristas);
    //arreglos para leer los datos: Origen, Destino, Peso
    int nodosOrigen [numeroAristas];
    int nodosDestino [numeroAristas];
    int arregloPesos [numeroAristas];

    /*se inician todos los arreglos a usar en 0 mediante memset*/
    memset ( matrizPesos, 0, sizeof(matrizPesos));//init matrix with 0's
    memset ( nodosOrigen, 0, sizeof(nodosOrigen));//init matrix with 0's
    memset ( nodosDestino, 0, sizeof(nodosDestino));//init matrix with 0's
    memset ( arregloPesos, 0, sizeof(arregloPesos));

        for (j=0; j<numeroAristas; j++)
        {
        scanf ("%d %d %d", &nodosOrigen[j], &nodosDestino[j], &arregloPesos[j]); //
        }

        for (j=0; j<numeroAristas; j++)
        {
        matrizPesos [nodosOrigen[j]][nodosDestino[j]] = arregloPesos [j];
        matrizPesos [nodosDestino[j]][nodosOrigen[j]] = arregloPesos [j];
        }

    // Initializo el arreglo de distancias en infinito (numero muy grande)
    memset (distancia, 10000, sizeof(distancia));
    //coloco en 0 todos los nodos del arbol recubridor
    memset (arbolMinimal, 0, sizeof (arbolMinimal));

    arbolMinimal[0] = 1;
    //empiezo a actualizar la distancia minima desde el nodo 0;
    actualizarDistancias(0);
    int total = 0;
    int tamanoArbol;
    int temp;
    //arreglo de struct para almacenar la informacion de cada vertice (i,j)
    nodosGrafo arreglo [numeroVertices-1];
    //arrayGraph aux;
    int aux;
    /*voy recorriendo los nodos y encontrando las distancias minimas para el arbol*/
    /* busco cual es el nodo con la distancia minima en el arbol*/
    for (tamanoArbol = 0; tamanoArbol < numeroVertices-1; ++tamanoArbol) {
        int min = -1;
        for (m= 0; m < numeroVertices; ++m)
            if (!arbolMinimal[m])
                if ((distancia[m] < distancia[min]  || (min == -1)))
                    min = m;

        //agrego ese nodo al arbol, guardando en cada campo del estruct la info de ese nodo
       arreglo [tamanoArbol].origen = linkeoNodos[min];
       arreglo [tamanoArbol].destino =min;
       arreglo [tamanoArbol].peso = distancia[min];
        //seteo ese vertice en 1 para saber que ya pertenece al arbol
        arbolMinimal[min] = 1;
        //acumulo esa distancia
        total += distancia[min];
        //actualizo la distancia
        actualizarDistancias(min);
    }
        printf ("Caso %d: Duracion Total %d\n", cont++, total);

        //aqui si el origen es mayor que destino hago swap entre ambos
      for (tamanoArbol = 0; tamanoArbol < numeroVertices-1; ++tamanoArbol)
        {
            if (arreglo[tamanoArbol].origen>arreglo[tamanoArbol].destino){
                temp = arreglo[tamanoArbol].origen;
                arreglo[tamanoArbol].origen = arreglo[tamanoArbol].destino;
                arreglo[tamanoArbol].destino = temp;

                }
        }
       //llamo a qsort con el arreglo de struct, tamaño el tamaño de cada
       //posicion del arreglo y la funcion de comparacion
        qsort(arreglo,tamanoArbol,sizeof(arreglo[0]),funcionSort);

                for (tamanoArbol = 0; tamanoArbol < numeroVertices-1; ++tamanoArbol)
                {
                printf ("%d %d %d\n", arreglo[tamanoArbol].origen, arreglo[tamanoArbol].destino , arreglo[tamanoArbol].peso);

                }
        printf ("\n");
    }

return (0);

}

/// actualizarDistancias
/// @param meta
///    Debe ser llamado inmediatamente después de la meta se añade al árbol;
///    Actualiza distancias [i] de manera que los valores son correctos
/// (pasa a través de todos los vertices adyacentes a meta para asegurarse de
/// que las distancias entre ellos y el árbol son mínimas)

void actualizarDistancias(int meta) {
    int i;
    for (i = 0; i < numeroVertices; ++i)
        if ((matrizPesos[meta][i] != 0) && (distancia[i] > matrizPesos[meta][i])) {
            distancia[i] = matrizPesos[meta][i];
            linkeoNodos[i] = meta;
        }
}
