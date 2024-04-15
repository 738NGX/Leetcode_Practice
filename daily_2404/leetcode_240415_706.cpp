#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyHashMap
{
private:
    struct Item
    {
        int key;
        int val;
        Item(int key, int val) : key(key), val(val) {}
    };
    vector<Item *> items;
    int find(int key)
    {
        if (items.size() == 0)
            return -1;
        int l = 0, r = items.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (items[m]->key == key)
                return m;
            else if (items[m]->key < key)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

public:
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        int idx = find(key);
        if (idx != -1)
        {
            items[idx]->val = value;
            return;
        }
        int l = 0, r = items.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (items[m]->key < key)
                l = m + 1;
            else
                r = m - 1;
        }
        items.insert(items.begin() + l, new Item(key, value));
    }

    int get(int key)
    {
        int idx = find(key);
        return idx == -1 ? -1 : items[idx]->val;
    }

    void remove(int key)
    {
        int idx = find(key);
        if (idx != -1)
            items.erase(items.begin() + idx);
    }
};

int main()
{
    MyHashMap map;
    map.put(2, 1);
    cout << map.get(2) << endl;
    return 0;
}