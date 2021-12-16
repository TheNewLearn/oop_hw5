#ifndef GCD_H
#define GCD_H
// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
int gcd(int a, int b) {
    if( b==0 )
        if (a < 0){
            return 0 - a;
        }
            
        else
        {return a;}
            
    return gcd( b, a%b );
}
#endif