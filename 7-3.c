/*
 * =====================================================================================
 *
 *       Filename:  7-3.c
 *
 *    Description:  count prime num
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 22时04分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include <math.h>
#include <stdio.h>
int valPrime(int n)
{
    int i;
    for(i=3; i<=sqrt(n); i+=2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    int n ,m, i,  cnt=1;
    scanf("%d %d", &m, &n);
    if(m==1)
        printf("2 ");

    for(i=3; cnt<n; i+=2)
    {
        if(valPrime(i))
        {
            cnt++;
            if(cnt>=m)
            {
                if((cnt-m+1)%10 == 0)
                    printf("%d\n",i);
                else if(cnt  == n)
                    printf("%d", i);
                else
                    printf("%d ",i);
            }
        }
    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
