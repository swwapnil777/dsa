#include <bits/stdc++.h>
#include <list>
using namespace std;
class LRUCache
{
    int cap = 0;
    int size = 0;
    map<int, int> cacheMap;
    list<int> l;
    map<int, list<int>::iterator> address;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (cacheMap.find(key) == cacheMap.end())
        {
            return -1;
        }
        list<int>::iterator it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return cacheMap[key];
    }

    void put(int key, int value)
    {
        if (cacheMap.find(key) != cacheMap.end())
        {
            l.erase(address[key]);
            address.erase(key);
            cacheMap.erase(key);
            size--;
        }
        if (size == cap)
        {
            int k = l.back();
            l.pop_back();
            address.erase(k);
            cacheMap.erase(k);
            size--;
        }
        size++;
        l.push_front(key);
        address[key] = l.begin();
        cacheMap[key] = value;
    }
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl;

    cache.put(3, 3);

    cout << cache.get(2) << endl;

    cache.put(4, 4);

    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}
