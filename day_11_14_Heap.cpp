// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <exception>
#include <vector>
using namespace std;

double division(int a, int b)
{
    if (b == 0) {
        throw "division by zero condition.";
    }
    return a / b;
}


struct MyException :public exception
{
    const char* what() const throw()
    {
        return "C++ Exception";
    }
};


int h[101];
int n;

/*交换函数*/
void swap(int x, int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
}

/*向下调整函数*/
void shiftdown(int i)
{
    int t, flag = 0;
    while (i * 2 <= n && flag == 0)
    {
        //与该节点的左子节点比较
        if (h[i] < h[i * 2])
        {
            t = i * 2;
        }
        else {
            t = i;
        }
        //处理该节点的右子节点比较
        if (i * 2 + 1 <= n)
        {
            if (h[t] < h[i * 2 + 1])
            {
                t = i * 2 + 1;
            }
        }

        //如果有改变则交换两个节点，交换过后处理，交换后的节点同之后的节点。
        if (t != i)
        {
            swap(t, i);
            i = t;
        }
        else
        {
            flag = 1;
        }
    }
}

void CreateHeap(void)
{
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        shiftdown(i);
    }
}

int deletemax(void)
{
    int t;
    t = h[1];
    h[1] = h[n];
    n--;
    shiftdown(1);
    return t;
}

void HeapSort(void)
{
    while (n > 1)
    {
        swap(1, n);
        n--;
        shiftdown(1);
    }
}
template <typename T>
class MyHeap {
public:
    MyHeap(T* ptArray, int len) :array(ptArray), size(len)
    {
        //从第一个非叶子节点的节点开始
        for (int i = len / 2; i >= 1; i--)
        {
            shiftDown(i);
        }
    }

    void printHeapArray(void);
    void sortArray(void);

private:
    T* array;
    int size;
    void swap(int x, int y);
    void shiftDown(int index);
};

template <typename T>
void MyHeap<T>::swap(int x, int y)
{
    T z = array[x];
    array[x] = array[y];
    array[y] = z;
}

template <typename T>
void MyHeap<T>::shiftDown(int index)
{
    int t, flag = 0;
    if (index > size)    return;

    while (index * 2 <= size && flag == 0)
    {
        // 获取该下标 的元素,与左子节点比较，得到更大的元素节点的坐标
        if (array[index] < array[2*index])
        {
            t = 2 * index;
        }
        else
        {
            t = index;
        }

        if (index * 2 + 1 <= size)
        {
            //如果存在右子节点， 与上面更大的元素坐标t比较
            if (array[index * 2 + 1] > array[t])
            {
                t = index * 2 + 1;
            }
        }

        if (index != t)
        {
            swap(index, t);
            index = t;
        }
        else
        {
            flag = 1;
        }

    }
}

template <typename T>
void MyHeap<T>::printHeapArray(void)
{
    for (int i = 1; i <= size; i++)
    {
        cout << array[i];
    }
    cout << endl;
}

template <typename T>
void MyHeap<T>::sortArray(void)
{
    //为什么大于1？ 因为下标只支持到1
    while (size > 1)
    {
        swap(1, size);
        size--;
        shiftDown(1);
    }
}


int main()
{
    int i, num;
    //cin >> num;

    //for (i = 1; i <= num; i++)
    //{
    //    cin >> h[i];
    //}
    /*
    89
    44 56
    23 78 
    */
    h[1] = 89;
    h[2] = 44;
    h[3] = 56;
    h[4] = 23;
    h[5] = 78;
    num = 5;
    n = num;

    MyHeap<int> myHeap(h, num);
    myHeap.printHeapArray();
    myHeap.sortArray();
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
