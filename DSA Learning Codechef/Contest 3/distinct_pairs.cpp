#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);
#define gc getchar_unlocked
#define ld long double
#define PI (ld)3.1415926535897932384626
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define viii vector<tuple<int,int,int>>
#define mll map<ll,ll>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define F first
#define S second 
#define take(a) for (auto& x : a) cin >> x;
#define eject(a) for(auto it=a.begin(); it!=a.end();++it) cout<<*it<<" ";cout<<endl; 
                                


const int mod = 1000000007;
//====================================

int main()
{
	IOS
  int m,n; cin>>n>>m;
  vi a,b;
  a.resize(0); a.resize(n);
  b.resize(0); b.resize(m);
  take(a); take(b);
  int size = n+m-1;
  unordered_set<int> s;
  vector<pii> pairs;
  // for(int i=0; i<max(a.size(),b.size()); i++){
  //     for(int j=0; j<min(b.size(),a.size()); j++){
  //       if(a[i]+b[j]!=a[i]+b[j+1])
  //         pairs.pb(mp(i,j));
  //     }
  // }
  for(int i=0; i<max(a.size(),b.size()); i++){
      for(int j=0; j<min(b.size(),a.size()); j++){
        int sum = a[i]+b[j];
        if(s.count(sum)==0){
          pairs.pb(mp(i,j));
        }

      }
  }


    // for(auto itr=pairs.begin(); itr!=pairs.end(); ++itr){
    //   cout<<itr->F<<" "<<itr->S<<endl;
    // }
    for(int i=0; i<size; i++){
      cout<<pairs[i].F<<" "<<pairs[i].S<<endl;
    }



	return 0;
}