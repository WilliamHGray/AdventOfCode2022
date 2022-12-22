#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

int extractNum(string instructions, int &pos)
{
	int j = 1;
	while (isdigit(instructions[pos + j]))
	{
		j++;
	}
	int out = stoi(instructions.substr(pos, j));
	pos += j;
	return out;
}

int turn(int direction, char instruction)
{
	if (instruction == 'R')
	{
		direction++;
		if (direction > 3)
		{
			direction -= 4;
		}
	}
	else if (instruction == 'L')
	{
		direction--;
		if(direction<0)
		{
			direction += 4;
		}
	}
	return direction;
}

void draw(vector<string>map)
{
	for (int i = 0; i < map.size(); i++)
	{
		cout << map[i] << endl;
	}
}

vector<int> getStart(vector<string>map)
{
	for (int i = 0; i < map[0].size(); i++)
	{
		if (map[0][i] != ' ')
		{
			return { 0, i };
		}
	}
}

void drawOn(vector<string>& route, int dir,vector<int>currPos)
{
	char toDraw;
	if (dir == 0)
	{
		toDraw = '^';
	}
	else if (dir == 1)
	{
		toDraw = '>';
	}
	else if (dir == 2)
	{
		toDraw = 'v';
	}
	else if (dir == 3)
	{
		toDraw = '<';
	}
	route[currPos[0]][currPos[1]] = toDraw;
}

vector<int> getNextPos(vector<int>currPos, int dir, vector<string>map)
{
	int starty = currPos[0], startx = currPos[1];
	if (dir == 0)
	{
		starty--;
		while (true)
		{
			if (starty < 0)
			{
				starty = map.size() - 1;
			}
			else if (map[starty].size() <= startx)
			{
				starty--;
			}
			else if (map[starty][startx] == ' ')
			{
				starty--;
			}
			else
			{
				return { starty,startx };
			}
		}
	}
	else if (dir == 1)
	{
		startx++;
		int rowSize = map[starty].size();
		while (true)
		{
			if (startx == rowSize)
			{
				startx = 0;
			}
			else if (map[starty][startx] == ' ')
			{
				startx++;
			}
			else
			{
				return { starty,startx };
			}
		}
	}
	else if (dir == 2)
	{
		starty++;
		while (true)
		{
			if (starty == map.size())
			{
				starty = 0;
			}
			else if (map[starty].size() <= startx)
			{
				starty++;
			}
			else if (map[starty][startx] == ' ')
			{
				starty++;
			}
			else
			{
				return { starty,startx };
			}
		}
	}
	else if (dir == 3)
	{
		startx--;
		int rowSize = map[starty].size();
		while (true)
		{
			if (startx < 0)
			{
				startx = rowSize-1;
			}
			else if (map[starty][startx] == ' ')
			{
				startx--;
			}
			else
			{
				return { starty,startx };
			}
		}
	}
}

int main()
{
	vector<int> currPos;
	ifstream FileName;
	int dir = 1;
	FileName.open("AOC22.txt");
	vector<string> map,route;
	string lineN;
	while (getline(FileName, lineN)) {
		map.push_back(lineN);
	}
	string instructions = map[map.size() - 1];
	map.pop_back();
	map.pop_back();
	currPos = getStart(map);
	vector<int>nextPos;
	int pos = 0;
	route = map;
	while (pos < instructions.size())
	{
		if (isdigit(instructions[pos]))
		{
			int numOfMoves = extractNum(instructions, pos);
			for (int i = 0; i < numOfMoves; i++)
			{
				drawOn(route, dir,currPos);
				nextPos = getNextPos(currPos, dir, map);
				if (map[nextPos[0]][nextPos[1]] == '#')
				{
					break;
				}
				else
				{
					currPos = nextPos;
				}
			}
		}
		else
		{
			dir=turn(dir,instructions[pos]);
			pos++;
		}
	}
	draw(route);
	int yScore = currPos[0] + 1;
	int xScore = currPos[1] + 1;
	int dirScore = dir-1;
	if (dirScore < 0)
	{
		dirScore += 4;
	}
	cout << yScore << ", " << xScore << ", " << dirScore << endl;
	int totalScore = 1000 * yScore + 4 * xScore + dirScore;
	cout << "Part 1 Answer: " << totalScore;
}
