#include <iostream>
using namespace std;
int main() {
	int ArrayB[10];                                // Simple Array Declaration
	int Array[10] = {0,1,2,3,4,5,6,7};             // Array Declaration + Initialization
	int size = sizeof(Array) / sizeof(Array[0]);   // Getting the Size of Array.
	// If we Do not Initialize any Values at declaration, Garbage Values are assigned in the Elements

	// Inserting an Element at any index in 1D Array
	Array[0] = 23;                                 // Array Indexes start from  0
	Array[4] = 34;
	Array[9] = 10;                                 // Array Index ends at ( Array-Size - 1 )
	Array[10] = 23;                                // LOGICAL ERROR: Index out of range (Gives Garbage Values, If printed)

	// Deleting an Element from an 1D Array.
	// There is no proper Deleting method for Array
	// Array[0] = NULL;                            // Setting Elements to NULL Works (Program is Compiled)
	// Array[3] = NULL;                            // However This Generates a Warning Message

	// Traversing the 1D Array
	cout << "[#] DISPLAYING/TRAVERSING 1D ARRAY: ";
	for (int i = 0; i < size; i++)
		cout << Array[i] << " - ";
	cout << "END" << endl;

	// Finding an Element in a 1D Array
	int find = 10;
	cout << "[#] SEARCHING FOR AN ELEMENT " << find << " IN 1D ARRAY!!" << endl;
	for (int i = 0; i < size; i++){
		if (find == Array[i]){                     // Condition to check if it is what we are looking for
			cout << ">[!] ELEMENT " << find << " FOUND AT INDEX " << i << " !" << endl;
			break;
		}
		else {
			cout << ">[!] ELEMENT " << find << " NOT FOUND!" << endl;
		}
	}

	// Taking Input into 1D Array
	cout << "[#] TAKING INPUT IN 1D ARRAY!!" << endl;
	for (int i = 0; i < size; i++){
		cout << ">[!] ENTER VALUE FOR INDEX " << i << " : ";
		cin >> Array[i];                           // Taking Input into each element
	}

	// Traversing 1D Array
	cout << "[#] DISPLAYING/TRAVERSING 1D ARRAY: ";
	for (int i = 0; i < size; i++)
		cout << Array[i] << " - ";
	cout << "END" << endl;

	// Finding Minimum Value
	int min = 0;
	cout << "[#] SEARCHING FOR THE MINIMUM ELEMENT IN 1D ARRAY!!" << endl;
	for (int i = 0; i < size; i++){
		if (Array[min] > Array[i]){
			min = i;
		}
	}
	cout << ">[!] MIMIMUM VALUE " << Array[min] << " FOUND AT INDEX [" << min << "]!" << endl;

	// Finding Maximum Value
	int max = 0;
	cout << "[#] SEARCHING FOR THE MAXIMUM ELEMENT IN 1D ARRAY!!" << endl;
	for (int i = 0; i < size; i++){
		if (Array[max] < Array[i]){
			max = i;
		}
	}
	cout << ">[!] MIMIMUM VALUE " << Array[max] << " FOUND AT INDEX [" << max << "]!" << endl;

	return 0;

}
