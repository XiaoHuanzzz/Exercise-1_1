#include<iostream>
#include<vector>
#include<functional>
#include<cmath>
#include<complex>

using namespace std;

#define PI 3.14159265358979
#define TOL 0.001
#define N 1110

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

int vectorNormInfPos(vector<double> x){
    int maxPos = 0, p = 0;
    double tempMax = abs(x[0]);
    while(1){
        if(tempMax < abs(x[p])){
            tempMax = abs(x[p]);
            maxPos = p;
        }
        p++;
        if(p == x.size()){
            break;
        }
    }
    return maxPos;
}

vector<double> numVecMultiplier(double num, vector<double> vec){
    vector<double> numVec = vec;
    for(int i = 0; i < vec.size(); i++){
        numVec[i] *= num;
    }
    return numVec;
}

vector<double> powerMethod(vector<vector<double>> A, vector<double> initialX){
    vector<double> x = initialX;
    int k = 1;
    int n = A.size();
    int maxPos = vectorNormInfPos(x);
    double tempMax = x[maxPos];
    for(int i = 0; i < n; i++){
        x[i] /= tempMax;
    }

    // cout << "x: " << x[0];
    // for(int i = 1; i < x.size(); i++){
    //     cout << ", " << x[i];
    // }
    // cout << endl;

    while(k <= N){
        vector<double> y = matrixVectorMultiplier(A, x);
        double mu = y[maxPos];
        int maxPos_ = vectorNormInfPos(y);
        double tempMax = y[maxPos_];
        // cout << "y: " << y[0];
        // for(int i = 1; i < x.size(); i++){
        //     cout << ", " << y[i];
        // }
        // cout << endl;
        if(tempMax == 0){
            cout << "Eigenvector: (" << x[0];
            for(int i = 1; i < x.size(); i++){
                cout << ", " << x[i];
            }
            cout << ")" << endl << "A has the eigenvalue 0, select a new vector x and restart.";
            x.insert(x.begin(), mu);
            return x;
        }
        vector<double> absoluteErr = vectorPlusMinus(x, numVecMultiplier(1/y[maxPos_], y), -1);
        double ERR = absoluteErr[vectorNormInfPos(absoluteErr)];
        x = numVecMultiplier(1/y[maxPos_], y);
        // cout << ERR << endl;
        if(abs(ERR) < TOL){
            // cout << "Eigenvalue: " << mu << endl;
            // cout << "Eigenvector: (" << x[0];
            // for(int i = 1; i < x.size(); i++){
            //     cout << ", " << x[i];
            // }
            // cout << ")" << endl;
            x.insert(x.begin(), mu);
            return x;
        }
        k++;
    }
    cout << "The maximum number of iterations exceeded.";
    return x;
}

vector<double> WielandtDeflation(vector<vector<double>> A, double lambda, vector<double> v, vector<double> x){
    int n = v.size();
    int i = vectorNormInfPos(v);
    vector<vector<double>> B(n-1, vector<double>(n-1, 0.0));
    if(i != 0){
        for(int k = 0; k < i; k++){
            for(int j = 0; j < i; j++){
                B[k][j] = A[k][j] - A[i][j]*v[k]/v[i];
            }
        }
    }
    if(i != 0 && i != n-1){
        for(int k = i; k <= n-2; k++){
            for(int j = 0; j < i; j++){
                B[k][j] = A[k+1][j] - A[i][j]*v[k+1]/v[i];
                B[j][k] = A[j][k+1] - A[i][k+1]*v[j]/v[i];
            }
        }
    }
    if(i != n-1){
        for(int k = i; k <= n-2; k++){
            for(int j = i; j <= n-2; j++){
                B[k][j] = A[k+1][j+1] - A[i][j+1]*v[k+1]/v[i];
            }
        }
    }
    vector<double> y = powerMethod(B, x);
    double mu = y[0];
    vector<double> w(n, 0.0);
    if(i != 0){
        for(int k = 0; k < i-1; k++){
            w[k] = y[k+1];
        }
    }
    w[i] = 0;
    if(i != n-1){
        for(int k = i+1; k <= n-1; k++){
            w[k] = y[k];
        }
    }
    vector<double> u(n, 0.0);
    for(int k = 0; k <= n-1; k++){
        for(int j = 0; j <= n-1; j++){
            u[k] += A[i][j]*w[j];
        }
        u[k] *= v[k]/v[i];
        u[k] += (mu-lambda)*w[k];
    }
    cout << "Eigenvalue: " << mu << endl;
    cout << "Eigenvector: (" << u[0];
    for(int i = 1; i < n; i++){
        cout << ", " << u[i];
    }
    cout << ")" << endl;
    u.insert(u.begin(), mu);
    return u;
}

int main(){
    vector<vector<double>> A = {{4, -1, 1}, {-1, 3, -2}, {1, -2, 3}};
    double lambda = 6.0;
    vector<double> v = {1, -1, 1};
    vector<double> x = {1.0/3.0, -1.0/6.0};
    vector<double> y = WielandtDeflation(A, lambda, v, x);
}