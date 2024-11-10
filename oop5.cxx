#include <iostream>
#include<iomanip>

using namespace std;

const int MAX_STUDENTS = 100;

class Student
{
public:
    string name;
    int rollNumber;
    string subject;

    virtual void input()
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter subject: ";
        cin >> subject;
    }

    virtual void display()
    {
        cout << setw(15)<<left<<name
            <<setw(15)<<left<<rollNumber
            <<setw(15)<<left<<subject;
    }

    virtual bool search(int roll)
    {
        return roll == rollNumber;
    }

    virtual void edit()
    {
        cout << "Edit details for Roll Number: " << rollNumber << endl;
        input();
    }
};

class DerivedStudent : public Student
{

public:
    int subjectCode;
    int internalAssessment;
    int universityMarks;
    void input()
    {
        Student::input();
        cout << "Enter subject code: ";
        cin >> subjectCode;
        cout << "Enter internal assessment marks: ";
        cin >> internalAssessment;
        cout << "Enter university marks: ";
        cin >> universityMarks;
    }

    void display()
    {
        Student::display();
        cout << setw(15)<<left<<subjectCode
            <<setw(15)<<left<<internalAssessment
            <<setw(15)<<left<<universityMarks << endl;
    }
};

int main()
{
    DerivedStudent s[MAX_STUDENTS];
    int n = 0;
    int choice, roll;

    while (true)
    {
        cout << "\n1. Build Master Table\n2. List Table\n3. Insert New Entry\n4. Delete Entry\n5. Edit Entry\n6. Search Record\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of students: ";
            cin >> n;
            for (int i = 0; i < n; ++i)
            {
                cout << "\nEntering details for student " << i + 1 << endl;
                s[i].input();
            }
            break;
        case 2:
               cout<<setw(15)<<left<<"Name"
                   <<setw(15)<<left<<"Roll"
                   <<setw(15)<<left<<"Subject"
                   <<setw(15)<<left<<"Subject-code"
                   <<setw(15)<<left<<"Internalmarks"
                   <<setw(15)<<left<<"UniversityMarks"<<endl;
                cout<<setfill('_')<<setw(90)<<""<<setfill(' ')<<endl;   
            for (int i = 0; i < n; ++i)
            {
                s[i].display();
            }
            break;
        case 3:
            if (n >= MAX_STUDENTS)
            {
                cout << "Maximum student limit reached.\n";
               
            }
            cout << "\nInserting new student entry:\n";
            s[n].input();
            n++;
            break;
        case 4:
            cout << "Enter roll number to delete: ";
            cin >> roll;
            int i;
            for (i = 0; i < n; ++i)
            {
                if (s[i].search(roll))
                {
                    break;
                }
            }
            if (i < n)
            {
                for (int j = i; j < n - 1; ++j)
                {
                    s[j] = s[j + 1];
                }
                n--;
                cout << "Record deleted successfully.\n";
            }
            else
            {
                cout << "Record not found.\n";
            }
            break;
        case 5:
            cout << "Enter roll number to edit: ";
            cin >> roll;
            for (int i = 0; i < n; ++i)
            {
                if (s[i].search(roll))
                {
                    s[i].edit();
                    cout << "Record updated successfully.\n";
                   
                }
            }
            cout << "Record not found.\n";
            break;

        case 6:
                cout << "Enter roll number to search: ";
                cin >> roll;

            for (int i = 0; i < n; ++i)
            {
                if (s[i].search(roll))
                {
                    s[i].display();
                    
                }
            }
            cout << "Record not found.\n";

            break;
        case 7:
            return 0;
        }
    }

    return 0;
}