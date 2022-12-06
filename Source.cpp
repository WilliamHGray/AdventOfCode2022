#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool getOverlap(string N) {
	int l = N.length();
	int mid = N.find(",");
	string first = N.substr(0, mid);
	string last = N.substr(mid + 1, l - 1);
	int firstMid = first.find("-"), lastMid = last.find("-"), firstL=first.length(),lastL=last.length();
	int firstMin = stoi(first.substr(0, firstMid)), firstMax = stoi(first.substr(firstMid + 1, firstL - 1));
	int lastMin = stoi(last.substr(0, lastMid)), lastMax = stoi(last.substr(lastMid + 1, lastL - 1));
	
	if (firstMin <= lastMin && firstMax>=lastMax)
	{
		return true;
	}
	else if (lastMin <= firstMin && lastMax>=firstMax)
	{
		return true;
	}

	return false;
}

bool anyOverlap(string N) {
	int l = N.length();
	int mid = N.find(",");
	string first = N.substr(0, mid);
	string last = N.substr(mid + 1, l - 1);
	int firstMid = first.find("-"), lastMid = last.find("-"), firstL = first.length(), lastL = last.length();
	int firstMin = stoi(first.substr(0, firstMid)), firstMax = stoi(first.substr(firstMid + 1, firstL - 1));
	int lastMin = stoi(last.substr(0, lastMid)), lastMax = stoi(last.substr(lastMid + 1, lastL - 1));

	if(firstMin <= lastMin && lastMin <= firstMax)
	{
		return true;
	}
	else if (lastMin <= firstMin && firstMin <= lastMax)
	{
		return true;
	}

	return false;
}

int main() {
	ifstream FileName;
	FileName.open("AOC4.txt");
	int totalCount = 0;
	int totalOverlap = 0;
	string lineN;
	while (getline(FileName, lineN)) {
		totalCount += getOverlap(lineN);
		totalOverlap += anyOverlap(lineN);
	}
	cout << totalCount << endl;
	cout << totalOverlap << endl;
}