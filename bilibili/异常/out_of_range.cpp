#include<iostream>
#include<stdexcept>//异常头文件
using namespace std;

class Person
{
public:
    int age;
    
    Person(int age)
    {
        if(age<0||age>150)
        {
            throw out_of_range("年龄必须在0~150之间");
        }else{
            this->age=age;
        }
    }
};

void test01()
{
    try
    {
        Person p(151);
    }//catch(out_of_range &e)
    catch(exception &e)
    {
        cout<<e.what()<<endl;//打印异常错误提示信息
    }
}

int main()
{
    test01();
    return 0;
}