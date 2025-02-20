#include<bits/stdc++.h>
#include "LCS.h"

using namespace std;

int main(){
    string s1="bbabcbcab";
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    LCS(s1, s2);
}

