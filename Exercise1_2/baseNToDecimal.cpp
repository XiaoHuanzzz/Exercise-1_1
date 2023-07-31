/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-30 15:45:12
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-07-31 17:05:53
 * @FilePath: \Numerical Analysis Exercise\Exercise1_2\baseNToDecimal.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

// 
int binaryToSign(int number){
    if(number == 0){
        return 1;
    }
    else if(number == 1){
        return -1;
    }
    else{
        std::cout << "not a binary number" << std::endl;
        return 0;
    }
}

// 计算位数
int countDigits(const std::vector<int>& customRadixBits, const int bits1, const int bits2, const int base){
    int digits[bits2] = {0};
    int sign = binaryToSign(customRadixBits[bits1]);
    for(int i = bits1+1; i < bits1 + bits2; i++){
        digits[i-bits1-1] = sign*customRadixBits[i];
    } 
    int bit = 0;
    int nthPowerOfBase = 1;
    for(int i = bits2 - 2; i >= 0; i--){
        bit += nthPowerOfBase * digits[i];
        nthPowerOfBase *= base;
    }
    return bit;
} 

double baseNToDecimal(const std::vector<int>& customRadixBits, const int bits1, const int bits2, const int base)
{
    int powerBit = countDigits(customRadixBits, bits1, bits2, base);
    std::vector<int> reverseBits;
    int integer = countDigits(customRadixBits, 0, bits1, base);
    // std::cout << integer << std::endl;
    double decimal = integer * 1.0 * pow(base, powerBit);
    return decimal;
}

// int main(int argc, char* argv[]){
//     std::vector<int> testVector = {0,1,1,0,0,1,0,0,1,1};
//     std::cout << countDigits(testVector, 5, 5, 3) << std::endl;
//     std::cout << baseNToDecimal(testVector, 5, 5, 3) << std::endl;
// }