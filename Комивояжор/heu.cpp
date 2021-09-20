#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main() {
	int n, start;
	cout << "Count towns:";
	cin >> n;
	cout << "Start town:";
	cin >> start;
	cout << "Input matrix:" << endl;
	vector<vector<int> >mtx(n,vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mtx[i][j];
		}
	}
	map<int, set<pair<int, int> > > m_map;
	vector<int> line;
	set<int> be;
	int  ans = 0;
	start--;
	line.push_back(start);
	be.insert(start);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				m_map[i].insert({ mtx[i][j], j });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto it = m_map[start].begin(); it != m_map[start].end(); it++) {
			if (be.find((*it).second) == be.end()) {
				line.push_back((*it).second);
				be.insert((*it).second);
				ans += ((*it).first);
				start = (*it).second;
				break;
			}
		}
	}
	for (auto item : m_map[line[line.size() - 1]]) {
		if (item.second == line[0]) {
			ans += item.first;
		}
	}
	for (auto item : line) {
		cout << item + 1 << "->";
	}
	cout << line[0] + 1 << " | ans = " << ans << endl;
	return ans;
}

