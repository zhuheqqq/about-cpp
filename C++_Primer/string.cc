#include<iostream>
#include<string>

using std::string;
using namespace std;

int main()
{
    string s1,s2;//string自动忽略开头的空格，从第一个的字符读起，遇到下一个空格为止

    cin>>s1>>s2;
    cout<<s1<<s2<<endl;

    return 0;
}