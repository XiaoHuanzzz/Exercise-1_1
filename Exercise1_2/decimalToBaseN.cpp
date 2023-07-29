/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-27 22:56:11
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-07-29 21:45:56
 * @FilePath: \Numerical Analysis Exercise\Exercise1_2\test2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <limits>

int determineSign(double number) {
    if (number >= 0) {
        return 0; // 输入的数为正，返回0
    } else {
        return 1; // 输入的数为负，返回1
    }
}

int signFunction(double number) {
    if (number > 0) {
        return 1; // 正数返回1
    } else if (number < 0) {
        return -1; // 负数返回-1
    } else {
        return 0; // 零返回0
    }
}

std::vector<int> decimalToBaseN(double decimalNumber, int bits1, int bits2, int base) {
    std::vector<int> customRadixBits;
    std::vector<int> powerBits;
    // customRadixBits.push_back(determineSign(decimalNumber));  // 符号位
    // std::cout << customRadixBits[0] << std::endl;

    int integerPart = static_cast<int>(abs(decimalNumber)); //整数部分
    double decimalPart = std::abs(decimalNumber) - static_cast<double>(integerPart);  //小数部分

    // 整数部分转换
    int precision1 = bits1;  // 位数上限bits1
    while (integerPart > 0) {
        int remainder = integerPart % base;
        customRadixBits.insert(customRadixBits.begin(), remainder);
        integerPart /= base;
        precision1--;
    }
    // 整数部分使用了bits1-precision1位，若precision1>0，则补充小数位；若precision1<=0，结束
    // std::cout << precision1 << std::endl;
    if(precision1 == 0){
        for(int i = 1; i <= bits2; i++){
            customRadixBits.push_back(0);
            customRadixBits.insert(customRadixBits.begin(), 0);
        }
        return customRadixBits;
    }
    // 幂的部分
    int power = precision1;
    int absPower = abs(power);
    int precision2 = bits2;  // 位数上限bits2 
    while (absPower > 0 && precision2 > 0) {
        int remainder = absPower % base;
        powerBits.insert(powerBits.begin(), remainder);
        absPower /= base;
        precision2--;
    }
    // std::cout << powerBits[2] << powerBits[1] << std::endl;
    // 补充0位
    for(int i = 1; i <= precision2; i++){
        powerBits.insert(powerBits.begin(), 0);
    }
    // 补充符号位
    powerBits.insert(powerBits.begin(), determineSign(power));
    if(precision2 == 0)// 超出上限，输出符号位+11111111
    {
        std::vector<int> infVector;
        infVector.resize(bits1+bits2-1, 1);
        infVector.insert(infVector.begin(), determineSign(decimalNumber));
        return infVector;
    }
    // 小数部分转换
    while (decimalPart > 0 && precision1 > 0) {
        decimalPart *= base;
        int bit = static_cast<int>(decimalPart);
        customRadixBits.push_back(bit);
        decimalPart -= bit;
        precision1--;
    }
    // 符号位
    customRadixBits.insert(customRadixBits.begin(), determineSign(decimalNumber));
    // 按位数截断
    std::vector<int> truncatedVector;
    truncatedVector.assign(customRadixBits.begin(), customRadixBits.begin() + bits1);
    // 合并
    for (int num : powerBits) {
        truncatedVector.push_back(num);
    }

    return truncatedVector;
}

int main() {
    double decimalNumber = -567578797978957.7686;
    std::vector<int> customRadixBits = decimalToBaseN(decimalNumber, 10, 2, 3);

    // Display the binary representation
    std::cout << decimalNumber << " in binary is: ";
    for (int bit : customRadixBits) {
        std::cout << bit;
    }
    std::cout << std::endl;

    return 0;
}
