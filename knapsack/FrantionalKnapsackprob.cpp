#include<bits/stdc++.h>

using namespace std;

struct item{
    int weight;
    int value;
    float ratio;
    int ser;
    item(int i, int b, int k){
        value=i;
        weight=b;
        ratio=value/weight;
        ser=k;
    }
};

void printitems(vector<item> &itm){
    for(int i=0; i<itm.size(); i++){
        cout<<"Value of item "<<itm[i].ser<<" is:"<<itm[i].value<<" Weight is: "<<itm[i].weight<<" Ratio is"<<itm[i].ratio<<endl;
    }
}

bool comp(item a, item b ){
    return a.ratio>b.ratio;
}

float fractionalkansack(int n, int W,vector<item> &items,float profit=0){
 
    sort(items.begin(), items.end(), comp);
    
    printitems(items);
    for(int i=0; i<items.size(); i++){
        if(W>items[i].weight){
            profit=profit+items[i].value;
            W-=items[i].weight;
        }
        else{
            profit+=(W*items[i].ratio);
            break;
        }
    }
    return profit;
}

int main(){
    int items_no, capacity;
    cin>>items_no>>capacity;
    vector<item> items;
    for(int i=0; i<items_no; i++){
        int v, w;
        cin>>v>>w;
        items.push_back(item(v,w,i+1));
    }
    cout<<fractionalkansack(items_no, capacity, items)<<endl;
    
}