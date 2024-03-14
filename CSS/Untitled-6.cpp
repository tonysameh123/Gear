#include <iostream>
#include <vector>

const int MAX_SIZE = 50;

int getRank(std::vector<std::vector<double>>& matrix, int rows, int cols) {
    int rank = std::min(rows, cols);

    for (int r = 0; r < rank; r++) {
        if (matrix[r][r] != 0) {
            for (int i = 0; i < rows; i++) {
                if (i != r) {
                    double factor = matrix[i][r] / matrix[r][r];
                    for (int j = r; j < cols; j++) {
                        matrix[i][j] -= factor * matrix[r][j];
                    }
                }
            }
        } else {
            bool reduced = false;
            for (int i = r + 1; i < rows; i++) {
                if (matrix[i][r] != 0) {
                    for (int j = 0; j < cols; j++) {
                        std::swap(matrix[i][j], matrix[r][j]);
                    }
                    reduced = true;
                    break;
                }
            }
            if (!reduced) {
                rank--;
                for (int i = 0; i < rows; i++) {
                    matrix[i][r] = matrix[i][rank];
                }
                r--;
            }
        }
    }
    return rank;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> rows >> cols;

    std::vector<std::vector<double>> matrix(MAX_SIZE, std::vector<double>(MAX_SIZE, 0));

    std::cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int rank = getRank(matrix, rows, cols);
    std::cout << "The rank of the matrix is: " << rank << std::endl;

    return 0;
}
