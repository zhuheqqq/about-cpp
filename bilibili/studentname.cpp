#include<iostream>
#include<string>
using namespace std;

const int MAX=100;


class Studentname
{
public:
    string studentname;
    int studentID;
};

void Setname()
{
    Studentname stud;
    stud.studentname="zhuheqin";
    stud.studentID=123456;

    cout<<"该学生姓名为:"<<stud.studentname<<endl;
    cout<<"该学生学号为:"<<stud.studentID<<endl;

}

int main()
{
    Setname();

    system("pause");

    return 0;
}