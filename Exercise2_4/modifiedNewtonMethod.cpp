/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-15 13:24:23
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-15 13:39:31
 * @FilePath: \Exercise2_4\modifiedNewtonMethod.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<cmath>

#define N 10000
#define TOL 1e-6

double function(double x){
    double f = x*(x*x+2)-3+4*sin(x)-5*cos(x);
    return f;
}

double derivativeFunction(double x){
    double f_ = 3*x*x+2+4*cos(x)+5*sin(x);
    return f_;
}

double secondDerivativeFunction(double x){
    double f__ = 6*x-4*sin(x)+5*cos(x);
    return f__;
}

double modifiedNewtonMethod(double p0){
    int i = 1;
    while(i <= N){
        double f0 = function(p0);
        double f0_ = derivativeFunction(p0);
        double f0__ = secondDerivativeFunction(p0);
        double p = p0 - f0*f0_/(f0_*f0_-f0*f0__);
        if(std::abs(p - p0) < TOL){
            std::cout << "The zero point is " << p << ", the procedure was successful.";
            return p;
            break;
        }
        std::cout << "The " << i << " step: p = " << p << std::endl;
        p0 = p;
        i++;
    }
    if(i > N){
        std::cout << "The method failed after N0 iterations, N0 = " << N << ". The procedure was failed.";
    }
}

int main(){
    double p0 = 1;
    double p = modifiedNewtonMethod(p0);
    return 0;
}
