#include<bits/stdc++.h>

using namespace std;

int par[1000];
//  Rank[1000];
int countcom;


int pathcomp(int a){
    if(par[a]==a){
        return a;
    } 
    // Rank[a]++;
    par[a]=pathcomp(par[a]);
    return par[a];
}

void Union_(int a, int b){
    int pa=pathcomp(a);
    int pb=pathcomp(b);
    if(pa==pb){
        return; 
    }
    if(pb>pa){
        par[pb]=pa;
    }
    else{
        par[pa]=pb;
    }
    countcom--;
}


int main(){
    int V=10;
    //cin>>V;
    countcom=V;
    for(int i=1; i<=V; i++ ){
        par[i]=i;
        // Rank[i]=0;
    }

    Union_(1,2);
    Union_(3,4);
    Union_(2,4);

    Union_(1,4);
    Union_(3,2);
    Union_(5,6);
    Union_(7,8);
    Union_(5,8);
    Union_(4,7);
    Union_(9,10);

    for (int i = 1; i <=V; i++)
    {
        cout<<i<<" " <<par[i]<<endl;
    }
    //cout<<pathcomp(5)<<endl;
    

    cout<<countcom<<endl;
    
    

}
