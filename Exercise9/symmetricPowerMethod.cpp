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

double innerProduct(vector<double> a, vector<double> b){
    double iP = 0;
    for(int i = 0; i < a.size(); i++){
        iP += a[i]*b[i];
    }
    return iP;
}

vector<double> symmetricPowerMethod(vector<vector<double>> A, vector<double> initialX){
    vector<double> x = initialX;
    int k = 1;
    int n = A.size();
    x = numVecMultiplier(1/vectorNorm2(x), x);
    while(k <= N){
        vector<double> y = matrixVectorMultiplier(A, x);
        double mu = innerProduct(x, y);
        if(vectorNorm2(y) == 0){
            cout << "Eigenvector: (" << x[0];
            for(int i = 1; i < x.size(); i++){
                cout << ", " << x[i];
            }
            cout << ")" << endl << "A has the eigenvalue 0, select a new vector x and restart.";
            x.insert(x.begin(), mu);
            return x;
        }
        vector<double> errVec = vectorPlusMinus(x, numVecMultiplier(1/vectorNorm2(y), y), -1);
        double err = vectorNorm2(errVec);
        x = numVecMultiplier(1/vectorNorm2(y), y);
        if(abs(err) < TOL){
            cout << "Eigenvalue: " << mu << endl;
            cout << "Eigenvector: (" << x[0];
            for(int i = 1; i < x.size(); i++){
                cout << ", " << x[i];
            }
            cout << ")" << endl;
            x.insert(x.begin(), mu);
            return x;
        }
        k++;
    }
    cout << "The maximum number of iterations exceeded.";
    return x;    
}

int main(){
    vector<vector<double>> A = {{4, -1, 1}, {-1, 3, -2}, {1, -2, 3}};
    vector<double> x = {1, 0, 0};
    vector<double> eigen = symmetricPowerMethod(A, x);
    return 0;
}