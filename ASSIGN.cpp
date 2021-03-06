/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 25;
int n;
int matrix[MAXN][MAXN];
ll dp[1 << MAXN];


int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof dp);
        cin >> n;
        for(int i = 0;i < n; i++){
            for(int j = 0;j < n; j++)
                cin >> matrix[i][j];
        }
        int limit = 1 << n;
        dp[0] = 1LL;
        for(int mask = 0;mask < limit; mask++){
            for(int i = 0;i < n; i++){
                if((mask & (1 << i)) == 0){
                    if(matrix[__builtin_popcount(mask)][i] == 1){
                        dp[mask | (1 << i)] += dp[mask];
                    }
                }
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }
    return 0;
}