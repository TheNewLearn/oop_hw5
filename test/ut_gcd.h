#include "../src/gcd.h"
#include<string>
#include <gtest/gtest.h>

TEST(GCDTEST,GCDT){
int result;
result = gcd(-2,5);
ASSERT_EQ(1,result);
ASSERT_EQ(5,gcd(12135,1235));
}
