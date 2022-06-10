#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void Join_to_single_num(int &x,int location, vector<int> &v) {		//	recursion
		if (v.size() == location) {
			return;
		}
		x = x * 10;
		x = x + v[location];

		if (location == 0) {
			x = v[location];
		}

		Join_to_single_num(x,location+1, v);
	}

	int  Join_to_single_num(vector<int> &v){		//	iteration
		int ret = v[0];

		for (int i = 1; i < v.size(); i++){
			ret = ret * 10;
			ret = ret + v[i];
		}

		return ret;
	}
};

int main() {

	vector<int> vec1 = { 5,6,4,4,5,6 };
	Solution s;
	int x = s.Join_to_single_num(vec1);
	cout << "\n\t" << x;

	s.Join_to_single_num(x,0,vec1);
	cout << "\n\t" << x;
	return 0;
}
