#include "mystring.hpp"

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