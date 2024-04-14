#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyHashSet
{
private:
    vector<int> items;
    int find(int key)
    {
        if (items.size() == 0)
            return -1;
        int l = 0, r = items.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (items[m] == key)
                return m;
            else if (items[m] < key)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

public:
    MyHashSet()
    {
    }

    void add(int key)
    {
        if (contains(key))
            return;
        int l = 0, r = items.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (items[m] < key)
                l = m + 1;
            else
                r = m - 1;
        }
        items.insert(items.begin() + l, key);
    }

    void remove(int key)
    {
        int idx = find(key);
        if (idx != -1)
            items.erase(items.begin() + idx);
    }

    bool contains(int key)
    {
        return find(key) != -1;
    }
};

int main()
{
    MyHashSet set;
    vector<string> funcs = {};
    vector<int> keys = {};
    for (int i = 0; i < funcs.size(); i++)
    {
        if (funcs[i] == "contains")
        {
            cout << set.contains(keys[i]);
        }
        else if (funcs[i] == "add")
        {
            set.add(keys[i]);
        }
        else
        {
            set.remove(keys[i]);
        }
    }
}