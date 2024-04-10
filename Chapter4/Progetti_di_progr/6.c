/*  - Progetti di prog
 *  
 *  6. European countries use a 13-digit code, known as a European 
 *  Article Number (EAN) instead of the 12-digit Universal Product 
 *  Code (UPC) found in North America. Each EAN ends with a check digit, 
 *  just as UPC does. The technique for calculating the check digit is 
 *  also similar:
 *
 *  Add the second, fourth, sixth, eighth, tenth and twelfth digits.
 *  Add the first, third, fifth, seventh, ninth, and eleventh digits.
 *  Multiply the first sum by 3 and add it to the second sum.
 *  Subtract 1 from the total.
 *  Compute the remainder when the adjusted total is divided by 10.
 *  Subtract the remainder from 9.
 *
 *  For example, consider Güllüoglu Turkish Delight Pistachio & Coconut, 
 *  which has an EAN of 86914842660008. The first sum is 6 + 1 + 8 + 2 + 0
 *  + 0 = 17, and the second sum is 8 + 9 + 4 + 4 + 6 + 0 = 31. Multiplying
 *  the first sum by 3 and adding the second yields 82. Subtracting 1 gives
 *  81. The remainder upon dividing by 10 is 1. When the remainder is 
 *  subtracted from 9, the result is 8, which matches the last digit of the
 *  original code. Your job is to modify the upc.c program of Section 4.1 so 
 *  that it calculates the check digit for an EAN. The user will enter the 
 *  first 12 digits of the EAN as a single number:
 *
 *      Enter the first 12 digits of an EAN: 869148426000
 *      Check digit: 8
 *
 * _____________________________________________________________________________________________
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZECD 12
#define INT(ch) (ch-'0')
#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            fputs((s), stdout);\
            exit(1);\
        }\
    }while(0)  


int calc_check_digitEAN(char*);
int* string_to_int_array(char*);

int main(void)
{
    char digits[SIZECD];
    
    fputs("Enter the first 12 digits of an EAN: ",stdout);
    fscanf(stdin,"%s",digits);

    fprintf(stdout,"check digit: %d\n",calc_check_digitEAN(digits));
    
return EXIT_SUCCESS;
}

int calc_check_digitEAN(char* digits){
    int first_sum = 0, second_sum = 0;
    int total = 0, cd = 0;
    int size = strlen(digits);
    
    EXIT_IF(size != 12, "Error! invalid size");

    int* newDigits=string_to_int_array(digits);

    for(unsigned int i=0; i<size; ++i){
        if(i%2 == 0)
            first_sum+=newDigits[i];
        else
            second_sum+=newDigits[i];
    }

    total = first_sum + second_sum*3;
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

