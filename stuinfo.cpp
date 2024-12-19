#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
    string name;
    int roll_no;
    string student_class;
    string division;
    string dob;
    string blood_group;
    string contact_address;
    string phone_number;
    string driving_license_no;

public:
    static int student_count;

    // Default constructor
    Student() {
        name = "";
        roll_no = 0;
        student_class = "";
        division = "";
        dob = "";
        blood_group = "";
        contact_address = "";
        phone_number = "";
        driving_license_no = "";
        student_count++;
    }

    // Parameterized constructor
    Student(string n, int r, string cl, string div, string dob, string blood, string addr, string phone, string license) {
        name = n;
        roll_no = r;
        student_class = cl;
        division = div;
        this->dob = dob;
        blood_group = blood;
        contact_address = addr;
        phone_number = phone;
        driving_license_no = license;
        student_count++;
    }

    // Copy constructor
    Student(const Student &s) {
        name = s.name;
        roll_no = s.roll_no;
        student_class = s.student_class;
        division = s.division;
        dob = s.dob;
        blood_group = s.blood_group;
        contact_address = s.contact_address;
        phone_number = s.phone_number;
        driving_license_no = s.driving_license_no;
        student_count++;
    }

    // Destructor
    ~Student() {
        student_count--;
        cout << "\nDestructor called for student: " << name << endl;
    }

    // Static member function to display total students
    static void displayStudentCount() {
        cout << "Total students: " << student_count << endl;
    }

    // Friend function to display student details
    friend void displayStudentDetails(const Student &s);

    // Member function to input student details
    void inputDetails() {
        cout << "\nEnter student details: \n";
        cout << "Name: ";
        cin.ignore();  // To clear the input buffer before reading a string
        getline(cin, name);
        cout << "Roll Number: ";
        cin >> roll_no;
        cout << "Class: ";
        cin >> student_class;
        cout << "Division: ";
        cin >> division;
        cout << "Date of Birth (DD/MM/YYYY): ";
        cin >> dob;
        cout << "Blood Group: ";
        cin >> blood_group;
        cout << "Contact Address: ";
        cin.ignore();
        getline(cin, contact_address);
        cout << "Phone Number: ";
        cin >> phone_number;
        cout << "Driving License Number: ";
        cin >> driving_license_no;
    }

    // Inline function to display student details
    inline void displayDetails() {
        cout << "\nStudent Information: \n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Class: " << student_class << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << blood_group << endl;
        cout << "Contact Address: " << contact_address << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Driving License No: " << driving_license_no << endl;
    }

    // Function to get the student's name (using the `this` pointer)
    string getName() {
        return this->name;
    }
};

// Initialize the static member variable
int Student::student_count = 0;

// Friend function to display student details
void displayStudentDetails(const Student &s) {
    cout << "\nFriend function displaying student details:\n";
    cout << "Name: " << s.name << endl;
    cout << "Roll No: " << s.roll_no << endl;
    cout << "Class: " << s.student_class << endl;
    cout << "Division: " << s.division << endl;
    cout << "Date of Birth: " << s.dob << endl;
    cout << "Blood Group: " << s.blood_group << endl;
    cout << "Contact Address: " << s.contact_address << endl;
    cout << "Phone Number: " << s.phone_number << endl;
    cout << "Driving License No: " << s.driving_license_no << endl;
}

int main() {
    // Dynamically allocating memory for an array of Student objects
    Student *students = new Student[5];  // Array of 5 students

    int choice;
    cout << "Student Information System\n";
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student Details\n";
        cout << "2. Display All Students\n";
        cout << "3. Display Total Student Count\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Add a new student's details
            for (int i = 0; i < 5; i++) {
                students[i].inputDetails();
            }
            break;

        case 2:
            // Display details of all students
            for (int i = 0; i < 5; i++) {
                students[i].displayDetails();
            }
            break;

        case 3:
            // Display total student count
            Student::displayStudentCount();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 4);

    // Cleaning up dynamic memory
    delete[] students;

    return 0;
}
