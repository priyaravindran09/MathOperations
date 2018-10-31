#include <stdio.h>
#include <stdbool.h>

bool isPowerOf2()
{
    int num,i,count = 0;

    printf("***Power of 2*** \nEnter the num to be checked:");
    scanf("%d",&num);

    for(i=0; i<sizeof(int); i++)
    {
        if((num>>i) & 1)
            count++;
    }

    if(count != 1)
        return false;
    else
        return true;
}

int main(void)
{
    bool powerOf2;

    powerOf2 = isPowerOf2();

        if(powerOf2)
            printf("Is a power of 2\n");
        else
            printf("Not a power of 2\n");

    return 0;
}
