#include <iostream>
#include <queue>
using namespace std;

int main() {
    const int N = 6; // nodes A-F
    int adjMatrix[N][N] = {0};
    int adjList[N][N];
    int adjCount[N] = {0};
    int edges[][3] = { // edges (node 1, node 2, weight)
        {1,0,4}, {1,2,9}, {0,3,8}, {2,3,6}, {2,4,14}, {3,5,4}, {5,4,3}
    };

    int numEdges = 7;
    for(int i=0;i<numEdges;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;

        adjList[u][adjCount[u]++] = v;
        adjList[v][adjCount[v]++] = u;
    }

    cout << "Adjacency Matrix: " << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }

    cout << "\nAdjacency List: " << endl;
    char nodes[] = {'A','B','C','D','E','F'};
    for(int i=0;i<N;i++){
        cout << nodes[i] << ": ";
        for(int j=0;j<adjCount[i];j++)
            cout << nodes[adjList[i][j]] << " ";
        cout << endl;
    }

    cout << "\nBFS Traversal starting from B:" << endl;
    bool visited[N] = {0};
    queue<int> q;
    q.push(1); visited[1]=true;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        cout << nodes[curr] << " ";
        for(int i=0;i<adjCount[curr];i++){
            int next = adjList[curr][i];
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
            }
        }
    }
    cout << endl;

    cout << "\nDFS Traversal starting from B:" << endl;
    bool visitedDFS[N] = {0};
    int stack[N];
    int top=-1;

    stack[++top] = 1;
    while(top>=0){
        int curr = stack[top--];
        if(!visitedDFS[curr]){
            visitedDFS[curr]=true;
            cout << nodes[curr] << " ";
            for(int i=adjCount[curr]-1;i>=0;i--){
                int next = adjList[curr][i];
                if(!visitedDFS[next])
                    stack[++top]=next;
            }
        }
    }

    return 0;
} 
