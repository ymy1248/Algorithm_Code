/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;
        for (size_t i = 0; i < employees.size(); ++i) {
            map[employees[i]->id] = employees[i];
        }
        return foo(map, id, 0);
    }

private:
    int foo(unordered_map<int, Employee*> &map, int id, int ans) {
        const auto &it = map.find(id);
        const auto &emp = it->second;
        ans += emp->importance;
        for (size_t i = 0; i < emp->subordinates.size(); ++i) {
            ans = foo(map, emp->subordinates[i], ans);
        }
        return ans;
    }
};
