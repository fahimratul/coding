#include<bits/stdc++.h>

using namespace std;
template<typename T>
int partition(T a[],int low, int high){
    T pivot=a[high];
    int i=low-1;
    for(int j=low; j<high; j++){
        if(pivot>=a[j]){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

template <typename T>
int partition_f(T a[], int low , int high){
    T pivot=a[low];
    int i=low;
    for(int j=low+1; j<=high; j++){
        if(pivot>=a[j]){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i], a[low]);
    return i;
}



template <typename T>
int partition_r(T a[], int low , int high){
    T pivot=a[low];
    int i=low;
    for(int j=low+1; j<=high; j++){
        if(pivot<=a[j]){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i], a[low]);
    return i;
}







template<typename T> 
void quicksort(T a[],int low, int high){
    if(low<high){
        int mid=partition(a,low, high);
        quicksort(a,low, mid-1);
        quicksort(a,mid+1, high);
    }
    return;
}


int main(){
    int n;
    cin>>n;
    float a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quicksort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    

    return 0;
}
