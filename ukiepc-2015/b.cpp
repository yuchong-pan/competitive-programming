#include <bits/stdc++.h>

using namespace std;

const long double pi=(long double)acos((long double)-1.0);
long double dv[100000];

int main(){
    int N;
    long double g;
    scanf("%d%Lf",&N,&g);

    for(int i=1;i<=N;i++){
        int d,the;
        cin>>d>>the;

        dv[i]=(long double)2.0*g*(long double)cos((long double)the*(long double)pi/(long double)180.0)*(long double)d;
    }

    for(int i=N-1;i>0;i--)
        dv[i]+=(long double)dv[i+1];

    for(int i=1;i<=N;i++){
        printf("%.10lf\n",(double)sqrt(dv[i]));
    }

    return 0;
}
