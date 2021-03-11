#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int> > st;
    prices.push_back(-1);
    
    for(int i = 0; i < prices.size(); i++)
    {
        while(!st.empty() && st.top().first > prices[i])
        {
            int index = st.top().second;
            int len = i - index; 
            st.pop();
            if(i == (prices.size() -1))
                len--;
            answer[index] = len;
        }
        st.push(make_pair(prices[i], i));
    }
    return answer;
}