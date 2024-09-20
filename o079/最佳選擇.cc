#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define eb emplace_back
#define F first
#define S second
#define endl '\n'
using namespace std;

signed main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	map<int, vector<pii>> prefix, suffix;
	int n, k, total = 0, diff = 0, ans = 0, goal; cin >> n >> k;
	vi v(n);
	for (int &i : v)
		cin >> i;
	for (int i = 0; i < n; ++i) {
		total += v[i];
		diff += (v[i]&1 ? 1 : -1);
		prefix[diff].eb(make_pair(total, i));
	}
	total = diff = 0;
	for (int i = n-1; i >= 0; --i) {
		total += v[i];
		diff += (v[i]&1 ? 1 : -1);
		suffix[diff].eb(make_pair(total, i));
	}
	// deal with zero case
	if (prefix.count(0)) { // left-hand-side zero case
		int l = 0, r = prefix[0].size()-1;
		while (l <= r) { // binary search
			int mid = (l+r)/2;
			if (prefix[0][mid].F <= k) {
				ans = prefix[0][mid].F;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
	} 
	if (ans == k) {
		cout << k << endl;
		exit(0);
	}
	if (suffix.count(0)) { // right-hand-side zero case
		int l = 0, r = suffix[0].size()-1;
		while (l <= r) { // binary search
			int mid = (l+r)/2;
			if (suffix[0][mid].F <= k) {
				ans = max(ans, suffix[0][mid].F);
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
	}
	if (ans == k) {
		cout << k << endl;
		exit(0);
	}
	for (auto [d, pres] : prefix) { // find the perfix and suffix merged case
		if (!suffix.count(-d)) continue;
		vector<pii> sufs(suffix[-d]);
		for (const auto& psum : pres) {
			//int sidx = -1;
			goal = k - psum.F;
			if (goal < 1) continue;
			int l = 0, r = sufs.size()-1;
			while (l <= r) { // binary search
				int mid = (l+r)/2;
				if (sufs[mid].F <= goal) {
					if (sufs[mid].S > psum.S)
						ans = max(ans, psum.F+sufs[mid].F);
					l = mid+1;
				} else {
					r = mid-1;
				}
			}
			if (ans == k) {
				cout << k << endl;
				exit(0);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
