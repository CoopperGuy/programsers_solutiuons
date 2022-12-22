#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/************************************************************************/
/*�Ķ��Ʈ�� ��ġ�� �̿��Ͽ� ���������� ��ȯ�Ͽ� ã�´�
������ ���ǻ� �Ϲ����� Ž�����δ� �Ұ����ϱ� ����
���� ���� �̳���� �������� �켱������ ó���ϰ� ū���� ���߿� ó���ϴ� 
�׸��� ������� ����Ͽ� �������� �ƴ��� üũ�Ѵ�.						*/
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
