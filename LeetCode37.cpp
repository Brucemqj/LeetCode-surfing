#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool isValid(vector< vector<char> >& board, int& i, int& j, char& ch)
	{
		int len = static_cast<int>(board.size());
		for (int k = 0; k < len; ++k)
		{
			if (board[i][k] == ch) return false;
			if (board[k][j] == ch) return false;
			if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == ch) return false;
		}
		return true;
	}

	bool solve(vector< vector<char> >& board)
	{
		int len = static_cast<int>(board.size());
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (board[i][j] == '.')
				{
					for (char ch = '1'; ch <= '9'; ++ch)
					{
						if (isValid(board, i, j, ch))
						{
							board[i][j] = ch;
							if (solve(board))
								return true;
							else
								board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	void solveSudoku(vector< vector<char> >& board)
	{
		if (board.size() == 0) return;
		solve(board);
	}
};

int main()
{
	Solution s;
	vector< vector<char> > board = { { '.','9','.','.','4','.','.','.','.' },{ '1','.','.','.','.','.','6','.','.' },{ '.','.','3','.','.','.','.','.','.' },{ '.','.','.','.','.','.','.','.','.' },{ '.','.','.','7','.','.','.','.','.' },{ '3','.','.','.','5','.','.','.','.' },{ '.','.','7','.','.','4','.','.','.' },{ '.','.','.','.','.','.','.','.','.' },{ '.','.','.','.','7','.','.','.','.' } };
	s.solveSudoku(board);
	system("pause");
	return 0;
}