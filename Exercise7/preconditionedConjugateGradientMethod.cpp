#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define N 1000
#define TOL 0.0001

using namespace std;

vector<double> matrixVectorMultiplier(vector<vector<double>> A, vector<double> b){
    int n = b.size();
    int m = A[0].size();
    
    vector<double> Ab(m, 0.0);

    if(m != n){
        cout << "The multiple of A and b is invalid." << endl;
        return Ab;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            Ab[i] += A[i][j]*b[j];
        }
    }
    return Ab;
}

vector<double> vectorPlusMinus(vector<double> a, vector<double> b, int calculationMode){
    int n = b.size();
    int m = a.size();
    
    vector<double> ab(m, 0.0);

    if(m != n){
        if(calculationMode == 1)
            cout << "The addition of a and b is invalid." << endl;
        if(calculationMode == -1)
            cout << "The subtraction of a and b is invalid." << endl;
        return ab;
    }
    if(calculationMode != 1 && calculationMode != -1){
        cout << "The calculation mode is undetermined." << endl;
        return ab;
    }

    for(int i = 0; i < m; i++){
        ab[i] += a[i]+b[i]*calculationMode;
    }
    return ab;
}

vector<vector<double>> matrixTranspose(vector<vector<double>> A){
    int n = A.size();
    int m = A[0].size();
    vector<vector<double>> At(m, vector<double>(n, 0.0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            At[i][j] = A[j][i];
        }
    }
    return At;
}

double vectorNorm2(vector<double> w){
    double alpha = 0;
    for(int i = 0; i < w.size(); i++){
        alpha += w[i]*w[i];
    }
    alpha = sqrt(alpha);
    return alpha;
}

vector<double> numVecMultiplier(double num, vector<double> vec){
    vector<double> numVec = vec;
    for(int i = 0; i < vec.size(); i++){
        numVec[i] *= num;
    }
    return numVec;
}

vector<double> preconditionedConjugateGradientMethod(int equationN, vector<vector<double>> matrixA, vector<vector<double>> preconditioningMatrixC, vector<double> initialX, vector<double> b){
    vector<vector<double>> A = matrixA, C = preconditioningMatrixC;
    vector<double> x = initialX;
    vector<double> r = vectorPlusMinus(b, matrixVectorMultiplier(A, x), -1);
    vector<double> w = matrixVectorMultiplier(C, r);
    vector<double> v = matrixVectorMultiplier(matrixTranspose(C), w);
    double alpha = 0;
    for(int i = 0; i < x.size(); i++){
        alpha += w[i]*w[i];
        // cout << v[i] << ' ' << w[i] << ' ' << r[i] << endl;
    }
    for(int k = 0; k < N; k++){
        if(vectorNorm2(v) < TOL){
            cout << "The solution of x is: (" << x[0];
            for(int i = 1; i < x.size(); i++){
                cout << ", " << x[i];
            }
            cout << "). " << endl;
            cout << "The residual of x is: (" << r[0];
            for(int i = 1; i < r.size(); i++){
                cout << ", " << r[i];
            }
            cout << "). " << endl;
            return x;
        }
        vector<double> u = matrixVectorMultiplier(A, v);
        double t = 0;
        for(int i = 0; i < u.size(); i++){
            t += v[i]*u[i];
        }
        t = alpha/t;
        x = vectorPlusMinus(x, numVecMultiplier(t, v), 1);
        r = vectorPlusMinus(r, numVecMultiplier(t, u), -1);
        w = matrixVectorMultiplier(C, r);
        double beta = 0;
        for(int i = 0; i < x.size(); i++){
            beta += w[i]*w[i];
            // cout << v[i] << ' ' << w[i] << ' ' << r[i] << endl;
        }
        if(beta < TOL){
            if(vectorNorm2(r) < TOL){
                cout << "The solution of x is: (" << x[0];
                for(int i = 1; i < x.size(); i++){
                    cout << ", " << x[i];
                }
                cout << "). " << endl;
                cout << "The residual of x is: (" << r[0];
                for(int i = 1; i < r.size(); i++){
                    cout << ", " << r[i];
                }
                cout << "). " << endl;
                return x;
            }
        }
        double s = beta/alpha;
        v = vectorPlusMinus(matrixVectorMultiplier(matrixTranspose(C), w), numVecMultiplier(s, v), 1);
        alpha = beta;
    }
    cout << "Maximum number of iterations exceeded." << endl;
    return x;
}

int main(){
    int equationN = 3;
    vector<vector<double>> A = {{4, 3, 0}, {3, 4, -1}, {0, -1, 4}};
    vector<double> b = {24, 30, -24};
    vector<vector<double>> C = {{1,0,0},{0,1,0},{0,0,1}};
    vector<double> x0 = {2,2,-2};
    vector<double> x = preconditionedConjugateGradientMethod(equationN, A, C, x0, b);
    return 0;
}