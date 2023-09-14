/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-14 11:57:26
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-14 12:09:59
 * @FilePath: \Exercise2_3\NewtonMethod.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<cmath>

#define N 100000
#define TOL 0.00001

double function(double x){
    double f = sin(x)*x + cos(x);
    return f;
}

double derivativeFunction(double x){
    double f_ = cos(x)*x;
    return f_;
}

int main(){
    int i = 1;
    double p0 = 1;
    while(i <= N){
        double p = p0 - function((p0))/derivativeFunction(p0);
        if(std::abs(p - p0) < TOL){
            std::cout << "The zero point is " << p << ", the procedure was successful.";
            break;
        }
        std::cout << "The " << i << " step: p = " << p << std::endl;
        p0 = p;
        i++;
    }
    if(i > N){
        std::cout << "The method failed after N0 iterations, N0 = " << N << ". The procedure was failed.";
    }
    return 0;
}
