#include<iostream>
#include"extern.h"
using namespace std;

// extern "C" 
// {
//     #include "extern.h"
// }

void Display_c()
{
    Show();//在cpp中有函数重载会修饰函数名,但是show是c语言文件,因此链接失败
}


int main()
{

    Display_c();

    system("pause");
    return 0;
}