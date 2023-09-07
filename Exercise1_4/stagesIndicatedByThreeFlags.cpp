/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-05 18:01:39
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-06 10:58:45
 * @FilePath: \Numerical Analysis Exercise\Exercise1_4\stagesIndicatedByThreeFlags.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<cmath>

int main(){
    int n, N;
    std::cout << "input n, N:";
    std::cin >> n >> N;
    double s, S, y, Y, lambda, x[n];
    std::cout << "\ninput x1,...,xn";
    for(int i = 0; i < n; i++){
        std::cin >> x[i];
    }
    std::cout << "\ninput s, S, y, Y, lambda:";
    std::cin >> s >> S >> y >> Y >> lambda;
    if(n <= 0){
        std::cout << "The integer n must be positive.\n";
    }
    else if(n >= N){
        std::cout << "The integer n is too large.\n";
    }
    int flag1 = 1, flag2 = 0, flag3 = 0;
    int done = 0, i = 1;
    double sum = 0, norm = 0;
    while(i <= n && flag1 == 1){
        if(std::abs(x[i]) < y){
            sum += (S*x[i])*(S*x[i]);
            i++;
        }
        else
            flag1 = 0;
    }
    if(i > n){
        norm = std::sqrt(sum)/S;
        done = 1;
    }
    else{
        sum = sum/S/S;
        flag2 = 1;
    }
    while(i <= n && flag2 == 1){
        if(std::abs(x[i]) < Y){
            sum += x[i]*x[i];
            i++;
        }
        else
            flag2 = 0;
    }
    if(done == 0){
        if(i > n){
            norm = std::sqrt(sum);
            done = 1;
        }
        else{
            sum = sum*s*s;
            flag3 == 1;
        }
    }
    while(i <= n && flag3 == 1){
        sum = sum + (s*x[i])*(s*x[i]);
        i++;
    }
    if(done = 0){
        if(std::sqrt(sum) < (lambda*s)){
            norm = std::sqrt(sum)/s;
            done = 1;
        }
        else
            sum = lambda;
    }
    if(done == 1){
        std::cout << "Norm is " << norm;
    }
    else{
        std::cout << "Norm >= " << norm << ", overflow occured";
    }
    return 0;
}