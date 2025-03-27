#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Datatypes
struct Bus {
    int routeNo;
    string busNo;
};

struct Route {
    int routeNumber;
    string destinations[3];
};

struct Student {
    string name;
    string regNo;
    Bus busInfo;
};

// Array to store registered bus numbers
const int MAX_BUSES = 20;
string registeredBuses[MAX_BUSES] = {"LXF-8333", "BSD-034", "PIS-9832", "RIL-3452", "RIP-5747", "RIL-4999",
                                     "IPA-2347", "RIM-5352", "LMN-5271", "JRP-5700", "FER-1254", "IIM-002", "IEF-2133", "RQP-1789", "SDA-9009", "MNP-1654",
                                     "TYR-4587", "REJ-2222", "RQL-5123", "MNQ-001"};

// Array to store student records
const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];

// Global Variables
int studentCount = 0;
const int MAX_ROUTES = 20;
Route routes[MAX_ROUTES];

const string FILE_NAME = "student_data.txt";

// Function prototypes
void loadStudentDataFromFile();
void saveStudentDataToFile();
void menu();
void studentPanel();
void adminPanel();
void insertStudent();
void displayRecord();
void displaySingleStudent(const Student&);
void searchByName();
bool compareStrings(const string&, const string&);
void searchByReg();
void searchByRoute();
void updateRecord();
void deleteStudent();
void addRoute();
void displayRoutes();
void displayRegisteredBuses();
//Reading data from file
void loadStudentDataFromFile() {
    ifstream file(FILE_NAME.c_str());
    if (file.is_open()) {
        file >> studentCount;

        for (int i = 0; i < studentCount; ++i) {
            file >> students[i].name >> students[i].regNo >> students[i].busInfo.routeNo;
            students[i].busInfo.busNo = registeredBuses[students[i].busInfo.routeNo - 1];
        }

        file.close();
    }
}
//Writing data into file
void saveStudentDataToFile() {
    ofstream file(FILE_NAME.c_str());
    if (file.is_open()) {
        file << studentCount << "\n";

        for (int i = 0; i < studentCount; ++i) {
            // Write the data with appropriate formatting
            file << "Name = | " << students[i].name << " Registration Number = | " << students[i].regNo << " Route Number = | " << students[i].busInfo.routeNo << "\n";
        }

        file.close();
    }
}


void menu() {
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Student Panel" << endl;
        cout << "2. Admin Panel" << endl;
        cout << "3. Display Registered Buses" << endl;
        cout << "4. Display Bus Routes" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                studentPanel();
                break;
            case 2:
                adminPanel();
                break;
            case 3:
                displayRegisteredBuses();
                break;
            case 4:
                displayRoutes();
                break;
            case 5:
                cout << "Exiting program." << endl;
                saveStudentDataToFile();
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

void studentPanel() {
    while (true) {
        cout << "Please select a function to perform :" << endl
             << "Search by Student Record (Press 1)" << endl
             << "Search by Route Numbers (Press 2)" << endl
             << "View Bus Routes (Press 3)" << endl
             << "To Sign Out (PRESS 4)" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Please specify how do you want to search?" << endl
                     << "Search By Name (Press 1)" << endl
                     << "Search by Registration Number (Press 2)" << endl;
                cin >> choice;
                switch (choice) {
                    case 1:
                        searchByName();
                        break;
                    case 2:
                        searchByReg();
                        break;
                    default:
                        cout << "INVALID INPUT!" << endl;
                }
                break;
            case 2:
                searchByRoute();
                break;

            case 3:
                displayRoutes();
                break;
            case 4:
                cout << "Signed Out!" << endl;
                saveStudentDataToFile();
                return;
            default:
                cout << "INVALID INPUT!" << endl;
                break;
        }
    }
}

void adminPanel() {
    // Adding login credentials
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if the entered credentials are correct
    if (username == "admin" && password == "comsats") {
        cout << "Login successful!" << endl;

        // Admin panel operations
        while (true) {
            cout << "Search a Student (PRESS 1)" << endl << "Register New Student (PRESS 2)" << endl
                 << "Update Record (PRESS 3)" << endl << "Delete a Record (PRESS 4)" << endl
                 << "View Record (PRESS 5)" << endl << "Add Bus Route (PRESS 6)" << endl << "To Sign Out (PRESS 7)" << endl;

            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Please specify how do you want to search?" << endl
                         << "Search By Name (Press 1)" << endl
                         << "Search by Registration Number (Press 2)" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            searchByName();
                            break;
                        case 2:
                            searchByReg();
                            break;
                        default:
                            cout << "INVALID INPUT!" << endl;
                            break;
                    }
                    break;
                case 2:
                    insertStudent();
                    break;
                case 3:
                    updateRecord();
                    break;
                case 4:
                    deleteStudent();
                    break;
                case 5:
                    cout << "The Student Records are :" << endl;
                    displayRecord();
                    break;
                case 6:
                    addRoute();
                    break;
                case 7:
                    cout << "Signed Out!" << endl;
                    saveStudentDataToFile();
                    return;
                default:
                    cout << "INVALID INPUT!" << endl;
                    break;
            }
        }
    } else {
        cout << "Invalid username or password. Access denied." << endl;
        return;
    }
}

void displayRegisteredBuses() {
    cout << "Registered Buses: " << endl;
    for (int i = 0; i < MAX_BUSES; ++i) {
        cout << i + 1 << ". " << registeredBuses[i] << endl;
    }
}

void insertStudent() {
    system("CLS");
    if (studentCount < MAX_STUDENTS) {
        Student& student = students[studentCount];
        cout << "Enter name of the Student :" << endl;
        cin >> student.name;
        cout << "Enter Registration number :" << endl;
        cin >> student.regNo;
        cout << "Enter Bus Route Number (1-" << MAX_BUSES << "):" << endl;
        cin >> student.busInfo.routeNo;
        if (student.busInfo.routeNo >= 1 && student.busInfo.routeNo <= MAX_BUSES) {
            student.busInfo.busNo = registeredBuses[student.busInfo.routeNo - 1];
            cout << "Student Registered!" << endl;
            studentCount++;
        } else {
            cout << "Invalid Bus Route Number!" << endl;
        }
    } else {
        cout << "Student database is full!" << endl;
    }
}

void displayRecord() {
    system("CLS");
    if (studentCount == 0) {
        cout << "There is No Record to Show!" << endl;
    }
    for (int i = 0; i < studentCount; ++i) {
        displaySingleStudent(students[i]);
        cout << "                                      &*&*&*&*&*&*&*&*&*&*&" << endl;
    }
}

void searchByName() {
    system("CLS");
    int flag = 0;
    cout << "Enter the Name of student you want to search :" << endl;
    string name;
    cin >> name;
    for (int i = 0; i < studentCount; ++i) {
        if (compareStrings(name, students[i].name)) {
            displaySingleStudent(students[i]);
            flag++;
        }
    }
    if (flag == 0) {
        cout << "No match found." << endl;
    }
}

void searchByReg() {
    system("CLS");
    int flag = 0;
    cout << "Enter Full Registration number to search :                    FORMAT = XXXX-XXX-XXX" << endl;

    string reg;
    cin >> reg;
    for (int i = 0; i < studentCount; ++i) {
        if (compareStrings(reg, students[i].regNo)) {
            displaySingleStudent(students[i]);
            flag++;
        }
    }
    if (flag == 0) {
        cout << "No match found." << endl;
    }
}

void displaySingleStudent(const Student& student) {
    cout << "Name = " << student.name << endl;
    cout << "Registration Number = " << student.regNo << endl;
    cout << "Bus Number = " << student.busInfo.busNo << endl;
    cout << "Route = " << student.busInfo.routeNo << endl;
}

bool compareStrings(const string& string1, const string& string2) {
    return string1 == string2;
}

void searchByRoute() {
    system("CLS");
    int flag = 0;
    cout << "Enter Route Number (between 1-" << MAX_BUSES << ") to search : " << endl;

    int route;
    cin >> route;
    if ((0 < route) && (route <= MAX_BUSES)) {
        for (int i = 0; i < studentCount; ++i) {
            if (route == students[i].busInfo.routeNo) {
                displaySingleStudent(students[i]);
                flag++;
            }
        }
        if (flag == 0) {
            cout << "No record found!" << endl;
        }
    } else
        cout << "Invalid Route given" << endl;
}

void updateRecord() {
    system("CLS");
    int flag = 0;
    cout << "Enter the Registration number of student you want to search :" << endl;
    string reg_no;
    cin >> reg_no;
    for (int i = 0; i < studentCount; ++i) {
        if (compareStrings(reg_no, students[i].regNo)) {
            flag++;
            cout << "    FOUND " << reg_no << endl;
            cout << "Enter new Name :" << endl;
            cin >> students[i].name;
            cout << "Enter new Registration Number :                   FORMAT = XXXX-XXX-XXX" << endl;
            cin >> students[i].regNo;
            cout << "Enter new Route Number :" << endl;
            cin >> students[i].busInfo.routeNo;
            if (students[i].busInfo.routeNo >= 1 && students[i].busInfo.routeNo <= MAX_BUSES) {
                students[i].busInfo.busNo = registeredBuses[students[i].busInfo.routeNo - 1];
                cout << "RECORD UPDATED!" << endl;
            } else {
                cout << "Invalid Bus Route Number!" << endl;
            }
        }
    }
    if (flag == 0) {
        cout << "Registration Number doesn't exist." << endl;
    }
}

void deleteStudent() {
    system("CLS");
    int flag = 0;
    cout << "Enter the Registration number of student you want to search :" << endl;
    string reg_no;
    cin >> reg_no;
    for (int i = 0; i < studentCount; ++i) {
        if (compareStrings(reg_no, students[i].regNo)) {
            flag++;
            cout << "Deleted " << reg_no << endl;
            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }
            studentCount--;
            break;
        }
    }

    if (flag == 0) {
        cout << "Registration Number doesn't exist." << endl;
    }
}

void addRoute() {
    system("CLS");
    int routeNumber;
    cout << "Enter the new Route Number: ";
    cin >> routeNumber;

    if (routeNumber >= 1 && routeNumber <= MAX_ROUTES) {
        cout << "Enter the three destinations for the route: " << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Destination " << i + 1 << ": ";
            cin >> routes[routeNumber - 1].destinations[i];
        }

        routes[routeNumber - 1].routeNumber = routeNumber;

        // Save route data to file
        ofstream routeFile("routes_data.txt", ios::app); // Open file in append mode
        if (routeFile.is_open()) {
            routeFile << "Route " << routeNumber << ": ";
            for (int i = 0; i < 3; ++i) {
                routeFile << routes[routeNumber - 1].destinations[i] << " ";
            }
            routeFile << endl;
            routeFile.close();
            cout << "Route added successfully and saved to file!" << endl;
        } else {
            cout << "Unable to open the routes file!" << endl;
        }
    } else {
        cout << "Invalid Route Number. It should be between 1 and " << MAX_ROUTES << endl;
    }
}


void displayRoutes() {
    system("CLS");
    cout << "List of Bus Routes:" << endl;
    for (int i = 0; i < MAX_ROUTES; ++i) {
        cout << "Route " << routes[i].routeNumber << ": ";
        for (int j = 0; j < 3; ++j) {
            cout << routes[i].destinations[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    loadStudentDataFromFile();
    menu();
    return 0;
}

