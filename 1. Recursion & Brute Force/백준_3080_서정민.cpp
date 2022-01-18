#include<iostream>
#include<vector>
#include<array>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>

#define INF 987654321
#define MIN 1e-10
#define HASHNUM 37813

using namespace std;

#define intA 65
#define div 1000000007
int dp[3001];
string* pass = new string("pass");

int factorial(int* cache, int n){
    if(n==0) return 1;
    else if(n<0){
        cout << "factorial error"<<endl;
        return 1;
    }
    if(cache[n]!=0) return cache[n];
    long long ret = 1;
    for(int i=1; i<=n; i++){
        ret*=i;
        ret%=div;
    }
    cache[n] = (int)ret;
    return (int)ret;
}
int max(int a, int b){
    return a>b ? a : b;
}
class Node{
    public:

        vector<Node*> nextList = *new vector<Node*>();
        vector<string*> value = *new vector<string*>();
        int passNum = 0;
        string key = "";
        int dim;
        Node(string key){
            this->key = key;
            dim = key.length();
        }
        
        Node(string* str, int dim){
            key = str->substr(0, dim);
            value.push_back(str);
            this->dim = dim;
        }
        Node(){
        }
        void setNext(Node* n){
            nextList.push_back(n);
            n->dim = dim+1;
            /*
            if(n->key.length()!=n->dim){
                cout << "dim error" <<endl;
            }
            */
        }
        void addString(string* str){
            value.push_back(str);
        }
        
        void chainPush(string* in, int i){
            int leng = in->length();
            if(leng<=i) return;
            string sub = in->substr(i, 1);
            for(Node* k : nextList){
                if(k->key.compare(sub)==0){
                    k->chainPush(in, i+1);
                    return;
                }
            }

            vector<string*>::iterator iter = value.begin();
            for (iter; iter!=value.end(); iter++){
                string* j = *iter;
                if(j->length()<=i || j==in || j==pass) continue;
                string jsub = j->substr(i, 1);
                if(sub.compare(jsub)==0){
                    Node* newone = new Node(sub); 
                    newone->addString(j);
                    setNext(newone);
                    *iter = pass;
                    passNum++;
                    newone->chainPush(in, i+1);
                    return;
                }
            }
            addString(in);
            
            return;
        }
        int DFS(){
            if(nextList.size()==0){
                
                //DEBUGGING
                /*
                cout << "last key : "<<key<< ", dim : "<<dim  <<", return DFS : "<< value.size() <<endl;
                
                for(string* i : value){
                    cout << "string : "<<*i<<endl;
                }
                */


                return (long long)value.size();
            }
            long long ret = 1;
            int leng = value.size() - passNum;
            for(Node* i : nextList){
                leng++;
                ret*=i->DFS();
                ret %= div;
            }
            
            //DEBUGGING
            /*
            cout << "key : "<<key<<", dim : "<<dim <<", DFS : "<< (int)(((long long)factorial(dp, leng))*ret%div) <<endl;
            
            for(string* i : value){
                    cout << "string : "<<*i<<endl;
            }
            */
            
            return (int)(((long long)factorial(dp, leng))*ret%div);

        }


};
class ArrayTree{
    public:
        vector<Node*> arr = *new vector<Node*>(26, nullptr);
        ArrayTree(){}
        void setNode(Node* n){
            if(n->dim!=1) return;
            int idx = (int)(n->key[0]) - intA;
            arr[idx] = n;
        }
        void push(string* in){
            int leng = in->length();
            int idx = (int)(in->at(0))-intA;
            if(arr[idx]==nullptr){
                setNode(new Node(in, 1));
                return;
            }
            arr[idx]->chainPush(in, 1);
            return;
        }
        int DFS(){
            long long ret = 1;
            int element = 0;
            for(Node* i : arr){
                if(i!=nullptr){
                    int d = i->DFS();

                    //DEBUGGING
                    //cout <<i->key << " : "<<d<<endl;

                    ret*=(long long)d;
                    ret%= div;
                    element++;
                }
            }
            return (int)(ret*factorial(dp, element) % div);
        }

};

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ArrayTree tree = *new ArrayTree();
    
    
    //scaffording    
    /*
    vector<string> arr;
    
    for(int i=0; i<3000; i++){
        int loopNum =  rand()%2999+1;
        string* put = new string("");
        for(int j=0; j<loopNum; j++){
            *put=*put + string({(char)(rand()%26+intA)});
        }
        if(arr.end() != find(arr.begin(), arr.end(), *put)) continue;
        //cout << "put"<<i+1 <<" = "<<*put <<endl;
        arr.push_back(*put);
        tree.push(put);

    }
    
    cout << tree.DFS();
    */



    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string* put = new string();
        cin >> *put;
      //  arr.push_back(put);
        tree.push(put);
    }
    cout << tree.DFS();
    
    return 0;

}

