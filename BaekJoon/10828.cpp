#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
map<string, int> list;
vector<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    list["push"] = 0;
    list["pop"] = 1;
    list["size"] = 2;
    list["empty"] = 3;
    list["top"] = 4;

    for(int i = 0; i < N; i++) {
        string tmp;
        cin>>tmp;
        int idx = list[tmp];
        if(idx == 0) {
            int tmp2;
            cin>>tmp2;
            st.push_back(tmp2);
        }
        else if(idx == 1) {
            if(st.size() == 0) {
                cout<<-1<<"\n";
            }
            else {
                cout<<st.back()<<"\n";
                st.pop_back();
            }
        }
        else if(idx == 2) {
            cout<<st.size()<<"\n";
        }
        else if(idx == 3) {
            if(st.empty()) {
                cout<<1<<"\n";
            }
            else {
                cout<<0<<"\n";
            }
        }
        else if(idx == 4) {
            if(st.size() == 0) {
                cout<<-1<<"\n";
            }
            else {
                cout<<st.back()<<"\n";
            }
        }

    }

}