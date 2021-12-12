//
// Created by Administrator on 2021/12/13.
//
#pragma once
#ifndef ALGORITHM_BIGNUMBER_H
#define ALGORITHM_BIGNUMBER_H

#include<string>
#include <iostream>
using namespace std;
class BigNumber {
private:
    string Integer;
    string Decimal;

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
    ostream& operator<<(const BigNumber& number);
    //重载输入运算符


};
#endif //ALGORITHM_BIGNUMBER_H
