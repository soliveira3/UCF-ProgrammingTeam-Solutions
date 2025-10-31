#include <bits/stdc++.h>
using namespace std;

int main() {
    string d1, t1;
    string d2, t2;
    cin >> d1 >> t1 >> d2 >> t2;

    if (d1 == d2 && t1 == t2) {
        cout << "7 days\n";
        return 0;
    }

    map<string, int> mp = {{"Mon", 0}, {"Tue", 1}, {"Wed", 2}, {"Thu", 3}, {"Fri", 4}, {"Sat", 5}, {"Sun", 6}};

    int day1 = mp[d1], hour1 = stoi(t1.substr(0,2)), minute1 = stoi(t1.substr(3,2));
    int day2 = mp[d2], hour2 = stoi(t2.substr(0,2)), minute2 = stoi(t2.substr(3,2));
    int numDays = 0, numHours = 0, numMinutes = 0;


    // making min2 bigger
    if (minute2 < minute1) {
        numMinutes += minute2+1;
        minute2 = 59;
    
        hour1 = (hour1 + 1);
        if (hour1 >= 24) day1 = (day1+1) % 7;
        hour1 %= 24;
    }

    // making hours 2 bigger
    if (hour2 < hour1) {
        numHours += hour2+1;
        hour2 = 23;
        day1 = (day1 + 1) % 7;
    }


    while (day2 < day1) {
        day1 = (day1+1) % 7;
        day2 = (day2+1) % 7;
    }

    numDays += day2-day1;
    numHours += hour2-hour1;
    numMinutes += minute2-minute1;

    numHours += numMinutes / 60;
    numMinutes = numMinutes % 60;
    numDays += numHours / 24;
    numHours = numHours % 24;

    int ct = (numMinutes != 0) + (numHours != 0) + (numDays != 0); 
    
    // OUTPUT
    if (ct == 1) {
        if (numMinutes != 0)
            cout << numMinutes << " minute" << (numMinutes > 1 ? "s\n" : "\n");
        if (numHours != 0)
            cout << numHours << " hour" << (numHours > 1 ? "s\n" : "\n");;
        if (numDays != 0)
            cout << numDays << " day" << (numDays > 1 ? "s\n" : "\n");;
    }

    else if (ct == 2) {
        string ans = "";
        if (numDays != 0) {
            ans.append(to_string(numDays) + " day" + (string)(numDays > 1 ? "s and " : " and "));
        }
        if (numHours != 0) {
            ans.append(to_string(numHours) + " hour" + (string)(numHours > 1 ? "s and " : " and "));
        }
        if (numMinutes != 0) {
            ans.append(to_string(numMinutes) + " minute" + (string)(numMinutes > 1 ? "s and " : " and "));
        }
        ans = ans.substr(0, ans.size()-4);
        cout << ans << '\n';
    }

    else {
        cout << numDays << " day" << (numDays > 1 ? "s, " : ", ");
        cout << numHours << " hour" << (numHours > 1 ? "s, " : ", ");
        cout << numMinutes << " minute" << (numMinutes > 1 ? "s\n" : "\n");
    }
}