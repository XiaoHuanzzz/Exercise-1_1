/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-05 14:02:44
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-06 14:51:57
 * @FilePath: \Exercise4\RombergIntegration.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

#define PI 3.1415926535897932384626

using namespace std;

double func(double x){
    double f = sin(x) + x*(3*x - 4*(x + 5));
    return f;
}

vector<vector<double>> RombergIntegration(double a, double b, function<double(double)> func, int n){
    vector<vector<double>> R(3, vector<double>(n+1, 0.0));
    double h = b-a;
    R[1][1] = (func(a)+func(b))*h/2;
    cout << "R_1,1 = " << R[1][1] << endl;
    for(int i = 2; i <= n; i++){
        R[2][1] = R[1][1];
        for(int k = 0; k < pow(2, i-2); k++){
            R[2][1] += h*func(a+(k-0.5)*h);
        }
        R[2][1] /= 2;
        cout << "R_" << i << ",1 = " << R[2][1] << ", ";
        for(int j = 2; j <= i; j++){
            R[2][j] = R[2][j-1] + (R[2][j-1]-R[1][j-1])/(pow(4,j-1)-1);
            cout << "R_" << i << "," << j << " = " << R[2][j] << ", ";
        }
        cout << endl;
        h /= 2;
        for(int j = 1; j <= i; j++){
            R[1][j] = R[2][j];
        }
    }
    return R;
}

int main(){
    double a = 0, b = PI;
    int n = 16;
    vector<vector<double>> result = RombergIntegration(a, b, func, n);
    return 0;
}
