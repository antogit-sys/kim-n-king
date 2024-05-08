#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CONVERT_TO_24_HOUR(hours) (hours+=12)

typedef struct{
    int hours;
    int minutes;
}Time;

Time input_t(const char*);
const char *view_t(Time); 

int main(void)
{
    Time t;
    
    t = input_t("Enter a 12-hour: ");
    fprintf(stdout,"Equivalent 24 hour time: %s\n",view_t(t));

return EXIT_SUCCESS;
}

Time input_t(const char *__s){
    Time t;
    char pm;

    fputs(__s,stdout);
    fflush(stdout);

    int result = fscanf(stdin, "%d:%d %c", &t.hours, &t.minutes, &pm);

    if (result != 3) {
        fputs("Error: Invalid time format!",stderr);
        exit(EXIT_FAILURE);
    }

    pm = toupper(pm); // Converti in maiuscolo per confronto case-insensitive

    if (pm != 'P') {
        fprintf(stderr, "%s", "Error: Invalid PM indicator!\n");
        exit(EXIT_FAILURE);
    }

    if (t.hours > 24 || t.minutes > 59) {
        fputs("Error: Invalid time!\n",stderr);
        exit(EXIT_FAILURE);
    }

    return t;
}

const char *view_t(Time t){
    //xx:yy
    char *buf = (char *)malloc(sizeof(char) * 6);

    if (buf == NULL) {
        fputs("Memory allocation failed\n",stderr);
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "%.2d:%.2d", CONVERT_TO_24_HOUR(t.hours), t.minutes);
    if(strlen(buf) > 6){
        puts("Error: size too large, overflow...");
        exit(EXIT_FAILURE);
    }
    
    return buf;
}

