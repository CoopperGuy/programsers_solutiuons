#include <vector>
#include <iostream>

int solution(int n, int k, std::vector<int> enemy);
int solution(std::vector<std::vector<int>> data, int col, int row_begin, int row_end);
int main()
{
	int n = 7, k = 3;
	std::vector<int> defVec ={4, 2, 4, 5, 3, 3, 1};
	solution(n,k,defVec);

	int col = 2, row_begin = 2, row_end = 3;

	std::vector<std::vector<int>> data = { {2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3} };
	solution(data, col, row_begin, row_end);
	return 0;
}