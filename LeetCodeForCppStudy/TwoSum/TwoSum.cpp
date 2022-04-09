/*
	给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
	你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
	你可以按任意顺序返回答案。

	示例1：
	输入：nums = [2,7,11,15], target = 9
	输出：[0,1]
	解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ind;
	if (nums.size() < 2) return ind;
	for (vector<int>::iterator first = nums.begin(); first != nums.end() - 1; ++first) {
		for (vector<int>::iterator second = first + 1; second != nums.end(); ++second) {
			if (*first + *second == target) {
				ind.push_back(first - nums.begin());
				ind.push_back(second - nums.begin());
				return ind;
			}
		}
	}
	return ind;
}

void print_vector(const string& vName, vector<int>& v)
{
	cout << vName.c_str() << " =" << endl;
	cout << "[" << endl;
	for (vector<int>::iterator itor = v.begin(); itor != v.end(); ++itor) {
		cout << "\t" << *itor << endl;
	}
	cout << "]" << endl;
}

void test()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(8);
	v.push_back(9);
	print_vector("int vector is", v);

	vector<int> r = twoSum(v, 10);
	print_vector("function twoSum result", r);
}

int main()
{
	test();
}