/*
 * =====================================================================================
 *
 *       Filename:  intasciiConv.c
 *
 *    Description:  Functions to convert int to ascii and vice-versa
 *
 *        Version:  1.0
 *        Created:  10/06/2018 15:30:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SHANMUGAPRIYA RAVINDRAN
 *
 *
 * =====================================================================================
 */

#include <stdio.h>

//#define DEBUG

int strlen_my(const char* s)
{
    int i = 0,length = 0;

    while(*(s+i) != '\0')
    {
        length++;
        i++;
    }

    return length;
}

char* myStrRev(char* strg)
{
    int strLen = 0, i = 0, mid = 0;
    char temp;


    strLen = strlen_my(strg);
#ifdef DEBUG
    printf("length = %d\n",strLen);
#endif

    mid = strLen/2;
#ifdef DEBUG
    printf("mid = %d\n",mid);
#endif


    for(i=0; i<mid; i++)
    {
        temp = *(strg+i);
        *(strg+i) = *(strg+strLen-i-1);
        *(strg+strLen-i-1) = temp;
    }

    return strg;
}

int my_atoi(char* numStr)
{
    int i  = 0, sign = 0, num;

    if(*numStr == '-')
    {
#ifdef DEBUG
        printf("[%c]\n",*numStr);
#endif
        sign = 1;
        numStr++;
    }
    else if((*numStr == '+') || (*numStr == '+'))
    {
#ifdef DEBUG
        printf("[%c]\n",*numStr);
#endif
        numStr++;
    }

    for(;*numStr != '\0' ;numStr++)
    {
        if(('0' > *numStr) || ('9' < *numStr))
        {
            printf("Invalid character\n");
#ifdef DEBUG
            printf("[%c]\n",*numStr);
#endif
            return 0;
        }
#ifdef DEBUG
       printf("[%c]\n",*numStr);
#endif
       num = (num*10) + (*numStr - '0');
    }

    if(sign)
        num = -num;

    return num;
}

void my_itoa(int num,char* str,int len)
{
    int n,i=0;
    n = num;

    if(n<0)
    {
        len = len-1;
        n = -n;
    }

    while(n != 0 && i<=len)
    {
        *str = (n%10) + '0';
#ifdef DEBUG
        printf("** %c\n",(char)*str);
#endif
        n = n/10;
        str++;
        i++;
    }
    if(num < 0)
        *str++ = '-';
    *str = '\0';
}

int main(void)
{
    char numString[11];
    char numString1[11];

    int num = 0,len = 0;

    printf("Enter the number string (max of 10 digits)\n");
    scanf("%s",numString);
    len = strlen_my(numString);
    if(len > 10)
    {
        printf("Error: exceeding max 10 digits\n");
        return 0;
    }
    num = my_atoi(numString);
    printf("number: %d\n",num);
    my_itoa(num,numString1,len);
    printf("number in string format: %s\n",myStrRev(numString1));

    return 0;
}
