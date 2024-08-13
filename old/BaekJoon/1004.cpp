#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <set>
#include <cmath>
#include <map>

using namespace std;


struct uf{
    vector<pair<int, pair<int, int> > > p;
    struct tree{
        int number;
        vector<tree*> child;
        tree(int _number = -1) {
            number = _number;
        }
    };
    tree root;

    uf(int n): p(n){
        root = tree(-1);
    }
    bool isInclude(int idx, int x, int y) {
        if(idx == -1)
            return true;
        return (pow(x - p[idx].second.first,2) + pow(y - p[idx].second.second,2)) <= pow(p[idx].first,2);
    }
    void change(int idx, int x, int y, int r) {
        p[idx] = make_pair(r, make_pair(x, y));
    }
    bool comp(pair<int, pair<int, int> > & a, pair<int, pair<int, int> >& b) {
        return a.first > b.first;
    }
    bool insert(tree* treep, int idx) {
        if(isInclude(treep->number, p[idx].second.first, p[idx].second.second)) {
            for(int i = 0; i < treep->child.size(); i++) {
                if(insert(treep->child[i], idx)) {
                    return true;
                }
            }
            treep->child.push_back(new tree(idx));
            return true;
        }
        return false;
    }
    void makeTree() {
        sort(p.begin(), p.end());//, comp);
        for(int i = p.size() - 1; i >=0; i--) {
            insert(&root, i);
        }
    }
    bool findLeastParent(int spx, int spy, int dpx, int dpy, tree** treepp, tree* treep) {
        bool spb = isInclude(treep->number, spx, spy);
        bool dpb = isInclude(treep->number, dpx, dpy);
        if(spb && dpb) {
            for(int i = 0; i < treep->child.size(); i++) {
                if(findLeastParent(spx, spy, dpx, dpy, treepp, treep->child[i])) {
                    return true;
                }
            }
            *treepp = treep; 
            return true;
        }
        return false;
    }
    bool downTree(tree* treep, int x, int y, int& count) {
        count++;
        if(isInclude(treep->number, x, y)) {
            for(int i = 0; i < treep->child.size(); i++) {
                if(downTree(treep->child[i], x, y, count)) {
                    return true;
                }
            }
            count--;
            return true;
        }
        count--;
        return false;
    }
    void findMinDist(int spx, int spy, int dpx, int dpy, int& count) {
        tree* sp = &root, *dp;
        findLeastParent(spx, spy, dpx, dpy, &sp, &root);
        dp = sp;
        downTree(sp, spx, spy, count);
        downTree(dp, dpx, dpy, count);
    }
};


int main() {
    int T;
    cin>>T;
    while(T--) {
        int dpx, dpy, spx, spy;
        int N;
        cin>>spx>>spy>>dpx>>dpy;
        cin>>N;
        uf pp(N);
        for(int i = 0; i < N ; i++) {
            int t1, t2, t3;
            cin>>t1>>t2>>t3;
            pp.change(i, t1, t2, t3);
        }
        int count = 0;
        pp.makeTree();
        pp.findMinDist(spx, spy, dpx, dpy, count);
        cout<<count<<"\n";
    }
}