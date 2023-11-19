#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

#define PI 3.14159265
#define N 1000
#define TOL 0.001

// 定义矩阵类型为二维向量
typedef std::vector<std::vector<double>> Matrix;

double func1(vector<double> x) {
    double f = 3 * x[0] - cos(x[1] * x[2]) - 0.5;
    return f;
}

double func2(vector<double> x) {
    double f = x[0] * x[0] - 81 * (x[1] + 0.1) * (x[1] + 0.1) + sin(x[2]) + 1.06;
    return f;
}

double func3(vector<double> x) {
    double f = exp(-x[0] * x[1]) + 20 * x[2] + (10 * PI - 3) / 3;
    return f;
}

vector<function<double(vector<double>)>> functions = {
    func1,
    func2,
    func3
};

vector<double> functionSystem(vector<double> x) {
    vector<double> f(x.size(), 0.0);
    for (int i = 0; i < x.size(); i++) {
        f[i] = functions[i](x);
    }
    return f;
}

double func1Derivative1(vector<double> x) {
    double f = 3;
    return f;
}

double func1Derivative2(vector<double> x) {
    double f = x[2] * sin(x[1] * x[2]);
    return f;
}

double func1Derivative3(vector<double> x) {
    double f = x[1] * sin(x[1] * x[2]);
    return f;
}

double func2Derivative1(vector<double> x) {
    double f = 2 * x[0];
    return f;
}

double func2Derivative2(vector<double> x) {
    double f = -162 * (x[1] + 0.1);
    return f;
}

double func2Derivative3(vector<double> x) {
    double f = cos(x[2]);
    return f;
}

double func3Derivative1(vector<double> x) {
    double f = -x[1] * exp(-x[0] * x[1]);
    return f;
}

double func3Derivative2(vector<double> x) {
    double f = -x[0] * exp(-x[0] * x[1]);
    return f;
}

double func3Derivative3(vector<double> x) {
    double f = 20;
    return f;
}

Matrix JacobiMatrix(vector<double> x) {
    int n = x.size();
    Matrix J(n, vector<double>(n, 0.0));
    J[0][0] = func1Derivative1(x);
    J[0][1] = func1Derivative2(x);
    J[0][2] = func1Derivative3(x);
    J[1][0] = func2Derivative1(x);
    J[1][1] = func2Derivative2(x);
    J[1][2] = func2Derivative3(x);
    J[2][0] = func3Derivative1(x);
    J[2][1] = func3Derivative2(x);
    J[2][2] = func3Derivative3(x);
    return J;
}

vector<double> vectorPlusMinus(vector<double> a, vector<double> b, int calculationMode) {
    int n = b.size();
    int m = a.size();

    vector<double> ab(m, 0.0);

    if (m != n) {
        if (calculationMode == 1)
            cout << "The addition of a and b is invalid." << endl;
        if (calculationMode == -1)
            cout << "The subtraction of a and b is invalid." << endl;
        return ab;
    }
    if (calculationMode != 1 && calculationMode != -1) {
        cout << "The calculation mode is undetermined." << endl;
        return ab;
    }

    for (int i = 0; i < m; i++) {
        ab[i] += a[i] + b[i] * calculationMode;
    }
    return ab;
}

double vectorNorm2(vector<double> w) {
    double alpha = 0;
    for (int i = 0; i < w.size(); i++) {
        alpha += w[i] * w[i];
    }
    alpha = sqrt(alpha);
    return alpha;
}

vector<double> GaussSeidelIteration(int equationN, vector<vector<double>> matrixA, vector<double> b, vector<double> initialX) {
    int n = equationN;
    vector<vector<double>> A = matrixA;
    vector<double> x0 = initialX;
    vector<double> x(n, 0.0);

    for (int k = 0; k < N; k++) {
        double error = 0;
        for (int i = 0; i < n; i++) {
            x[i] = b[i];
            for (int j = 0; j < i; j++) {
                x[i] -= A[i][j] * x[j];
            }
            for (int j = i + 1; j < n; j++) {
                x[i] -= A[i][j] * x0[j];
            }
            x[i] /= A[i][i];
            error += abs(x[i] - x0[i]);
        }
        if (error < TOL) {
            // cout << "The solution of x is (" << x[0];
            // for (int i = 1; i < n; i++) {
            //     cout << ", " << x[i];
            // }
            // cout << ").";
            return x;
        }
        for (int i = 0; i < n; i++) {
            x0[i] = x[i];
        }
    }
    cout << "Maximum number of iterations exceeded.";
    return x;
}

vector<double> NewtonMethodForSystems(vector<double> initialX) {
    int k = 1;
    vector<double> x = initialX;
    while (k <= N) {
        vector<double> F = functionSystem(x);
        // cout << "F: " << F[0];
        // for (int i = 1; i < x.size(); i++) {
        //     cout << ", " << F[i];
        // }
        // cout << ")" << endl;
        Matrix J = JacobiMatrix(x);
        // for(int j = 0; j < x.size(); j++){
        //     cout << "J: " << J[j][0];
        //     for (int i = 1; i < x.size(); i++) {
        //         cout << ", " << J[j][i];
        //     }
        //     cout << ")" << endl;
        // }
        vector<double> b = F;
        for (int i = 0; i < b.size(); i++) {
            b[i] = -b[i];
        }
        vector<double> x0(x.size(), 0.0);
        vector<double> y = GaussSeidelIteration(b.size(), J, b, x0);
        x = vectorPlusMinus(x, y, 1);
        // cout << "x: " << x[0];
        // for (int i = 1; i < x.size(); i++) {
        //     cout << ", " << x[i];
        // }
        // cout << ")" << endl;
        if (vectorNorm2(y) < TOL) {
            cout << "The solution is (" << x[0];
            for (int i = 1; i < x.size(); i++) {
                cout << ", " << x[i];
            }
            cout << ")";
            return x;
        }
        k++;
    }
    cout << "Maximum number of iterations exceeded.";
    return x;
}

int main() {
    vector<double> initialX = { 0.1, 0.1, -0.1 };
    vector<double> x = NewtonMethodForSystems(initialX);
    return 0;
}