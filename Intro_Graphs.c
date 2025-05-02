#include <stdio.h>
#include <stdlib.h>

void DFS(int node,int** Graph,int* Vis,int N){
    Vis[node] = 1;
    printf("%d ",node);
    for(int i = 1; i <= N; i++){
        if(Vis[i] == 0 && Graph[node][i] == 1)
        DFS(i,Graph,Vis,N);
    }
    return ;
}
int main() {
	int N,E;
	scanf("%d %d",&N,&E);
	int** Graph = (int**)calloc(N + 1,sizeof(int*));
	for(int i = 0; i <= N; i++){
	    Graph[i] = (int*)calloc(N + 1,sizeof(int));
	}
	int u,v;
	for(int i = 0; i < E; i++){
	    scanf("%d %d",&u,&v);
	    Graph[u][v] = 1;
	    Graph[v][u] = 1;
	}
	int* Vis = (int*)calloc(N + 1,sizeof(int));
	DFS(1,Graph,Vis,N);
	for(int i = 0; i <= N; i++){
	    free(Graph[i]);
	}
	free(Graph);
	free(Vis);
	return 0;
}

