/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-30 15:45:12
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-07-31 12:35:09
 * @FilePath: \Numerical Analysis Exercise\Exercise1_2\baseNToDecimal.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef BASE_N_TO_DECIMAL_H
#define BASE_N_TO_DECIMAL_H

#include <iostream>
#include <vector>
#include <limits>

int binaryToSign(int number) ;

int countDigits(std::vector<int> customRadixBits, int bits1, int bits2, int base);

double baseNToDecimal(std::vector<int> customRadixBits, int bits1, int bits2, int base) ;

#endif