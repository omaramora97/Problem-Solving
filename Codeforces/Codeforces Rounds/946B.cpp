#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
ll a,b;
cin>>a>>b;
while(a && b){
if(a >= 2*b) a%=(2*b);
else if(b >= 2*a) b%=(2*a);
else break;
}
printf("%lld %lld\n",a,b);

return 0;
}