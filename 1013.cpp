/*
 * =====================================================================================
 *
 *       Filename:  1013.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月26日 10时12分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

void funHandle(vector<vector<int> > table, int n, int del)
{
    vector<int> line(n-1);
    vector<vector<int> > newTable(n-1, line);
    int i ;

    for ( i = 0; i < n; i += 1 ) 
    {
        if (i==del)
            continue;
        line.insert(line.begin(),table[i].begin(),table[i].begin()+del);
        line.insert(line.end(),table[i].begin()+del+1,table[i].end()-1);
        for(vector<int>::iterator ix=line.begin(); ix!=line.end(); ix++)
            cout << *ix << "  ";

        cout << "end" << i << endl;

        
    }

    
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
    int n, m, k;
    int i, j, a, b;
    cin >> n >> m >> k;
    vector<int> line(n);
    vector< vector<int> > table(n,line);
    for ( i = 0; i < m; i += 1 ) 
    {
        cin >> a >> b;
        a--;b--;
        table[a][b]=1;
        table[b][a]=1;
    }
    vector<int> concern(k);
    for ( i = 0; i < k; i += 1 ) 
    {
        cin >> concern[i];
    }

    for ( i = 0; i < k; i += 1 ) 
    { 
        funHandle(table, n, concern[i]-1);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout << table[i][j];
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
