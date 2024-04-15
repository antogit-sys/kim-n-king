#include <stdio.h>
#define N 5

void analyze_of_array(int*, int, int*, int*);
int main(void)
{
    //int v[N]={1,2,3,4,5};
    //int v[N]={21,48,10,35,1};
    //int v[N]={2,2,2,2,2};
    int v[N]={2, 3, 9, 7, 1};

    int min,max;

    analyze_of_array(v, N, &min, &max);
    
    printf("Largest: %d\n",max);
    printf("Smallest: %d\n",min);
    

return 0;
}

void analyze_of_array(int* v, int size, int* min, int* max){
    
    *min = *max = v[0];
    
    for(size_t i=1; i<size; ++i){
        *min = (*min>v[i])?v[i]:*min;
        *max = (*max<v[i])?v[i]:*max;
    }
}
