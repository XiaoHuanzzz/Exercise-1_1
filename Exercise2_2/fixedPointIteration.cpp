/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-13 20:20:14
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-13 21:00:33
 * @FilePath: \Exercise2_2\fixedPointIteration.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<cmath>

#define N 100000
#define TOL 0.001

double function(double x){
    double f = pow(3, -x) ;
    return f;
}

int main(){
    int i = 0;
    double p0 = 0;
    while(i <= N){
        double p = function(p0);
        if(std::abs(p-p0) < TOL){
            std::cout << "The result is " << p << ", the procedure was successful.";
            break;
        }
        i++;
        p0 = p;
    }
    if(i >= N)
        std::cout << "The method failed after N0 iterations, N0 = " << N << ", the procedure was failed";
}
