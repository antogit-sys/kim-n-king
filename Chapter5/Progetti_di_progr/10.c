#include <stdio.h>
#include <stdlib.h>

/* Negative Acknowledgement */
#define NACK 21 

#define BETWEEN(a,n1,n2) (a>=n1 && a<=n2)

#define __CALC_GRADE(n)\
    (BETWEEN(n,90,100)?'A':\
     (BETWEEN(n,80,89)?'B': \
      (BETWEEN(n,70,79)?'C': \
       (BETWEEN(n,60,69)?'D': \
        (BETWEEN(n,0,59)?'F':NACK)))))

#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            fputs((s), stdout);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)  

const char calc_grade(int);

int main(void)
{
    int n = 0;
    
    fputs("Enter numerical grade: ",stdout);
    fscanf(stdin,"%d",&n);

    fprintf(stdout,"Letter grade: %c\n",calc_grade(n));

return EXIT_SUCCESS;
}

const char calc_grade(int n){
    const char letter = __CALC_GRADE(n);
    
    EXIT_IF(letter == NACK, "Error calc_grade: Invalid grade range!\n");
    
    return letter;
}
