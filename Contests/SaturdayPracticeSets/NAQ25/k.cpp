#include <bits/stdc++.h>
using namespace std;

int q(int r, int c) {
    cout << "? " << r << " " << c << endl;
    int res; cin >> res;
    return res; 
}

void a(int r, int c) {
    cout << "! " << r << " " << c << endl;
}

int main() {
    if (q(3, 2)) {
        if (q(3, 1)) {
            if (q(2, 1)) {
                a(2, 1);
            } else {
                a(3, 1);
            }
        } else {
            if (q(2, 2)) {
                a(2, 2);
            } else {
                a(3, 2);
            }
        }
    } else {
        if (q(2, 4)) {
            if (q(2, 3)) {
                if (q(1, 3)) {
                    a(1, 3);
                } else {
                    a(2, 3);
                }
            } else {
                if (q(1, 4)) {
                    a(1, 4);
                } else {
                    a(2, 4);
                }
            }
        } else {
            if (q(4, 4)) {
                if (q(4, 3)) {
                    if (q(3, 3)) {
                        a(3, 3);
                    } else {
                        a(4, 3);
                    }
                } else {
                    if (q(3, 4)) {
                        a(3, 4);
                    } else {
                        a(4, 4);
                    }
                }
            } else {
                if (q(2, 2)) {
                    if (q(1, 1)) {
                        a(1, 1);
                    } else {
                        a(1, 2);
                    }
                } else {
                    if (q(4, 1)) {
                        a(4, 1);
                    } else {
                        a(4, 2);
                    }
                }
            }
        }
    }
}