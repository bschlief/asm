#include <stdio.h>

double absD( double n ) {
    double result ;
    __asm__ __volatile__ ("fldl %1;"        /* load input operand onto FPU stack         */
                          "fabs;"           /* clears sign bit of st(0)                  */
                          "fstpl %0;"       /* pop value into the return value off st(0) */
                          : "=m" (result)   /* output operand   */ 
                          : "m" (n)         /* input operand(s) */
    );
    return result ;
}
int main() {
    double numD;

    printf( "Enter a double: " ) ;
    scanf( "%lf", &numD );
    printf( "absD of %f\n", absD(numD) ) ;

    return 0 ;
}
