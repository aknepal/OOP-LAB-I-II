#include <iostream>
using namespace std;

class MATRIX {
private:
    int rows, cols;
    int** data;

public:
    // Constructor to initialize matrix with zero values
    MATRIX(int m, int n) : rows(m), cols(n) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]();
        }
    }

    // Copy constructor
    MATRIX(const MATRIX& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Destructor to free allocated memory
    ~MATRIX() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Overload + operator to add two MATRIX objects
    MATRIX operator+(const MATRIX& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have the same dimensions to be added.");
        }

        MATRIX result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Function to input matrix elements
    void inputMatrix() {
        cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Function to display matrix elements
    void displayMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m, n;

    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> m >> n;

    MATRIX mat1(m, n);
    MATRIX mat2(m, n);

    cout << "Input matrix 1:\n";
    mat1.inputMatrix();

    cout << "Input matrix 2:\n";
    mat2.inputMatrix();

    try {
        MATRIX result = mat1 + mat2;

        cout << "Matrix 1:\n";
        mat1.displayMatrix();

        cout << "Matrix 2:\n";
        mat2.displayMatrix();

        cout << "Result of Matrix 1 + Matrix 2:\n";
        result.displayMatrix();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
