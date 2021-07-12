#include <bits/stdc++.h>

using namespace std;
string P, T;
int TLen = 0;
int PLen = 0;
int F[1000001];

void kmp() {
    int ret[1000001];
    int k = 0;
    int i = 0, j = -1;
    while(i < TLen) {
        if(T[i] == P[j + 1]){
            if(j + 1 == PLen - 1) {
                j = F[j + 1];
                ret[k++] = i - PLen + 1;
            }
            else {
                j++;
            }
            i++;
        }
        else {
            if(j == -1) {
                i++;
            }
            else {
                j = F[j];
            }
        }
    }
    cout<<k<<"\n";
    for(int i = 0; i < k; i++) {
        cout<<ret[i] + 1 <<" ";
    }
}

void initial() {
    F[0] = -1;
    for(int i = 1; i < PLen; i++) {
        int before = F[i-1];
        while(P[before + 1] != P[i] && before >= 0) {
            before = F[before];
        }
        if(P[before + 1] == P[i])
            F[i] = before + 1;
        else {
            F[i] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cout.tie(0);
    cin.tie(0);

    getline(cin, T);
    getline(cin, P);

    TLen = T.size();
    PLen = P.size();

    initial();
    kmp();
}