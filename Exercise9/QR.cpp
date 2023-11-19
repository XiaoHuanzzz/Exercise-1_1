#include <iostream>
#include <vector>
#include <cmath>

// 定义矩阵类型为二维向量
typedef std::vector<std::vector<double>> Matrix;

// 打印矩阵
void printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// 计算向量的2范数
double norm(const std::vector<double>& vector) {
    double sum = 0.0;
    for (const auto& element : vector) {
        sum += element * element;
    }
    return std::sqrt(sum);
}

// 计算两个向量的点积
double dotProduct(const std::vector<double>& vector1, const std::vector<double>& vector2) {
    double sum = 0.0;
    for (size_t i = 0; i < vector1.size(); ++i) {
        sum += vector1[i] * vector2[i];
    }
    return sum;
}

// 对向量进行标准化
void normalize(std::vector<double>& vector) {
    double vectorNorm = norm(vector);
    for (auto& element : vector) {
        element /= vectorNorm;
    }
}

// 计算两个向量的外积
std::vector<double> outerProduct(const std::vector<double>& vector1, const std::vector<double>& vector2) {
    std::vector<double> result(vector1.size(), 0.0);
    for (size_t i = 0; i < vector1.size(); ++i) {
        result[i] = vector1[i] * vector2[i];
    }
    return result;
}

// 执行QR分解
void qrDecomposition(Matrix& matrix, Matrix& Q, Matrix& R) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();

    Q = matrix;
    R = Matrix(cols, std::vector<double>(cols, 0.0));

    for (size_t j = 0; j < cols; ++j) {
        std::vector<double> column(rows, 0.0);
        for (size_t i = 0; i < rows; ++i) {
            column[i] = Q[i][j];
        }

        for (size_t k = 0; k < j; ++k) {
            std::vector<double> qk(rows, 0.0);
            for (size_t i = 0; i < rows; ++i) {
                qk[i] = Q[i][k];
            }

            double dot = dotProduct(column, qk);
            for (size_t i = 0; i < rows; ++i) {
                column[i] -= dot * qk[i];
            }
        }

        normalize(column);

        for (size_t i = 0; i < rows; ++i) {
            Q[i][j] = column[i];
        }

        for (size_t k = j; k < cols; ++k) {
            std::vector<double> qj(rows, 0.0);
            for (size_t i = 0; i < rows; ++i) {
                qj[i] = Q[i][j];
            }

            R[j][k] = dotProduct(qj, matrix[k]);
        }
    }
}

int main() {
    Matrix A = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};

    Matrix Q, R;
    qrDecomposition(A, Q, R);

    std::cout << "Matrix Q:\n";
    printMatrix(Q);

    std::cout << "Matrix R:\n";
    printMatrix(R);

    return 0;
}