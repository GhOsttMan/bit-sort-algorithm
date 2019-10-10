/*****************Bismillahir Rahmanir Rahim***********************/

#include<bits/stdc++.h>
using namespace std;

/************************Start Of Template*************************/

/******** Mahin Shefat - GhOstMan *************/


#define     pb              push_back
#define     popb            pop_back
#define     ll              long long int
#define     ull             unsigned long long int
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     MOD             1000000007
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair
#define     check           printf("check")
#define     sqr(x)          (x)*(x)
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     Pair            pair<ll,ll>
#define     MAX             1000000000000014
#define     MIN             -100000000000014
#define 	endl			'\n'
#define     Fread           freopen("inputdur.txt","r",stdin)
#define     Fwrite          freopen("output.txt","w",stdout)

/************************End Of Template*************************/
Pair bit[100005];
ll arr[100005];
ll ans[100005];
int main(int argc, char const *argv[])
{
    Fread;
    auto start = chrono::steady_clock::now();
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
        scanf("%lld",&arr[i]);
        bit[i] = mp(arr[i] , i);
	}
	bit[0] = mp(MAX , -1);
	for(int i = n; i >= 1; i--){
        int par = (i - (i & -i));
        if(bit[i].f < bit[par].f){
            bit[par] = bit[i];
        }
	}

	int par;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
        ans[i] = bit[0].f;
        par = bit[0].s;
        bit[0] = mp(MAX , -1);
        arr[par] = MAX;
        arr[0] = MAX;
        while(par >= 0){
            bit[par] = mp(arr[par] , par);
            for(int j = 0; j < 17; j++){
                //    cnt++;
                bool ok = (bool)(par & (1 << j));
                if(ok == true) break;
                int child = (par | (1 << j));
                if(child > n) break;
                if(bit[par].f > bit[child].f){
                    bit[par] = bit[child];
                }
            }
            if(par == 0) break;
            par -= (par & -par);
        }
	}
	for(int i = 1; i <= n; i++){
        printf("%lld " , ans[i]);
	}
	/*auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
	cout << chrono::duration <double, nano> (diff).count() << " ns" << endl;
	//cout << cnt << " " << cnt / n << " " << log2(n) <<  endl;*/
	return 0;
}
