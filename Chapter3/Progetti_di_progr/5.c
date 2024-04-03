/* - Progetti di prog
 *
 *  5. traccia che inserirò dopo XD
 *  ...
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long ulong;

ulong** create_matrix(ulong, ulong, bool);
ulong** fill_matrix(ulong, ulong, ulong, ulong);

int main()
{
    int** m = (int**)create_matrix(4,4, true);
    

return 0;
}

ulong** create_matrix(ulong r, ulong c, bool f_fill){
    ulong **m = (ulong**) calloc(r, sizeof(ulong*));
    ulong size = r*c;

    if(m == NULL){
	    fprintf(stderr,"Error of allocation the memory for rows\n");
	    exit(1);	
    }
	
    for(size_t i=0; i<r; ++i){
	    m[i] = (ulong*)calloc(c, sizeof(ulong));
	    if(m[i] == NULL){
	    	fprintf(stderr,"Error of allocation the memory for columns\n");
		   	exit(1);	
	    }
    }

    (f_fill == true)? m = fill_matrix(1, size, r,c):0;

	return m;
}


ulong** fill_matrix(ulong n_min, ulong n_max, ulong r, ulong c){
    if(r*c != n_max-n_min+1){
		fprintf(stderr,"Error number maximum is less of max number element\n");
		exit(1);
	}

}
