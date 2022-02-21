#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vector<int> ans;
        ans.push_back(1);
        for (int j = a + 1; j <= b; j++)
        {
            if (ans.back() >= 1e8)
            {
                ans.push_back(1);
            }
            ans.back() *= j;
        }
        for (int j = 2; j <= b - a; j++)
        {
            int div = j;
            for (int k = 0; k < ans.size(); k++)
            {
                int gd = gcd(ans[k], div);
                if (gd > 1)
                {
                    ans[k] /= gd;
                    div /= gd;
                    if (div == 1)
                    {
                        break;
                    }
                }
            }
        }
        for (int j = 1; j < ans.size(); j++)
        {
            ans[0] *= ans[j];
        }
        cout << ans[0] << "\n";
    }
}