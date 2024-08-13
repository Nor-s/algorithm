#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

string strs;
int k;

struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {}
    bool operator ()(int a, int b) {
        if(group[a] != group[b]) return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};
 
vector<int> getSuffixArray(const string& s)
{
    int n = s.size();
    int t = 1;
    vector<int> group(n+1, 0);
    for(int i = 0; i < n; i++) group[i] = s[i];
    group[n] = -1;
 
    vector<int> perm(n, 0);
    for(int i = 0; i < n; i++) perm[i] = i;
 
    while(t < n)
    {
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
 
        t*=2;
        if(t>=n) break;
 
        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
 
        for(int i = 1; i < n; i++)
        {
            if(compareUsing2T(perm[i-1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        }
        group = newGroup;
    }
    return perm;
}
int commonPrefix(const string& s, int i, int j)
{
    int k = 0;
    int size = s.size();
    while (i < size && j < size && s[i] == s[j])
    {i++; j++; k++;}
    return k;
}

int longestFrequent()
{
    int ret = 0;
    vector<int> a = getSuffixArray(strs);
    for(int i = 0; i + k <= a.size(); i++)
        ret = max(ret, commonPrefix(strs, a[i], a[i+k - 1]));
    return ret;
}

int main()
{
    int testCase = 0;
    cin>>testCase;

    for(int i = 0; i < testCase; i++)
    {
        cin>>k>>strs;
        cout<<longestFrequent()<<"\n";
    }

}