#include "../src/fraction.h"
#include<string>
#include <gtest/gtest.h>

class FractionTest: public::testing::Test{
protected:
Fraction f1;
    Fraction f2;
    Fraction f2_1;
    Fraction f3;
    Fraction f3_1;
    Fraction f3_2;
    Fraction f3_3;
    Fraction f3_4;
    Fraction f4;
    Fraction f4_1;
    Fraction f4_2;
    Fraction f5;
    Fraction f5_1;
    Fraction f5_2;
    Fraction f6;
    Fraction f6_1;
    Fraction f6_2;
    Fraction f7;
    Fraction f7_1;
    Fraction f7_2;
    void SetUp(){
    f1 = Fraction();
    f2 = Fraction(-3);
    f2_1 = Fraction(3);
    f3 = Fraction(5,9);
    f3_1 = Fraction(-7,8);
    f3_3 = Fraction(5,-9);
    f3_4 = Fraction(-5,-9);
    f4 = Fraction(3,2);
    f4_1 = Fraction(-3,1);
    f4_2 = Fraction(-3,2);
    }
};

TEST_F(FractionTest,fract_default_constr_test){
    ASSERT_EQ('+',f1.sign());
    ASSERT_EQ(0,f1.numerator());
    ASSERT_EQ(1,f1.denominator());
}

TEST_F(FractionTest,fract_constr_1_test){
    ASSERT_EQ('-',f2.sign());
    ASSERT_EQ(3,f2.numerator());
    ASSERT_EQ(1,f2.denominator());
    ASSERT_EQ('+',f2_1.sign());
    ASSERT_EQ(3,f2_1.numerator());
    ASSERT_EQ(1,f2_1.denominator());
}

TEST_F(FractionTest,fract_constr_2_test){
    ASSERT_THROW( Fraction f3_2(2,0),std::string);
    ASSERT_EQ('-',f3_1.sign());
    ASSERT_EQ(7,f3_1.numerator());
    ASSERT_EQ(8,f3_1.denominator());
    ASSERT_EQ('+',f3.sign());
    ASSERT_EQ(5,f3.numerator());
    ASSERT_EQ(9,f3.denominator());
    ASSERT_EQ('-',f3_3.sign());
    ASSERT_EQ(5,f3_3.numerator());
    ASSERT_EQ(9,f3_3.denominator());
    ASSERT_EQ('+',f3_4.sign());
    ASSERT_EQ(5,f3_4.numerator());
    ASSERT_EQ(9,f3_4.denominator());
}

TEST_F(FractionTest,fract_tostring_test){
    ASSERT_EQ("3/2",f4.toString());
    ASSERT_EQ("-3",f4_1.toString());
    ASSERT_EQ("-3/2",f4_2.toString());
    ASSERT_EQ("5/9",f3_4.toString());
}

TEST_F(FractionTest,fract_oper_add){
    f5 = f3 + f4;
    f5_1 = f3_1 + f3;
    f5_2 = f3_4 + f3_4;
    ASSERT_EQ("37/18",f5.toString());
    ASSERT_EQ("-23/72",f5_1.toString());
    ASSERT_EQ("10/9",f5_2.toString());
}

TEST_F(FractionTest,fract_oper_minus){
    f6 = f3 - f4;
    f6_1 = f3_1 - f3;
    f6_2 = f3_4 - f3_4;
    ASSERT_EQ("-17/18",f6.toString());
    ASSERT_EQ("-103/72",f6_1.toString());
    ASSERT_EQ("0",f6_2.toString());
}

TEST_F(FractionTest,fract_oper_Divided){
    f7 = f3 / f4;
    f7_1 = f3_1 / f3;
    f7_2 = f3_4 / f3_4;
    ASSERT_EQ("10/27",f7.toString());
    ASSERT_EQ("-63/40",f7_1.toString());
    ASSERT_EQ("1",f7_2.toString());
}

TEST_F(FractionTest,numerator_test){
    ASSERT_EQ(3,f4.numerator());
}

TEST_F(FractionTest,den_test){
    ASSERT_EQ(2,f4.denominator());
}

TEST_F(FractionTest,sign_test){
    ASSERT_EQ('+',f4.sign());
}




