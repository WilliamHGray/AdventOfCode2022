#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void draw(vector<char>crt)
{
	for (int i = 0; i < crt.size(); i++)
	{
		cout << crt[i];
		if (((i + 1) % 40) == 0)
		{
			cout << endl;
		}
	}
}
int main()
{
	ifstream FileName;
	FileName.open("AOC10.txt");
	vector<string> instructions;
	string lineN;
	while (getline(FileName, lineN)) {
		instructions.push_back(lineN);
	}

	int cycle = 0;
	int totalCount = 1;
	int signal = 0;
	int toAdd = 0;
	int currInstr = 0;
	int exec = 0;
	int q = -1;
	vector<char> crt;
	
	for (int i = 0; i < 240; i++)
	{
		string instr = instructions[currInstr];
		if (exec)
		{
			currInstr++;
			toAdd = stoi(instr.substr(5, -1));
			exec--;
		}
		else if (instr[0] == 'a')
		{
			toAdd = 0;
			exec++;
		}
		else
		{
			toAdd = 0;
			currInstr++;
		}
		
		if (((i + 21) % 40)==0)
		{
			//cout << "cycle: " << i+1 << ", reg:" << totalCount << endl;
			signal += (i+1) * totalCount;
		}

		q = i % 40;
		if (abs(totalCount - q) < 2)
		{
			crt.push_back('#');
		}
		else
		{
			crt.push_back('.');
		}
		totalCount = totalCount + toAdd;
		
	}
	cout << signal<<endl<<endl;

	draw(crt);
}