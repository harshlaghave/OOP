#include <iostream>
#include <iomanip>
using namespace std;
class Person
{
  public:
	string name, gender;
	string ID;
	int age;
	int num;
	void setData()
	{
		cout << "Enter the name :";
		cin >> name;
		cout << "Enter the ID :";
		cin >> ID;
		cout << "Enter the num :";
		cin >> num;
		cout << "Enter the age :";
		cin >> age;
		cout << "Enter the Gender :";
		cin >> gender;
	}
};
class Doctor : virtual public Person
{
  public:
	string skills;
	int exp;
	void setData()
	{
		Person ::setData();

		cout << "Enter the experience :";
		cin >> exp;
		cout << "Enter the specialist :";
		cin >> skills;
	}
	void getData()
	{
		cout << setw(15) << left << name
			 << setw(15) << left << ID
			 << setw(15) << left << num
			 << setw(15) << left << age
			 << setw(15) << left << gender
			 << setw(15) << left << exp
			 << setw(15) << left << skills << endl;
	}
};

class Nurse : virtual public Person
{
  public:
	string exp;
	void setData()
	{
		Person ::setData();
		cout << "Enter the experience :";
		cin >> exp;
	}
	void getData()
	{
		cout << setw(15) << left << name
			 << setw(15) << left << ID
			 << setw(15) << left << num
			 << setw(15) << left << age
			 << setw(15) << left << gender
			 << setw(15) << left << exp << endl;
	}
};
class AdministrativeStaff : virtual public Doctor, public Nurse
{
  public:
	string department, exp;

	void setData()
	{
		Person ::setData();
		cout << "Enter the Department :";
		cin >> department;
		cout << "Enter the experience :";
		cin >> exp;
	}
	void getData()
	{
		cout << setw(15) << left << name
			 << setw(15) << left << ID
			 << setw(15) << left << num
			 << setw(15) << left << age
			 << setw(15) << left << gender
			 << setw(15) << left << exp
			 << setw(15) << left << department << endl;
	}
};
int main()
{
	Doctor obj[10];
	Nurse obj2[10];
	AdministrativeStaff obj3[10];

	int i, n, ch;
	do
	{
		cout << "Menu\n1. Enter Doctor Detalis\n2. Enter Nurse Detalis\n3. Enter the Staff Detalis\n4. Display Doctor Detalis\n5. Display Nurse Detalis\n6. Display Staff Detalis\n7. Exit...\nEnter your choice:" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter how many Docotor Detalis Enter it:";
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cout << "Enter " << i + 1 << "th Doctor Detalis :" << endl;
				obj[i].setData();
			}
			break;

		case 2:
			cout << "Enter how many Nurse Detalis Enter it:";
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cout << "Enter " << i + 1 << "th Nurse Detalis :" << endl;
				obj2[i].setData();
			}
			break;
		case 3:
			cout << "Enter how many Staff Detalis Enter it:";
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cout << "Enter " << i + 1 << "th Staff Detalis :" << endl;
				obj3[i].setData();
			}
			break;
		case 4:
			cout << setw(15) << left << "Name"
				 << setw(15) << left << "ID"
				 << setw(15) << left << "Number"
				 << setw(15) << left << "Age"
				 << setw(15) << left << "Gender"
				 << setw(15) << left << "Experience"
				 << setw(15) << left << "Skilss" << endl;
			cout << setfill('_') << setw(105) << "" << setfill(' ') << endl;
			for (i = 0; i < n; i++)
			{
				obj[i].getData();
			}
			break;
		case 5:
			cout << setw(15) << left << "Name"
				 << setw(15) << left << "ID"
				 << setw(15) << left << "Number"
				 << setw(15) << left << "Age"
				 << setw(15) << left << "Gender"
				 << setw(15) << left << "Experience" << endl;

			cout << setfill('_') << setw(90) << "" << setfill(' ') << endl;
			for (i = 0; i < n; i++)
			{
				obj2[i].getData();
			}
			break;
		case 6:
			cout << setw(15) << left << "Name"
				 << setw(15) << left << "ID"
				 << setw(15) << left << "Number"
				 << setw(15) << left << "Age"
				 << setw(15) << left << "Gender"
				 << setw(15) << left << "Experience"
				 << setw(15) << left << "department" << endl;

			cout << setfill('_') << setw(105) << "" << setfill(' ') << endl;
			for (i = 0; i < n; i++)
			{
				obj3[i].getData();
			}
		}
	} while (ch != 7);

	return 0;
}