#include<iostream>
#include<string>

using namespace std;
using std::string;

int main()
{
    string line;

    while(getline(cin,line)){
        if(line.size()>5){//返回string对象的长度
            cout<<line<<endl;
        }
    }
    return 0;
}