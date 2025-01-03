#include <iostream>

int main() {
    int rows, cols;

    // Input matrix dimensions
    std::cout << "Enter number of rows and columns: ";
    std::cin >> rows >> cols;

    // Dynamically allocate memory for matrix A and matrix B
    int** matrixA = new int*[rows];
    int** matrixB = new int*[rows];
    int** resultMatrix = new int*[rows];

    // Allocate memory for columns of each matrix
    for (int i = 0; i < rows; i++) {
        matrixA[i] = new int[cols];
        matrixB[i] = new int[cols];
        resultMatrix[i] = new int[cols];
    }

    // Input elements for Matrix A
    std::cout << "Enter elements for Matrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrixA[i][j];
        }
    }

    // Input elements for Matrix B
    std::cout << "Enter elements for Matrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrixB[i][j];
        }
    }

    // Perform matrix addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Output the result of addition
    std::cout << "Resultant Matrix after addition:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << resultMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] matrixA[i];
        delete[] matrixB[i];
        delete[] resultMatrix[i];
    }
    delete[] matrixA;
    delete[] matrixB;
    delete[] resultMatrix;

    return 0;
}



             //Excepetational Handling

// double divide(int a, int b) {
//     if (b == 0) {
//         throw invalid_argument("Division by zero is not allowed.");
//     }
//     return static_cast<double>(a) / b;
// }

// int main() {
//     try {
//         int num = 10, denom = 0;
//         cout << "Result: " << divide(num, denom) << endl;
//     } catch (const invalid_argument& e) {
//         cout << "Error: " << e.what() << endl;
//     }

//     return 0;
// }
