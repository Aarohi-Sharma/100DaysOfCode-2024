#include <iostream>
#include <stack>
#include <map>
using namespace std;

class FreqStack {
public:
    map<int, int> freq;
    map<int, stack<int>> st;
    int maxFreq = 0;

    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        st[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        if(st[maxFreq].empty()) {
            maxFreq--;
        }
        int x = st[maxFreq].top();
        freq[x]--;
        st[maxFreq].pop();
        return x;
    }
};
