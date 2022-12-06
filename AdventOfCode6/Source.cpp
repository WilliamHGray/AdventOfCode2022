#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include<chrono>
using namespace std;
/*
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
*/

int main() {
	auto start = chrono::high_resolution_clock::now();
	ifstream FileName;
	FileName.open("AOC6.txt");
	string lineN;
	getline(FileName, lineN);
	int lookingFor = 14;
	for (int i = lookingFor; i < lineN.length(); i++)
	{			
		set<char> letters;
		for (int j = i - lookingFor; j < i; j++)
		{
			letters.insert(lineN[j]);
		}
		if (letters.size() == lookingFor)
		{
			cout << i << endl;
			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
			cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
			exit(0);
		}
	}
}
