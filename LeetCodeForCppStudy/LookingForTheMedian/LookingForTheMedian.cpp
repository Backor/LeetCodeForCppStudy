/*
	给定两个大小分别为m和n的正序（从小到大）数组nums1和nums2。请你找出并返回这两个正序数组的中位数

	知识点之中位数：中位数，又称中点数，中值。
	中位数是按顺序排列的一组数据中居于中间位置的数，即在这组数据中，有一半的数据比他大，有一半的数据比他小，这里用来表示中位数

	示例1：
	输入：nums1 = [1,2], nums2 = [3,4]
	输出：2.50000
	解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

	要求算法时间度：O(log(m+n))

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> nums3(nums1);
	nums3.insert(nums3.end(), nums2.begin(), nums2.end());
	sort(nums3.begin(), nums3.end());
	return nums3.size() % 2 != 0
		? nums3.at(nums3.size() / 2)
		: (nums3.at(nums3.size() / 2 - 1) + nums3.at(nums3.size() / 2)) / 2.0;
}

void test()
{
	vector<int> v1;
	vector<int> v2;
	v1.push_back(1);
	v1.push_back(3);
	v2.push_back(2);
	//v2.push_back(4);

	double m = findMedianSortedArrays(v1, v2);
	cout << "Median is " << m << endl;
}

int main()
{
	test();
}