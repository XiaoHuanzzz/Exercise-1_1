#include<iostream>
#include<vector>
#include<functional>
#include<cmath>
#include<complex>

using namespace std;

#define PI 3.14159265358979
#define TOL 0.001
#define N 10

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

vector<double> GaussianEliminationWithPartialPivoting(int equationN, vector<vector<double>> augmentedMatrixA){
    int n = equationN;
    vector<vector<double>> m(n, vector<double>(n, 0.0));
    vector<vector<double>> A = augmentedMatrixA;
    vector<double> x(n, 0.0);
    vector<int> nRow(n, 0);
    for(int i = 0; i < n; i++){
        nRow[i] = i;
    }
    for(int i = 0; i < n-1; i++){
        int p = i;
        int maxPos = i;
        double tempMax = abs(A[nRow[p]][i]);
        while(1){
            if(tempMax < abs(A[nRow[p]][i])){
                tempMax = abs(A[nRow[p]][i]);
                maxPos = p;
            }
            p++;
            if(p == equationN){
                break;
            }
        }
        if(tempMax == 0){
            cout << "No unique solution exists.";
            return x;
        }
        if(nRow[i] != nRow[maxPos]){
            int nCopy = nRow[i];
            nRow[i] = nRow[maxPos];
            nRow[maxPos] = nCopy;
        }
        for(int j = i+1; j < n; j++){
            m[nRow[j]][i] = A[nRow[j]][i]/A[nRow[i]][i];
            for(int k = 0; k < n+1; k++){
                A[nRow[j]][k] -= m[nRow[j]][i]*A[nRow[i]][k];
            }
        }
    }
    if(A[nRow[n-1]][nRow[n-1]] == 0){
        cout << "No unique solution exists." << endl;
        return x;
    }
    x[n-1] = A[nRow[n-1]][n]/A[nRow[n-1]][n-1];
    for(int i = n-2; i >= 0; i--){
        x[i] = A[nRow[i]][n];
        for(int j = i+1; j <= n-1; j++){
            x[i] -= A[nRow[i]][j]*x[j];
        }
        x[i] /= A[nRow[i]][i];
    }
    cout << "The solution is (" << x[0];
    for(int i = 1; i < x.size(); i++){
        cout << ", " << x[i];
    }
    cout << ")";
    return x;
}

vector<double> inversePowerMethod(vector<vector<double>> A, vector<double> initialX){
    vector<double> x = initialX;
    double q = innerProduct(x, matrixVectorMultiplier(A, x)) / innerProduct(x, x);
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
    // cout << ")" << endl;

    
    // cout << "q: " << q << endl;

    while(k <= N){
        vector<vector<double>> Aq(n, vector<double>(n+1, 0.0));
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                Aq[i][j] = A[i][j];
            }
            Aq[i][n] = x[i];
            Aq[i][i] -= q;
        }
        vector<double> y = GaussianEliminationWithPartialPivoting(n, Aq);
        double mu = y[maxPos];
        // cout << "mu:" <<  mu << endl;
        // cout << "y: (" << y[0];
        // for(int i = 1; i < y.size(); i++){
        //     cout << ", " << y[i];
        // }
        // cout << ")" << endl;

        int maxPos_ = vectorNormInfPos(y);
        
        vector<double> absoluteErr = vectorPlusMinus(x, numVecMultiplier(1/y[maxPos_], y), -1);
        double ERR = absoluteErr[vectorNormInfPos(absoluteErr)];
        x = numVecMultiplier(1/y[maxPos_], y);
        // cout << "x: (" << x[0];
        // for(int i = 1; i < x.size(); i++){
        //     cout << ", " << x[i];
        // }
        // cout << ")" << endl;
        
        if(abs(ERR) < TOL){
            mu = 1/mu + q;
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
    vector<vector<double>> A = {{-4, 14, 0}, {-5, 13, 0}, {-1, 0, 2}};
    vector<double> x = {1, 1, 1};
    // vector<vector<double>> A = {{4, -1, 1}, {-1, 3, -2}, {1, -2, 3}};
    // vector<double> x = {1, 0, 0};
    vector<double> eigen = inversePowerMethod(A, x);
    return 0;
}