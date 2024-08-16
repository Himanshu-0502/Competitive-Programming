#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int cntEnd=0;
    int cntPre=0;
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(auto ch:word){
            if(node->get(ch)==nullptr) node->put(ch,new Node());
            node=node->get(ch);
            node->cntPre+=1;
        }
        node->cntEnd+=1;
    }
    int countString(string word){
        Node* node=root;
        for(auto ch:word){
            if(node->get(ch)==nullptr) return 0;
            node=node->get(ch);
        }
        return node->cntEnd;
    }
    int countPrefix(string word){
        Node* node=root;
        for(auto ch:word){
            if(node->get(ch)==nullptr) return 0;
            node=node->get(ch);
        }
        return node->cntPre;
    }
    void erase(string word){
        Node* node=root;
        for(auto ch:word){
            if(node->get(ch)==nullptr) return;
            node=node->get(ch);
            node->cntPre-=1;
        }
        node->cntEnd-=1;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}