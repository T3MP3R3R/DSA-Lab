#include <iostream>
using namespace std;

const int N = 4; // we assume n is a 4x4 maze here

bool isSafe(int maze[N][N], int x, int y, int sol[N][N]){
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]){
    if (x == 2 && y == 0){
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y, sol)){
        sol[x][y] = 1;
        if (solveMaze(maze, x + 1, y, sol)) return true;
        if (solveMaze(maze, x, y + 1, sol)) return true;
        if (solveMaze(maze, x - 1, y, sol)) return true;
        if (solveMaze(maze, x, y - 1, sol)) return true;
         // backtrack
        sol[x][y] = 0;
    }
    return false;
}

int main(){
    int maze[N][N] = {
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    int sol[N][N] = {0};

    if (solveMaze(maze, 0, 0, sol)){
        cout << "Path found:" << endl;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No path can be found" << endl;
    }

    return 0;
}