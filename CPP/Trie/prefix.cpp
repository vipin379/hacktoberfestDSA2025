#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    unordered_map<char,Node*> children;
    bool endOfWord ;
    int freq;

    Node(){
        endOfWord = false;
    }
};

class Trie{

    

public:

    Node* root;
    Trie(){
        root = new Node();
        root->freq=-1;
    }


    void insert(string key){
        Node* temp = root;

        for(int i=0;i<key.size();i++){

            if(temp->children.count(key[i])==0){
                temp->children[key[i]] = new Node();  
                temp->children[key[i]]->freq = 1; 
            }else{
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];

        }

        temp->endOfWord = true;
    }

    bool search(string key){
        Node*temp = root;

        for(int i=0;i<key.size();i++){
            if(!temp->children.count(key[i])){
                return false;
            }
            temp = temp->children[key[i]];
        }

        return temp->endOfWord;
    }
};


vector<string> Prefix( vector<string> words){
    Trie trie;

    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }


    vector<string> ans;
     
    
    
    for(int i=0;i<words.size();i++){
        Node* curr = trie.root;
        string key = words[i];
        string prefix="";
        for(int j=0;key.size();j++){

            prefix+=key[j];

           if( curr->children[key[j]]->freq==1){
             ans.push_back(prefix);
             break;
           }

           curr = curr->children[key[j]];
        }
    }

    return ans;

}


int main() {

    vector<string> words  = {"zebra" , "dog" , "dove" , "duck"};

    vector<string> prefix = Prefix(words);

    for(int i=0;i<prefix.size();i++){
        cout<<prefix[i]<<" , ";
    }

     
    
    return 0;
}