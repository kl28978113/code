#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<string> S;
	string tmp;
	while (cin >> tmp)
		S.insert(tmp);

	set<string> :: iterator it = S.begin();
	for (; it != S.end(); it++) {
		tmp = *it;
		for (int i = 1; i < tmp.length(); i++)
			if (S.find(tmp.substr(0, i)) != S.end() && S.find(tmp.substr(i, tmp.length() - i)) != S.end()) {
				cout << tmp << endl;
				break;
			}
	}
	return 0;
}
