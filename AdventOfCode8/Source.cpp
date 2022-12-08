#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int checkUp(int row, int col, vector<vector<int>> line)
{
	int num = line[row][col];
	if (row == 0 || row == line.size() - 1)
	{
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		if (line[i][col] >= num)
		{
			return 0;
		}
	}
	return 1;
}

int checkDown(int row, int col, vector<vector<int>> line)
{
	int num = line[row][col];
	if (row == 0 || row == line.size() - 1)
	{
		return 1;
	}
	for (int i = row+1; i < line.size(); i++)
	{
		if (line[i][col] >= num)
		{
			return 0;
		}
	}
	return 1;
}

int checkLeft(int row, int col, vector<int> line)
{
	int num = line[col];
	if (col == 0 || col == line.size()-1)
	{
		return 1;
	}
	for (int i = 0; i < col; i++)
	{
		if (line[i] >= num)
		{
			return 0;
		}
	}
	return 1;
}

int checkRight(int row, int col, vector<int> line)
{
	int num = line[col];
	if (col == 0 || col == line.size() - 1)
	{
		return 1;
	}
	for (int i = col+1; i < line.size(); i++)
	{
		if (line[i] >= num)
		{
			return 0;
		}
	}
	return 1;
}

int lookLeft(int row, int col, vector<int> line)
{
	int temp = 0;
	int num = line[col];
	if (col == 0)
	{
		return 0;
	}
	else
	{
		for (int i = col - 1; i >= 0; i--)
		{
			temp++;
			if (line[i] >= num)
			{
				return temp;
			}
		}
	}
	return temp;
		
}

int lookRight(int row, int col, vector<int> line)
{
	int temp = 0;
	int num = line[col];
	if (col == line.size())
	{
		return 0;
	}
	else
	{
		for (int i = col + 1; i <line.size(); i++)
		{
			temp++;
			if (line[i] >= num)
			{
				return temp;
			}
		}
	}
	return temp;

}

int lookUp(int row, int col, vector<vector<int>> line)
{
	int temp = 0;
	int num = line[row][col];
	if (row == 0)
	{
		return 0;
	}
	else
	{
		for (int i = row - 1; i >= 0; i--)
		{
			temp++;
			if (line[i][col] >= num)
			{
				return temp;
			}
		}
	}
	return temp;

}

int lookDown(int row, int col, vector<vector<int>> line)
{
	int temp = 0;
	int num = line[row][col];
	if (row == line.size())
	{
		return 0;
	}
	else
	{
		for (int i = row + 1; i <line.size(); i++)
		{
			temp++;
			if (line[i][col] >= num)
			{
				return temp;
			}
		}
	}
	return temp;

}

int main()
{
	ifstream FileName;
	FileName.open("AOC8.txt");
	int totalCount = 0;
	vector<vector<int>> trees;
	vector<vector<bool>> treesChecked;
	string lineN;
	int scenicScore = 0;
	while (getline(FileName, lineN)) 
	{
		vector<int> temp;
		vector<bool> nullity;
		for (int i = 0; i < lineN.length(); i++)
		{
			temp.push_back(lineN[i]);
			nullity.push_back(false);
		}
		trees.push_back(temp);
		treesChecked.push_back(nullity);
	}
	int rows = trees.size();
	int cols = trees[1].size();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (checkLeft(i,j,trees[i]))
			{
				totalCount += 1;
			}
			else if (checkRight(i, j, trees[i]))
			{
				totalCount += 1;
			}
			else if (checkUp(i,j,trees))
			{
				totalCount += 1;
			}
			else if (checkDown(i,j,trees))
			{
				totalCount += 1;
			}
			
			int tempScenicScore = lookLeft(i, j, trees[i]) * lookUp(i, j, trees) * lookRight(i, j, trees[i]) * lookDown(i, j, trees);
			if (tempScenicScore > scenicScore)
			{
				scenicScore = tempScenicScore;
			}
			
		}
	}
	cout << totalCount << endl;
	cout << scenicScore;
}