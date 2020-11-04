#include "box.h"
#include "wcbox.h"
#include "boxdb.h"
#include <gtest/gtest.h>
namespace {

class StudentDbTest : public ::testing::Test {

protected:
  void SetUp() { 
    student.addStudent(10,12,5, RED,   100);  //600
    student.addStudent(8,5,10,  GREEN, 150);  //400
    student.addStudent(6,10,5,  BLUE,  110);  //300
    student.addStudent(12,10,8, GREEN, 180);  //960
    student.addStudent(12,5,8,  RED,   200);  //480
    student.addStudent(15,8,10, BLUE,  140);  //1200
    student.addStudent(15,10,6, RED,   120);  //900
    student.addStudent(10,12,6, GREEN, 160);  //720
  }
  void TearDown() {}
  WCStudentDatabase student;
};

TEST_F(StudentDbTest, AddStudentTest) {
  student.addStudent(15,10,12, GREEN, 210);
  EXPECT_EQ(9, student.countAll());
}
TEST_F(StudentDbTest, RemoveStudentTest) {
  student.removeStudent(6,10,5);
  EXPECT_EQ(7, student.countAll());
}
TEST_F(StudentDbTest, CountTest) {             
  EXPECT_EQ(8, student.countAll());
}
TEST_F(StudentDbTest, ComputationalTest) {  
  int maxVolume = student.findMaxVolume();
  double avgWeight = student.findAverageWeight();
  EXPECT_EQ(1200, maxVolume);
  EXPECT_EQ(145, avgWeight);         
}

TEST_F(StudentDbTest, CountByColorTest) {
  int redCount,blueCount;
  redCount=student.countstudentByColor(RED);
  blueCount=student.countstudentByColor(BLUE);
  EXPECT_EQ(3, redCount);
  EXPECT_EQ(2, blueCount);
}
TEST_F(StudentDbTest, AnotherDbTest) {
  student.addStudent(15,12,10, GREEN, 210);
  student.addStudent(10,5,4,   RED,   170);
  EXPECT_EQ(10, student.countAll());
  EXPECT_EQ(1800, student.findMaxVolume());
  EXPECT_EQ(154, student.findAverageWeight());
}

} // namespace
