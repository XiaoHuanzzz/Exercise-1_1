/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-25 11:21:03
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-07-31 17:08:49
 * @FilePath: \Numerical Analysis Exercise\Exercise1_2\NumericalErrorCalculator.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cmath>
#include <iostream>
#include <vector>

#include "decimalToBaseN.h"
#include "baseNToDecimal.h"

class NumericalErrorCalculator {
private:
    int base_;    // 进制
    int bits1_;    // 位数
    int bits2_;
    double value1_; // 第一个要进行运算的数
    double value2_; // 第二个要进行运算的数
    std::vector<int> customRadixBits1;
    std::vector<int> customRadixBits2;

    // Function to calculate absolute error
    // double absoluteError(double trueValue, double approxValue) {
    //     return std::abs(trueValue - approxValue);
    // }

    // // Function to calculate relative error
    // double relativeError(double trueValue, double approxValue) {
    //     return std::abs((trueValue - approxValue) / trueValue);
    // }

public:
    // Constructor
    NumericalErrorCalculator(int base, int bits1, int bits2, double value1, double value2)
        : base_(base), bits1_(bits1), bits2_(bits2), value1_(value1), value2_(value2) {
            customRadixBits1 = decimalToBaseN(value1, bits1, bits2, base);
            customRadixBits2 = decimalToBaseN(value2, bits1, bits2, base);
        }

    // Function to calculate addition error
    double calculateAdditionError() {
        std::vector<int> additionError;
        //计算位数差
        int bitsDifference = countDigits(customRadixBits1, bits1_, bits2_, base_) - countDigits(customRadixBits2, bits1_, bits2_, base_);
        // 位数差过大，直接return大的数
        if(bitsDifference >= bits1_){
            return value1_;
        }
        else if(bitsDifference <= -bits1_){
            return value2_;
        }
        // 位数差不大，进行计算
        else if(bitsDifference >= 0){
            for(int i = 1; i < bits1_-bitsDifference; i++){
                additionError.push_back(binaryToSign(customRadixBits1[0]) * customRadixBits1[i]);
            }
            for(int i = bits1_-bitsDifference; i < bits1_; i++){
                additionError.push_back(binaryToSign(customRadixBits1[0]) * customRadixBits1[i] + binaryToSign(customRadixBits2[0]) * customRadixBits2[i]);
            }
            additionError.insert(additionError.end(), customRadixBits1.begin()+bits1_, customRadixBits1.end());
        }
        else{
            for(int i = 1; i < bits1_-bitsDifference; i++){
                additionError.push_back(binaryToSign(customRadixBits2[0]) * customRadixBits2[i]);
            }
            for(int i = bits1_-bitsDifference; i < bits1_; i++){
                additionError.push_back(binaryToSign(customRadixBits2[0]) * customRadixBits2[i] + binaryToSign(customRadixBits1[0]) * customRadixBits1[i]);
            }
            additionError.insert(additionError.end(), customRadixBits2.begin()+bits1_, customRadixBits2.end());
        }
        double additionError_ = baseNToDecimal(additionError, bits1_, bits2_, base_);
        return additionError_;
    }
        
};

int main() {
    int base = 10;      // Specify the base (e.g., 10 for decimal)
    int bits1 = 4, bits2 = 2;       // Specify the number of bits (e.g., 4 for 4 bits)
    double value1 = 0.1; // Specify the first value for operations
    double value2 = 0.2; // Specify the second value for operations

    NumericalErrorCalculator calculator(base, bits1, bits2, value1, value2);

    std::cout << calculator.calculateAdditionError() <<std::endl;
    // calculator.calculateSubtractionError();
    // calculator.calculateMultiplicationError();
    // calculator.calculateDivisionError();

    return 0;
}
