#include "box.h"
#include "WCStudent.h"
#include <gtest/gtest.h>
namespace {

class StudentTest : public ::testing::Test {

protected:
  void SetUp() { // override {
    bptr = new WCStudent(10,12,5, RED, 100); 
  }
  void TearDown() {
    delete bptr;
  }
  Student *bptr;  
};

TEST_F(StudentTest, DefaultConstructor) {
  WCStudent b1;
  EXPECT_EQ(0, b1.getLength());
  EXPECT_EQ(0, b1.getBreadth());
  EXPECT_EQ(0, b1.getHeight());
  EXPECT_EQ(BLACK, b1.getColor());
  EXPECT_EQ(0, b1.getWeight());
}
TEST_F(StudentTest, ParameterizedConstructor) {
  WCStudent w1(12, 8, 10, GREEN, 150); 
  EXPECT_EQ(12, w1.getLength());
  EXPECT_EQ(8, w1.getBreadth());
  EXPECT_EQ(10, w1.getHeight());
  EXPECT_EQ(960, w1.volume());
  EXPECT_EQ(592, w1.surfacearea());
  EXPECT_EQ(GREEN, w1.getColor());
  EXPECT_EQ(150, w1.getWeight());
}
TEST_F(StudentTest, ComputationTest) {
  EXPECT_EQ(600, bptr->volume());
  EXPECT_EQ(460, bptr->surfacearea());
}
TEST_F(StudentTest, AnotherTest) {
  WCStudent w2(5,8,10, BLUE, 180);  
  Student *uptr = &w2;
  EXPECT_EQ(5, w2.getLength());
  EXPECT_EQ(8, w2.getBreadth());
  EXPECT_EQ(10, w2.getHeight());
  EXPECT_EQ(BLUE, w2.getColor());
  EXPECT_EQ(180, w2.getWeight());
  EXPECT_EQ(400, uptr->volume());
  EXPECT_EQ(340, uptr->surfacearea());  
}
} // namespace
