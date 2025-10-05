#include <bits/stdc++.h>
using namespace std;

/*
Sliding window with last-seen index.
Time: O(n) | Space: O(K) where K charset size
*/

int lengthOfLongestSubstring(const string& s){
    vector<int> last(256,-1);
    int best=0, start=0;
    for(int i=0;i<(int)s.size();++i){
        if(last[s[i]]>=start) start=last[s[i]]+1;
        last[s[i]]=i;
        best=max(best, i-start+1);
    }
    return best;
}

int main(){
    cout<<lengthOfLongestSubstring("abcabcbb")<<"\n"; // 3
    cout<<lengthOfLongestSubstring("bbbbb")<<"\n";     // 1
}
