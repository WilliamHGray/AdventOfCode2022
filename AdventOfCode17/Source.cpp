#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>>getShape(int n) {
	vector<vector<int>> out;
	if (n % 5 == 1)
	{
		vector<int>temp{ 1,1,1,1 };
		out.push_back(temp);
	}
	else if (n % 5 == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			vector<int>temp;
			if (i == 1)
			{
				temp={ 1,1,1 };
			}
			else
			{
				temp={ 0,1,0 };
			}
			out.push_back(temp);
		}
	}
	else if (n % 5 == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			vector<int>temp;
			if (i == 0)
			{
				temp = { 1,1,1 };
			}
			else
			{
				temp = { 0,0,1 };
			}
			out.push_back(temp);
		}
	}
	else if (n % 5 == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			vector<int>temp{ 1 };
			out.push_back(temp);
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			vector<int>temp{ 1,1 };
			out.push_back(temp);
		}
	}
	return out;
}

void draw(vector<vector<int>> input)
{
	for (int i = input.size()-1; i >-1; i--)
	{
		int j = 0;
		while (j < input[i].size())
		{
			if (input[i][j] == 0)
			{
				cout << '.';
			}
			else
			{
				cout << '#';
			}
			j++;
		}
		cout << endl;
	}

}

int getShapeFootprint(int num)
{
	int r = num % 5;
	if (r == 1)
	{
		return 4;
	}
	else if (r == 4)
	{
		return 1;
	}
	else if(r>0)
	{
		return 3;
	}
	else
	{
		return 2;
	}
}

void drawInShape(vector<vector<int>>& grid,vector<vector<int>>shape,int startx, int starty)
{
	for (int i = shape.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < shape[i].size(); j++)
		{
			if(shape[i][j])
				grid[i + starty][j + startx] = shape[i][j];
		}
	}
}

int getVertFootprint(int shapenum, char jetMove)
{
	int r = shapenum % 5;

	if (r == 0)
	{
		return 2;
	}
	else if (r == 2)
	{
		return 3;
	}
	else
	{
		return r;
	}
}

void jetMoveShape(int& startx, int starty, int shapenum, vector<vector<int>>grid, char jetMove)
{
	int footprint = getShapeFootprint(shapenum);
	int vertFootprint = getVertFootprint(shapenum, jetMove);
	bool weirdShape = false;
	bool lShape = false;
	if (shapenum == 2)
		weirdShape = true;
	if (shapenum == 3)
		lShape = true;

	int t = 1;
	if (jetMove == '<' && startx > 0)
	{
		if (weirdShape)
		{
			for (int i = starty; i < starty + vertFootprint; i++)
			{
				if (i == starty+1 && grid[i][startx - 1] == 1)
				{
					t = 0;
				}
				else if (grid[i][startx] == 1)
				{
					t = 0;
				}
			}
		}
		else if (lShape)
		{
			for (int i = starty; i < starty + vertFootprint; i++)
			{
				if (i == starty && grid[i][startx - 1] == 1)
				{
					t = 0;
				}
				else if (grid[i][startx+1] == 1)
				{
					t = 0;
				}
			}
		}
		else
		{
			for (int i = starty; i < starty + vertFootprint; i++)
			{
				if (grid[i][startx - 1] == 1)
				{
					t = 0;
				}
			}
		}
		if(t)
			startx--;
	}
	else if (jetMove == '>'&&(startx + footprint) < 7)
	{
		if(!weirdShape)
		{	
			for (int i = starty; i < starty + vertFootprint; i++)
			{
				
				if (grid[i][startx + footprint] == 1)
				{
					t = 0;
				}
			}
		}
		else
		{
			for (int i = starty; i < starty + vertFootprint; i++)
			{
				if (i == starty+1 && grid[i][startx+footprint] == 1)
				{
					t = 0;
				}
				else if (grid[i][startx+footprint-1] == 1)
				{
					t = 0;
				}
			}
		}
		if (t)
			startx++;
	}

}

int drop(vector<vector<int>>& grid, int shapeNum, int Height, string Jets, int &instr)
{
	int startx = 2, starty = Height+3;
	vector<vector<int>> shape = getShape(shapeNum);
	int footprint = getShapeFootprint(shapeNum);
	bool falling = true;
	bool weirdShape = false;
	if (shapeNum == 2)
	{
		weirdShape = true;
	}
	
	while (falling)
	{
		char jetMove = Jets[instr];
		instr = (instr + 1) % Jets.size();
		jetMoveShape(startx, starty, shapeNum, grid, jetMove);

		if (starty == 0)
		{
			falling = false;
		}
		else
		{
			
			if (!weirdShape)
			{
				for (int i = 0; i < footprint; i++)
				{
					if (grid[starty - 1][startx + i] == 1)
					{
						falling = false;
					}
				}
			}
			else
			{
				for (int i = 0; i < footprint; i++)
				{
					if (i == 1&& grid[starty - 1][startx + i] == 1)
					{
						falling = false;
					}
					else if(grid[starty][startx + i] == 1)
					{
						falling = false;
					}
				}
			}
			if (falling)
			{
				starty--;
				
			}
		}
	}

	drawInShape(grid, shape, startx, starty);
	return starty;
}

bool rowsEmpty(vector<int>row)
{
	for (int i = 0; i < row.size(); i++)
	{
		if(row[i]==1)
		{
			return false;
		}
	}
	return true;
}

int rowIsFull(vector<int>row)
{
	int total = 0;
	for (int i = 0; i < row.size(); i++)
	{
		if (row[i] == 1)
		{
			total++;
		}
	}
	return total;
}

int main() {
	ifstream FileName;
	FileName.open("AOC17.txt");
	string Jets,lineN;
	while (getline(FileName, lineN))
	{
		Jets = lineN;
	}
	int instr = 0;
	int64_t someConstant= 5000000;
	int maxHeight = 0;
	int oldMaxHeight = 0;
	int64_t totalHeight = 0;
	int placedy = 0;
	vector<vector<int>>grid;
	cout << Jets.size() << endl;
	for (int i = 0; i <= maxHeight; i++)
	{
		grid.push_back({ 0,0,0,0,0,0,0 });
	}
	for (int64_t i = 1; i <= someConstant; i++)
	{
		if (!(i % 100000))
		{
			cout << "iteration " << i << endl;
		}
		if (!(instr % Jets.size()))
		{
			cout << i << endl;
		}
		if (maxHeight+7 > grid.size())
		{
			for(int h=grid.size()+1;h<=maxHeight+7;h++)
			{
				grid.push_back({ 0,0,0,0,0,0,0 });
			}
		}
		placedy = drop(grid, i%5, maxHeight,Jets,instr);
		oldMaxHeight = maxHeight;
		while (!rowsEmpty(grid[maxHeight]))
		{
			maxHeight++;
		}
		for (int j = placedy; j < maxHeight; j++)
		{
		
			if (rowIsFull(grid[j])>6)
			{
				vector<vector<int>>tempgrid;
				for (int r = j; r < maxHeight; r++)
				{
					tempgrid.push_back(grid[r]);
				}
				totalHeight += j;
				maxHeight -= j ;
				grid = tempgrid;
				break;
			}
		}
		
		if (i == someConstant)
		{
			totalHeight += maxHeight;
			//draw(grid);
		}
	}

	cout << totalHeight;
}