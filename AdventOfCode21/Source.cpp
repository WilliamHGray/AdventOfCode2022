#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

bool isPositive(int64_t num)
{
	if(num>0)
	{
		return true;
	}
	return false;
}

int64_t useOp(char op, string Monkey1, string Monkey2, map<string, int64_t>monkeys)
{
	int64_t num1 = monkeys[Monkey1], num2 = monkeys[Monkey2];
	if (op == '+')
	{
		return num1 + num2;
	}
	else if (op == '-')
	{
		return num1 - num2;
	}
	else if (op == '/')
	{
		return num1 / num2;
	}
	else if (op == '*')
	{
		return num1 * num2;
	}
}

bool monkeyIter(map<string, int64_t>monkeys, queue<string>monkeySums)
{
	while (monkeySums.size() > 0)
	{
		string currMonkey = monkeySums.front();
		monkeySums.pop();
		string currMonkeyName = currMonkey.substr(0, 4);
		string Monkey1 = currMonkey.substr(6, 4), Monkey2 = currMonkey.substr(13, 4);
		char op = currMonkey[11];
		if (monkeys.count(Monkey1) && monkeys.count(Monkey2))
		{
			if (currMonkeyName != "root")
			{
				int64_t num = useOp(op, Monkey1, Monkey2, monkeys);
				monkeys[currMonkeyName] = num;
			}
			else
			{
				if (monkeys[Monkey1] == monkeys[Monkey2])
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			monkeySums.push(currMonkey);
		}
	}
}

int64_t monkeyMaths(map<string, int64_t>monkeys, queue<string>monkeySums)
{
	while (monkeySums.size() > 0)
	{
		string currMonkey = monkeySums.front();
		monkeySums.pop();
		string currMonkeyName = currMonkey.substr(0, 4);
		string Monkey1 = currMonkey.substr(6, 4), Monkey2 = currMonkey.substr(13, 4);
		char op = currMonkey[11];
		if (monkeys.count(Monkey1) && monkeys.count(Monkey2))
		{
			int64_t num = useOp(op, Monkey1, Monkey2, monkeys);
			monkeys[currMonkeyName] = num;
		}
		else
		{
			monkeySums.push(currMonkey);
		}
	}

	return monkeys["root"];
}

int64_t getDiff(map<string, int64_t>monkeys, queue<string>monkeySums, int64_t humanNumber)
{
	monkeys["humn"] = humanNumber;
	while (monkeySums.size() > 0)
	{
		string currMonkey = monkeySums.front();
		monkeySums.pop();
		string currMonkeyName = currMonkey.substr(0, 4);
		string Monkey1 = currMonkey.substr(6, 4), Monkey2 = currMonkey.substr(13, 4);
		char op = currMonkey[11];
		if (monkeys.count(Monkey1) && monkeys.count(Monkey2))
		{
			int64_t num = useOp(op, Monkey1, Monkey2, monkeys);
			monkeys[currMonkeyName] = num;
		}
		else
		{
			monkeySums.push(currMonkey);
		}
	}
	return monkeys["bsbd"] - monkeys["fcgj"];
}

int main()
{
	ifstream FileName;
	FileName.open("AOC21.txt");
	map<string, int64_t>monkeys;
	vector<string> lines;
	string lineN;
	queue<string> monkeySums;
	while (getline(FileName, lineN)) {
		lines.push_back(lineN);
	}
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].size() < 11)
		{
			string monkeyName = lines[i].substr(0, 4);
			int64_t monkeyNum = stoi(lines[i].substr(6, -1));
			monkeys[monkeyName] = monkeyNum;
		}
		else
		{
			monkeySums.push(lines[i]);
		}
	}

	int64_t rootAns = monkeyMaths(monkeys, monkeySums);
	cout << "Part 1 answer: " << rootAns << endl << endl;
	int64_t startNum = monkeys["humn"];
	int64_t leftSide = startNum, rightSide, shift;
	int64_t startDiff = getDiff(monkeys, monkeySums, startNum);
	int64_t offDiff = getDiff(monkeys, monkeySums, startNum + 1000);
	if (startDiff > offDiff)
	{
		shift = 10;
	}
	else
	{
		shift = -10;
	}
	rightSide = shift*startNum;
	bool startSign = isPositive(startDiff);
	bool rightSign = isPositive(getDiff(monkeys, monkeySums, rightSide));
	while (rightSign==startSign)
	{
		rightSide *= shift;
		rightSign = isPositive(getDiff(monkeys, monkeySums, rightSide));
	}
	int64_t midPoint = (rightSide + leftSide) / 2;
	int64_t midDiff = getDiff(monkeys, monkeySums, midPoint);
	while (midDiff != 0)
	{
		cout << "midDiff = " << midDiff << ", midPoint = " << midPoint << endl;
		bool q = isPositive(midDiff);
		if (q == rightSign)
		{
			rightSide = midPoint;
		}
		else
		{
			leftSide = midPoint;
		}
		midPoint = (rightSide + leftSide) / 2;
		midDiff = getDiff(monkeys, monkeySums, midPoint);
	}
	cout << endl;
	cout << "Part 2 answer: " << midPoint;

}
