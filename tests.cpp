#include "gtest/gtest.h"
#include "methods.h"

const float ABS_ERROR = 0.001;

TEST(OPZ, t1)
{
    float result;
    Calculate("1+2", result);
    EXPECT_NEAR(result, 3, ABS_ERROR);
}

TEST(OPZ, t2)
{
    float result;
    Calculate("3*6", result);
    EXPECT_NEAR(result, 18, ABS_ERROR);
}

TEST(OPZ, t3)
{
    float result;
    Calculate("5-20", result);
    EXPECT_NEAR(result, -15, ABS_ERROR);
}

TEST(OPZ, t4)
{
    float result;
    Calculate("20/5", result);
    EXPECT_NEAR(result, 4, ABS_ERROR);
}

TEST(OPZ, t5)
{
    float result;
    Calculate("4 + 5 - 2", result);
    EXPECT_NEAR(result, 7, ABS_ERROR);
}

TEST(OPZ, t6)
{
    float result;
    Calculate("12 + 8 /16", result);
    EXPECT_NEAR(result, 12.5, ABS_ERROR);
}

TEST(OPZ, t7)
{
    float result;
    Calculate("    (   1                    +                  15    )    /    4    ", result);
    EXPECT_NEAR(result, 4, ABS_ERROR);
}

//ДОДЕЛАТЬ
TEST(OPZ, t8)
{
    float result;
    Calculate("(12-2)*((9/3+4560)/(156-4861*2))-((125/5)+45-81*(5846/51)+651*584-651+(18/8431))", result);
    EXPECT_NEAR(result, 379085.031, ABS_ERROR);
}

TEST(OPZ, t9)
{
    float result;
    Calculate("((12+4)/2)*2", result);
    EXPECT_NEAR(result, 16, ABS_ERROR);
}

TEST(OPZ, t10)
{
    float result;
    Calculate("(12+4/2)*2", result);
    EXPECT_NEAR(result, 28, ABS_ERROR);
}

TEST(OPZ, t11)
{
    float result;
    Calculate("12*3/15+4/8", result);
    EXPECT_NEAR(result, 2.9, ABS_ERROR);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
