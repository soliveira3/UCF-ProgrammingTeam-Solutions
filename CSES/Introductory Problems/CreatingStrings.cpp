#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	string s; cin >> s;
	vector<string> ans;
	sort(s.begin(), s.end());
 
	do
	{
		ans.push_back(s);
	} while (next_permutation(s.begin(), s.end()));
 
	cout << ans.size() << '\n';
	for (auto s : ans) cout << s << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}