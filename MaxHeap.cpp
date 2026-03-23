#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    private:
        vector<int>H;
        void HeapifyDown(int par){
            int n = H.size();
            while(par < n){
                int l = 2 * par + 1;
                int r = 2 * par + 2;
                int larg = par;
                if(l < n && H[larg] < H[l])larg = l;
                if(r < n && H[larg] < H[r])larg = r;
                if(larg != par){
                    swap(H[larg],H[par]);
                    par = larg;
                }else break;
            }
        }
        void HeapifyUp(int child){
            while(child > 0){
                int p = (child - 1)/2;
                if(H[p] < H[child]){
                    swap(H[p],H[child]);
                    child = p;
                }else break;
            }
        }
    public:
        bool empty(){
            return H.empty();
        }
        int top(){
            if(H.empty())return -1;
            return H[0];
        }
        void pop(){
            if(H.empty())return;
            H[0] = H.back();
            H.pop_back();
            HeapifyDown(0);
            return;
        }
        void push(int val){
            H.push_back(val);
            HeapifyUp(H.size() - 1);
            return;
        }
};

int main(){
    MaxHeap pq;
    pq.push(10);
    pq.push(49);
    pq.push(1);
    pq.push(299);
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}
