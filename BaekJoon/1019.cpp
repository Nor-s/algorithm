#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int number[10] = {0};

void addToNumber(int n, int x) {
    number[n] += x;
}

void addCount(int n, int digit) {
    if(n == 0) return;
    for(int i = 0; i < n; i++) {
        addToNumber(i, pow(10, digit));
        for(int i = 0; i < 10; i++) {
            addToNumber(i, (digit)*pow(10,digit-1));
        }
    }
    for(int i = 0; i <= digit; i++) {
        addToNumber(0, -1*pow(10, i));
    }
    addToNumber(n, 1);
    addToNumber(0, digit);

}

void counting(string& n) {
    int digit = 1;
    for(int i = 0; i < n.size(); i++) {
        int num = (int)n[i] - '0';
        addCount(num, i);

        for(int j = i+1; j < n.size(); j++) {
            addToNumber((int)n[j]- '0', num*digit);
        }
        digit*= 10;
    }

}

int main() {
    string n;
    cin>>n;
    reverse(n.begin(), n.end());
    counting(n);
    for(int i = 0; i < 10; i++) {
        cout<<number[i]<<" ";
    }
}