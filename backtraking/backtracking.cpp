#include<bits/stdc++.h>
using namespace std;

void printsubset(vector<int> &v,vector<int> &subset,int index){
    if(index == v.size()){
          for(auto i:subset){
              cout<<i<<" ";
          }
            cout<<endl;
            return;
    }
    cout<<"pushing "<<v[index]<<endl;
    subset.push_back(v[index]);
    printsubset(v,subset,index+1);
    cout<<"popping "<<v[index]<<endl;
    subset.pop_back();
    printsubset(v,subset,index+1);
}



int main(){
    vector<int> v={1,2,3,4};
    vector<int> subset;
    printsubset(v,subset,0);
}