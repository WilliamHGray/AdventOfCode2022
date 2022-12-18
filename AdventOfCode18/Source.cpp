#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int freeSides(vector<int>coords,vector<vector<int>>positions)
{
	int total = 0;
	vector<vector<int>>temp;
	int x = coords[0], y = coords[1], z = coords[2];
	temp.push_back({ x - 1,y,z });
	temp.push_back({ x + 1,y,z });
	temp.push_back({ x,y - 1,z });
	temp.push_back({ x,y + 1,z });
	temp.push_back({ x,y,z - 1 });
	temp.push_back({ x,y,z + 1 });

	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < positions.size(); j++)
		{
			if (temp[i] == positions[j])
			{
				total++;
				break;
			}
		}
	}
	return 6 - total;
}

int freeSides(vector<int>coords, vector<vector<int>>positions, int range)
{
	int total = 0;
	int x = coords[0], y = coords[1], z = coords[2];

	int up = 0, down = 0, front = 0, back = 0, left = 0, right = 0;

	for (int i = range; i > 0; i--)
	{
		for (int j = 0; j < positions.size(); j++)
		{
			if (!up&&vector<int>{x,y,z+i}==positions[j])
			{
				up = 1;
				total++;
			}
			else if (!down && vector<int>{x, y, z-i} == positions[j])
			{
				down = 1;
				total++;
			}
			else if (!front && vector<int>{x, y+i, z} == positions[j])
			{
				front = 1;
				total++;
			}
			else if (!back && vector<int>{x, y-i, z} == positions[j])
			{
				back = 1;
				total++;
			}
			else if (!left && vector<int>{x-i, y, z} == positions[j])
			{
				left = 1;
				total++;
			}
			else if (!right && vector<int>{x+i, y, z} == positions[j])
			{
				right = 1;
				total++;
			}
		}
		if(total==6)
		{
			break;
		}
	}
	return 6 - total;
}

int main() {
	ifstream FileName;
	FileName.open("AOC18.txt");
	int someConstant =8;
	string lineN;
	vector<vector<int>> positions;
	while (getline(FileName, lineN)) {
		vector<int>temp;
		int j = 0;
		for (int i = 0; i < lineN.size(); i++)
		{
			if (lineN[i] == ',')
			{
				string q = lineN.substr(j, i - j);
				temp.push_back(stoi(q));
				j = i+1;
			}
			else if (i == lineN.size() - 1)
			{
				string q = lineN.substr(j, i - j+1);
				temp.push_back(stoi(q));
			}
		}
		positions.push_back(temp);
	}

	cout << "checking surface area" << endl;
	int total = 0;
	for (int i = 0; i < positions.size(); i++)
	{
		total += freeSides(positions[i], positions);
	}
	cout << total<<endl;
	cout << "part 2" << endl;
	total = 0;
	for (int i = 0; i < positions.size(); i++)
	{
		total += freeSides(positions[i],positions,someConstant);
	}
	cout << total;
}