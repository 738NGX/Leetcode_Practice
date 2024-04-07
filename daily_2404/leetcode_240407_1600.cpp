#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

class ThroneInheritance
{
public:
    struct Person
    {
        string name;
        vector<unique_ptr<Person>> children;
        bool is_alive = true;
        Person(string name) : name(move(name)) {}
    };

    unique_ptr<Person> king;
    unordered_map<string, Person *> name_map;

    ThroneInheritance(string kingName) : king(make_unique<Person>(move(kingName)))
    {
        name_map[king->name] = king.get();
    }

    void birth(string parentName, string childName)
    {
        auto child = make_unique<Person>(move(childName));
        name_map[child->name] = child.get();
        name_map[parentName]->children.push_back(move(child));
    }

    void death(const string &name)
    {
        if (name_map.find(name) != name_map.end())
        {
            name_map[name]->is_alive = false;
        }
    }

    vector<string> getInheritanceOrder() const
    {
        vector<string> order;
        getInheritanceOrderHelper(king.get(), order);
        return order;
    }

private:
    void getInheritanceOrderHelper(const Person *person, vector<string> &order) const
    {
        if (person->is_alive)
        {
            order.push_back(person->name);
        }
        for (const auto &child : person->children)
        {
            getInheritanceOrderHelper(child.get(), order);
        }
    }
};