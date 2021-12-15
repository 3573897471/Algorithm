//
// Created by Administrator on 2021/12/13.
//

#include "BigNumber.h"

//构造函数
BigNumber::BigNumber() {
    Integer = string();
    Decimal = string();
}

BigNumber::BigNumber(const BigNumber &number) {
    Integer = number.Integer;
    Decimal = number.Decimal;
    Flag = number.Flag;
}
//重载加法运算符
BigNumber BigNumber::operator+(const BigNumber number) {
    BigNumber temp;
    return temp;
}
//重载减法运算符
BigNumber BigNumber::operator-(const BigNumber number) {
    BigNumber temp;
    return temp;
}
//重载乘法运算符
BigNumber BigNumber::operator*(const BigNumber number) {
    BigNumber temp;
    return temp;
}
//重载除法运算符
BigNumber BigNumber::operator/(const BigNumber number) {
    BigNumber temp;
    return temp;
}
//规格化输出：保留多少位小数
void BigNumber::RemindDecimalShow(int count) {

}
//重载输出运算符
ostream& operator<<(ostream& out, BigNumber& number) {
    if (! number.Flag) out << "-";
    if (number.Decimal[number.Decimal.length() - 1] == '0') out << number.Integer;
    else out << number.Integer << "." << number.Decimal;
    return out;
}
//重载输入运算符
istream& operator>>(istream& in, BigNumber& number) {
    string Input;
    cin >> Input;
    //负数处理
    if (Input[0] == '-') number.Flag = false;

    int PointIndex = Input.find('.');
    //整数处理
    if (PointIndex == -1) {
        number.Integer = Input.substr(0, PointIndex);
        number.Decimal = '0';
    }
    else {
        //小数处理
        number.Integer = Input.substr(0, PointIndex);
        number.Decimal = Input.substr(PointIndex + 1, Input.length());
    }

    //对已经分割的整数和小数进行处理：规格化
    //1、整数部分：左边多余的0以及全部是0的情况下的规格化
    int IntegerZeroIndex = -1;
    for (int i = 0; i < number.Integer.length(); i++) {
        if (number.Integer[i] == '0') IntegerZeroIndex = i;
        else break;
    }
    if (IntegerZeroIndex == number.Integer.length() - 1) {
        number.Integer = '0';
    }
    else if (IntegerZeroIndex != -1) {
        number.Integer = number.Integer.substr(IntegerZeroIndex + 1, number.Integer.length());
    }
    //2、小数部分：右边有0以及全部是0的情况下的规格化
    int DecimalZeroIndex = number.Decimal.length();
    for (int i = number.Decimal.length() - 1;i >= 0;i--) {
        if (number.Decimal[i] == '0') DecimalZeroIndex = i;
        else break;
    }
    if (DecimalZeroIndex == 0) {
        number.Decimal = '0';
    }
    else if (DecimalZeroIndex != number.Decimal.length()) {
        number.Decimal = number.Decimal.substr(0, DecimalZeroIndex);
    }
    return in;
/*
 *  旧版本：没有做到规格化多余的0，比如整数左边的0，小数右边的0
    //通过小数点来确定是什么类型输入
    int PointIndex = Input.find('.');
    if (PointIndex == -1) {
        //整数情况
        number.Integer = Input;
        number.Decimal = '0';
    } else if (Input[PointIndex - 1] == '0') {
        //纯小数情况
        number.Integer = '0';
        number.Decimal = Input.substr(PointIndex + 1, Input.length());
    } else {
        //普通小数
        number.Integer = Input.substr(0, PointIndex);
        number.Decimal = Input.substr(PointIndex + 1, Input.length());
    }
    //如果是负数，则需要将负号删除，因为Flag已经记录了正负数信息
    if (number.Integer[0] == '-') number.Integer = number.Integer.substr(1, number.Integer.length());
    //删除整数部分和小数部分多余的0
    for (int i = 0;i < number.Integer.length();i++) {
        if (number.Integer[i] == 0 && number.Integer.length() != 1)
            number.Integer = number.Integer.substr(i + 1, number.Integer.length());
        else break;
    }
*/
}


void TestBigNumber() {
    BigNumber b1, b2;
    cin >> b1;
    //cin >> b2;
    //BigNumber b3 = b1 + b2;
    cout << b1 << endl;
    //cout << b3 << endl;

}

int main() {
    TestBigNumber();
    return 0;
}