#include <stdio.h>

int main(void)
{
    //sizeof: return size_t
    //%zu in printf --> print size_t value
    //%zu avoid the casting (unsigned long)
    puts("\tTYPE\tBYTE");
    puts("\t============");
    printf("\tint\t %zu\n",sizeof(int));
    printf("\tshort\t %zu\n",sizeof(short));
    printf("\tlong\t %zu\n",sizeof(long));
    printf("\tfloat\t %zu\n",sizeof(float));
    printf("\tdouble\t %zu\n",sizeof(double));
    printf("\tldouble\t %zu\n",sizeof(long double));

return 0;
}
