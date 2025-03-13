#include<bits/stdc++.h>

using namespace std;
 
void permitation(vector<int> &v, vector<vector<int>> &subset, int index){
    if(index == v.size()){
        subset.push_back(v);
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=index;i<v.size();i++){
        cout<<"swapping "<<v[index]<<" "<<v[i]<<endl;
        swap(v[index],v[i]);
        permitation(v,subset,index+1);
        cout<<"swapping "<<v[index]<<" "<<v[i]<<endl;
        swap(v[index],v[i]);
    }
}



int main(){
    vector<int> v={1,2,3};
    vector<vector<int>> subset;
    permitation(v,subset,0);
}