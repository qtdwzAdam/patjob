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
#include <algorithm>
#include <vector>
using namespace std;

class MyClass{
    public:
        int id;
        char c;
        int next;
};
int cmpId(MyClass i, MyClass j) { return i.id<j.id; }
int cmpCH(MyClass i, MyClass j) { return i.c<j.c; }
int main()
{
    int st1, st2, n;
    cin >> st1>>st2>>n;
    int i;
    vector<MyClass> da;
    vector<int> tempList;
    MyClass temp;
    for(i=0; i<n; i++)
    {
        cin >> temp.id >> temp.c >> temp.next;
        da.push_back(temp);
        tempList.push_back(temp.id);
    }

    sort(da.begin(), da.end(), cmpId);
    sort(tempList.begin(),tempList.end());
    vector<MyClass>::iterator it;
    vector<int>::iterator itInt;
    string word1("");
    while(it->next != -1)
    {
        word1+=it->c;
        cout << it->c;
        itInt = lower_bound(tempList.begin(), tempList.end(), it->next);
        it = da.begin()+(itInt-tempList.begin());

    }
    cout << word1;
}

