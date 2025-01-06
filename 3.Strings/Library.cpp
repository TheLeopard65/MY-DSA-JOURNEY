#include <iostream>
#include <string>        // Importing C++ Library for More Functions
#include <cstring>       // Importing C Library for Even More Functions
using namespace std;
int main() {
	string name = "Leopard", name2 = "LION";
	cout << "[#] My Name is " << name << endl << endl;

	// C++ Library Operations
	cout << "##### [#] C++ STRINGS [#] #####" << endl;
	cout << "[#] The Character at Index 0 is : " << name.at(3) << endl;
	cout << "[#] The Lenght of name String is : " << name.length() << endl;
	cout << "[#] Is the Name String Empty? " << (name.empty() ? "YES" : "NO") << endl;
	cout << "[#] My New Name is " << name.append(" the Great") << endl;
	cout << "[#] My New Name is " << name.substr(0,3) << endl;
	cout << "[#] Found the Character r at Index :" << name.find('r') << endl;
	cout << "[#] Reverse Found the Character L at Index :" << name.rfind('r') << endl;
	cout << "[#] My New Name is " << name << endl;
	cout << "[#] Is My Name the same in both strings : " << (name.compare(name2) ? "YES" : "NO") << endl;

	char fullname[20], Lname[] = "Leopard";

	// C Library Operations
	cout << endl << "##### [#] C STRINGS [#] #####" << endl;
	strcpy(fullname, Lname);                                                               // Copying Name2 into Name
	cout << "[#] The New Name is : " << fullname << endl;
	cout << "[#] The Lenght of My New name is : " << strlen(fullname) << endl;
	strcat(fullname, " the Great");
	cout << "[#] The New Name is : " << fullname << endl;
	cout << "[#] The Lenght of My New name is : " << strlen(fullname) << endl;

	cout << endl << "[#] Similarly Take a look at more of String Functions = https://www.w3schools.com/cpp/cpp_ref_cstring.asp" << endl;
	return 0;
}
