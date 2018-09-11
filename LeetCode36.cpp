#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int len = static_cast<int>(board.size());
		char ch = '.';
		for (int i = 0; i<len; ++i)
		{
			set<char> row;
			set<char> col;
			set<char> box;
			for (int j = 0; j < len; ++j)
			{
				if (board[i][j] != ch)
				{
					if (row.count(board[i][j]))
						return false;
					else
						row.insert(board[i][j]);
				}
				if (board[j][i] != ch)
				{
					if (col.count(board[j][i]))
						return false;
					else
						col.insert(board[j][i]);
				}
				int m, n;
				m = 3 * (i / 3) + j / 3;
				n = 3 * (i % 3) + j % 3;
				if (board[m][n] != ch)
				{
					if (box.count(board[m][n]))
						return false;
					else
						box.insert(board[m][n]);
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	vector< vector<char> > board = { 
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};
	board = { {'.', '9', '.', '.', '4', '.', '.', '.', '.'}, { '1','.','.','.','.','.','6','.','.' }, { '.','.','3','.','.','.','.','.','.' }, { '.','.','.','.','.','.','.','.','.' }, { '.','.','.','7','.','.','.','.','.' }, { '3','.','.','.','5','.','.','.','.' }, { '.','.','7','.','.','4','.','.','.' }, { '.','.','.','.','.','.','.','.','.' }, { '.','.','.','.','7','.','.','.','.' } };
	bool rst = s.isValidSudoku(board);
	cout << rst << endl;
	system("pause");
	return 0;
}