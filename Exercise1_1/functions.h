/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-21 22:52:58
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-07-21 22:53:04
 * @FilePath: \Numerical Analysis Exercise\function.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <functional>

double calculateDerivative(const std::function<double(double)>& func, double x, double epsilon = 1e-6);
double calculateSecondDerivative(const std::function<double(double)>& func, double x, double epsilon = 1e-6);

#endif // FUNCTIONS_H
