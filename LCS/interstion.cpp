#include<bits/stdc++.h>
#include "LCS.h"

using namespace std;

int main(){
    string s1="heap";
    string s2="pea";
    int i=LCS(s1,s2);
    cout<<s1.size()-i<<endl;
    cout<<s2.size()-i<<endl;
}