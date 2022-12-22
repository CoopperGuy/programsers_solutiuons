#include <vector>
#include <iostream>

int solution(int n, int k, std::vector<int> enemy);
int main()
{
	int n = 7, k = 3;
	std::vector<int> defVec ={4, 2, 4, 5, 3, 3, 1};
	solution(n,k,defVec);

	return 0;
}