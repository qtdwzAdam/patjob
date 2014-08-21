/*
 * =====================================================================================
 *
 *       Filename:  1038.cpp
 *
 *    Description:  主要优点在于
 *          1. 数字和字符串到相互转换
 *          2. map绑定后自动排序
 *          3. 字符串到相关操作
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 22时37分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
string num2str(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}
int cntNum(int n)
{
    int i=1;
    while((n = n / 10)!=0)
        i++;
    return i;
}
int calSma(vector<string> str, int n1, int n2)
{
    string temp = str[n1];
    if(str[n1].size() >= str[n2].size() && str[n1] < str[n2])
        return 1;
    for(int i=0; i <= int((str[n2].size()-str[n1].size())/str[n1].size()); i++)
    {
        temp = temp + str[n1];
    }
    if(temp <= str[n2])
        return 1;

    return 0;
        
}
int main()
{
    vector<int> num;
    map<string, int> mapstr;
    map<string, int>::iterator msi;
    map<double, int> out;
    map<double, int>::iterator mi, mitemp;
    int ntemp, cnt;
    int n;
    int i;
    vector<string> str;
    string strtemp;
    
    cin >> n;
    for ( i = 0; i < n; i += 1 ) {
        cin >> ntemp;
        cnt = cntNum(ntemp);
        num.push_back(ntemp);
        out.insert( pair<double, int> (ntemp/pow(10,cnt), i));
        mapstr.insert( pair<string, int> (num2str(ntemp), i) );

    }
    for(msi=mapstr.begin(); msi!=mapstr.end(); msi++)
    {
        str.push_back(msi->first);
    }

    for(i=0; i<n-1; i++)
    {
        int ntemp = i;
        while(!(calSma(str, ntemp, ntemp+1)) && ntemp++ < n-1);
        
		if(ntemp > i)
		{
			ntemp = ntemp<n?ntemp:n-1;
			strtemp = str[i];
			str[i] = str[ntemp];
			str[ntemp] = strtemp;
		}
	
	        cout << str[i];

    }
	cout << str[i] << endl;


	return 0;
}
