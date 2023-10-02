/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-02 14:58:28
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-02 16:20:34
 * @FilePath: \Exercise4\compositeSimpsonRule.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<functional>

using namespace std;

double compositeSimpsonRule(double a, double b, int n, std::function<double(double)> func){
    double h = (b-a)/n;
    double XI0 = func(a)+func(b);
    double XI1 = 0, XI2 = 0; // Summation of f(x2i−1) and f(x2i)
    for(int i = 0; i < n; i++){
        double X = a+i*h;
        if(i % 2 == 1)
            XI1 += func(X);
        else
            XI2 += func(X);
    }
    double XI = h*(XI0 + 2*XI2 + 4*XI1)/3;
    return XI;
}

double func(double x){
    double f = exp(x);
    return f;
}

int main(){
    double a = 0, b = 4;
    int n = 10;
    double XI = compositeSimpsonRule(a, b, n, func);
    cout << "The result of approximation by composite Simpson's rule is " << XI;
    return 0;
}