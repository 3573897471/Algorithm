//
// Created by Administrator on 2021/12/13.
//
#ifndef ALGORITHM_BIGNUMBER_H
#define ALGORITHM_BIGNUMBER_H

#include<string>
#include<cstring>
#include <iostream>
using namespace std;
class BigNumber {
private:
    string Integer;
    string Decimal;
    bool Flag = true;
public:
    //构造函数
    BigNumber();
    BigNumber(const BigNumber& number);
    //重载加法运算符
    BigNumber operator+(const BigNumber number);
    //重载减法运算符
    BigNumber operator-(const BigNumber number);
    //重载乘法运算符
    BigNumber operator*(const BigNumber number);
    //重载除法运算符
    BigNumber operator/(const BigNumber number);
    //规格化输出:保留多少位小数
    void RemindDecimalShow(int count);
    //重载输出运算符
    friend ostream& operator<<(ostream& out, BigNumber& number);
    //重载输入运算符
    friend istream& operator>>(istream& in, BigNumber& number);

};
#endif //ALGORITHM_BIGNUMBER_H
