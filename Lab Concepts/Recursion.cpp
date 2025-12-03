#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumArray(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}

bool isSafeNQueens(int board[10][10], int row, int col, int n) {
    for (int i = 0; i < row; i++) if (board[i][col] == 1) return false;
    for (int i = row-1, j=col-1; i>=0 && j>=0; i--, j--) if (board[i][j]==1) return false;
    for (int i = row-1, j=col+1; i>=0 && j<n; i--, j++) if (board[i][j]==1) return false;
    return true;
}

bool solveNQueensUtil(int board[10][10], int row, int n) {
    if (row == n) return true;
    for (int col=0; col<n; col++) {
        if (isSafeNQueens(board, row, col, n)) {
            board[row][col]=1;
            if (solveNQueensUtil(board, row+1, n)) return true;
            board[row][col]=0; // backtrack
        }
    }
    return false;
}

void solveNQueens(int n) {
    int board[10][10]={0};
    if (!solveNQueensUtil(board,0,n)) { cout<<"No solution exists\n"; return; }
    cout<<"One solution:\n";
    for(int i=0;i<n;i++){ for(int j=0;j<n;j++) cout<<board[i][j]<<" "; cout<<endl; }
}

void permute(char str[], int l, int r) {
    if (l==r) { cout<<str<<endl; return; }
    for(int i=l;i<=r;i++){
        char temp=str[l]; str[l]=str[i]; str[i]=temp;
        permute(str,l+1,r);
        temp=str[l]; str[l]=str[i]; str[i]=temp; // backtrack
    }
}

#define M 4
bool isSafeMaze(int maze[M][M], int x, int y) {
    return (x>=0 && x<M && y>=0 && y<M && maze[x][y]==1);
}

bool solveMazeUtil(int maze[M][M], int x, int y, int sol[M][M]) {
    if (x==M-1 && y==M-1) { sol[x][y]=1; return true; }
    if (isSafeMaze(maze,x,y)) {
        sol[x][y]=1;
        if (solveMazeUtil(maze,x,y+1,sol)) return true;
        if (solveMazeUtil(maze,x+1,y,sol)) return true;
        sol[x][y]=0; // backtrack
        return false;
    }
    return false;
}

void solveMaze(int maze[M][M]) {
    int sol[M][M]={0};
    if(!solveMazeUtil(maze,0,0,sol)){ cout<<"No solution exists\n"; return; }
    cout<<"One path:\n";
    for(int i=0;i<M;i++){ for(int j=0;j<M;j++) cout<<sol[i][j]<<" "; cout<<endl; }
}

// ---------------- Main Menu ----------------
int main() {
    int choice;
    do {
        cout<<"\n--- Recursion & Backtracking Menu ---\n";
        cout<<"1. Factorial\n2. Fibonacci\n3. Sum of Array\n4. N-Queens\n5. String Permutations\n6. Rat in a Maze\n0. Exit\n";
        cout<<"Enter choice: "; cin>>choice;

        switch(choice){
            case 1: {
                int n; cout<<"Enter number: "; cin>>n;
                cout<<"Factorial: "<<factorial(n)<<endl; break;
            }
            case 2: {
                int n; cout<<"Enter term (n): "; cin>>n;
                cout<<"Fibonacci: "<<fibonacci(n)<<endl; break;
            }
            case 3: {
                int n; cout<<"Enter array size: "; cin>>n;
                int arr[50]; cout<<"Enter elements: ";
                for(int i=0;i<n;i++) cin>>arr[i];
                cout<<"Sum: "<<sumArray(arr,n)<<endl; break;
            }
            case 4: {
                int n; cout<<"Enter N for N-Queens (<=10): "; cin>>n;
                solveNQueens(n); break;
            }
            case 5: {
                char str[20]; cout<<"Enter string (<=20 chars): "; cin>>str;
                int len=0; while(str[len]!='\0') len++;
                permute(str,0,len-1); break;
            }
            case 6: {
                int maze[M][M] = { {1,0,0,0}, {1,1,0,1}, {0,1,0,0}, {1,1,1,1} };
                solveMaze(maze); break;
            }
            case 0: cout<<"Exiting...\n"; break;
            default: cout<<"Invalid choice.\n";
        }

    } while(choice!=0);

    return 0;
}