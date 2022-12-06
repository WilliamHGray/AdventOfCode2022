#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<stack>

using namespace std;


void moveBox(int start, int end, vector<stack<char>> &columns)
{
	char swap = columns[start].top();
	columns[start].pop();
	columns[end].push(swap);
}

void moveBoxes(int start, int end, int total, vector<stack<char>>& columns)
{
	stack<char> swap;
	for (int i = 0; i < total; i++)
	{
		swap.push(columns[start].top());
		columns[start].pop();
	}
	for (int i = 0; i < total; i++)
	{
		columns[end].push(swap.top());
		swap.pop();
	}
}

void useInstruction(string Instruction, vector<stack<char>>& columns)
{
	int total = 0, start = 0, end = 0, l = Instruction.length() - 1;
	string tempSubstr;
	total = stoi(Instruction.substr(5,7));
	start = int(Instruction[l - 5]-48);
	end = int(Instruction[l]-48);
	/*
	for (int i = 0; i < total; i++)
	{
		moveBox(start-1, end-1, columns);
	}
	*/
	moveBoxes(start-1, end-1, total, columns);
	
}

void sortStack(stack<string> initial, vector<stack<char>> &columns)
{
	int k = initial.size();
	int l = initial.top().length();
	int totalNumOfStacks = 0;
	for (int i = 0; i < l; i++)
	{
		string numRow = initial.top();
		if (numRow[i] != ' ' && int(numRow[i]) > totalNumOfStacks)
		{
			totalNumOfStacks++;
		}
	}
	initial.pop();
	string Line;
	for (int i = 0; i < k - 1; i++)
	{
		Line = initial.top();
		if (i == 0)
		{
			for (int j = 0; j < totalNumOfStacks; j++)
			{
				stack<char> tempSetup;
				tempSetup.push(Line[4 * j + 1]);
				columns.push_back(tempSetup);
			}
		}
		else
		{
			for (int j = 0; j < totalNumOfStacks; j++)
			{
				if (Line[4 * j + 1] != ' ') 
				{
					columns[j].push(Line[4 * j + 1]);
				}
				
			}
		}
		initial.pop();
	}

}

void main()
{
	ifstream FileName;
	FileName.open("AOC5.txt");
	vector<string> instructions;
	vector<stack<char>> columns;
	stack<string> readTillColNums;
	string LineN;
	int reachedInstructions = 0;
	while (getline(FileName, LineN))
	{
		if (reachedInstructions == 0) 
		{
			if (LineN[1] != '1')
			{
				readTillColNums.push(LineN);
			}
			else 
			{
				reachedInstructions++;
				readTillColNums.push(LineN);
			}
		}
		else if (reachedInstructions == 1)
		{
			reachedInstructions++;
		}
		else
		{
			instructions.push_back(LineN);
		}
	}
	sortStack(readTillColNums,columns);

	int numOfInstructions = instructions.size();
	for (int i = 0; i < numOfInstructions; i++)
	{
		useInstruction(instructions[i], columns);
	}
	
	for (int i = 0; i < columns.size(); i++)
	{
		cout << columns[i].top();
	}
}