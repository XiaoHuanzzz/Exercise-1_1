/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-16 14:56:47
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-16 15:30:45
 * @FilePath: \Exercise2_5\StefensenMethod.cpp
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

double steffensenMethod(double p0){
    int i = 1;
    while(i < N){
        double p1 = function(p0);
        double p2 = function(p1);
        double p = p0 - (p1-p0)*(p1-p0)/(p2-2*p1+p0);
        if(std::abs(p-p0) < TOL){
            std::cout << "The zero point is " << p << ", the procedure was successful.";
            return p;
            break;
        }
        std::cout << "The " << i << " step: p = " << p << std::endl;
        i++;
        p0 = p;
    }
    if(i == N){
        std::cout << "Method failed after N0 iterations, N0 =" <<  N << "Procedure completed unsuccessfully.";
    }
}

int main(){
    double p0 = 1;
    double p = steffensenMethod(p0);
    return 0;
}