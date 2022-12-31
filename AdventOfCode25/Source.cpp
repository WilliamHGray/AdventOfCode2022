#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int64_t SNAFUToInt(string number)
{
	int n = number.size();
	int q = n - 1;
	int64_t running = 0;
	for (int i = 0; i < n; i++)
	{
		char digit = number[i];
		int currDigit;
		if (digit == '=')
		{
			currDigit = -2;
		}
		else if(digit == '-')
		{
			currDigit = -1;
		}
		else
		{
			currDigit = digit - '0';
		}
		running += currDigit * pow(5, q - i);
	}
	return running;
}

string intToSNAFU(int64_t n)
{
	int j = 1;
	string out;
	while (n != 0)
	{
		int64_t q = pow(5, j);
		int64_t p = pow(5, j - 1);
		int64_t rem = n % q;
		char next;
		rem = rem / p;
		if (rem == 0)
		{
			next = '0';
		}
		else if (rem == 1)
		{
			next = '1';
			n -= p;
		}
		else if (rem == 2)
		{
			next = '2';
			n -= 2 * p;
		}
		else if (rem == 3)
		{
			next = '=';
			n += 2 * p;
		}
		else if (rem == 4)
		{
			next = '-';
			n += p;
		}
		out = next + out;
		j++;
	}
	return out;
}

int main() {
	ifstream FileName;
	FileName.open("AOC25.txt");
	string lineN;
	vector<string>numbers;
	int64_t total = 0;
	while (getline(FileName, lineN)) {
		numbers.push_back(lineN);
	}
	for (int i = 0; i < numbers.size(); i++)
	{	
		//cout << "Input = " << numbers[i] << endl;
		int64_t out = SNAFUToInt(numbers[i]);
		//cout << "Output = " << out << endl << endl;
		total += out;
	}
	cout << "Total in decimal = " << total << endl;
	string out = intToSNAFU(total);
	cout << "Total in SNAFU = " << out << endl;
}