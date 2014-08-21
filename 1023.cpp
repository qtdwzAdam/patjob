/*
 * =====================================================================================
 *
 *       Filename:  1023.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月17日 22时13分23秒
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
#include <algorithm>
using namespace std;
int main()
{
    string num;
    cin >>num;
    reverse(num.begin(), num.end());
    string out;
    int da, in=0;
    for(int i=0; i<num.size(); i++)
    {
        da = in + (num[i]-'0')*2;
        if(da>=10)
        {
            in = 1;
            da = da%10;
        }else
            in = 0;
        out+=da+'0';
    }
    if(in)
        out+='1';
    reverse(out.begin(),out.end());
    for(int i=0; i<out.size(); i++)
    {
        string::iterator it = find(num.begin(), num.end(), out[i]);
        if(it==num.end())
        {
            cout << "No" << endl;
            cout << out << endl;
            return 0;
        }
        *it = 'a';
    }
    cout << "Yes\n" << out << endl;
    return 0;

}

