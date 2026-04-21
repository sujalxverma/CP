#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

struct Student
{
    string name;
    int age;
};
ostream &operator<<(ostream &out, const Student &s)
{
    out << "Name : " << s.name << "\n";
    out << "Age : " << s.age << "\n";
    return out;
}

istream &operator>>(istream &in, Student &s)
{
    in >> s.name;
    in >> s.age;
    return in;
}

int main()
{
    Student s;
    cin >> s;
    cout << s;
}

/*
This is custom output and input operator.
*/
