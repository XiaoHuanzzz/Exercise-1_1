/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-27 22:56:11
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-07-30 05:49:00
 * @FilePath: \Numerical Analysis Exercise\Exercise1_2\test2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef DECIMAL_TO_BASE_N_H
#define DECIMAL_TO_BASE_N_H

#include <iostream>
#include <vector>
#include <limits>

int determineSign(double number) ;

int signFunction(double number) ;

std::vector<int> decimalToBaseN(double decimalNumber, int bits1, int bits2, int base) ;

#endif