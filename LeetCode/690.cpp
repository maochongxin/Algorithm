/*************************************************************************
	> File Name: 690.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 一  3/ 4 21:34:24 2019
 ************************************************************************/

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
        int importanceSum = 0;
		for (auto employee : employees) {
			if (employee->id == id) {
				importanceSum = employee->importance;
				if (employee->subordinates.size() != 0)
					for (int id : employee->subordinates)
						importanceSum += getImportance(employees,id);
			}
		}
		return importanceSum;
    }
};
