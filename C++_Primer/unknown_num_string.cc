//读取数量不定的string对象

#include<iostream>
#include<string>

using namespace std;
using std::string;

int main()
{
    string word;

    while(cin>>word){
        cout<<word<<endl;
    }
    return 0;
}