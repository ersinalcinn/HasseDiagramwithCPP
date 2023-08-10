#include <iostream>
#include <fstream>
#include <array>
using namespace std;
ofstream saveFile("output.txt");
ifstream input("input.txt");
int a = 0, b = 0, c = 0, d = 0, e = 0;
void Symmetric(int rSize, char relationElements[][2], int element);
int lastSymmetric(int rSize, char relationElements[][2], int element);
int antiSymmetric(int rSize, char relationElements[][2], int element);
void Transitive(int rSize, char relationElements[][2], int element, char elements[20]);
void Hasse(int rSize, char relationElements[][2], int element, char elements[20]);
void print(int rSize, char relationElements[][2]) {
	cout << "POSET: ";
	saveFile << "POSET: ";
	for (int i = 0; i < rSize; i++) {
		cout << "(" << relationElements[i][0] << "," << relationElements[i][1]<< ")";
		saveFile << "(" << relationElements[i][0] << "," << relationElements[i][1]<< ")";
	}
	cout << endl;
}
void Reflexive(int rSize, char relationElements[][2], int element, char elements[20]) {
	char temp[element];
	int count = 0;
	for (int i = 0; i < element; i++)
	{
		temp[i] = 0;
	}
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < rSize; j++) {
			if (elements[i] == relationElements[j][0] && elements[i] == relationElements[j][1])
			{
				temp[count] = elements[i];
				count++;
				break;
			}
		}
	}
	for (int i = 0; i < element; i++) {
		if (temp[i] != elements[i]) {
			relationElements[rSize][0] = elements[i];
			relationElements[rSize][1] = elements[i];
			rSize++;
		}
	}
	Symmetric(rSize, relationElements, element);
}
void Symmetric(int rSize, char relationElements[][2], int element) {
	int symmetric = 0;
	for (int i = 0; i < rSize; i++) {
		for (int j = 0; j < rSize; j++) {
			if (relationElements[i][0] == relationElements[j][1] && relationElements[i][1] == relationElements[j][0]) {
				symmetric++;
			}
		}
	}
	if (symmetric == rSize) {
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1] && relationElements[i][1] != relationElements[j][0]) {
					relationElements[j][0] = relationElements[rSize - 1][0];
					relationElements[j][1] = relationElements[rSize - 1][1];
					rSize--;
					break;
				}
			}
			break;
		}
	} else {
		symmetric = 0;

		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1]&& relationElements[i][1] == relationElements[j][0]) {
					symmetric++;
				}
			}
			if (symmetric == 0) {

				i = rSize;
			}
			symmetric = 0;
		}
		symmetric = 0;
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1]
						&& relationElements[i][1] == relationElements[j][0]) {
					symmetric++;
				}
			}
			if (symmetric == 0) {

				i = rSize;
			}
			symmetric = 0;
		}
	}
	lastSymmetric(rSize, relationElements, element);
}
int lastSymmetric(int rSize, char relationElements[][2], int element) {

	for (int i = 0; i < rSize; i++) {
		for (int j = 0; j < rSize; j++) {
			if (relationElements[i][0] == relationElements[j][1] && relationElements[i][1] == relationElements[j][0] && relationElements[i][0] != relationElements[i][1]) {
				relationElements[j][0] = relationElements[rSize - 1][0];
				relationElements[j][1] = relationElements[rSize - 1][1];
				rSize--;
				break;
			}
		}
	}
	print(rSize, relationElements);
	return 0;
}
int antiSymmetric(int rSize, char relationElements[][2], int element) {
	int antisymmetric = 0;
	for (int i = 0; i < rSize; i++) {
		for (int j = 0; j < rSize; j++) {
			if (relationElements[i][0] == relationElements[j][1] && relationElements[i][1] == relationElements[j][0]) {
				antisymmetric++;
			}
		}
	}
	if (antisymmetric == rSize) {
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1] && relationElements[i][1] == relationElements[j][0]) {
					antisymmetric++;
				}
			}
			if (antisymmetric != 0) {

				i = rSize;
			}
			antisymmetric = 0;
		}
	} else {
		antisymmetric = 0;
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1] && relationElements[i][1] == relationElements[j][0]) {
					antisymmetric++;
				}
			}
			if (antisymmetric == 0) {
				i = rSize;
			}
			antisymmetric = 0;
		}
		antisymmetric = 0;
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < rSize; j++) {
				if (relationElements[i][0] == relationElements[j][1] && relationElements[i][1] == relationElements[j][0]) {
					antisymmetric++;
				}
			}
			if (antisymmetric == 0) {

				i = rSize;
			}
			antisymmetric = 0;
		}
	}
}
void Transitive(int rSize, char relationElements[][2], int element, char elements[20]) {
	char tempElements[50][2];
	char tempNot[rSize][2];
	int h = 0;
	int check = 0;
	int tempSize = rSize;
	int count = 0;
	char x, y;
	for (int i = 0; i < tempSize; i++) {
		for (int j = 0; j < tempSize; j++) {
			if (relationElements[i][1] == relationElements[j][0]) {
				tempElements[h][0] = relationElements[i][0];
				tempElements[h][1] = relationElements[j][1];
				h++;

			}
		}
	}
	for (int i = 0; i < rSize; i++) {
		tempNot[i][0] = 0;
		tempNot[i][1] = 0;
	}
	int r = 0;
	c = 0;
	for (int i = 0; i < h; i++) {
		check = 0;
		for (int j = 0; j < rSize; j++) {

			if (tempElements[i][0] == relationElements[j][0]
					&& tempElements[i][1] == relationElements[j][1]) {
				check++;
				break;
			}
		}
		if (check == 0) {
			tempNot[r][0] = tempElements[i][0];
			tempNot[r][1] = tempElements[i][1];
			r++;
		}
	}
	if (tempNot[0][0] == '\0') {
	} else {

		for (int i = 0; i < rSize; i++) {
			if (tempNot[i][0] != '\0') {
				relationElements[rSize ][0] = tempNot[i][0];
				relationElements[rSize ][1] = tempNot[i][1];
				rSize++;

			} else{
				break;
			}
		}
	}
	Reflexive(rSize, relationElements, element, elements);
}
void Hasse(int rSize, char relationElements[][2], int element, char elements[20]) {

}
void inputFile() {

	int element = 0, rSize, newElements = 0, size = 20;
	char elements[20], c;
	//First of all, I can check the file, then I use the while loop to read to the end of the line.
	if (input.is_open()) {
		while (!input.eof()) {
			for (int i = 0; i < size; i++) {
				elements[i] = 0;
			}
			element = 0;
			input.get(c);
			//I keep reading for the \ n at the end of the line. I used my reading as char. (getc)
			if (c == '\n') {
				input.get(c);
			} else {
				//I am reading relation size and if there is no value after you, I applied the if condition because it will be \ n.
				rSize = (int) c - 48;
				input.get(c);
				if (c != '\n') {
					rSize = (rSize * 10) + ((int) c - 48); //The coefficient was determined for the possibility of having a relation greater than 10.
					input.get(c);
				}
				input.get(c);
				char relationElements[rSize][2]; //then define the char array to keep the elements according to the relation size.
				while (c != '\n') {
					if (c != ',') {
						elements[element - (element / 2)] = c;
					}
					input.get(c);
					//the number of elements increases with every char data it reads here
					element++;
				}
				//Thus, I filled the relation elements array separately for each relation using a loop and sent it to functions.
				for (int k = 0; k < rSize; k++) {
					input.get(c);
					relationElements[k][0] = c;
					input.get(c);
					input.get(c);
					relationElements[k][1] = c;
					input.get(c);
				}
				cout <<"\nn \n";
				saveFile <<"\nn \n";
				newElements = element - (element / 2); //I subtract the number of commas read from each number of characters counted.
				Transitive(rSize, relationElements, newElements, elements);
				//Hasse( rSize, relationElements,  newElements,elements);
			}
		}
	}
}
int main() {
	//I call the input File function, where we will read the relations on main.
	inputFile();
}
