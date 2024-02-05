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

        auto data_tuple = *(it->second);
        auto val = std::get<1>(data_tuple);
        auto cnt = std::get<2>(data_tuple);
        put(key, val, cnt + 1);
        return val;
    }

    void put(const K& key, const V& value, int cnt = 1) {
        auto it = hash.find(key);
        if (it == hash.end()) {
            if (hash.size() >= cap) {
                remove_one_elem();
            }
        } else {
            auto d_it = it->second;
            data_list.erase(d_it);
            hash.erase(it);
        }

        data_list.emplace_back(key, value, cnt);
        hash[key] = --data_list.end();
    }

private:
    void remove_one_elem() {
        auto need_rm = data_list.begin();
        auto it = need_rm;
        for (int i = 1; i < 3 && it != data_list.end(); ++i, ++it) {
            if (std::get<2>(*it) < std::get<2>(*need_rm)) {
                need_rm = it;
            }
        }

        hash.erase(std::get<0>(*need_rm));
        data_list.erase(need_rm);
    }

private:
    int cap;
    list<tuple<K, V, int> > data_list;

    using LIST_IT = typename list<tuple<K, V, int> >::iterator;
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

    return 0;
}
