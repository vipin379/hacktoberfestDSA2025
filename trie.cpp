#include <bits/stdc++.h>
using namespace std;

/*
Trie for lowercase 'a'-'z'
- Insert, exact search, prefix check.
Time per op: O(length) | Space: O(total chars)
*/

struct Node{
    bool end=false;
    array<int,26> nxt;
    Node(){ nxt.fill(-1); }
};

struct Trie{
    vector<Node> t; Trie(){ t.emplace_back(); }
    void insert(const string& s){
        int u=0;
        for(char c:s){
            int k=c-'a';
            if(t[u].nxt[k]==-1){ t[u].nxt[k]=t.size(); t.emplace_back(); }
            u=t[u].nxt[k];
        }
        t[u].end=true;
    }
    bool search(const string& s){
        int u=0;
        for(char c:s){
            int k=c-'a'; if(t[u].nxt[k]==-1) return false;
            u=t[u].nxt[k];
        }
        return t[u].end;
    }
    bool startsWith(const string& p){
        int u=0;
        for(char c:p){
            int k=c-'a'; if(t[u].nxt[k]==-1) return false;
            u=t[u].nxt[k];
        }
        return true;
    }
};

int main(){
    Trie tr; tr.insert("code"); tr.insert("coder");
    cout<<tr.search("code")<<" "<<tr.startsWith("co")<<" "<<tr.search("codex");
}
