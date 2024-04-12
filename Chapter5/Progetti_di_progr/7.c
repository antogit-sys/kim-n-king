#include <stdio.h>
#define N 5

void analyze_of_array(int*, int, int*, int*);
int main(void)
{
    int v[N]={21,48,10,35,1};
    int min,max;

    analyze_of_array(v, N, &min, &max);
    
    printf("%d\n%d",min,max);
    

return 0;
}

void analyze_of_array(int* v, int size, int* min, int* max){
    *min = v[0];
    *max = v[0];

    for(size_t i=1; i<size; ++i)
        *max = (*min<v[i])?*min=v[i]:v[i];
}
