/*
 * =====================================================================================
 *
 *       Filename:  1016.cpp
 *
 *    Description: A long-distance telephone company charges its customers by the following rules:

 Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

 Input Specification:

 Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

 The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

 The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

 For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

 Output Specification:

 For each test case, you must print a phone bill for each customer.

 Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

 Sample Input:
 10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
 10
 CYLL 01:01:06:01 on-line
 CYLL 01:28:16:05 off-line
 CYJJ 01:01:07:00 off-line
 CYLL 01:01:08:03 off-line
 CYJJ 01:01:05:59 on-line
 aaa 01:01:01:03 on-line
 aaa 01:02:00:01 on-line
 CYLL 01:28:15:41 on-line
 aaa 01:05:02:24 on-line
 aaa 01:04:23:59 off-line
 Sample Output:
 CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80 
 *
 *        Version:  1.0
 *        Created:  2014年05月24日 21时00分56秒
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
#include <vector>
#include <map>
#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;
typedef map<string, vector<vector<int> > > mapdef;
int main()
{
    vector<int> rate(24);
    int n;
    mapdef data;
    string chName, chLine;
    vector<int> tmpData(5);
    for(vector<int>::size_type ix = 0; ix!=rate.size(); ix++)
    {
        cin >> rate[ix];
    }
    cin >> n;
    for( int i=0; i<n; i++)
    {
        cin >> chName;
        scanf("%d:%d:%d:%d",&tmpData[0],&tmpData[1],&tmpData[2],&tmpData[3]);
        cin >> chLine;
        if(chLine == "on-line")
            tmpData[4] = 0;
        else 
            tmpData[4] = 1;
        mapdef::iterator it = 
            data.find(chName);
        if (it != data.end())
        {
            it->second.push_back(tmpData);
        }else{
            data[chName].push_back(tmpData);
        }
    }
    for(mapdef::iterator ix=data.begin(); ix!=data.end(); ix++)
    {
        vector<vector<int> > datasecond = ix->second;
        cout << ix->first << " ";

        if(*(datasecond.begin()->begin())<10)
            cout << "0" << *(datasecond.begin()->begin()) << endl;
        else 
            cout << *(datasecond.begin()->begin()) << endl;

        sort(datasecond.begin(), datasecond.end());
        vector<double> bill;
        for(vector<vector<int> >::iterator itemp=datasecond.begin(); 
                itemp!=datasecond.end()-1; itemp++)
        {
            if((*itemp)[4]==0 && (*(itemp+1))[4]==1)
            {
                printf ( "%02d:%02d:%02d %02d:%02d:%02d ",(*itemp)[1] ,(*itemp)[2] ,(*itemp)[3] ,(*(itemp+1))[1],(*(itemp+1))[2],(*(itemp+1))[3]);
                int totaltime = (*(itemp+1))[3]-(*itemp)[3]
                    +((*(itemp+1))[2]-(*itemp)[2])*60
                    +((*(itemp+1))[1]-(*itemp)[1])*60*24;
                double billtemp = 0;

                (*(itemp+1))[2] += ((*(itemp+1))[1]-(*itemp)[1])*24;

                if((*(itemp+1))[2] == (*itemp)[2])
                {
                    billtemp += rate[(*itemp)[2]] * ((*(itemp+1))[3]-(*itemp)[3]) /100.0;
                }
                else
                {
                    billtemp += rate[(*itemp)[2]] * (60-(*itemp)[3]) / 100.0;
                    int i;
                    for(i = (*itemp)[2]+1;i<(*(itemp+1))[2]; i++)
                    {
                        billtemp += rate[i%24] * 60 / 100.0;
                    }
                    billtemp += rate[i%24] * (*(itemp+1))[3] / 100.0;
                }
                bill.push_back(billtemp);
                printf ( "%d $%.2f\n", totaltime, billtemp );
            }

        }
        if(bill.size()!=0)
        {
            double sum = accumulate(bill.begin(), bill.end(), 0.0);
            printf ( "Total amount: $%.2f\n", sum);
        }
    }
/*
    for(mapdef::iterator ix=data.begin(); ix!=data.end(); ix++)
    {
        vector<vector<int> > temp = ix->second;
        cout << ix->first << ":   ";
        for(vector<vector<int> >::iterator itemp=temp.begin(); itemp!=temp.end(); itemp++)
        {
            vector<int> temp2 = *itemp;
            for(vector<int>::iterator iii=temp2.begin(); iii!=temp2.end(); iii++)
            {
                cout << *iii << " " ;
            }
            cout << endl;
        }
    }
*/
}
