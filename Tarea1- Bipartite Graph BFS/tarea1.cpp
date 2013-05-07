#include <vector>
#include <iostream>
#include <queue>
#define MAX 10000
using namespace std;


int particion[MAX], visitado[MAX];
vector< int > adyacencia[MAX];
int numeroVertices, numeroAristas;
char conjunto [MAX];

bool bfs(int begin)
{
    int i, origin, destination;
    queue< int > queueVertex;
    queueVertex.push(begin);
    particion[begin] = 1;
    visitado[begin] = 1;

    while(!queueVertex.empty())
    {
        origin = queueVertex.front(); queueVertex.pop();
        for(i=0; i < adyacencia[origin].size(); i++)
        {
            destination = adyacencia[origin][i];
            if(particion[origin] == particion[destination])
            {
                return false;
            }
            if(visitado[destination] == 0)
            {
                visitado[destination] = 1;
                particion[destination] = 3 - particion[origin];
                queueVertex.push(destination);
            }
        }
    }
    return true;
}

bool is_bipartite()
{
    for(int i=0; i< numeroVertices; i++)
    {
       if (visitado[i] == 0 && !bfs(i)) {
           return false;
       }
    }
    return true;
}

int main()
{

freopen("tarea1.in", "r", stdin);
freopen("tarea1.out", "w", stdout);
    int nodoOrigen ,nodoDestino, i, j, k;
    ///numero de casos de prueba
    int casosPrueba;
    cin>>casosPrueba;
    for (i=0; i<casosPrueba; i++){
        memset (adyacencia, 0, sizeof(adyacencia));//init matrix with 0's
        memset (particion, 0, sizeof(particion) );
        memset (visitado, 0, sizeof(visitado));
		cin>>numeroVertices>>numeroAristas;

        for(j=0; j<numeroAristas; j++)
    {
        cin>>nodoOrigen>>nodoDestino;
        adyacencia[nodoOrigen].push_back(nodoDestino);
        adyacencia[nodoDestino].push_back(nodoOrigen);
    }

    cout<<"Caso "<<i+1<<": ";

    if(is_bipartite()) {

        printf("Es bipartito\n");
          for (j=0; j<numeroVertices; j++){
        if (particion[j]==2){cout<<j<<" "<<"b"<<endl;}
           else{cout<<j<<" "<<"a"<<endl;}
        }

    }
    else {printf("No es bipartito\n");}

     cout <<endl;

    } //fin casos prueba
return 0;
}

