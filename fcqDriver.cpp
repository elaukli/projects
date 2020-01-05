#include"fcq.hpp"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
void menu()
{
	cout << "======Main Menu======" << endl ;
	cout << "1. Get the Number of Classes" << endl ;
    cout << "2. Get Class Average for Teacher" << endl ;
	cout << "3. Print the teachers classes" << endl ;
	cout << "4. Print the classes teachers" << endl ;
	cout << "6. Best Teacher" << endl ;
	cout << "5. Quit" << endl ;
}
//arr 14
void split(string inputMSG, char delim, string splitARR[], int arrLength) {
    if (inputMSG.length() == 0) {
        return;
    }
    string word = "";
    int j = 0;
    inputMSG = inputMSG + delim;
    for (int i = 0; i < inputMSG.length(); i++) {
        if (inputMSG[i] == delim) {
        	if (word.length() == 0) continue;
        	splitARR[j] = word;
            //cout << word << endl;
            j++;
            word = "";
        }
        else {
				word = word + inputMSG[i];
        }
    }
    return;
}

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		cout << "please provide 2 input filenames <teacher class> " << endl;
		return 0;
	}
	TeacherTree newTree;
	ClassTree newCTree;
	string tFilename = argv[1];
	string cFilename = argv[2];
	ifstream teacherFCQ;
	ifstream classFCQ;
	string lineIn;
	string clineIn;
	string classArr[14];
	string cArr[14];
	int numClasses = 0;
	teacherFCQ.open(tFilename);
	classFCQ.open(cFilename);
	if (teacherFCQ.is_open()) {
		while(getline(teacherFCQ, lineIn)) {
		//cout << lineIn << endl;
		split(lineIn, ',', classArr, 14);
			newTree.addClassNode(classArr[2], classArr[13], (classArr[1] + classArr[0]), stof(classArr[5]), stof(classArr[6]), stof(classArr[8]), stof(classArr[10]), stof(classArr[11]), stof(classArr[12]));
			numClasses += 1;
		}
	}
	if (classFCQ.is_open()) {
		while(getline(classFCQ, clineIn)) {
		//cout << lineIn << endl;
		split(clineIn, ',', cArr, 14);
			newCTree.addClassCNode(cArr[2], cArr[13], (cArr[1] + cArr[0]), stof(cArr[5]), stof(cArr[6]), stof(cArr[8]), stof(cArr[10]), stof(cArr[11]), stof(cArr[12]));
		}
	}
	menu();
	string choice;
	getline(cin, choice);
	while (stoi(choice) != 5) {
    	if (stoi(choice) == 1) {
    		cout << "num classes:" << numClasses << endl;
    	}
    	if (stoi(choice) == 2) {
    		string input;
    		cout << "search for course ID <ATLS-0000>" << endl ;
    			getline(cin, input);
    		newTree.queryClassAvg(input);
    	}
    	if (stoi(choice) == 3) {
    		newTree.printTeacherInventory();
    	}
		if (stoi(choice) == 4) {
    		newCTree.printClassInventory();
    	}
		if (stoi(choice) == 6) {
    		newCTree.queryBestTeachersA();
    	}
    	menu();
    	getline(cin, choice);
	}
    cout << "Goodbye!" << endl ;
		return 0;
}
