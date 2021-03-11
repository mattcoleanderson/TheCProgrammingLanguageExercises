#include <stdio.h>
#include <limits.h>

// Write a program to determine the ranges of
// char , short , int , and long variables, both signed and unsigned

#define MAX_LINE_LENGTH 1000
#define UNSIGNED_MIN 0

int main() {

    printf("\n");
    printf("---------------------- CHAR ------------------------------- \n");
    printf("Unsigned   | %6d to %u \n", UNSIGNED_MIN , UCHAR_MAX);
    printf("Signed     | %6d to %d \n", CHAR_MIN, CHAR_MAX);
    printf("\n");
    printf("---------------------- SHOR ------------------------------- \n");
    printf("Unsigned   | %6d to %u \n", UNSIGNED_MIN , USHRT_MAX);
    printf("Signed     | %6d to %d \n", SHRT_MIN, SHRT_MAX);
    printf("\n");
    printf("---------------------- INT -------------------------------- \n");
    printf("Unsigned   | %15d to %u \n", UNSIGNED_MIN , UINT_MAX);
    printf("Signed     | %15d to %d \n", INT_MIN, INT_MAX);
    printf("\n");
    printf("---------------------- LONG ------------------------------- \n");
    printf("Unsigned   | %15d to %lu \n", UNSIGNED_MIN , ULONG_MAX);
    printf("Signed     | %15ld to %ld \n", LONG_MIN, LONG_MAX);
    printf("\n");
    printf("---------------------- LONG LONG -------------------------- \n");
    printf("Unsigned   | %21d to %llu \n", UNSIGNED_MIN , ULLONG_MAX);
    printf("Signed     | %21lld to %lld \n", LLONG_MIN, LLONG_MAX);





    return 0;
}
