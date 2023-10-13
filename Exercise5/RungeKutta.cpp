/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-13 12:01:34
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-13 12:18:04
 * @FilePath: \Exercise5\RungeKutta.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

using namespace std;

#define N 100
#define PI 3.14159265358979

double func(double x, double y){
    double f = sin(x) + cos(y);
    return f;
}

vector<vector<double>> RungeKutta(double a, double b, double initialValue, function<double(double, double)> func){
    double h = (b-a)/N;
    double t = a, omega = initialValue;
    vector<vector<double>> result(2, (vector<double>(N+1, 0.0)));
    result[0][0] = t; result[1][0] = omega;
    cout << "The approximations are (" << t << ", " << omega << ")";
    for(int i = 1; i <= N; i++){
        double K1 = h*func(t, omega);
        double K2 = h*func(t+h/2, omega+K1/2);
        double K3 = h*func(t+h/2, omega+K2/2);
        double K4 = h*func(t+h, omega+K3);
        omega += (K1+2*(K2+K3)+K4)/6;
        t += h;
        result[0][i] = t; result[1][i] = omega;
        cout << "(" << t << "," << omega << ")";
    }
    return result;
}

int main(){
    double a = 0, b = PI;
    double initialValue = 0;
    vector<vector<double>> result = RungeKutta(a, b, initialValue, func);
    return 0;
}