#include "boxdb.h"
#include<list>
using namespace std;

void WCStudentDatabase::addStudent(int a, string b, int c, string d, int m1, int m2, int m3, DEPT e, double e)
{
    student.push_back(WCStudent(a,b,c,d,m1,m2,m3,e));
}
void WCStudentDatabase::removeStudent(int a, string b, int c, string d)
{
    std::list<WCStudent>::iterator it;
    for(it=student.begin();it!=student.end();++it)
    {
        if((it->getId()==a) && (it->getName()==b) && (it->getAge()==c) && (it->getCity()==d))
        {
            student.erase(it);
        }
    }
}
int WCStudentDatabase::countAll()
{
    return student.size();
}
int WCStudentDatabase::findMaxMark()
{
    int max=0;
    std::list<WCStudent>::iterator it;
    std::list<WCStudent>::iterator maxit;
    maxit=it;
    max=it->total_marks();
    for(it=student.begin();it!=student.end();++it)
    {
        if(it->total_marks()>max)
        {
            max=it->total_marks();
            maxit=it;
        }
    }
    return max;
}
int WCStudentDatabase::findMinMark()
{
    int max=1000;
    std::list<WCStudent>::iterator it;
    std::list<WCStudent>::iterator maxit;
    maxit=it;
    max=it->total_marks();
    for(it=student.begin();it!=student.end();++it)
    {
        if(it->total_marks()<max)
        {
            max=it->total_marks();
            maxit=it;
        }
    }
    return max;
}
double WCStudentDatabase::findAvgMark()
{
    int mk=0;
    std::list<WCStudent>::iterator it;
    for(it=student.begin();it!=student.end();++it)
    {
        mk+=it->total_marks();
    }
    double avg=mk/(student.size());
    return avg;
}
int WCStudentDatabase::countStudentByDept(DEPT d)
{
    int count=0;
    std::list<WCStudent>::iterator it;
    for(it=student.begin();it!=student.end();++it)
    {
        if(it->getDept()==d)
        {
            ++count;
        }
    }
    return count;
}