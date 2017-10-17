#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin >> n && n != EOF){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool sb = true, qb = true, pqb = true;
        for(int i = 0; i < n; i++){
            int op, v;
            cin >> op >> v;
            if(op == 1){
                s.push(v);
                q.push(v);
                pq.push(v);
            } else {
                if(s.empty() ||s.top() != v) sb = false;
                if(q.empty() || q.front() != v) qb = false;
                if(pq.empty()||pq.top() != v) pqb = false;
                if(!s.empty())s.pop(); 
                if(!q.empty())q.pop();
                if(!pq.empty())pq.pop();
            }
        }
        vector<bool> ve{sb,qb,pqb};
        int res = 0;
        for(bool b: ve){
            if(b) res++;
        }
        if(res > 1) cout << "not sure" << endl;
        else if(res == 1){
            if(sb) cout << "stack" << endl;
            else if(qb) cout <<"queue" << endl;
            else if(pqb) cout << "priority queue" << endl;
        } else cout << "impossible" << endl;
    }
}
