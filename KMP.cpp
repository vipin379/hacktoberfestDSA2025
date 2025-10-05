#include <bits/stdc++.h>
using namespace std;

/*
KMP pattern matching
- Precompute LPS (longest proper prefix that is also suffix).
- Skips redundant comparisons.
Time: O(n + m) | Space: O(m)
*/

vector<int> lpsArray(const string& p){
    int m=p.size(); vector<int> lps(m,0);
    for(int i=1,len=0;i<m;){
        if(p[i]==p[len]) lps[i++]=++len;
        else if(len) len=lps[len-1];
        else lps[i++]=0;
    }
    return lps;
}

vector<int> kmpSearch(const string& s,const string& p){
    vector<int> lps=lpsArray(p), pos;
    for(int i=0,j=0;i<(int)s.size();){
        if(s[i]==p[j]){ i++; j++; if(j==(int)p.size()){ pos.push_back(i-j); j=lps[j-1]; } }
        else if(j) j=lps[j-1];
        else i++;
    }
    return pos;
}

int main(){
    string s="abxabcabcaby", p="abcaby";
    auto idx = kmpSearch(s,p);
    for(int x: idx) cout<<x<<" "; // 6
}
