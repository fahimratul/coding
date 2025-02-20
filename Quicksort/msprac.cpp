#include<bits/stdc++.h>


using namespace std;
int marge(int a[], int low, int mid , int high){
    int i=low;
    int j=mid+1;
    int invcount=0;
    vector<int> temp;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
        invcount++;
    }
    while (i<=mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(a[j]);
        i++;
    }
    for(int i=0; i<temp.size(); i++){
        a[i+low]=temp[i];
    }

}


int margesort(int a[], int low, int high){
    int invcount=0;
    if(low<high){
        int mid=(low+high)/2;
        invcount+=margesort(a, low, mid);
        invcount+=margesort(a, mid+1, high);
        invcount+=marge(a, low, mid, high);
    }
    return invcount;
}