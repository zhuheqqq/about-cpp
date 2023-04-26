#include<iostream>
using namespace std;

class Person
{
public:
    Person(int a,int b)
    {
        this->A=a;
        this->B=b;
    }
    int A;
    int B;//一般来说,成员变量最好私有化,但是这里为了简化操作直接将成员变量定义在public下
};

ostream& operator<<(ostream &cout,Person &p1)//返回值为ostream&主要是为了可以在后面无限的拼接"<<"
{
    cout<<"A="<<p1.A<<"B="<<p1.B;
    return cout;
}

void test01()
{
    Person p1(10,10);
    cout<<p1<<endl;
}

int main()
{
    test01();
    return 0;
}