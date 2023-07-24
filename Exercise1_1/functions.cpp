/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-21 22:53:09
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-07-22 16:35:08
 * @FilePath: \Numerical Analysis Exercise\functions.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "functions.h"

double calculateDerivative(const std::function<double(double)>& func, double x, double epsilon) {
    // 计算函数在给定点x处的一阶导数
    double h = epsilon;
    double derivative = (func(x + h) - func(x)) / h;
    return derivative;
}

double calculateSecondDerivative(const std::function<double(double)>& func, double x, double epsilon) {
    // 计算函数在给定点x处的二阶导数
    double h = epsilon;
    double secondDerivative = (func(x + h) - 2.0 * func(x) + func(x - h)) / (h * h);
    return secondDerivative;
}
