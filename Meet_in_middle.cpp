#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void meetinmiddle()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>left,right;
    for(int i=0;i<n/2;i++)
    {
        left.push_back(a[i]);
    }
    for(int i=n/2;i<n;i++)
    {
        right.push_back(a[i]);
    }
    int n1=left.size();
    int n2=right.size();
    //apply power set for left half
    vector<int>s1;
    for(int num=0;num<(1<<n1);num++)
    {
        int sum=0;
        //generate all subsequence 
        for(int i=0;i<n;i++)
        {
            if(num&(1<<i))
            {
                sum+=left[i];
            }
        }
        s1.push_back(sum);
        
    }
    map<int,int>dic;
    for(int num=0;num<(1<<n2);num++)
    {
        int sum=0;
        for(int i=0;i<n2;i++)
        {
            if(num&(1<<i))
            {
                sum+=right[i];
            }
        }
        dic[sum]++;
    }
    int count=0;
    for(int i=0;i<s1.size();i++)
    {
        count+=dic[x-s1[i]];
    }
    cout<<count;
    
}
int main() {
    meetinmiddle();
	return 0;
}