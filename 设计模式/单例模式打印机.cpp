#include<iostream>
using namespace std;

class Printer
{
public:
    static Printer *getInstance()
    {
        return printer;//返回指针,提供只读接口
    }
    
    void printerText(string text)
    {
        cout<<text<<endl;
        cnt++;
    }
    
    int cnt;//打印次数
    
private:
    Printer(){
        //cout<<"打印机构造函数"<<endl;
    };//构造函数私有化
    
    Printer(const Printer &p){
        
    };//拷贝构造函数私有化
    
    static Printer *printer;//唯一实例化指针私有化
};

Printer *Printer::printer=new Printer;

void test01()
{
    Printer *p1=Printer::getInstance();
    p1->printerText("summer");
    cout<<"打印机打印次数:"<<p1->cnt<<endl;
    
    Printer *p2=Printer::getInstance();
    p2->printerText("u.");
    cout<<"打印机打印次数:"<<p1->cnt<<endl;
}

int main()
{
    cout<<"main函数调用"<<endl;
    test01();
    return 0;
}