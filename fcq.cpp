#include"fcq.hpp"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

classByTeacher::classByTeacher()
{
}

bool classByTeacher::isEmpty() {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
} //checks to se If LL is empty


void classByTeacher::insertTeacher(classLink* previous, string teach, float cO, float iO, float iE, float chall, float l, float r) {
classLink* temp = head;
while (temp != NULL) {
	if (temp->instructor == teach) { //when adding class, checks if teacher exhists already and adds accordingly
		temp->numClasses += 1;
	   	temp->classOverall += cO;
	   	temp->instrOverall += iO;
	   	temp->instrEffective += iE;
	   	temp->challenge += chall;
	   	temp->learned += l;
	   	temp->respect += r;
		return;
	}
	temp = temp->next;
}
   if(head == NULL) {
	   head = new classLink;
	  	head->instructor = teach;
	   	head->numClasses = 1;
	   	head->classOverall = cO;
	   	head->instrOverall = iO;
	   	head->instrEffective = iE;
	   	head->challenge = chall;
	   	head->learned = l;
	   	head->respect = r;
	   	head->next = NULL;
   }
   // if list is not empty, look for previous and append our node there
   else if(previous == NULL) {
	   classLink* newNode = new classLink;
	   newNode->instructor = teach;
	   newNode->numClasses = 1;
	   newNode->classOverall = cO;
	   newNode->instrOverall = iO;
	   newNode->instrEffective = iE;
	   newNode->challenge = chall;
	   newNode->learned = l;
	   newNode->respect = r;
	   head = newNode;
   }
   //inserting
   else {
	   classLink* newNode = new classLink;
	   newNode->instructor = teach;
	   newNode->numClasses = 1;
	   newNode->classOverall = cO;
	   newNode->instrOverall = iO;
	   newNode->instrEffective = iE;
	   newNode->challenge = chall;
	   newNode->learned = l;
	   newNode->respect = r;
	   previous->next = newNode;
   }
}



void classByTeacher::printPath()
{
	if(head == NULL) {
   	 cout << "nothing in path" << endl;
    }
    classLink* temp = head;

    while(temp->next != NULL){

		cout << "instructor" << temp->instructor << ", "
		 << "numClasse" << temp->numClasses << ", "
		 << "classOverall" << temp->classOverall/temp->numClasses << ", "
		 << "instrOverall" << temp->instrOverall/temp->numClasses << ", "
		 << "instrEffective" << temp->instrEffective/temp->numClasses << ", "
		 << "challenge" << temp->challenge/temp->numClasses << ", "
		 << "learned" << temp->learned/temp->numClasses << ", "
		 << "respect" << temp->respect/temp->numClasses << ", " << endl;
      temp = temp->next;
    }

}

TeacherTree::TeacherTree() {
	root = NULL;
}

ClassTree::ClassTree() {
	root = NULL;
}

void deleteTree(singleClass* node)
{
    if (node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);

    //cout << "\n Deleting node: " << node->title;
    delete node;
}

TeacherTree::~TeacherTree() {
  deleteTree(root);
}

ClassTree::~ClassTree() {
  deleteTree(root);
}

void printTreeHelper(singleClass* currNode)
{
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << "Class: " << currNode->cid << currNode->teacher << " Info: courseO, instructorO, learned (";
		cout << currNode->courseOverall;
		cout << ", " << currNode->instrOverall << ", " << currNode->learned << ")"<< endl;
        printTreeHelper( currNode->right);
     }
}


void TeacherTree::printTeacherInventory() {
	if (root != NULL)
     {
         printTreeHelper(root);
         return;
     }
    cout << "Tree is Empty. Cannot print" << endl;
}

void ClassTree::printClassInventory() {
	if (root != NULL)
     {
         printTreeHelper(root);
         return;
     }
    cout << "Tree is Empty. Cannot print" << endl;
}

singleClass* insert(singleClass* anchor, string teach, string t, string c,
					float cO, float iO, float iE, float chall, float l, float r)
{
    if (anchor == NULL) {
		singleClass* insert = new singleClass(teach, t, c, cO, iO, iE, chall, l, r);
		return insert;
	}
	else if((c.compare(anchor->cid)) < 0){
  	  	anchor->left = insert(anchor->left, teach, t, c, cO, iO, iE, chall, l, r);
    }
    else if((c.compare(anchor->cid)) > 0){
		anchor->right = insert(anchor->right, teach, t, c, cO, iO, iE, chall, l, r);
    }
    return anchor;
}



void TeacherTree::addClassNode(string teacher, string title, string cid,
	float courseOverall, float instrOverall, float instrEffective,
	float challenge, float learned, float respect)
{
	singleClass * newNode = new singleClass(teacher, title, cid, courseOverall, instrOverall, instrEffective, challenge, learned, respect);
	if (root == NULL)
		root = newNode;
	root = insert(root, teacher, title, cid, courseOverall, instrOverall, instrEffective, challenge, learned, respect);
}

void ClassTree::addClassCNode(string teacher, string title, string cid, float courseOverall,
							float instrOverall, float instrEffective, float challenge,
							float learned, float respect)
{
	singleClass * newNode = new singleClass (teacher, title, cid, courseOverall, instrOverall, instrEffective, challenge, learned, respect);

	if (root == NULL) {
		root = newNode;
		numClasses = 1;
	}
	numClasses += 1;
	root = insert(root, teacher, title, cid, courseOverall, instrOverall, instrEffective, challenge, learned, respect);
}

void ClassTree::queryBestTeachers(singleClass* searchNode) //finds the best teacher and shows it
{

	if (searchNode == NULL)
        return;
	cBT.insertTeacher(cBT.getHead(), searchNode->teacher, searchNode->courseOverall, searchNode->instrOverall, searchNode-> instrEffective, searchNode->challenge, searchNode->learned, searchNode-> respect);
	queryBestTeachers(searchNode->left);
	queryBestTeachers(searchNode->right);

}
void ClassTree::queryBestTeachersA()
{
queryBestTeachers(root);
cBT.printPath(); //prints teachers
}

classLink* classByTeacher::getHead() {
	return head;
}

string courseNum(string inId, int num)
{
	char letters[100];
	string out;
	for (int i = 0; i < num; i++) {
		letters[i] = inId[i];
	}
	for (int i = 0; i < num; i++) {
		out += inId[i];
	}
	return out;
}

singleClass* search( singleClass* root, string key)
{
    if (root == NULL || courseNum(root->cid, 9) == key)
       return root;

    if (courseNum(root->cid, 9) < key)
       return search(root->right, key);

    return search(root->left, key);
}

bool TeacherTree::findClass(string title)
{
	singleClass * newNode = root;
	newNode = search(newNode, title);
	if (newNode == NULL) {
        cout << "Movie not found." << endl;
        return false;
    }
	return true;
}

void TeacherTree::queryHelp(singleClass* searchNode, string courseID)
{

    if (searchNode == NULL)
        return;
	string cNum = courseNum(searchNode->cid, 9);
	if (cNum == courseID) {
		tempAverage.numCourse += 1;
		tempAverage.courseOverall += searchNode->courseOverall;
		tempAverage.instrOverall += searchNode->instrOverall;
		tempAverage.instrEffective += searchNode->instrEffective;
		tempAverage.challenge += searchNode->challenge;
		tempAverage.learned += searchNode->learned;
		tempAverage.respect += searchNode->respect;
	}

    queryHelp(searchNode->left, courseID);

    queryHelp(searchNode->right, courseID);
}

void TeacherTree::queryClassAvg(string courseID)
{
	tempAverage.numCourse = 0;
	tempAverage.courseOverall = 0.0;
	tempAverage.instrOverall = 0.0;
	tempAverage.instrEffective = 0.0;
	tempAverage.challenge = 0.0;
	tempAverage.learned = 0.0;
	tempAverage.respect = 0.0;
	if (root == NULL)
		cout << "Tree is Empty. Cannot query Class" << endl ;
	cout << "Average Ratings for: " << courseID << "courseOverall, instrOverall, instrEffective, challenge, learned, respect:" << endl;
	singleClass* searchNode = root;
	if (findClass(courseID)) {
		queryHelp(searchNode, courseID);

		cout << tempAverage.courseOverall/tempAverage.numCourse << ", " << tempAverage.instrOverall/tempAverage.numCourse << ", " << tempAverage.instrEffective/tempAverage.numCourse << ", " <<  tempAverage.challenge/tempAverage.numCourse << ", " <<  tempAverage.learned/tempAverage.numCourse << ", " <<  tempAverage.respect/tempAverage.numCourse << endl;
	}

}
