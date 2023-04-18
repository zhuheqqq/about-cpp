#include<iostream>
using namespace std;

const double PI=3.14;

class Circle
{
public://公共权限

    int m_R;//半径,类中变量称为成员变量

    //类中函数称为成员函数 成员方法
    double calculateZC()
    {
        return 2*PI*m_R;
    }

    void setR(int r)//设置半径
    {
        m_R=r;
    }

    int getR()//获取半径
    {
        return m_R;
    }
};



void test01()
{
    Circle c1;//通过类创建一个对象  实例化对象
    //给c1半径赋值
    //c1.m_R=10;
    c1.setR(10);

    //求c1圆的周长
    cout<<"圆的周长为:"<<c1.calculateZC()<<endl;
    cout<<"圆的半径为:"<<c1.getR()<<endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}