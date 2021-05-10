#include <iostream>

int main() {
    int n = 0, ret = 1;
    std::cin>>n;
    for(int i = 1; i <= n; i++)
        ret*= i;
    std::cout<<ret;
}