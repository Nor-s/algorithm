#include <iostream>
void f(int a, int b, int n, int w) {
    int yang = 1, yum = n-1;
    int count  = 0, ya = 0, yu = 0 ;
    for(;yang != n; yang++, yum--)
        if( w == a*yang + b*yum) {
            count++;
            if(count == 2){
                std::cout<<-1;
                return;
            }
            ya  = yang;
            yu  = yum;
        }
    if(count == 0 ) {
        std::cout<<-1;
        return;
    }
    std::cout<<ya<<" "<<yu;
    return;
}
int main(void) {
    int a, b, n, w;
    std::cin>>a>>b>>n>>w;
    f(a,b,n,w);
}
