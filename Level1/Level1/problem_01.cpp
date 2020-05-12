#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	//solution
	stack<int> s;

 	for (int m = 0; m < moves.size(); m++)
	{
		int crane = moves.at(m) - 1;
		for (int i = 0; i < board.size(); i++)
		{
			int current = board.at(i).at(crane);
			if (current != 0)
			{
				//cout << stack[top] << "\n";
				if (!s.empty() && s.top() == current)
				{
					s.pop();
					answer += 2;
				}
				else
					s.push(current);

				board.at(i).at(crane) = 0;
				break;
			}
		}
	}

	
	cout << answer << "\n";

	return answer;
}

int main()
{
	vector<vector<int>> board = {
		{0,0,0,0,0}, 
	    {0,0,1,0,3},
	    {0,2,5,0,1},
	    {4,2,4,4,2},
	    {3,5,1,3,1}
	};

	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	solution(board, moves);

	return 0;
}