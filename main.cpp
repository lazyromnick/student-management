#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int STUDENTS = 5;
const int SUBJECT = 5;
const int GRADES = 5;
//5 Subjects - Math, English, Science, Programming, PE

//function declarations
void header();
void menu();
void addStudent(int id[], string name[],int size);
void addGrades(string name[],string subject[],float grades[][GRADES],int row);
void displayStudents(int id[], string name[], string subject[], float grades[][GRADES], int size);
float calcGWA(float grades[], int numSubjects);
void sortByID(int id[]);

int main(){
    int studentID[STUDENTS];
    string studentName[STUDENTS];
    string subject[SUBJECT] = {"Math","Science","Filipino","History","Programming"};
    float grades[STUDENTS][GRADES];
    float gwa[STUDENTS][GRADES];
    int choice;

    do{
        header();
        menu();
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 9){
            cout << "\nThank you for using our system." << endl;
        } else{
            switch(choice){
                case 1:
                    addStudent(studentID,studentName,STUDENTS);
                    break;
                case 2:
                    addGrades(studentName,subject,grades,STUDENTS);
                    break;

                case 3:
                    displayStudents(studentID, studentName, subject, grades, STUDENTS);
                    break;

                case 4:
                    break;
            }
        }
    } while(choice != 9);

    return 0;
}

void header(){
    cout << "===============================================" << endl;
    cout << "------- STUDENT GRADES MANAGEMENT SYSTEM ------" << endl;
    cout << "===============================================" << endl;
}

void menu(){
    cout << "[1] Add Student" << endl;
    cout << "[2] Add Students Grade" << endl;
    cout << "[3] View Students Information" << endl;
    cout << "[4] Sort Students by ID" << endl;
    cout << "[5] Sort Students by Name" << endl;
    cout << "[6] Sort Students by GWA" << endl;
    cout << "[7] Search Students by Name" << endl;
    cout << "[8] Search Students by ID" << endl;
    cout << "[9] Exit" << endl;
}

void addStudent(int id[],string name[], int size){
    cout << "------------------------------" << endl;
    cout << "Add students ID and Names" << endl;
    for(int i = 0; i < size; i++){
        cout << "\nStudent " << i+1 << ": " << endl;
        cout << "ID: ";
        cin >> id[i];
        cin.ignore();
        cout << "Name: ";
        getline(cin, name[i]);
    }
    cout << endl;
}

void addGrades(string name[],string subject[],float grades[][GRADES],int row){
    cout << "------------------------------" << endl;
    cout << "Add students grade" << endl;
    for(int i = 0; i < row; i++){
        cout << "\n" << name[i] << endl;
        for(int j = 0; j < GRADES; j++){
            cout << "  " << subject[j] << ": ";
            cin >> grades[i][j];
            cin.ignore();
        }
    }
    cout << endl;
}

float calcGWA(float grades[], int numSubjects) {
    float sum = 0;
    for (int j = 0; j < numSubjects; j++) {
        sum += grades[j];
    }
    return sum / numSubjects;
}

void displayStudents(int id[], string name[], string subject[], float grades[][GRADES], int size){
    cout << "------------------------------" << endl;
    cout << "View students masterlist" << endl;
    cout << "\n" << left << setw(8) << "ID" << setw(20) << "Name";
    cout << setw(9) << subject[0] << setw(12) << subject[1] << setw(13) << subject[2] << setw(12) << subject[3] << setw(12) << subject[4];
    cout << setw(12) << "GWA" << endl;


    for(int i = 0; i < size; i++){
        float gwa = calcGWA(grades[i], GRADES);
        cout << left << setw(8) << id[i] << setw(20) << name[i];


        for(int j = 0; j < GRADES; j++){
            cout << setw(12) << fixed << setprecision(2) << grades[i][j];
        }

        cout << setw(10) << fixed << setprecision(2) << gwa << endl;
    }
    cout << endl;
}
