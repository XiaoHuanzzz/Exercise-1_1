/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-17 19:34:02
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-17 19:54:52
 * @FilePath: \Exercise2_6\MullerMethod.cpp
 */
#include<iostream>
#include<cmath>

#define N 10000
#define TOL 1e-6

double function(double x){
    double f = x*x*x*x - 3*x*x*x + x*x + x + 1;
    return f;
}

double MullerMethod(double p0, double p1, double p2){
    double h1 = p1-p0;
    double h2 = p2-p1;
    double sigma1 = (function(p1)-function(p0))/h1;
    double sigma2 = (function(p2)-function(p1))/h2;
    double d = (sigma2-sigma1)/(h1+h2);
    int i = 3;
    while(i < N){
        double b = sigma2 + h2*d;
        double D = std::sqrt(b*b - 4*function(p2)*d);
        double E = (bool(b-D)*(b-D) < bool(b+D)*(b+D))? b-D : b+D;
        double h = -2*function(p2)/E;
        double p = p2 + h;
        if(std::abs(h) < TOL){
            std::cout << "The zero point is " << p << ", the procedure was successful.";
            return p;
            break;
        }
        std::cout << "The " << i << " step: p = " << p << std::endl;
        p0 = p1; p1 = p2; p2 = p;
        h1 = p1-p0; h2 = p2-p1;
        sigma1 = (function(p1)-function(p0))/h1; 
        sigma2 = (function(p2)-function(p1))/h2;
        d = (sigma2-sigma1)/(h1+h2);
        i++;
    }
    if(i > N){
        std::cout << "The method failed after N0 iterations, N0 = " << N << ". The procedure was failed.";
    }
}

int main(){
    double p0 = 1, p1 = 1.1, p2 = 1.2;
    double p = MullerMethod(p0, p1, p2);
    return 0;
}
