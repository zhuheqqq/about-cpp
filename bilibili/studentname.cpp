#include<iostream>
#include<string>
using namespace std;

const int MAX=100;


class Studentname
{
private:
    string studentname;
    int studentID;

public:
    void setName(string name)
    {
        studentname=name;
    }

    void setID(int id)
    {
        studentID=id;
    }

    void Show()
    {
        cout<<"姓名:"<<studentname<<"\n"<<"学号:"<<studentID<<endl;
    }
};

void Setname()
{
    Studentname stud;
    stud.setName("zhuheqin");
    stud.setID(123456);
    stud.Show();
   // cout<<"该学生姓名为:"<<stud.studentname<<endl;
    //cout<<"该学生学号为:"<<stud.studentID<<endl;
    

}

int main()
{
    Setname();
    
    system("pause");

    return 0;
}