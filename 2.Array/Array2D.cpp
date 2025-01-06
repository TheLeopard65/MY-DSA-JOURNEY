#include <iostream>
using namespace std;
int main(){
	float Array[3][3];                                   // Simple Array Declaration (Datatype can be Anything)
	float Array2D[3][3] = {{1,2,3},{4,5,6}};             // Array Declaration + Initialization

    int row = sizeof(Array2D) / sizeof(Array2D[0]);      // Getting the Row Size of a 2D Array
    int column = sizeof(Array2D[0]) / sizeof(float);     // Getting the Column Size of 2D Array. (Float is the Data type of Array)

    // Inserting an Element at any index in 1D Array
    Array2D[0][0] = 23.5;                                // 2D Array have 2 Indexes (row and Column Repectively) start from 0 each
    Array2D[1][2] = 34.2;
    Array2D[2][2] = 10.1;                                // Array Index ends at ( Array-Row-Size - 1  && Array-Column-Size -1 )
    Array2D[2][3] = 23.0;                                // ERROR: Index out of range

    // Deleting an Element from an 1D Array.
    // There is no proper Deleting method for Array
    // Array[0][2] = NULL;                               // Setting Elements to NULL Works (Program is Compiled)
    // Array[3][3] = NULL;                               // However This Generates a Warning Message

	// Traversing a 2D Array
    cout << "[#] DISPLAYING/TRAVERSING 2D ARRAY IN FORM OF A MATRIX/TABLE!!" << endl;
    for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++)
        	cout << Array2D[i][j] << "\t";
        cout << endl;
    }

	// Finding an Element in a 2D array.
    float find2D = 34.2;
    cout << "[#] SEARCHING FOR THE ELEMENT " << find2D << " IN 2D ARRAY!!";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (find2D == Array2D[i][j]){
                cout << ">[!] ELEMENT " << find2D << " FOUND AT INDEX [" << i << "][" << j << "]!" << endl;
                break;
            }
            else {
            	cout << ">[!] ELEMENT " << find2D << " NOT FOUND!!" << endl;
            }
        }
    }

	// Taking Input in a 2D Array
    cout << "[#] TAKING INPUT IN A 2D ARRAY!!" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cout << ">[!] ENTER VALUE FOR INDEX [" << i << "][" << j << "] : ";
            cin >> Array2D[i][j];
        }
    }

    // Traversing a 2D Array
    cout << "[#] DISPLAYING/TRAVERSING 2D ARRAY IN FORM OF A MATRIX/TABLE!!" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++)
            cout << Array2D[i][j] << "\t";
        cout << endl;
    }

	// Find Minimum
	int minr = 0, minc = 0;
    cout << "[#] SEARCHING FOR THE MAXIMUM ELEMENT IN 2D ARRAY!!";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (Array2D[minr][minc] > Array2D[i][j]){
            	minr = i;
            	minc = j;
            }
        }
    }
    cout << endl << ">[!] MINIMUM VALUE " << Array2D[minr][minc] << " FOUND AT INDEX [" << minr << "][" << minc << "]!" << endl;

    // Find Maximum
	int maxr = 0, maxc = 0;
    cout << "[#] SEARCHING FOR THE MINIMUM ELEMENT IN 2D ARRAY!!";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (Array2D[maxr][maxc] < Array2D[i][j]){
            	maxr = i;
            	maxc = j;
            }
        }
    }
    cout << endl << ">[!] MAXIMUM VALUE " << Array2D[maxr][maxc] << " FOUND AT INDEX [" << maxr << "][" << maxc << "]!" << endl;
}
