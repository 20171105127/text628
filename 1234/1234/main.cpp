
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define N 4
#define M 3
#define W 3
struct Student
{
    Student(){}
    Student(vector<string>* departments):depars(departments){}
    void Input();
    void Print();
    friend ofstream& operator<<(ofstream& ofs, Student& stu);
    friend ifstream& operator>>(ifstream& ifs, Student& stu);
    string name;
    string department;
    int points;
private:
    vector<string>* depars;
};
ofstream& operator<<(ofstream& ofs, Student& stu)
{
    ofs << stu.name <<"\t"<< stu.department<<"\t" << stu.points;
    return ofs;
}
ifstream& operator>>(ifstream& ifs, Student& stu)
{
    ifs >> stu.name >> stu.department >> stu.points;
    return ifs;
}
void Student::Input()
{
    cout<<"输入名字："<<endl;
    cin >> name;
    bool invalid(true);
    do
    {
        string d;
        cout<<"输入院系名称："<<endl;
        cin >> d;
        vector<string>::iterator found=find(depars->begin(),depars->end(),d);
        if(found != depars->end())
        {
            invalid = false;
            department = d;
        } else {
            cout<<"无效院系名称，请重新输入。"<<endl;
        }
    } while(invalid);
}
        case 5:
            return 1;
            break;
    }
    return 0;
}
