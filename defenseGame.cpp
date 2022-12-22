#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/************************************************************************/
/*파라메트릭 서치를 이용하여 결정문제로 변환하여 찾는다
문제의 조건상 일반적인 탐색으로는 불가능하기 때문
일정 범위 이내라면 작은것을 우선적으로 처리하고 큰것을 나중에 처리하는 
그리디 방식으로 계산하여 가능한지 아닌지 체크한다.						*/
/************************************************************************/
bool IsDefensable(const vector<int>& _enemys, int _idx,int _solider,int _k)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i <= _idx; ++i)
	{
		pq.emplace(_enemys[i]);
	}

	while (!pq.empty())
	{
		int enemy = pq.top();
		pq.pop();
		if (_solider >= enemy)
		{
			_solider -= enemy;
		}
		else
		{
			_k--;
		}
		if (_k < 0)
			return false;
	}
	return true;
}

int FindIndex(int n, int k, const vector<int>& _enemys)
{
	int left = 0, right = _enemys.size();
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (IsDefensable(_enemys, mid, n, k))
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int solution(int n, int k, vector<int> enemy) {
	int answer = 0;

	answer = FindIndex(n, k, enemy);

	return answer;
}
