/* Project of prog
 *
 * 11. Write a program that asks the user for a two-digit 
 * number, then prints the English word for the number:
 *  
 *  Enter a two-digit number: 45
 *  You entered the number forty-five.
 *
 * Hint: Break the number into two digits. Use one switch 
 * statement to print the word for the first digit 
 * ("twenty," "thirty," and so forth). Use a second switch 
 * statement to print the word for the second digit. Don't 
 * forget that the numbers between 11 and 19 require special 
 * treatment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TENS(num) (num/10)
#define ONES(num) (num%10)

#define NEW(type,n) ((type*)malloc(sizeof(type)*n))

#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            fputs((s), stdout);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)  

const char* num_to_letter(unsigned int);

int main(void)
{
    int num;

    printf("Enter a two digit number: ");
    scanf("%d", &num);

    printf("You entered the number %s.\n",num_to_letter(num));

    return 0;
}

const char* num_to_letter(unsigned int n){
    EXIT_IF(n>=100,"Error: (num_to_letter) num rande max [1 - 99]\n");
    EXIT_IF(n == 0,"Error: (num_to_letter) num -> [0] not valid\n");

    int tens = TENS(n);
    int ones = ONES(n);

    // 21 max + '\0'
    char *buf = NEW(char, 22);
    EXIT_IF(buf == NULL, "Error: (num_to_letter) Dynamic allocation failed\n");

    if(tens == 1){
        switch(ones){
            case 0: strcpy(buf,"ten"); break;
            case 1: strcpy(buf,"eleven"); break;
            case 2: strcpy(buf, "twelve"); break;
            case 3: strcpy(buf, "thirteen"); break;
            case 4: strcpy(buf, "fourteen"); break;
            case 5: strcpy(buf, "fifteen"); break;
            case 6: strcpy(buf, "sixteen"); break;
            case 7: strcpy(buf, "seventeen"); break;
            case 8: strcpy(buf, "eighteen"); break;
            case 9: strcpy(buf, "nineteen"); break;
        }
    }else{
        switch(tens){
            case 2: strcpy(buf, "twenty-"); break;
            case 3: strcpy(buf, "thirty-"); break;
            case 4: strcpy(buf, "forty-"); break;
            case 5: strcpy(buf, "fifty-"); break;
            case 6: strcpy(buf, "sixty-"); break;
            case 7: strcpy(buf, "seventy-"); break;
            case 8: strcpy(buf, "eighty-"); break;
            case 9: strcpy(buf, "ninety-"); break;
        }

        switch(ones){
            case 1: strcat(buf, "one"); break;
            case 2: strcat(buf, "two"); break;
            case 3: strcat(buf, "three"); break;
            case 4: strcat(buf, "four"); break;
            case 5: strcat(buf, "five"); break;
            case 6: strcat(buf, "six"); break;
            case 7: strcat(buf, "seven"); break;
            case 8: strcat(buf, "eight"); break;
            case 9: strcat(buf, "nine"); break;
        }
    }
    return buf;
}

/*
    if (TENS(num) == 1){
        switch(ONES(num)){
            case 0: printf("ten."); break;
            case 1: printf("eleven."); break;
            case 2: printf("twelve."); break;
            case 3: printf("thirteen."); break;
            case 4: printf("fourteen."); break;
            case 5: printf("fifteen."); break;
            case 6: printf("sixteen."); break;
            case 7: printf("seventeen."); break;
            case 8: printf("eighteen."); break;
            case 9: printf("nineteen."); break;
        }
    }else{
        switch(TENS(num)){
            case 2: printf("twenty-"); break;
            case 3: printf("thirty-"); break;
            case 4: printf("forty-"); break;
            case 5: printf("fifty-"); break;
            case 6: printf("sixty-"); break;
            case 7: printf("seventy-"); break;
            case 8: printf("eighty-"); break;
            case 9: printf("ninety-"); break;
        }
        
        switch(ONES(num)){
            case 1: printf("one."); break;
            case 2: printf("two."); break;
            case 3: printf("three."); break;
            case 4: printf("four."); break;
            case 5: printf("five."); break;
            case 6: printf("six."); break;
            case 7: printf("seven."); break;
            case 8: printf("eight."); break;
            case 9: printf("nine."); break;
        }
    }*/
