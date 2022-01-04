#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int fromRandom(int a, int b)
{
	int c = (rand() % (b - a + 1)) + a;
	return c;
}

int main()
{
	srand(time(NULL));
	int p_lenght;
	string get_string;
	bool symbols, numbers, uppercase;
	string p;
	string l[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
	string u[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	string s[19] = { "!","#","$","%","&","*",",","-",".","/",":","<","=",">","?","@","^","_","|" };
	string n[10] = { "1","2","3","4","5","6","7","8","9","0" };
	cout << "#############################\n# RANDOM PASSWORD GENERATOR #\n#############################\n\n";
	cout << "Password Length: ";
	cin >> p_lenght;
	cout << "Include Symbols (e.g. @#$%)  [y/n]: ";
	cin >> get_string;
	if (get_string == "y")
		symbols = true;
	else
		symbols = false;
	cout << "Include Numbers              [y/n]: ";
	cin >> get_string;
	if (get_string == "y")
		numbers = true;
	else
		numbers = false;
	cout << "Include Uppercase Characters [y/n]: ";
	cin >> get_string;
	if (get_string == "y")
		uppercase = true;
	else
		uppercase = false;
	cout << "\n[ENTER] GENERATE  [ESC] EXIT\n\n";
	while (true)
	{
		string r_p;
		for (int i = 0; i < p_lenght; i++)
		{
			char b = fromRandom(1, 4);
			if (b == 1)
				r_p += l[fromRandom(0, 25)];
			else if (b == 2 && uppercase)
				r_p += u[fromRandom(0, 25)];
			else if (b == 3 && symbols)
				r_p += s[fromRandom(0, 18)];
			else if (b == 4 && numbers)
				r_p += n[fromRandom(0, 9)];
			else
				i--;
		}
		p = "Password: " + r_p;
		cout << p << endl;
		int a = _getch();
		if (a == 27)
			break;
	}
	return 0;
}