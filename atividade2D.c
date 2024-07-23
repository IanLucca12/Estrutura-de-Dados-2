#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool add(unordered_set<string>& my_set, const string& key) {
    if (my_set.count(key) > 0) {
        return false;
    }
    my_set.insert(key);
    return true;
}

bool del(unordered_set<string>& my_set, const string& key) {
    if (my_set.erase(key) > 0) {
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    for (int testcase = 0; testcase < N; testcase++) {
        int m;
        cin >> m;

        unordered_set<string> my_set;
        vector<string> entries;

        for (int operation = 0; operation < m; operation++) {
            string op, key;
            cin >> op >> key;

            if (op == "ADD") {
                if (add(my_set, key)) {
                    entries.push_back(key);
                }
            } else if (op == "DEL") {
                if (del(my_set, key)) {
                    entries.erase(remove(entries.begin(), entries.end(), key), entries.end());
                }
            }
        }

        cout << entries.size() << endl;
        for (const string& entry : entries) {
            cout << entry << endl;
        }
    }

    return 0;
}
