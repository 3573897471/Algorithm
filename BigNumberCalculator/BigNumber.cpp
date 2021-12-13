//
// Created by Administrator on 2021/12/13.
//

#include "BigNumber.h"

//构造函数
BigNumber::BigNumber() {
    //Integer = new string();
    //Decimal = new string();
}

BigNumber::BigNumber(const BigNumber &number) {
    Integer = number.Integer;
    Decimal = number.Decimal;
}
/*//重载加法运算符
BigNumber BigNumber::operator+(const BigNumber number) {

}
//重载减法运算符
BigNumber BigNumber::operator-(const BigNumber number) {

}
//重载乘法运算符
BigNumber BigNumber::operator*(const BigNumber number) {

}
//重载除法运算符
BigNumber BigNumber::operator/(const BigNumber number) {

}
//规格化输出：保留多少位小数
void BigNumber::RemindDecimalShow(int count) {

}*/
//重载输出运算符
ostream& operator<<(ostream& out, BigNumber& number) {
    out << number.Integer << "." << number.Decimal;
    return out;
}
//重载输入运算符
istream& operator>>(istream& in, BigNumber& number) {
    string Input;
    in >> Input;
    int PointIndex = Input.find(".45");
    cout << PointIndex <<endl;
    number.Integer = Input.substr(0, PointIndex);
    number.Decimal = Input.substr(PointIndex + 1, Input.length());
    return in;
}


void TestBigNumber() {
    BigNumber b1;    cin >> b1;
    cout << b1 << endl;

}

int main() {
    TestBigNumber();
    return 0;
}