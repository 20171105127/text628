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
void Student::Print()
{
    cout<< name <<"\t"<<department<<endl;
}
// Forward declaration
class GameInfo;
class SportEvent
{
public:
    static int GetPoint(int ranking);
    void InputWinners(GameInfo& g);
    void Print();
    friend ofstream& operator<<(ofstream& ofs, SportEvent& se);
    friend ifstream& operator>>(ifstream& ifs, SportEvent& se);
public:
    vector<Student> winners;
    string name;
};
ofstream& operator<<(ofstream& ofs, SportEvent& se)
{
    ofs << se.name << endl;
    ofs << se.winners.size() << endl;
    for(unsigned int i(0);i<se.winners.size();i++)
    {
        ofs << se.winners.at(i) <<"\t";
    }
    return ofs;
}
ifstream& operator>>(ifstream& ifs, SportEvent& se)
{
    ifs >> se.name;
    unsigned int count(0);
    ifs >> count;
    se.winners.clear();
    for(unsigned int i(0);i<count;i++)
    {
        Student student;
        ifs >> student;
        se.winners.push_back(student);
    }
    return ifs;
}
int SportEvent::GetPoint(int ranking)
{
    switch(ranking)
    {
        case 1:
            return 7;
            break;
        case 2:
            return 5;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 2;
            break;
        case 5:
            return 1;
            break;
    }
    return 0;
}
