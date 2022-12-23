#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct CustomComp
{
	CustomComp(int _idx) :idx(_idx - 1) {};
	bool operator() (const vector<int>& a, const vector<int>& b)
	{
		if (a[idx] == b[idx])
			return a.front() > b.front();
		return a[idx] < b[idx];
	}
	int idx;
};

int SFunc(const vector<int>& _data, int _row)
{
	int res = 0;
	for (const auto& iter : _data)
	{
		res += iter % _row;
	}
	return res;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	int answer = 0;

	sort(data.begin(), data.end(), CustomComp(col));
	int sSum = 0;
	for (int i = row_begin - 1; i < row_end; ++i)
	{
		int res = SFunc(data[i], i + 1);
		sSum = sSum ^ res;
	}
	answer = sSum;
	return answer;
}