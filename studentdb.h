#ifndef __STUDENTDB_H
#define __STUDENTDB_H

#include "box.h"
#include "wcbox.h"
#include<list>

using namespace std;

class WCStudentDatabase
{
    std::list<WCBox> student;

    public:
    WCStudentDatabase();
    void addStudent(int a, string b, int c, string d, int m1, int m2, int m3, DEPT e, double e);
    void removeStudent(int a, string b, int c, string d, int m1, int m2, int m3);
    int countAll();
    int findMaxMark();
    int findMinMark();
    int findAvgMark();
    //int findMaxAvgMark();
    //int findMinAvgMark();
    int countStudentByDept(DEPT d);
};


#endif