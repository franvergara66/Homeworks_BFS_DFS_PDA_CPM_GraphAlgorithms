#include<iostream>
#include<queue>
#define MAX 100
#include <vector>
#include <stdlib.h>


using namespace std;

typedef struct node
{
        int value;
        struct node *left, *right;
}*tree;


queue<int> myQueue;
int visit[MAX];
int BFS_graph[MAX][MAX];
int BFS_tree [ MAX ];
int V, it2=0;


void bfs(int );
void preorder(int);



int main(int argc, char *argv []){

    /// //////////////////////////////////
#ifndef ONLINE_JUDGE
#pragma warning(disable: 4996)
	freopen("input.in", "r", stdin); ///entrada y salida standard se redirige a un archivo

#endif


    int vertexNumber, edgesNumber;

    int origin ,destination, i, j;
    int testCases, initial;
     memset(visit, 0, sizeof(visit));
    scanf ("%d", &testCases);


        for (i=0; i<testCases; i++){

        printf ("Case %d:\n",i+1);



        scanf("%d %d" , &vertexNumber , &edgesNumber );
        V=vertexNumber;

        int followOrder [vertexNumber];



        for (int j=0; j<edgesNumber; j++){
            scanf("%d %d" , &origin ,&destination );
            BFS_graph[origin][destination]=1;
            BFS_graph[destination][origin]=1;

        }

        for (int j=0; j<edgesNumber; j++){
        scanf ("%d ", &followOrder[j]);
        }

       initial=followOrder[0];


        printf ("BFS: ");
            bfs (initial);
        for (int j=0; j<V; ++j)
            printf ("%d ", BFS_tree[j]);//here instead of printing directly
            //make a call to pre-order ()


        printf ("\n");


    printf ("\n");


    }

return 0;
}


void bfs(int s) {
     int i, j,it2=0, node;
     memset(visit, 0, sizeof(visit));
     myQueue.push(s);

     while(!myQueue.empty())
     {
          node = myQueue.front();
          myQueue.pop();
          if(visit[node]) continue;
          visit[node] = 1;
          BFS_tree[it2]=node; //here instead of going storing in an array must be inserting a
          // tree structure and then call a function preorder
          it2++;

          for(i=0; i<V; i++){
               if( BFS_graph[i][node]) myQueue.push(i);
               if( BFS_graph[node][i]) myQueue.push(i);
               }
     }

}


void preorder(tree t)
{
        if(t == NULL)
                return;
        printf("%d ", t->value);
        preorder(t->left);
        preorder(t->right);
}
