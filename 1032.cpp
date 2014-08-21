/*
 * =====================================================================================
 *
 *       Filename:  1032.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月19日 22时01分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Adam_zju 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int st1, st2, n;
    cin >> st1>>st2>>n;
    int i;
    int da[ 100000 ]={0};
    int id;

    char t;
    int next;
    for(i=0; i<n; i++)
    {
        cin >> id >> t >> next;
        da[ id ]=next;
    }
    int it = da[st1];
    int w1[ 100000 ]={0};
    w1[it] = 1;
    while(it != -1){
        w1[it] = 1;
        it = da[it];
    }
    it = da[st2];
    while( it != -1)
    {
        if(w1[it] == 1)
        {            
            printf("%05d\n",it);
            return 0;
        }
        it = da[it];
    }
    cout<<"-1" <<endl;
    return 0;
}

