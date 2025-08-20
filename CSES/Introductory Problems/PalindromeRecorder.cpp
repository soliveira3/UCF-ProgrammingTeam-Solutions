#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	string s; cin >> s;
	ll odd = 0;
	bool possible = true;
	ll oddIndex = 0;
	vector<ll> charAmount(26, 0);
 
	for (char c : s) charAmount[c-'A']++;
 
	for (int i = 0; i < 26; i++)
	{
		if (charAmount[i] % 2 == 1)
		{
			odd++;
			oddIndex = i;
		}
	}
 
	if (odd > 1) possible = false;
 
	if (possible)
	{
		for (int i = 0; i < 26; i++)
		{
			if (i == oddIndex) continue;
			char c = 'A'+i;
			for (int j = 0; j < charAmount[i] / 2; j++)
				cout << c;
		}
 
		char d = 'A' + oddIndex;
		for (int i = 0; i < charAmount[oddIndex]; i++)
			cout << d;
 
		for (int i = 25; i >= 0; i--)
		{
			if (i == oddIndex) continue;
			char c = 'A'+i;
			for (int j = 0; j < charAmount[i] / 2; j++)
				cout << c;
		}
 
		cout << '\n';
	}
 
	else
		cout << "NO SOLUTION\n";
 
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}