//
// Created by Administrator on 2022/1/1.
//
#include <iostream>
#include<conio.h>
using namespace std;
void one(int);
void two();
int three(int);
void zhu()
{
    int a = 0;
    int n = 1;
    cout << "\t" << "1.开始游戏" << endl;
    cout << endl;
    cout << "\t" << "2.查看游戏规则" << endl;
    cout << endl;
    cout << "\t"<<"3.设置游戏难度" << endl;
    cout << endl;
    cout << "\t"<<"4.退出游戏" << endl;
    cin >> a;
    switch (a)
    {
        case 1:
            one(n);
            break;
        case 2:
            two();
            break;
        case 3:
            three(n);
            break;
        case 4:break;
        default:
            break;
    }
}
void one(int n)
{
    int num = 0, p = 0;//引入两个变量，num记录相同数字个数，p记录位置相同个数，p<=num
    int a = 0;
    int* p1 = new int[n];//随机数数组
    int* p2 = new int[n];//用户输入的数组
    for (int i=0;i<n;i++)
    {
        p1[i] = (rand() % (9 - 1 + 1)) + 1;
    }

    while ( a==0 )
    {
        cout << "请输入数字：";
        for (int i = 0; i < n; i++)//用户输入
        {
            int a = 0;
            cin >> a;
            p2[i] = a;
        }
        for (int i = 0; i < n; i++)//进行一次判定
        {
            for (int b = 0; b < n; b++)
            {
                if (p1[i]==p2[a])
                {
                    num += 1;
                    if (i==a)
                    {
                        p += 1;
                    }
                }
            }
        }
        if (num==n&&p==n)
        {
            a = 1;
            cout << "恭喜你通关了！" << endl;
            cout << "按ESC返回主页面" << endl;
            char c = getch();
            if (c == 27)
            {
                zhu();
            }
            else
            {
                cout << "请输入正确指令！";
            }
        }
        else
        {
            cout << "很可惜没有全部猜对" << endl;
            cout << "您猜对了" << num << "个数字" << endl;
            cout << "位置相同的有" << p << "个" << endl;
        }
    }
}
void two()
{
    cout << "游戏开始前，用户可通过难度设置(3)设置随机数个数，"
            "游戏开始时，系统会根据难度生成n个随机数，每个数"
            "都有相应位置,每个数字范围为1-9，用户可通过系统提"
            "示,进行多次猜数字操作，直到完全猜对为止！"
            "(温馨提示：难度代表猜数字个数，例：难度为1，则个数为1)";
    "(如不设置难度，则系统默认为1.)";
    cout << endl;
    cout << "按ESC返回主页面" << endl;
    char ch = getch();
    if (ch == 27)
    {
        zhu();
    }
    else
    {
        cout << "请输入正确指令！";
    }

}
int three(int n)
{
    cout << "共有1-5个难度等级" << endl;
    cout << "请输入难度等级：";
    int i = 1;
    while ( i==1 )
    {
        cin >> n;
        if (n <= 0 && n > 5)
        {
            cout << "请输入一个正确的数字:";
            i = 1;
            cin >> n;
        }
        else
        {
            break;
        }
    }
    cout << "按ESC返回主页面" << endl;
    char c = getch();
    if (c==27)
    {
        zhu();
    }
    else
    {
        cout << "请输入正确指令！";
    }
    return n;
}
int main()
{
    zhu();
    return 0;

}


