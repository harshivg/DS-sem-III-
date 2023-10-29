#include <bits/stdc++.h>
using namespace std;

class SparseMatrix {
private:
    int rows, cols;

    vector<vector<int>> data;
public:
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows);
        for (int i = 0; i < rows; i++) {
            data[i].resize(cols, 0);
        }
    }

    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        } else {
            cout << "Invalid row or column index." << endl;
        }
    }

    int getValue(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        } else {
            cout << "Invalid row or column index." << endl;
            return 0;
        }
    }

    SparseMatrix operator+(const SparseMatrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrix dimensions must be the same for addition." << endl;
            return SparseMatrix(rows, cols);
        }

        SparseMatrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    SparseMatrix operator-(const SparseMatrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrix dimensions must be the same for subtraction." << endl;
            return SparseMatrix(rows, cols);
        }

        SparseMatrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    SparseMatrix operator*(const SparseMatrix& other) const {
        if (cols != other.rows) {
            cout << "Invalid matrix dimensions for multiplication." << endl;
            return SparseMatrix(rows, other.cols);
        }

        SparseMatrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix matrix1(3, 3);
    SparseMatrix matrix2(3, 3);

    matrix1.setValue(0, 0, 1);
    matrix1.setValue(0, 2, 2);
    matrix1.setValue(2, 2, 3);

    matrix2.setValue(0, 0, 2);
    matrix2.setValue(1, 1, 1);
    matrix2.setValue(2, 2, 4);

    cout << "Matrix 1:" << endl;
    matrix1.display();

    cout << "Matrix 2:" << endl;
    matrix2.display();

    SparseMatrix resultAdd = matrix1 + matrix2;
    SparseMatrix resultSub = matrix1 - matrix2;
    SparseMatrix resultMul = matrix1 * matrix2;

    cout << "Matrix 1 + Matrix 2:" << endl;
    resultAdd.display();

    cout << "Matrix 1 - Matrix 2:" << endl;
    resultSub.display();

    cout << "Matrix 1 * Matrix 2:" << endl;
    resultMul.display();

    return 0;
}
