#include "mystring.hpp"
//重载左移运算符
ostream& operator<<(ostream & cout,MyString & str)
{
    cout<<str.pstring;
    return cout;
}
//重载右移运算符
istream& operator>>(istream & cin,MyString & str)
{
    //先清空原来堆区数据
    if(str.pstring)
    {
        delete[] str.pstring;
        str.pstring=NULL;
    }

    char buf[1024];//临时数组
    cin>>buf;
    str.pstring=new char[strlen(buf)+1];
    strcpy(str.pstring,buf);
    str.Size=strlen(buf);

    return cin;
}

MyString::MyString(char *str)
{
    cout<<"MyString的有参构造"<<endl;
    this->pstring=new char[strlen(str)+1];
    strcpy(this->pstring,str);
    this->Size=strlen(str);

}

MyString::MyString(const MyString & str)
{
    cout<<"MyString的拷贝构造"<<endl;
    this->pstring=new char[strlen(str.pstring)+1];
    strcpy(this->pstring,str.pstring);
    this->Size=str.Size;

}

MyString::~MyString()
{
    cout<<"MyString的析构调用"<<endl;
    if(this->pstring)
    {
        delete [] this->pstring;
        this->pstring=NULL;
    }

}

void test01()
{
    MyString str("abc");
   
    cout<<"请重新输入str的值"<<endl;
    cin>>str;
    cout<<"str新的值为:"<<str<<endl;
}

int main()
{
    test01();
    return 0;
}