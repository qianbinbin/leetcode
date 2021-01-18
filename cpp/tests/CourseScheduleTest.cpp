#include "CourseSchedule.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(CourseSchedule, Solution207_1) {
  const int NumCourses1 = 2;
  std::vector<std::pair<int, int>> Prerequisites1{{1, 0}};
  EXPECT_TRUE(Solution207_1().canFinish(NumCourses1, Prerequisites1));

  const int NumCourses2 = 2;
  std::vector<std::pair<int, int>> Prerequisites2{{1, 0}, {0, 1}};
  EXPECT_FALSE(Solution207_1().canFinish(NumCourses2, Prerequisites2));
}