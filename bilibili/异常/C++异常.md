# C++异常

## 异常基本概念

让一个函数在发现了自己无法处理的错误时抛出一个异常,然后它的(直接或间接)调用者能够处理这个问题,也就是将问题检测和问题处理相分离

异常处理就是处理程序中的错误.所谓错误是指在程序运行的过程中发生的一些异常事件(如0溢出,数组下标越界,所要读取的文件不存在,空指针,内存不足等)

C++的异常必须有函数进行处理,否则程序会中止

```c++
#include<iostream>
using namespace std;

int myDivision(int a,int b)
{
    if(b==0)
    {
        return -1;
    }
    return a/b;
}

void test01()
{
    int a=10;
    int b=0;
    
    //c语言处理异常,返回值不统一,返回值只有一个,无法区分是结果还是异常
    //int ret=myDivision(a,b);
    //if(ret==-1)
    //{
       // cout<<"异常"<<endl;
    //}
}

int main()
{
    test01();
    return 0;
}
```

