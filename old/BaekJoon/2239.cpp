#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;


class SOO{

public:
    struct sooLine{
        bool checknum[10] = {false, };
        int line[9];
        void push(int x, int num) {
            line[x] = num;
            checknum[num] = true;
        }
    };
    sooLine vertical[9];
    sooLine horizontal[9];
    sooLine square[3][3];
    vector<pair<int, int> > bins;

    void push(int y, int x, int num) {
        vertical[x].push(y, num);
        horizontal[y].push(x, num);
        square[y/3][x/3].push( 3*(y%3)+ x%3, num);
        if(num == 0) {
            bins.push_back(make_pair(y, x));
        }
    }
    void print() {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout<<horizontal[i].line[j];
            }
            cout<<"\n";
        }
    }
    bool solve(int idx) {
        if(idx == bins.size()) {
            return true;
        }

        pair<int, int> yx = bins[idx];
        sooLine& h = horizontal[yx.first];
        sooLine& v = vertical[yx.second];
        sooLine& s = square[yx.first/3][yx.second/3];
        
        for(int i = 1; i <= 9; i++) {
            if(!h.checknum[i] && !v.checknum[i] && !s.checknum[i]) {
                h.line[yx.second] = i;
                v.line[yx.first] = i;
                s.line[(yx.first % 3) * 3 + yx.second % 3] = i;
                h.checknum[i] = v.checknum[i] = s.checknum[i] = true;
                if(solve(idx + 1)) {
                    return true;
                }
                h.line[yx.second] = 0;
                v.line[yx.first] = 0;
                s.line[(yx.first % 3) * 3 + yx.second % 3] = 0;
                h.checknum[i] = v.checknum[i] = s.checknum[i] = false;
            }
        }
        return false;
    }
};

int main() {
    SOO soo;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            char tmp;
            cin>>tmp;
            soo.push(i, j, (int)(tmp - '0'));
        }
    }
    soo.solve(0);
    soo.print();
}