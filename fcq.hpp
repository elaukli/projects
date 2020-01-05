#include <string>

using namespace std;

struct classLink
{
    std::string instructor;
	int numClasses;
	float classOverall;
	float instrOverall;
	float instrEffective;
	float challenge;
	float learned;
	float respect;
    classLink *next;
};

struct avgClass {
	string courseNumbers;
	int numCourse;
	float courseOverall;
	float instrOverall;
	float instrEffective;
	float challenge;
	float learned;
	float respect;
};

struct avgTeacher {
	string name;
	float courseOverall;
	float instrOverall;
	float instrEffective;
	float challenge;
	float learned;
	float respect;
};

struct avgTeacherC {
	string name;
	int numClasses;
	float courseOverall;
	float instrOverall;
	float instrEffective;
	float challenge;
	float learned;
	float respect;
};

struct singleClass{
    string teacher;
	string title;
    string cid;//course ID
    float courseOverall;
	float instrOverall;
	float instrEffective;
	float challenge;
	float learned;
	float respect;

    singleClass* left = NULL;
    singleClass* right = NULL;

    singleClass(string teach, string t, string c, float cO, float iO, float iE, float chall, float l, float r) {
		teacher = teach;
		title = t;
		cid = c;
		courseOverall = cO;
		instrOverall = iO;
		instrEffective = iE;
		challenge = chall;
		learned = l;
		respect = r;
    }

};

class classByTeacher{
	private:

		classLink* head;
	public:

		classByTeacher();
		bool isEmpty();
		classLink* lastLink();
		void insertTeacher(classLink* previous, string teach, float cO, float iO, float iE, float chall, float l, float r);
		void printPath();
		classLink* getHead();
};

class ClassTree{
    private:
        singleClass* root;
		avgTeacher teachersArr[100];
		int numClasses;
		classByTeacher cBT;
    public:

        ClassTree();

        ~ClassTree();

        void printClassInventory();

        void addClassCNode(string teacher, string title, string cid, float courseOverall, float instrOverall, float instrEffective, float challenge, float learned, float respect);

		void queryBestTeachers(singleClass* searchNode);
		void queryBestTeachersA();




};


class TeacherTree{
    private:
        singleClass* root;
		avgClass tempAverage;

    public:

        TeacherTree();

        ~TeacherTree();

        void printTeacherInventory();

        void addClassNode(string teacher, string title, string cid, float courseOverall, float instrOverall, float instrEffective, float challenge, float learned, float respect);

        bool findClass(std::string tName);

		void queryHelp(singleClass* searchNode,string courseID);

        void queryClassAvg(string courseID);

        //void averageRating();
};
