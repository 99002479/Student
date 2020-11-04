#include "wcbox.h"
using namespace std;

Student::Student():id(0),name(""),age(0),city(""),mark1(0),mark2(0),mark3(0){}
Student::Student(int id, string name, int age, string address):id(id),name(name),age(age),city(address),mark1(mark1),mark2(mark2),mark3(mark3){}
WCStudent::WCStudent():phone(0),DEPT(CSE){}
WCBox::WCBox(int a, string b, int c, int m1, int m2, int m3, string d, DEPT e, double e):id(a),name(b),age(c),mark1(m1),mark2(m2),mark3(m3),city(d),dept(e),phone(e){}

double WCStudent::total_marks()
{
    return (mark1+mark2+mark3);
}
/*double WCStudent::average()
{
    return ((mark1+mark2+mark3)/3);
}*/
int WCStudent::getPhone()
{
    return phone;
}
DEPT WCBox::getDept()
{
    return dept;
}