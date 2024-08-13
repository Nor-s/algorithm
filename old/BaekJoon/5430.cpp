#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
string instruction;
int n;
list<int> item;
bool isReversed = false;

void R() {
    isReversed = !isReversed;
}
bool D() {
    if(item.empty()) {
        return false;
    }
    if(isReversed) {
        item.pop_back();
    }
    else {
        item.pop_front();
    }
    return true;
}


int main() {
    int T;
    cin>>T;
    while(T--) {
        isReversed = false;
        cin>>instruction;
        cin>>n;
        char tmp1;
        cin>>tmp1;
        for(int i = 0; i < n; i++) {
            int tmp2;
            cin>>tmp2;
            item.push_back(tmp2);
            if(i != n-1) {
                cin>>tmp1;
            }
        }
        cin>>tmp1;
        int i = 0;
        for(i = 0; i < instruction.length(); i++) {
            if(instruction[i] == 'R') {
                R();
            } else {
                if(!D()) {
                    cout<<"error\n";
                    item.clear();
                    break;
                }
            }
        }
        if(i == instruction.length()) {
            cout<<"[";
            while(!item.empty()) {
                if(isReversed) {
                    cout<<item.back();
                    item.pop_back();
                }
                else {
                    cout<<item.front();
                    item.pop_front();
                }   
                if(item.size() != 0) {
                    cout<<",";
                }
            }
            cout<<"]\n";
        }
    }
}