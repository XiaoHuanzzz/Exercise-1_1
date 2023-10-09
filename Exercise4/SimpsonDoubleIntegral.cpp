/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-09 00:28:50
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-09 14:56:31
 * @FilePath: \Exercise4\SimpsonDoubleIntegral.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<cmath>
#include<vector>
#include<functional>

using namespace std;

#define TOL 0.00001
#define N 10000
#define PI 3.141592653589793238

double func(double x, double y){
    double f = sin(x)+cos(x);
    return f;
}

double lowerBoundFunc(double x){
    double f = x;
    return f;
}

double upperBoundFunc(double x){
    double f = 2*x;
    return f;
}

// approximate integral $\int_a^b\int_{c(x)}^{d(x)} f(x,y) dydx $
double SimpsonDoubleIntegral(double a, double b, int m, int n, function<double(double, double)> func, function<double(double)> lowerBoundFunc, function<double(double)> upperBoundFunc){
    double h1 = (b-a)/n; // Interval of column
    double result = 0;
    double endColumn = 0, evenColum = 0, oddColumn = 0;
    for(int i = 0; i <= n; i++){
        double x = a+i*h1;
        double h2 = (upperBoundFunc(x)-lowerBoundFunc(x))/m; // Interval of row
        double endRow = 0, evenRow = 0, oddRow = 0;
        for(int j = 0; j <= m; j++){
            double y = lowerBoundFunc(x) + j*h2;
            
            if(j == 0 || j == m)
                endRow += func(x, y);
            else if(j % 2 == 1)
                oddRow += func(x, y);
            else
                evenRow += func(x, y);
        }
        double column = (endRow + 2*evenRow + 4*oddRow)*h2/3;
        if(i == 0 || i == n)
            endColumn += column;
        else if(i % 2 == 1)
            oddColumn += column;
        else
            evenColum += column;
    }
    result = (endColumn + 2*evenColum + 4*oddColumn)*h1/3;
    cout << "The approximation is " << result;
    return result;
}

int main(){
    double a = 0, b = PI;
    int n = 8, m = 10;
    double J = SimpsonDoubleIntegral(a, b, m, n, func, lowerBoundFunc, upperBoundFunc);
}