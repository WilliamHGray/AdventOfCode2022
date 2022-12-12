#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void checkAdj(vector<int> checkLocation,vector<vector<int>> &distances, vector<vector<int>> grid,queue<vector<int>>&toCheck)
{
	int x = checkLocation[1], y = checkLocation[0];
	if (y > 0)	//check up
	{
		int q = grid[y - 1][x];
		if ((q - grid[y][x] < 2) && (distances[y-1][x] >distances[y][x] +1))
		{
			distances[y - 1][x] = distances[y][x] + 1;
			vector<int> temp;
			temp.push_back(y - 1);
			temp.push_back(x);
			
			toCheck.push(temp);
		}
	}
	if (x > 0)	//check left
	{
		int q = grid[y][x-1];
		if ((q - grid[y][x] < 2) && (distances[y][x-1] > distances[y][x] + 1))
		{
			distances[y][x-1] = distances[y][x] + 1;
			vector<int> temp;
			temp.push_back(y);
			temp.push_back(x-1);
			
			toCheck.push(temp);
		}
	}
	if (y < distances.size()-1) //check down
	{
		int q = grid[y + 1][x];
		
		if ((q - grid[y][x] < 2) && (distances[y + 1][x] > distances[y][x] + 1))
		{
			distances[y + 1][x] = distances[y][x] + 1;
			vector<int> temp;
			temp.push_back(y + 1);
			temp.push_back(x);
			
			toCheck.push(temp);
		}
	}
	if (x < distances[y].size() - 1) //check right
	{
		int q = grid[y][x+1];
		if ((q - grid[y][x] < 2) && (distances[y][x+1] > distances[y][x] + 1))
		{
			distances[y][x+1] = distances[y][x] + 1;
			vector<int> temp;
			temp.push_back(y);
			temp.push_back(x + 1);
			
			toCheck.push(temp);
		}
	}
}

int checkDistance(vector<int> start,vector<int> end, vector<vector<int>>distances,vector<vector<int>>grid)
{
	queue<vector<int>>toCheck;
	toCheck.push(start);
	distances[start[0]][start[1]] = 0;
	while (size(toCheck) > 0)
	{
		checkAdj(toCheck.front(), distances, grid, toCheck);
		toCheck.pop();
	}
	return distances[end[0]][end[1]];
}


int main() {
	ifstream FileName;
	FileName.open("AOC12.txt");
	string lineN;
	vector<int> start, end;
	vector<vector<int>>grid;
	vector<vector<int>> distances;
	queue<vector<int>> toCheck;
	vector<vector<int>> allStarts;
	int row = 0;
	while (getline(FileName, lineN)) {
		vector<int> temp, tempDist;
		for (int i = 0; i < lineN.size(); i++)
		{
			
			if (lineN[i] == 'S')
			{
				temp.push_back(1);
				start.push_back(row);
				start.push_back(i);
				tempDist.push_back(10000);
			}
			else if (lineN[i] == 'E')
			{
				temp.push_back(26);
				end.push_back(row);
				end.push_back(i);
				tempDist.push_back(10000);
			}
			else if (lineN[i] == 'a')
			{
				temp.push_back(int(lineN[i]) - 96);
				tempDist.push_back(10000);
				vector<int> tempStart;
				tempStart.push_back(row);
				tempStart.push_back(i);
				allStarts.push_back(tempStart);
			}
			else
			{
				temp.push_back(int(lineN[i]) - 96);
				tempDist.push_back(10000);
			}
		}
		row++;
		grid.push_back(temp);
		distances.push_back(tempDist);
	}
	toCheck.push(start);
	allStarts.push_back(start);
	cout << "start checking" << endl;
	int distance = 0;
	/*
	while (size(toCheck) > 0)
	{		
		checkAdj(toCheck.front(), copyDist, grid,toCheck);
		toCheck.pop();
	}
	*/
	int distanceMain = checkDistance(start, end, distances, grid);
	cout << "exit loop" << endl;;
	cout << distanceMain<< endl;

	int minDist = 1000;
	for (int i = 0; i < allStarts.size(); i++)
	{
		vector<int> currStart = allStarts[i];

		distances[currStart[0]][currStart[1]] = 0;
		toCheck.push(currStart);
		int tempDist = checkDistance(currStart, end, distances, grid);
	
		if (tempDist < minDist)
		{
			minDist = tempDist;
		}



		distances[currStart[0]][currStart[1]] = 10000;
	}
	cout << minDist;
	/*
	
	*/
}