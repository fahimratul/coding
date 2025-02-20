#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        string names;
        int roll;
        int dsa;
        int c;
        int TEC;
};


int partition(vector<Node> &a, int low, int high){
    int pivot=a[high].dsa;
    int i=low-1;
    for(int j=low; j<high; j++){
        if(pivot>a[j].dsa){
            i++;
            swap(a[j], a[i]);
        }
    }
    // cout<<pivot<<endl;
    swap(a[i+1], a[high]);
    return i+1;
}

void quicksort(vector<Node> &a, int low , int high){
    if(low<high){
        int pivot= partition(a, low, high);
        // cout<<pivot<<endl;
        quicksort(a, low, pivot-1);
        quicksort(a, pivot+1, high);
    }
}


int main(){
    int n;
    cin>>n;
    vector<Node>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].names;
        cin>>a[i].roll;
        cin>>a[i].dsa;
        cin>>a[i].c;
        cin>>a[i].TEC;
        cin.ignore();       
    }
    quicksort(a,0,n-1);
    for(int i=0; i<n; i++){
        if(a[i].TEC<40){
            continue;
        }
        cout<<a[i].names<<" "<<a[i].dsa<<endl;
    }


}