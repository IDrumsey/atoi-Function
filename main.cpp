#include <iostream>
#include <string>

using namespace std;

bool isValid(char x) {
	if (x == '+' || x == '-' || isdigit(x)) {
		return 1;
	}
	else return 0;
}

int convert(char x) {
	int c;
	switch (x)
	{
	case '1':
		c = 1;
		break;
	case '2':
		c = 2;
		break;
	case '3':
		c = 3;
		break;
	case '4':
		c = 4;
		break;
	case '5':
		c = 5;
		break;
	case '6':
		c = 6;
		break;
	case '7':
		c = 7;
		break;
	case '8':
		c = 8;
		break;
	case '9':
		c = 9;
		break;
	}

	return c;
}


int main() {
	bool negative = 0;
	int num = 0;

	//get string from user
	string str;
	cout << "String : ";
	getline(cin, str);

	//find first non-white char
	int i = 0;
	while (str[i] == ' ') {
		i++;
	}

	cout << "First char = " << str[i] << endl;


	//Check if first non-white is valid
	if (isValid(str[i])) {
		//Cut out whitespaces
		str = str.substr(i, str.length() - i);

		//check if it is negative symbol
		if (str[i] == '-') {
			negative = 1;
			i++;
		}
		
		//find endIndex
		int endIndex = 0;
		while (isdigit(str[endIndex])) {
			endIndex++;
		}
		endIndex--;


		//Cut out trailing chars
		str = str.substr(0, endIndex + 1);

		int j = 0;
		while (j <= endIndex) {
			num += convert(str[j] * pow(10, str.length() - (j+1)));
			j++;
		}
		
		if (negative == 1)num *= -1;
	}
	else {
		num = 0;
	}
	
	cout << "Final num = " << num << endl;
	
	system("pause");
	return 0;
}