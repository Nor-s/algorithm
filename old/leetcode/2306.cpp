#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
// 두 글자를 선택
// 첫글자를 서로 변경
//  만약 새로운 문자열이면?
    unordered_map<char, vector<string*>> us;
    int answer = 0;
    int idx[2] = {0, 0};
    int size;

    long long distinctNames(vector<string>& ideas) {
        size = ideas.size();
        for(auto& s : ideas) {
            us[s[0]].push_back(&s);
        }
        int answer = 0;
        
        
        return answer;
    }
};