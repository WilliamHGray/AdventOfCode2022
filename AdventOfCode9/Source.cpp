#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int checkDistance(vector<int>tPos, vector<int>hPos)
{
	int q = tPos[0] - hPos[0];
	int p = tPos[1] - hPos[1];
	//cout << q << ", " << p << endl;
	int distance = (q * q) + (p * p);
	//cout << distance << endl;
	if (distance < 4)
	{
		return 0;
	}
	return 1;
}

void moveHead(vector<int>& hPos, char dir)
{
	if (dir == 'U')
	{
		hPos[1] += 1;
	}
	else if (dir == 'D')
	{
		hPos[1] -= 1;
	}
	else if (dir == 'R')
	{
		hPos[0] += 1;
	}
	else if (dir == 'L')
	{
		hPos[0] -= 1;
	}
}

void moveTail(vector<int>& tPos, vector<int>hPos)
{
	double xDiff = hPos[0] - tPos[0];
	double yDiff = hPos[1] - tPos[1];
	if (xDiff < 0)
	{
		tPos[0] -= 1;
	}
	else if (xDiff > 0)
	{
		tPos[0] += 1;
	}
	if (yDiff < 0)
	{
		tPos[1] -= 1;
	}
	else if (yDiff > 0)
	{
		tPos[1] += 1;
	}
}


int main()
{
	ifstream FileName;
	FileName.open("AOC9.txt");
	vector<string> instructions;
	vector<vector<int>> positions;
	int someConstant = 10;
	for (int i = 0; i < someConstant; i++)
	{
		vector<int> temp;
		temp.push_back(0);
		temp.push_back(0);
		positions.push_back(temp);
	}
	set<vector<int>> allTPos;
	string lineN;
	while (getline(FileName, lineN)) {
		instructions.push_back(lineN);
	}
	for (int i = 0; i < instructions.size(); i++)
	{
		char dir = instructions[i][0];
		int num = stoi(instructions[i].substr(2,-1));
		for (int j = 0; j < num; j++)
		{
			moveHead(positions[0], dir);
			for (int q = 0; q < someConstant - 1; q++)
			{
				if (checkDistance(positions[q + 1], positions[q]))
				{
					moveTail(positions[q + 1], positions[q]);
				}
			}

			allTPos.insert(positions[someConstant - 1]);
		}
	}
	cout << allTPos.size();
}