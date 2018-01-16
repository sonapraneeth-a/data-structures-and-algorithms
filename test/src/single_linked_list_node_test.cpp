#include "single_linked_list_node.h"
#include "gtest/gtest.h"
using namespace std;

class LinkedListTest : public ::testing::Test
{

};


// Tests factorial of 0.
TEST_F(LinkedListTest, Print)
{
    EXPECT_EQ(100, print_list_value());
}
