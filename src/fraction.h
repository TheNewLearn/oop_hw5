#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include "./gcd.h"


class Fraction {
public:

  // default value is +0/1
  // i.e., _sign='+', _numerator=0, _denominator=1
  Fraction() {
    _numerator = 0;
    _denominator = 1;
    _sign = '+';
  }

  // default value is an integer (denominator=1)
  // e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
  Fraction(int num) {
    _denominator = 1;
    if (num < 0){
      _sign = '-';
      _numerator = 0-num;
    }else{
      _sign = '+';
      _numerator = num;
    }
  }

  // hint: use gcd
  // throw exception when the denominator is 0
  Fraction(int numerator, int denominator) {
    if(numerator < 0 && denominator < 0){
      _sign = '+';
      int num = 0 - numerator;
      int den = 0 - denominator;
      int g = gcd(num,denominator);
      _numerator = num / g;
      _denominator = den / g;
    }
    else if(denominator < 0){
      _sign = '-';
      int num = numerator;
      int den = 0 - denominator;
      int g = gcd(num,denominator);
      _numerator = num / g;
      _denominator = den / g;
    }
    else if(denominator == 0 && numerator != 0){
      throw std::string("denominator is 0");
    }
    else{
      int num;
      if(numerator < 0){
        _sign = '-';
        num = 0 - numerator;
      }
      else{
        _sign = '+';
        num = numerator;
      }
      int g = gcd(num,denominator);
      _numerator = num / g;
      _denominator = denominator / g;
    }
  }

  // get the numerator of the fraction
  int numerator() const {
    return _numerator;
  }

  // get the denominator of the fraction
  int denominator() const {
    return _denominator;
  }

  // get positive or negative sign of the fraction
  char sign() const {
    return _sign;
  }

  // display the fraction by string
  std::string toString() const {
    int num;
    if(_denominator == 1){
      if(_sign == '-'){
        num = _numerator - _numerator * 2;
      }
      else{
        num = _numerator;
      }
      return std::to_string(num);
    }else{
      if(_sign == '-'){
        num = _numerator - _numerator * 2;
        return std::to_string(num) + "/" + std::to_string(_denominator);
      }
      else{
        return std::to_string(_numerator) + "/"  + std::to_string(_denominator);
      }
    }
  }

  


  // addition of two Fractions
  Fraction operator + (Fraction const & f) const {
    int num;
    bool check = (_denominator == f._denominator);
    if(check){
      if(_sign == '-' && f._sign == '-'){
        num = (_numerator - _numerator *2) + (f._numerator - f._numerator * 2);
      }
      else if(_sign == '-'){
        num = (_numerator - _numerator *2) + f._numerator;
      }else if (f._sign == '-')
      {
        num = (f._numerator - f._numerator * 2) + _numerator;
      }
      else{
        num = _numerator + f._numerator;
      }
      return Fraction(num,_denominator);
    }
    else{

      int den = _denominator * f._denominator;


      if(_sign == '-' && f._sign == '-'){
        num = ((_numerator - _numerator *2) * (den/_denominator)) + ((f._numerator - f._numerator * 2)* (den/f._denominator));
      }
      else if(_sign == '-'){
        num = ((_numerator - _numerator *2)*(den/_denominator)) + (f._numerator * (den/f._denominator));
      }else if (f._sign == '-')
      {
        num = ((f._numerator - f._numerator * 2)* (den/f._denominator)) + (_numerator * (den/_denominator));
      }
      else{
        num = (_numerator * (den/_denominator)) + (f._numerator * (den/f._denominator));
      }
      return Fraction(num,den);
    }
   
    
  }

  // subtraction of two Fractions
  Fraction operator - (Fraction const & f) const {
    int num;
    bool check = (_denominator == f._denominator);
    if(check){
      if(_sign == '-' && f._sign == '-'){
        num = (_numerator - _numerator *2) - (f._numerator - f._numerator * 2);
      }
      else if(_sign == '-'){
        num = (_numerator - _numerator *2) - f._numerator;
      }else if (f._sign == '-')
      {
        num = (f._numerator - f._numerator * 2) - _numerator;
      }
      else{
        num = _numerator - f._numerator;
      }
      return Fraction(num,_denominator);
    }
    else{
      int den = _denominator * f._denominator;


      if(_sign == '-' && f._sign == '-'){
        num = ((_numerator - _numerator *2) * (den/_denominator)) - ((f._numerator - f._numerator * 2)* (den/f._denominator));
      }
      else if(_sign == '-'){
        num = ((_numerator - _numerator *2)*(den/_denominator)) - (f._numerator * (den/f._denominator));
      }else if (f._sign == '-')
      {
        num = ((f._numerator - f._numerator * 2)* (den/f._denominator)) - (_numerator * (den/_denominator));
      }
      else{
        num = (_numerator * (den/_denominator)) - (f._numerator * (den/f._denominator));
      }
      return Fraction(num,den);
    }
  }

  // division of two Fractions
  Fraction operator / (Fraction const & f) const {
    int num;
    int den;
    if(_sign == '-' && f._sign == '-'){
      num = (_numerator - _numerator *2) * f._denominator;
      den = _denominator * (f._numerator - f._numerator * 2);
    }
    else if(_sign == '-'){
      num = (_numerator - _numerator *2) * f._denominator;
      den = _denominator * f._numerator;
    }
    else if(f._sign == '-'){
      num = _numerator * f._denominator;
      den = _denominator * (f._numerator - f._numerator * 2);
    }
    else{
      num = _numerator * f._denominator;
      den = _denominator * f._numerator;
    }
    return  Fraction(num,den);
  }

private:
  // both numerator and denominator should be positive
  int _numerator;
  int _denominator;
  char _sign;
};
#endif