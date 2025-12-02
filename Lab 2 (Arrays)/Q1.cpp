#include <iostream>
using namespace std;

class DynamicMat{
private:
    int rows, cols;
    int** mat;

    void allocateMat(int r, int c, int initVal = 0){
        rows = r;
        cols = c;
        mat = new int*[rows];
        for (int i = 0; i < rows; i++){
            mat[i] = new int[cols];
            for (int j = 0; j < cols; j++){
                mat[i][j] = initVal;
            }
        }
    }
public:
    DynamicMat(int r, int c, int initVal = 0){
        allocateMat(r, c, initVal);
    }
    ~DynamicMat() {
        for (int i = 0; i < rows; i++){
            delete[] mat[i];
        }
        delete[] mat;
    }

    void resize(int newRows, int newCols, int initVal = 0){
        int** newMatrix = new int*[newRows];
        for (int i = 0; i < newRows; i++){
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; j++){
                if (i < rows && j < cols){
                    newMatrix[i][j] = mat[i][j]; 
                } else {
                    newMatrix[i][j] = initVal;
                }
            }
        }

        for (int i = 0; i < rows; i++){
            delete[] mat[i];
        }
        delete[] mat;

        mat = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    void transpose(){
        int** transposed = new int*[cols];
        for (int i = 0; i < cols; i++){
            transposed[i] = new int[rows];
            for (int j = 0; j < rows; j++){
                transposed[i][j] = mat[j][i];
            }
        }

        for (int i = 0; i < rows; i++){
            delete[] mat[i];
        }
        delete[] mat;

        int temp = rows;
        rows = cols;
        cols = temp;
        mat = transposed;
    }

    void printOddIndexUpdate(){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                int value = mat[i][j];
                if ((i + j) % 2 != 0){ 
                    value += 2;
                }
                cout << value << " ";
            }
            cout << endl;
        }
    }

    void setValue(int r, int c, int val){
        if (r >= 0 && r < rows && c >= 0 && c < cols){
            mat[r][c] = val;
        }
    }

    void print(){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    DynamicMat mat(2, 3, 1);
    cout << "Initial Matrix:" << endl;
    mat.print();
    mat.setValue(0, 1, 5);
    mat.setValue(1, 2, 9);
    cout << "\nAfter Updates:" << endl;
    mat.print();
    mat.resize(3, 4, 7);
    cout << "\nResized Matrix (3x4):" << endl;
    mat.print();
    mat.transpose();
    cout << "\nTransposed Matrix:" << endl;
    mat.print();
    cout << "\nMatrix with +2 at odd indices:" << endl;
    mat.printOddIndexUpdate();

    return 0;
}
