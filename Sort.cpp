//
// Created by 黎炜堂 on 2021/12/11.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//测试数组
int Array[10] = {9, 4, 6, 2, 1, 7, 5 ,3 ,8, 0};
const int ArrayLen = 10000;
int RandomArray[ArrayLen];
//生成随机数函数
void MemsetRandomArray(int *Array) {
    srand(1);
    for (int i = 0;i < ArrayLen;i++) RandomArray[i] = rand();
}

int Count = 0;  //  记录交换了多少次
//函数声明
template<class T>
void Swap(T&, T&);
template<class T>
void ShowArray(T*, int);
template<class T>
void SelectSort(T*, int);
template<class T>
void InsertSort(T*, int);
template<class T>
void ShellSort(T*, int);
template<class T>
void MergeSort(T*, int);


/*int main() {
    return 0;
}*/
// 交换函数
template<class T>
void Swap (T& a, T& b) {
    Count++;
    T temp = a;
    a = b;
    b = temp;
}

//输出数组到屏幕上
template<class T>
void ShowArray(T* Array, int len) {
    int j = 0;
    for (int i = 0;i < len;i++) {
        cout << Array[i] << "\t";
        if (j++ == 4) {
            cout << endl;
            j = 0;
        }
    }
    cout << endl;
    cout << "Swap Count is : " << Count << endl;
}

//选择排序
template<class T>
void SelectSort(T* Array, int len) {
    for (int i = 0;i < len;i++) {
        int MinNumIndex = i;
        for (int j = i + 1;j < len;j++) {
            if (Array[MinNumIndex] > Array[j]) MinNumIndex = j;
        }
        Swap(Array[MinNumIndex], Array[i]);
    }
    return;
}

//插入排序
template<class T>
void InsertSort(T* Array, int len) {
    for (int i = 1;i < len;i++) {
        for (int j = i;j > 0;j--) {
            //当我前一个较大时，就交换
            if (Array[j] < Array[j - 1]) {
                Swap(Array[j - 1], Array[j]);
            }
        }
    }
}

//希尔排序：插入排序的优化
//和插入排序不同的是，希尔排序把相隔h的数据分为一组，每一组都进行插入排序
//随着h的减少……直到h=1，此时变为插入排序，排序完成后，数组有序
//跟插入排序不同的地方在于，希尔排序能够减少数据交换的次数，因为插入排序每次只能移动一位
//即：随着h的减少，每组包含的关键词越来越多，当增量减少至1时，整个数组为一组，排序完成
template<class T>
void ShellSort(T* Array, int len) {
    int h = 1;
    while (h < len / 3) h = 3 * h;
    while (h >= 1) {
        for (int i = h;i < len;i++) {
            for (int j = i;j >= h;j -= h) {
                if(Array[j] < Array[j - h]) Swap(Array[j], Array[j - h]);
                else break;
            }
        }
        h /= 3;
    }
}

//归并排序
template<class T>
void MergeSort(T* Array, int len) {

}
