#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename K, typename V>
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    V get(const K& key) {
        auto it = hash.find(key);
		if (it == hash.end()) {
			return V();
		}

        auto val = it->second->second;
        put(key, val);
        return val;
    }

    void put(const K& key, const V& value) {
        auto it = hash.find(key);
        if (it == hash.end()) {
            if (hash.size() >= cap) {
                auto d_it = data_list.begin();
                auto h_it = d_it->first;
                data_list.erase(d_it);
                hash.erase(h_it);
            }
        } else {
            auto d_it = it->second;
            data_list.erase(d_it);
            hash.erase(it);
        }

        data_list.emplace_back(key, value);
        hash[key] = --data_list.end();
    }

private:
    int cap;
    list<pair<K, V> > data_list;

    using LIST_IT = typename list<pair<K, V> >::iterator;
    unordered_map<K, LIST_IT> hash;
};

int main() {
	LRUCache<int, int> lru(2);

	vector<pair<string, vector<int> > > test_case = {
		{"put", {1, 1}},
		{"put", {2, 2}},
		{"get", {1}},
		{"put", {3, 3}},
		{"get", {2}},
		{"put", {4, 4}},
		{"get", {1}},
		{"get", {3}},
		{"get", {4}},
	};

	for (const auto& [opt, param] : test_case) {
		if (opt == "get") {
			auto val = lru.get(param.front());
			cout << val << endl;
		} else {
			lru.put(param.front(), param.back());
		}
	}

	return 0;
}
