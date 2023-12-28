#define CATCH_CONFIG_MAIN
#include <gtest/gtest.h>

#include "my_lib.h"

TEST(FactorialTests, Test1)
{
    EXPECT_TRUE(factorial(0) == 1);
    EXPECT_TRUE(factorial(1) == 1);
    EXPECT_TRUE(factorial(2) == 2);
    EXPECT_TRUE(factorial(3) == 6);
    EXPECT_TRUE(factorial(10) == 3628800);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
