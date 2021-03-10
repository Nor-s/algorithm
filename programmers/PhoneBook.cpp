#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct tri {
    bool isTerminal;
    tri* triNode[10];
    tri(): isTerminal(false)
    {
        memset(triNode, false, sizeof(triNode));
    }
    bool pushTri(const string& str)
    {
        int count = 0;
        tri* tmp = this;
        for(int i = 0; i < str.length(); i++)
        {
            int n = (int)str[i] - (int)'0';
        	if(tmp->triNode[n] == NULL)
            {
                count++;
                tmp->triNode[n] = new tri();
            }
            tmp = tmp->triNode[n];
            if(tmp->isTerminal)
                return true;
        }
        tmp->isTerminal = true;
        if(count == 0)
            return true;
        return false;
    }
    ~tri()
    {
        for(int i = 0; i < 10; i++)
        {
            if(triNode[i])
                delete triNode[i];
        }
    }
};

bool solution(vector<string> phone_book) {
    tri dic;
    for(int i = 0; i < phone_book.size(); i++)
    {
        if(dic.pushTri(phone_book[i]))
            return false;
    }
    return true;
}
int main()
{
    vector<string> pb;
    int n;
    cin>>n;
    while(n--)
    {
        string tmp;
        cin>>tmp;
        pb.push_back(tmp);
    }
    cout<<solution(pb)<<"\n";
}