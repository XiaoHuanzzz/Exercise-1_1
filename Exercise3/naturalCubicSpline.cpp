/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-24 14:41:58
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-24 23:24:35
 * @FilePath: \Exercise3\naturalCubicSpline.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>

using namespace std;

vector<vector<double>> naturalCubicSpline(const vector<double> x, const vector<double> y){
    int n = x.size()-1;
    // S按行为abcd
    std::vector<std::vector<double>> S(4, std::vector<double>(n+1, 0.0));
    vector<double> h(n, 0.0);
    for(int i = 0; i < n; i++){
        h[i] = x[i+1]-x[i];
        S[0][i] = y[i];
    }
    S[0][n] = y[n];
    vector<double> alpha(n, 0.0);
    for(int i = 0; i < n; i++){
        alpha[i] = 3*(S[0][i+1]-S[0][i])/h[i] - 3*(S[0][i]-S[0][i-1])/h[i-1];
    }
    vector<double> l(n+1, 0.0), mu(n+1, 0.0), z(n+1, 0.0);
    l[0] = 1.0;
    for(int i = 1; i < n; i++){
        l[i] = 2*(x[i+1]-x[i-1]) - h[i-1]*mu[i-1];
        mu[i] = h[i]/l[i];
        z[i] = alpha[i] - h[i-1]*z[i-1]/l[i];
    }
    l[n] = 1.0;
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
    vector<vector<double>> result = naturalCubicSpline(x, y);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < x.size()-1; j++)
            cout << "S_" << i << ',' << j << " = " << result[i][j] << endl;
    }
    return 0;
}