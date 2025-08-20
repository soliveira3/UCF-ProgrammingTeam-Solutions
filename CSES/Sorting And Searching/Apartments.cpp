#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
    ll n, m, k;
    cin >> n >> m >> k;
 
    vector<ll> applicants(n);
    for (auto &i : applicants) cin >> i;
 
    vector<ll> appt(m);
    for (auto &i : appt) cin >> i;
 
    sort(applicants.begin(), applicants.end());
    sort(appt.begin(), appt.end());
 
 
    ll applicantIndex = 0, apartmentIndex = 0;
 
    ll count = 0;
    while (applicantIndex < n && apartmentIndex < m)
    {
        if (abs(appt[apartmentIndex] - applicants[applicantIndex]) <= k)
        {
            count++;
            applicantIndex++;
            apartmentIndex++;
        }
 
        else
        {
            if (appt[apartmentIndex] < applicants[applicantIndex]) apartmentIndex++;
            else applicantIndex++;
        }
    }
 
    cout << count << '\n';
 
	return 0;
}