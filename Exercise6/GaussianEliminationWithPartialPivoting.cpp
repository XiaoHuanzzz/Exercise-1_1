#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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
        cout << "No unique solution exists.";
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

int main(){
    int equationN = 3;
    vector<vector<double>> augmentedMatrixA = {{1,3,1,4},{1,1,4,5},{0,1,5,6}};
    vector<double> x = GaussianEliminationWithPartialPivoting(equationN, augmentedMatrixA);
    return 0;
}
