#include <stdio.h>
int main(void)
{
    int speed;

    fputs("Enter a value speed: ",stdout);
    scanf("%d", &speed);
    
    if(speed < 1)
        puts("Calm");
    else if (speed <= 3)
        puts("Light air");
    else if (speed <= 27)
        puts("Breeze");
    else if (speed <= 47)
        puts("Gale");
    else if (speed <= 63)
        puts("Storm");
    else
        puts("Hurricane");

return 0;
}
