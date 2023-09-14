/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-14 14:42:21
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-14 19:13:42
 * @FilePath: \Exercise2_4\secantMethod.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<cmath>

#define N 100000
#define TOL 1e-6

double function(double x){
    double f = x*(x*(x-2)+3)-4 + sin(x);
    return f;
}

int main(){
    double p0 = 1, p1 = 2;
    double q0 = function(p0), q1 = function(p1);
    int i = 2;
    while(i <= N){
        double p = p1-q1*(p1-p0)/(q1-q0);
        if(std::abs(p-p1) < TOL){
            std::cout << "The zero point is " << p << ", the procedure was successful.";
            break;
        }
        std::cout << "The " << i << " step point is: " << p << std::endl;
        i++;
        p0 = p1;
        q0 = q1;
        p1 = p;
        q1 = function(p);
    }
    if(i == N){
        std::cout << "The method failed after N0 iterations, N0 = " << N << ", the procedure was failed.";
    }
    return 0;
}
