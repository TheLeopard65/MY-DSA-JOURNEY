#include <iostream>
using namespace std;
int main() {
	char name[] = "Leopard";                                        // Normal String Declaration (Giving Size is Optional for Strings and Arrays
	char role[] = {'C','T','F',' ','P','L','A','Y','E','R','\0'};   // Character by Character Declaration (Null Character is Required for this)
	cout << "[#] My name is " << name << endl;                          // Normal Printing of a String
	int size = sizeof(role) / sizeof(role[0]);

	// Printing A String (Charater Wise)
	cout << "[#] I am a ";
	for (int i = 0; i < size; i++)
		cout << role[i];                                            // Character by Character Printing
	cout << endl;

	// Printing a Lenght of a String
	cout << "[#] Length of NAME String: " << sizeof(name) << endl;  // This will print 8 because (7 for characters and 1 for Null Character)

	// Taking Input into String (ALL AT ONCE)
	cout << "[#] ENTER YOUR NAME: ";
	cin >> name;

	// Taking Input into String (Character wise)
	for (int i = 0; i < size; i++){
		cout << ">[!] Enter Character for Index [" << i << "] : ";
		cin >> role[i];                                             // Last Character Entered must be '\0'. (But that cant be entered Manually)
	}
	cout << "I am a " << role << endl;

	return 0;
}
