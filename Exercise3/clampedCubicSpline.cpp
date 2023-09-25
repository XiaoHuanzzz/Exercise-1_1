/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-24 23:51:44
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-25 13:42:41
 * @FilePath: \Exercise3\clampedCubicSpline.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>

using namespace std;

vector<vector<double>> clampedCubicSpline(vector<double> x, vector<double> y, double FPO, double FPN){
    int n = x.size()-1;
    // S按行为abcd
    vector<vector<double>> S(4, std::vector<double>(n+1, 0.0));
    vector<double> h(n, 0.0);
    for(int i = 0; i < n; i++){
        h[i] = x[i+1]-x[i];
        cout << h[i];
        S[0][i] = y[i];
    }
    S[0][n] = y[n];

    vector<double> alpha(n+1, 0.0);
    alpha[0] = 3*(S[0][1]-S[0][0])/h[0]-3*FPO;
    alpha[n] = 3*FPN-3*(S[0][n]-S[0][n-1])/h[n-1];
    cout << alpha[n];
    for(int i = 1; i < n; i++){
        alpha[i] = 3*(S[0][i+1]-S[0][i])/h[i] - 3*(S[0][i]-S[0][i-1])/h[i-1];
    }

    std::vector<double> l;
    std::vector<double> mu;
    std::vector<double> z;
    
    l.push_back(2*h[0]);
    mu.push_back(0.5); 
    z.push_back(alpha[0]/l[0]);
    
    for(int i = 1; i < n; i++){
        l.push_back(2*(x[i+1]-x[i-1]) - h[i-1]*mu[i-1]);
        mu.push_back(h[i]/l[i]);
        z.push_back(alpha[i] - h[i-1]*z[i-1]/l[i]);
        
    }

    l[n] = h[n-1]*(2-mu[n-1]); z[n] = (alpha[n]-h[n-1]*z[n-1])/l[n];
    S[2][n] = z[n]; 
    for(int j = n-1; j >= 0; j--){
        S[2][j] = z[j] - mu[j]*S[2][j+1];
        S[1][j] = (S[0][j+1]-S[0][j])/h[j] - h[j]*(S[2][j+1]+2*S[2][j])/3;
        S[3][j] = (S[2][j+1]-S[2][j])/(3*h[j]);
    }

    return S;
}

int main(){
    vector<double> x = {1.0, 2.0, 3.0, 4.0};
    vector<double> y = {1.5, 4.3, 2.6, 3.0};
    double FPO = 1.0, FPN = -1.0;
    vector<vector<double>> result = clampedCubicSpline(x, y, FPO, FPN);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < x.size()-1; j++)
            cout << "S_" << i << ',' << j << " = " << result[i][j] << endl;
    }
    return 0;
}
