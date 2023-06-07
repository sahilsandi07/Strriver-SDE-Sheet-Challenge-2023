#include <bits/stdc++.h>


vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> pairs;
   map<int,int> mp;
   for(int n:arr){
      mp[n]++;
   }


   map<int,int>::iterator itr=mp.begin();
   while(itr!=mp.end()){
      int val=itr->first;
      if(s-val<0 || val>(s-val)){
         break;
      }
      auto it=mp.find(s-val);
      if(it!=mp.end()){
         int count=val==it->first ? (itr->second*(itr->second-1))/2 : itr->second*it->second;
         for(int i=0;i<count;i++){
            pairs.push_back({val,it->first});
         }
      }
      itr++;
   }
   
   return pairs;
}