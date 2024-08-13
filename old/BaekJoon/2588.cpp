#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int a;
    string b;
    vector<int> result;

    cin>>a;
    cin>>b;

    for(int i = b.size() - 1, digit = 1; i >= 0; i--, digit*=10) {
        int tmp = ((int)b[i]-'0')*a;
        std::cout<<tmp<<"\n";
        result.push_back(tmp*digit);
    }
    if(b.size() != 1)
    std::cout<<accumulate(result.begin(), result.end(), 0)<<"\n";
}