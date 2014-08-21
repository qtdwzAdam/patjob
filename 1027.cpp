/*
 * =====================================================================================
 *
 *       Filename:  1027.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月03日 14时32分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
string lookid("0123456789ABC");

string change(int n)
{
    string out;
    if(n<13)
        out += lookid[n];
    else
        out = change(n/13) + lookid[n%13] + out;
    return out;


}
int main(){
    int a , b, c;
    cin >> a >> b >> c;
    cout << "#";
    if(change(a).size()==1)
        cout << "0" << change(a);
    else
        cout << change(a);
    if(change(b).size()==1)
        cout << "0" << change(b);
    else
        cout << change(b);
    if(change(c).size()==1)
        cout << "0" << change(c);
    else
        cout << change(c);
    cout << endl;
    return 0;

}
