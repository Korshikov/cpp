#include "stdafx.h"
#include "gtest/gtest.h"

class CRectTest : public ::testing::Test {
};

TEST_F(CRectTest, CheckPerimeter)
{
CSomeRect rect;
rect.x = 5;
rect.y = 6;
ASSERT_TRUE(rect.GetPerimeter() == 22);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}