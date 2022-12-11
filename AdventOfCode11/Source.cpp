#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int modulus = 1;

void throwItem(int64_t value, int monkey, vector<queue<int64_t>> &bags)
{
	bags[monkey].push(value);
}

int64_t operate(int monkey, int64_t in, vector<vector<int>> monkeyOps)
{	
	bool t = false;
	if (monkeyOps[monkey][1] == -1)
	{
		t = true;
		monkeyOps[monkey][1] = in;
	}
	if (monkeyOps[monkey][0] == 0)
	{
		return in + monkeyOps[monkey][1];
	}
	else
	{
		return (in * monkeyOps[monkey][1])%modulus;
	}
}

int test(int value, int testInt, vector<int> throwTo)
{
	if (value % testInt == 0)
	{
		return throwTo[0];
	}
	return throwTo[1];
}

int main()
{
	ifstream FileName;
	FileName.open("AOC11.txt");
	string lineN;
	vector<string> input;
	while (getline(FileName, lineN)) {
		input.push_back(lineN);
	}
	vector<int> inspected;
	vector<vector<int>> operations;	//contains operations for inspection
	vector<queue<int64_t>> monkeyBags;	//contains each monkey's current items
	vector<int> testInts;	//contains what to divide by
	vector<vector<int>> throwTo; //contains the monkeys to which each monkey throws
	int monkey=-1;
	int someConstant = 10000;
	int someDivisionConstant = 1;

	for (int i = 0; i < input.size(); i++)
	{
		string instruction = input[i];
		if (instruction.size() > 2)
		{
			if (instruction[0] == 'M')
			{
				char t = instruction[7];
				monkey = t - '0';
				inspected.push_back(0);
				//cout << monkey << endl;
			}

			else if (instruction[2] == 'S')
			{
				queue < int64_t > temp;
				for (int j = 18; j < instruction.size(); j += 4)
				{
					string t = instruction.substr(j, 2);
					temp.push(stoi(t));
					//cout << t << ", ";
				}
				//cout << endl;
				monkeyBags.push_back(temp);
			}
			else if (instruction[2] == 'O')
			{
				vector<int> temp;
				if (instruction[23] == '+')
				{
					temp.push_back(0);
				}
				else
				{
					temp.push_back(1);
				}
				string t = instruction.substr(25, -1);
				if (t == "old")
				{
					temp.push_back(-1);
				}
				else
				{
					temp.push_back(stoi(t));
				}
				//cout << instruction[23] << t << endl;
				operations.push_back(temp);
			}
			else if (instruction[2] == 'T')
			{
				int t = stoi(instruction.substr(21, -1));
				testInts.push_back(t);
				modulus *= t;
				//cout << instruction.substr(21, -1) << endl;
			}
			else if (instruction[7] == 't')
			{
				vector<int> temp;
				int s = instruction[29] - '0';
				int t = input[i + 1][30] - '0';
				temp.push_back(s);
				temp.push_back(t);
				throwTo.push_back(temp);
				//cout << s << ", " << t << endl << endl;
			}
		}
	}

	for (int i = 0; i < someConstant; i++)
	{
		for (int j = 0; j <= monkey; j++)
		{
			int q = monkeyBags[j].size();
			inspected[j] += q;
			for (int k = 0; k < q;k++)
			{
				int64_t item = monkeyBags[j].front();
				int64_t value = operate(j, item, operations)/ someDivisionConstant;
				value = value % modulus;
				int testRes = test(value, testInts[j], throwTo[j]);
				throwItem(value, testRes, monkeyBags);
				monkeyBags[j].pop();
			}
		}
	}
	int64_t max1 = 0, max2 = 0;
	for (int m = 0; m <= monkey; m++)
	{
		cout << inspected[m] << endl;
		if (inspected[m] > max1)
		{
			max2 = max1;
			max1 = inspected[m];
		}
		else if (inspected[m] > max2)
		{
			max2 = inspected[m];
		}
	}
	cout << max1 * max2;
}