/*
 * =====================================================================================
 *
 *       Filename:  1031.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月19日 21时45分54秒
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

using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int l = (n+2)/3;
    int d = n+2-l*2;
    string bla("");
    int i=0;
    for(; i<d-2; i++)
        bla += " " ;
    for(i=0;i<l-1;i++)
        cout << s[i] << bla << s[n-i-1] << endl;
    for(; i<l+d-1; i++)
    cout << s[i];
    return 0;
}

