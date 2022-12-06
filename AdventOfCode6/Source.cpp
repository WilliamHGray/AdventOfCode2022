#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int checkUnique(vector<char> code) {
	int l = code.size();
	for (int i = 0; i < l-1; i++)
	{
		for (int j = i + 1; j < l; j++)
		{
			if (code[i] == code[j])
			{
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	ifstream FileName;
	FileName.open("AOC6.txt");
	string lineN;
	getline(FileName, lineN);

	vector<char> code;
	int max = 14, position = 0;
	for (int i = 0; i < max; i++)
	{
		code.push_back(lineN[i]);
		position++;

	}
	bool uniqueness = checkUnique(code);
	
	for (int i = max; i < lineN.length(); i++)
	{
		position++;
		code[i % max] = lineN[i];
		uniqueness = checkUnique(code);
		if (uniqueness)
		{
			cout << position;
			break;
		}
	}

}

