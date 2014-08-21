/*
 * =====================================================================================
 *
 *       Filename:  1024.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月17日 23时05分21秒
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
#include <string>
#include <algorithm>
using namespace std;
int ispa(string n)
{
    string s(n);
    reverse(s.begin(),s.end());
    return s==n;
}
int main()
{
    string n;
    int k;
    cin >> n>>k;
    int it=0;
    int su,in=0;
    do{
        if(ispa(n)) break;
        string s(n);
        reverse(s.begin(),s.end());
        string out;
        in = 0;
        for(int i=0;i<s.size();i++)
        {
            su = s[i]-'0' + n[i]-'0' + in;
            if(su>=10)
            {
                su%=10;
                in = 1;
            }else
                in = 0;
            out += su+'0';
        }
        if(in)
            out +='1';
        reverse(out.begin(), out.end());
        n = out;
        it++;
    }while(it<k);
    cout << n <<"\n"<<it<<endl;
    return 0;
}

