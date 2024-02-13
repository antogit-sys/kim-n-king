/* - Progetti di Programmazione - 
   
   3. Modificate il programma del Progetto 2 in modo da che chieda
      all' utente di inserire il raggio della sfera.   
  
 */
#include <stdio.h>
int main(void)
{
	int r = 0; //raggio
	float v = 0.0f;
	
	printf("r: ");
	scanf("%d",&r); //input intero
	v = 4.0f/3.0f*3.14f*r*r*r; //volume
	
	printf("raggio: %d\n",r);
	printf("volume: %.2f\n",v);
	
return 0;	
}
