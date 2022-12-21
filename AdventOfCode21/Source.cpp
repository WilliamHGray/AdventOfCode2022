#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

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

bool monkeyIter(map<string,int64_t>monkeys,queue<string>monkeySums)
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
	cout << "monkey 1 = " << monkeys["bsbd"] << endl;
	cout << "monkey 2 = " << monkeys["fcgj"] << endl;
	cout << "diff = "<< monkeys["bsbd"]- monkeys["fcgj"] << endl;
	return monkeys["root"];
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
	cout << "Part 1 answer: " << rootAns << endl;
	monkeys["humn"] += 3759566888160;
	int startNum = monkeys["humn"];
	while (!monkeyIter(monkeys, monkeySums))
	{
		monkeys["humn"]++;
		startNum++;
		if (startNum % 100)
		{
			cout << startNum << endl;
		}
	}
	
	cout << monkeys["humn"];
	
}