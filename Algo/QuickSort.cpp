#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

using namespace std;


template<typename Type>
void MySwap(Type& a, Type& b)
{
    Type temp = a;
    a = b;
    b = temp;
}

template<typename Type>
typename vector<Type>::size_type partition(vector<Type>& arr, typename vector<Type>::size_type left, typename vector<Type>::size_type right)
{
    // typedef typename vector<Type>::size_type SizeType;
    int small = left-1;
    int index = left;
    Type pivot = arr[right];
    while(index < right)
    {
        if(arr[index] < pivot)
        {
            if(arr[small+1] != arr[index])
            {
                MySwap(arr[small+1], arr[index]);
            }
            small++;
        }
        index++;
    }
    MySwap(arr[++small], arr[right]);
    return small;
}

template<typename Type>
void QuickSort(vector<Type>& arr, int left, int right)
{
    if(left >= right){
        return;
    }
    int mid = partition(arr, left, right);
    QuickSort(arr, left, mid-1);
    QuickSort(arr, mid+1, right);
}
template<typename Type>
void printArr(vector<Type> arr)
{
    for(Type t : arr){
        cout << t << " ";
    }
    cout << endl;
}

template<typename T, int SIZE>
vector<T> RandomArray(T min, T max)
{
    vector<T> arr;
    // 创建随机数生成器并初始化种子
    std::random_device rd;  // 获取随机种子
    std::mt19937 gen(rd()); // 以随机种子初始化梅森旋转算法生成器
    // 定义分布范围
    std::uniform_real_distribution<T> dis(min, max); // min到max之间的数
    for(int i = 0; i < SIZE; ++i)
    {
        arr.push_back(dis(gen));// 生成一个随机数
        // std::cout << "Random Number: " << random_number << std::endl; // 输出随机数
    }
    return arr;
}


int main()
{
    // vector<int> arr = {1,4,56,7,32,76,324,8,123,45,567,23};
    // vector<float> arr = {1.9,4.3,5.6,0.7,3.2,76.1,32.4,1.8,12.3,45.0,567.1,23};
    // vector<string> arr = {"dsf","gf","fdg","s",};
    vector<float> arr = RandomArray<float, 10000>(1.0, 100000.0);
    // printArr(arr);
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(arr, 0, arr.size()-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "耗时：" << duration.count() << "ms, 排序后：" << endl;
    QuickSort(arr, 0, arr.size()-1);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - end);
    cout << "耗时2：" << duration2.count() << "ms, 排序后：" << endl;
    // printArr(arr);
}
