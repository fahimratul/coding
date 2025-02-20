#include<bits/stdc++.h>

using namespace std;

void marge(int a[], int low, int mid, int high){
    int i=low;
    int j=mid+1;
    vector<int> b;

    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b.push_back(a[i]);
            i++;
        }
        else{
            b.push_back(a[j]);
            j++;
        }
    }
    
    while(j<=high){
            b.push_back(a[j]);
            j++;
    }
    while(i<=mid){
            b.push_back(a[i]);
            i++;
    }
    for(int i=0; i<b.size(); i++){
        a[i+low]=b[i];
    }
}


void margesort(int a[], int low, int high){
    if(high==low){
        return;
    }
    int mid=(low+high)/2;
    margesort(a,low,mid);
    margesort(a,mid+1, high);
    marge(a,low,mid, high);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    margesort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}