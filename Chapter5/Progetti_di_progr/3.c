/*
 * - Progetti di Prog
 *  
 *  3. Modify the broker.c program of Section 5.2 by making both of the following changes:
 *
 *  (a) Ask the user to enter the number of shares and the price per share, 
 *  instead of the value of the trade.
 *
 *  (b) Add statements that compute the commission charged by a rival broker ($33 plus 3 cents per share 
 *  fewer than 2000 shares; $33 plus 2 cents per share for 2000 shares or more). Display the rival's 
 *  commission as well as the commission charged by the original broker.
 *
 */


/*calcola le commissione di un broker*/
/*calculate a broker commissions*/

#include <stdio.h>

int main(void)
{
    float commission, value;
    float shares, share_p;
    float rival;

    fputs("Enter number of shares: ",stdout);
    scanf("%f",&shares);

    fputs("Enter price per share: ",stdout);
    scanf("%f",&share_p);

    /*** edit ! ***/
    value = shares*share_p;
    //-----------------------
    if (value < 2500.00f)
        commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;

    if (commission < 39.00f)
        commission = 39.00f;

    printf("Commission: $%.2f\n", commission);

    /*** edit ! ****/
    rival = (shares < 2000)?33.00f+.03f*shares : 33.00f+.02f*shares;

    printf("Rival comission: $%.2f\n", rival);
    printf("Diffecence commission: %.2f\n",commission>rival?commission-rival:rival-commission);
    

return 0;
}
