/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-13 16:10:14
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-13 16:57:34
 * @FilePath: \Exercise5\TaylorMethodOfOrderFour.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

using namespace std;

#define N 10
#define PI 3.14159265358979

double func(double t, double y){
    double f = y*y/(1+t);
    return f;
}

double func1(double t, double y){
    double f = y*y*(2*y-1)/(1+t)/(1+t);
    return f;
}

double func2(double t, double y){
    double f = y*y*(6*y*(y-1)+2)/((t+1)*(t+1));
    return f;
}

double func3(double t, double y){
    double f = y*y*(y*(y*(y*24-36)+22)-6)/((t+1)*(t+1)*(t+1));
    return f;
}

vector<vector<double>> TaylorFour(double a, double b, double initialValue, function<double(double, double)> func, function<double(double, double)> func1, function<double(double, double)> func2, function<double(double, double)> func3){
    vector<vector<double>> result(2, vector<double>(N+1, 0.0));
    double t = a, w = initialValue;
    result[0][0] = t; result[1][0] = w;
    cout << "The approximations are (" << t << ", " << w << ")";
    double h = (b-a)/N;
    for(int i = 0; i <= N; i++){
        t += h;
        w += h*(func(t, w) + (h/2)*(func1(t,w) + (h/3)*(func2(t, w) + (h/4)*func3(t, w))));
        result[0][i] = t; result[1][i] = w;
        cout << "(" << t << "," << w << ")";
    }
    return result;
}

int main(){
    double a = 1, b = 2, initialvalue = -1/log(2);
    vector<vector<double>> result = TaylorFour(a, b, initialvalue, func, func1, func2, func3);
    return 0;
}