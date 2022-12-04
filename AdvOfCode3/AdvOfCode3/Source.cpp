#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int charToScore(char n) {
	int i = int(n);
	if (i > 96) {
		//cout << (i - 96) << endl;
		return (i - 96);
	}
	else {
		//cout << (i - 38) << endl;
		return(i - 38);
	}
}

int convertLineToScore(string k) {
	int l = k.length();
	for (int i = 0; i < l < 2; i++)
	{
		for (int j = l / 2; j < l; j++)
		{
			if(k[i] == k[j])
			{
				//cout << k[i] << ": ";
				return charToScore(k[i]);
			}
		}
	}
}

int findBadge(string e1, string e2, string e3) {
	int a = e1.length(), b = e2.length(), c = e3.length();
	vector<char> badgePoss;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (e1[i] == e2[j]) {
				badgePoss.push_back(e1[i]);
			}
		}
	}
	for (int k = 0; k < c; k++)
	{
		if (find(badgePoss.begin(), badgePoss.end(), e3[k]) != badgePoss.end()) {
			//cout << e3[k] << ": ";
			return charToScore(e3[k]);
		}
	}

}

int main() {
	ifstream FileName;
	FileName.open("AOC3.txt");
	int totalScore = 0, loop = 0, totalBadgeScore = 0;
	string LineN, e1, e2, e3;
	while (getline(FileName, LineN)) {
		totalScore+=convertLineToScore(LineN);
		//cout << LineN << endl;
		if (loop == 0) {
			e1 = LineN;
			loop++;
		}
		else if (loop == 1) {
			e2 = LineN;
			loop++;
		}
		else if (loop == 2) {
			e3 = LineN;
			loop = 0;
			totalBadgeScore += findBadge(e1, e2, e3);
		}
	}
	cout << totalScore << endl;
	cout << totalBadgeScore << endl;
}