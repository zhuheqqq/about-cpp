#include<iostream>
#include<string>
using namespace std;

void test01()
{
    string str="hello world";
   // for(int i=0;i<str.size();i++)
    //{
        //cout<<str[i]<<endl;
        //or cout<<str.at(i)<<endl;
        //[]和at区别,[]访问越界直接挂掉,at访问越界,抛出out_of_range异常
    //}
    
    try
    {
        cout<<str.at(100)<<endl;
    }catch(out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
}

int main()
{
    test01();
    return 0;
}