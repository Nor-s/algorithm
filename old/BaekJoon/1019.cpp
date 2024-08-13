#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

long long number[10] = {0};

void printNumber() {
    for(int i = 0; i < 10; i++) {
        cout<<number[i]<<" ";
    }
    cout<<"\n";
}
void addToNumber(int n, long long x) {
    number[n] += x;
}

void addCount(int n, long long digit, int idx) {
    if(n == 0) return;
    for(int i = 0; i < n; i++) {
        addToNumber(i,digit);
        for(int j = 0; j < 10; j++) {
            addToNumber(j, (idx)*digit/10);
        }
    }
    
    addToNumber(n, 1);
    addToNumber(0, idx);
}

void counting(string& n) {
    long long digit = 1;
    for(int i = 0; i < n.size(); i++) {
        int num = (int)n[i] - '0';
        addCount(num, digit ,i);
        if(i != n.size() -1 && num != 0) {
            addToNumber(0, -i-1);
        }

        for(int j = i+1; j < n.size(); j++) {
            addToNumber((int)n[j]- '0', num*digit);
        }
        addToNumber(0, -1*digit);
        digit*= 10;
    }    
}
void converting(int n) {
    vector<int> countNum(10, 0);
    for(int i = 1; i <= n; i++) {
        int tmp = i;
        while(tmp != 0) {
            countNum[tmp%10]++;
            tmp/=10;
        }
    }
    for(int i = 0; i < 10; i++) {
        cout<<countNum[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    string n;
    cin>>n;
    converting(stoi(n));
    reverse(n.begin(), n.end());
    counting(n);
    printNumber();
}