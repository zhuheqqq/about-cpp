#include<iostream>
#include<string>

using namespace std;
using std::string;

int main()
{
    string line;
    while(getline(cin,line)){
        if(!line.empty()){//遇到空行跳过
            cout<<line<<endl;
        }
    }
    return 0;
}