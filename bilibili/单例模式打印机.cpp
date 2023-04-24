#include<iostream>
using namespace std;

class Printer
{
public:
    static Printer *getInstance()
    {
        return printer;//返回指针,提供只读接口
    }
private:
    Printer(){
        cout<<"打印机构造函数"<<endl;
    };//构造函数私有化
    
    Printer(const Printer &p){
        
    };//拷贝构造函数私有化
    
    static Printer *printer;//唯一实例化指针私有化
};

Printer *Printer::printer=new Printer;

void test01()
{
    Printer *p1=Printer::getInstance();
}

int main()
{
    cout<<"main函数调用"<<endl;
    test01();
    return 0;
}