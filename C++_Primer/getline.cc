#include<iostream>
#include<string>

using namespace std;
using std::string;

int main()
{
    string line;
    while(getline(cin,line)){//getline返回的换行符被丢弃了,得到的string对象中不含换行符
        cout<<line<<endl;
    }

    return 0;
}