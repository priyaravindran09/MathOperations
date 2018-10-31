/*
 * =====================================================================================
 *
 *       Filename:  powern.c
 *
 *    Description:  Given any number y check if its a power of x
 *
 *        Version:  1.0
 *        Created:  10/30/2018 19:53:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SHANMUGAPRIYA RAVINDRAN
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfN(void)
{
    int num, power;

    printf("Enter 2 positive numbers:(1) y to check if it is a power of another number (2)x\n");
    scanf("%d %d",&num,&power);

    if((num <= 0) || (power <= 0))
        return false;

    while(num != 1)
    {
        if(num%power != 0)
            return false;
        else
            num = num/power;
    }

    return true;
}

int main(void)
{
    bool powerOfN;

    powerOfN = isPowerOfN();

    if(powerOfN)
        printf("Yes it is\n");
    else
        printf("No it is not\n");

    return 0;

}
