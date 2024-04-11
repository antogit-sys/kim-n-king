/*  - Progetti di prog
 *  
 *  6. Modify the upc.c program of Section 4.1 so that it 
 *  checks whether a UPC is valid. After the users enters 
 *  a UPC, the program will display either VALID or NOT VALID.
 *
 * ___________________________________________________________
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZECD 11
#define INT(ch) (ch-'0')
#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            fputs((s), stdout);\
            exit(1);\
        }\
    }while(0)  


int calc_check_digitUPC(char*);
int* string_to_int_array(char*);

int main(void)
{
    char digits[SIZECD];
    
    fputs("Enter the first 11 digits of a UPC: ",stdout);
    fscanf(stdin,"%s",digits);

    fprintf(stdout,"check digit: %d\n",calc_check_digitUPC(digits));
    
return EXIT_SUCCESS;
}

int calc_check_digitUPC(char* digits){
    int first_sum = 0, second_sum = 0;
    int total = 0, cd = 0;
    int size = strlen(digits);
    
    EXIT_IF(size != 11, "Error! UPC NOT VALID");

    int* newDigits=string_to_int_array(digits);

    for(unsigned int i=0; i<size; ++i){
        if(i%2 == 0)
            first_sum+=newDigits[i];
        else
            second_sum+=newDigits[i];
    }

    total = 3 * first_sum + second_sum;
    cd = 9-((total-1) % 10);
    
    return cd;
}


int* string_to_int_array(char* v){
    int size = strlen(v);
    int* newArray = (int*)malloc(sizeof(int)*size);

    for(size_t i=0; i<size; ++i)
       newArray[i] = INT(v[i]);

    return newArray;
}

