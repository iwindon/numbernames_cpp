using namespace std;

#include <iostream>
#include <string>



// Forward declaration of helper function 
string helper(long long num, string ones[], string teens[], string tens[]);


// funciton to display the written name of a number
string numberToWords(long long num) {
	string result = "";
	string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	string teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
						  "Nineteen"};
	string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	string thousands[] = {"", "Thousand", "Million", "Billion", "Trillion", "Quadrillion", "Quintillion", "Sextillion", "Septillion", "Octillion", "Nonillion", "Decillion"};

	if (num == 0) {
		return "Zero";
	}

	int i = 0;
	while (num > 0) {
		if (num % 1000 != 0) {
			result = helper(num % 1000, ones, teens, tens) + thousands[i] + " " + result;
		}
		num /= 1000;
		i++;
	}

	return result;
}

string helper(long long num, string ones[], string teens[], string tens[]) {
	string result = "";
	if (num >= 100) {
		result += ones[num / 100] + " Hundred ";
		num %= 100;
	}
	if (num >= 11 && num <= 19) {
		result += teens[num - 10] + " ";
	}
	else if (num >= 10) {
		result += tens[num / 10] + " ";
		num %= 10;
	}
	if (num >= 1 && num <= 9) {
		result += ones[num] + " ";
	}
	return result;
}


int main() {
	long long num = 0;
	cout << "Enter a number: ";
	cin >> num;
	cout << numberToWords(num) << endl;
	return 0;
}
