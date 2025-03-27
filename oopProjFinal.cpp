#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <conio.h>
using namespace std;

// user interface class
class UserInterface
{
	public:
    	void displayMainMenu() 
		{
        	cout<<"Choose an option:"<<endl
        		<<"1. Student Panel (Press 1)"<<endl
        		<<"2. Admin Panel (PRESS 2)"<<endl
        		<<"3. Exit (PRESS 3)"<<endl;
    	}

    	void displayStudentPanel() 
		{
			cout<<"Please select a function to perform :"<<endl<<"\n"
             	<<"1. Search Student by registration number (Press 1) "<<endl
             	<<"2. Display Bus Routes (PRESS 2) "<<endl
             	<<"3. Display Registered Buses (PRESS 3) "<<endl
             	<<"4. To Sign Out (PRESS 4) "<<endl;
    	}

    	void displayAdminPanel() 
		{
            cout<<"Please select a function to perform :"<<endl<<"\n"
				<<"1. Register New Student (PRESS 1) "<<endl
        		<<"2. Search a Student (PRESS 2) "<<endl
             	<<"3. Update Record (PRESS 3) "<<endl
             	<<"4. Delete a Record (PRESS 4) "<<endl
             	<<"5. View Record (PRESS 5) "<<endl
             	<<"6. To Sign Out (PRESS 6) "<<endl;
    	}
    	
    	int mainMenuInputCheck()
    	{
    		int choice;
			string choiceStr;
			
			cout<<"\n"<<"Enter your choice : "<<endl;
			cin>>choiceStr;

        	stringstream ss(choiceStr);
        	if(!(ss >> choice) || !ss.eof() || choice < 1 || choice > 3) // check if the conversion failed or if there are extra characters
        	{
        	    cout<<"\nInvalid input. Please enter a correct integer choice. "<<endl
        	    	<<"************************************* "<<endl<<"\n"
					<<"\nPress any key to continue. ";
        	    return -1;
        	}
        	return choice;
		}
    	
		int studentInputCheck()
    	{
    		int studentChoice;
			string studentChoiceStr;
			
			cout << "\nEnter your choice: ";
    		cin >> studentChoiceStr;
			
			stringstream ss(studentChoiceStr);
			if(!(ss >> studentChoice) || !ss.eof() || studentChoice < 1 || studentChoice > 4)
        	{
           		cout<<"\nInvalid input. Please enter a correct integer choice. "<<endl
        	    	<<"************************************* "<<endl<<"\n"
					<<"\nPress any key to continue. ";
           		cin.clear();
           		return -1;
       		}
       		return studentChoice;
		}
		
		int adminInputCheck() 
		{
            int adminChoice;
            string adminChoiceStr;
            
            cout<<"\nEnter your choice: ";
            cin>>adminChoiceStr;
            
            stringstream ss(adminChoiceStr);
            if (!(ss >> adminChoice) || !ss.eof() || adminChoice < 1 || adminChoice > 6) 
			{
                cout<<"\nInvalid input. Please enter a correct integer choice. "<<endl
        	    	<<"************************************* "<<endl<<"\n"
					<<"\nPress any key to continue. ";
                cin.clear();
                return -1;
            }
            return adminChoice;
        }
};

class Bus
{
	public:
		void displayBuses()
		{
			const int MAX_BUSES = 6;
			string registeredBuses[MAX_BUSES] = {"RIA-1397", "RIA-1398", "RIA-460", "RIA-419", "RIB-395", "RIA-2035"};
			
			ofstream File("Buses.txt");
    		if(!File)
    		{
    			cout<<"Error! FIle not opening. "<<endl;
    			return;
			}
    		
			cout<<"Registered Buses: "<<endl;
    		for(int i = 0; i < MAX_BUSES; ++i) 
			{
        		File<<i + 1<<". "<<registeredBuses[i]<<endl
        			<<"******************************************** "<<endl<<"\n";
				cout<<i + 1<<". "<<registeredBuses[i]<<endl
        			<<"******************************************** "<<endl<<"\n";
			}
			File.close();		
		}
};

class Route
{
	public:
		void displayRoutes()
		{
			cout<<"Bus Name: RIA-1397"<<endl
				<<"Route 1: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Rawal chowk "<<"					"<<"6:55"<<endl
				<<"2. Highway "<<"					"<<"7:03"<<endl
				<<"3. Iqbal town "<<"					"<<"7:06"<<endl
				<<"4. Zia masjid "<<"					"<<"7:07"<<endl
				<<"5. Chaklala station "<<"				"<<"7:20"<<endl
				<<"6. Sadder "<<"					"<<"7:30"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			cout<<"Bus Name: RIA-1398"<<endl
				<<"Route 2: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Faizabad "<<"					"<<"6:55"<<endl
				<<"2. 6th road "<<"					"<<"7:03"<<endl
				<<"3. Sadiqabad "<<"					"<<"7:06"<<endl
				<<"4. Chandni chowk "<<"				"<<"7:07"<<endl
				<<"5. Sadder "<<"					"<<"7:20"<<endl
				<<"6. Depu stop "<<"					"<<"7:40"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			cout<<"Bus Name: RIA-460"<<endl
				<<"Route 3: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Abbpara stop "<<"				"<<"6:55"<<endl
				<<"2. Melody stop "<<"					"<<"7:03"<<endl
				<<"3. G-7 "<<"						"<<"7:06"<<endl
				<<"4. G-8 "<<"						"<<"7:07"<<endl
				<<"5. G-9 "<<"						"<<"7:20"<<endl
				<<"6. G-11 "<<"					"<<"7:30"<<endl
				<<"7. B-17 "<<"					"<<"7:55"<<endl
				<<"8. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			cout<<"Bus Name: RIA-419"<<endl
				<<"Route 4: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Khanna pull "<<"					"<<"6:55"<<endl
				<<"2. Gangal stop "<<"					"<<"7:03"<<endl
				<<"3. Gulzar e Quaid "<<"				"<<"7:06"<<endl
				<<"4. Old Airport PSO pump"<<"				"<<"7:10"<<endl
				<<"5. Chorr chowk "<<"					"<<"7:30"<<endl
				<<"6. Kohinoor Mills "<<"				"<<"7:40"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			cout<<"Bus Name: RIB-395"<<endl
				<<"Route 5: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. I-8 "<<"						"<<"6:55"<<endl
				<<"2. Double road signal "<<"				"<<"7:03"<<endl
				<<"3. Katariyan "<<"					"<<"7:06"<<endl
				<<"4. CDA "<<"						"<<"7:20"<<endl
				<<"5. Mandimor "<<"					"<<"7:25"<<endl
				<<"6. G-11 signal "<<"					"<<"7:40"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			cout<<"Bus Name: RIA-2035"<<endl
				<<"Route 6: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Kacheri "<<"					"<<"6:55"<<endl
				<<"2. Shell pump "<<"					"<<"7:03"<<endl
				<<"3. 3 Miles "<<"					"<<"7:06"<<endl
				<<"4. Karf colony "<<"					"<<"7:20"<<endl
				<<"5. Qutba mor "<<"					"<<"7:25"<<endl
				<<"6. Lawrence Pur "<<"				"<<"7:40"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";	
			
			ofstream File("Routes.txt");
    		if(!File)
    		{
    			cout<<"Error! FIle not opening. "<<endl;
    			return;
			}
			
			File<<"Bus Name: RIA-1397"<<endl
				<<"Route 1: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Rawal chowk "<<"					"<<"6:55"<<endl
				<<"2. Highway "<<"					"<<"7:03"<<endl
				<<"3. Iqbal town "<<"					"<<"7:06"<<endl
				<<"4. Zia masjid "<<"					"<<"7:07"<<endl
				<<"5. Chaklala station "<<"				"<<"7:20"<<endl
				<<"6. Sadder "<<"					"<<"7:30"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			File<<"Bus Name: RIA-1398"<<endl
				<<"Route 2: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Faizabad "<<"					"<<"6:55"<<endl
				<<"2. 6th road "<<"					"<<"7:03"<<endl
				<<"3. Sadiqabad "<<"					"<<"7:06"<<endl
				<<"4. Chandni chowk "<<"				"<<"7:07"<<endl
				<<"5. Sadder "<<"					"<<"7:20"<<endl
				<<"6. Depu stop "<<"					"<<"7:40"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			File<<"Bus Name: RIA-460"<<endl
				<<"Route 3: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Abbpara stop "<<"				"<<"6:55"<<endl
				<<"2. Melody stop "<<"					"<<"7:03"<<endl
				<<"3. G-7 "<<"						"<<"7:06"<<endl
				<<"4. G-8 "<<"						"<<"7:07"<<endl
				<<"5. G-9 "<<"						"<<"7:20"<<endl
				<<"6. G-11 "<<"					"<<"7:30"<<endl
				<<"7. B-17 "<<"					"<<"7:55"<<endl
				<<"8. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			File<<"Bus Name: RIA-419"<<endl
				<<"Route 4: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Khanna pull "<<"					"<<"6:55"<<endl
				<<"2. Gangal stop "<<"					"<<"7:03"<<endl
				<<"3. Gulzar e Quaid "<<"				"<<"7:06"<<endl
				<<"4. Old Airport PSO pump"<<"				"<<"7:10"<<endl
				<<"5. Chorr chowk "<<"					"<<"7:30"<<endl
				<<"6. Kohinoor Mills "<<"				"<<"7:40"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			File<<"Bus Name: RIB-395"<<endl
				<<"Route 5: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. I-8 "<<"						"<<"6:55"<<endl
				<<"2. Double road signal "<<"				"<<"7:03"<<endl
				<<"3. Katariyan "<<"					"<<"7:06"<<endl
				<<"4. CDA "<<"						"<<"7:20"<<endl
				<<"5. Mandimor "<<"					"<<"7:25"<<endl
				<<"6. G-11 signal "<<"					"<<"7:40"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
		
			File<<"Bus Name: RIA-2035"<<endl
				<<"Route 6: "<<endl<<"Destinations"<<"					"<<"Timings"<<endl
				<<"1. Kacheri "<<"					"<<"6:55"<<endl
				<<"2. Shell pump "<<"					"<<"7:03"<<endl
				<<"3. 3 Miles "<<"					"<<"7:06"<<endl
				<<"4. Karf colony "<<"					"<<"7:20"<<endl
				<<"5. Qutba mor "<<"					"<<"7:25"<<endl
				<<"6. Lawrence Pur "<<"				"<<"7:40"<<endl
				<<"7. Cui Wah Campus "<<"				"<<"8:20"<<endl
				<<"******************************************************** "<<endl<<"\n";
			File.close();
		}
};

class StudentData
{
	protected:
		string name;
		string regNo;
		string busNo;
	public:
		StudentData(const string& n, const string& r, const string& b) : name(n), regNo(r), busNo(b) {}

		
		const string& getName() const
		{
			return name; 
		}
		
		const string& getRegNo() const
		{
			return regNo;
		}
		
		const string getBusNo() const
		{
			return busNo;
		}
		
		const virtual void setName(const string& newName) = 0;
		const virtual void setBusNo(const string& newBusNo) = 0;
		
		const virtual void signOut(int)
		{
			cout<<"Signed out of Student Panel. "<<endl
        		<<"************************************ "<<endl<<"\n";
		}
};

class Student : public StudentData
{
	private:
		bool loggedIn;
	public:
		Student() : StudentData("null", "null", "null"), loggedIn(true) {}
		
		Student(const string& n, const string& r, const string& b) : StudentData(n, r, b) {}
		
		const virtual void setName(const string& newName)
		{
			name = newName;
		}
		const virtual void setBusNo(const string& newBusNo)
		{
			busNo = newBusNo;
		}
		
		const virtual void signOut(int) override
    	{	
        	loggedIn = false;
        	cout<<"Signed out of Student Panel. "<<endl
        		<<"************************************ "<<endl<<"\n";
    	}
};

class BusSystem
{
	private:
		vector<Student>& students;
		Bus bus;
		bool loggedIn;
		UserInterface ui;
    	Route route;
	public:
    	BusSystem(vector<Student>& studentsRef) : students(studentsRef), loggedIn(true) {}
    	
    	// Reading data from file
    	void loadStudentDataFromFile(const string& fileName) 
		{
        	ifstream file("Student.txt");
        	if(file.is_open()) 
			{
            	int studentCount;
            	file>>studentCount;

            	for(int i = 0; i < studentCount; ++i) 
				{
                	string name, regNo, busNo;
                	file>>name>>regNo>>busNo;
                	students.push_back(Student(name, regNo, busNo));
            	}
				file.close();
			}
			else 
			{
            	cout<<"Error opening file: "<<fileName<<endl;
        	}
    	}

    	// Writing data into file
    	void saveStudentDataToFile(const string& fileName) 
		{
        	ofstream file("Student.txt");
        	if(file.is_open()) 
			{
            	file<<students.size()<<"\n";

            	for(const auto& student : students) 
				{
                	file<<student.getName()<<" "<<student.getRegNo()<<" "<<student.getBusNo()<<"\n";
            	}

            	file.close();
        	}
			else 
			{
            	cout<<"Error opening file: "<<fileName<<endl;
        	}	
    	}
			
		void displayAdminPanel() 
		{
        	ui.displayAdminPanel();
    	}
		
		void displayStudentPanel()
		{
			ui.displayStudentPanel();
		}
		
    	void displayRoutes() 
		{
        	route.displayRoutes();
    	}
		
		void addStudent() 
		{
        	string name, regNo, busNo, season, department;
        	int rollN, seasonNo;
        	cout<<"Enter student name: ";
        	cin.ignore();
			getline(cin, name);
        	cout<<"Enter student registration number: "<<endl;
        	cout<<"Enter season (SP or FA): ";
			
        	while(true)
			{	
				cin>>season;
				if(season == "SP" || season == "FA")
        		{	
					break;
				}
				else
				{
					cout<<"\nInvalid input or small characters. Please give correct Season and write in capital characters. "<<endl
						<<"************************************* "<<"\n";
				}
			}
			
			cout<<"Enter Season number (18-23): ";
			string sNo;
			
			while(true)
			{
				cin>>sNo;
				stringstream ss(sNo);
				
				if(ss >> seasonNo && seasonNo > 18 && seasonNo <= 23 && ss.eof())
        		{	
					break;
				}
				
				else
				{
					cout<<"\nInvalid input. Please give correct Season number. "<<endl
						<<"************************************* "<<"\n";
				}
			}
			
        	cout<<"Enter Department (BCS/BBA/BEE/BCE/BME): ";
			
        	while(true)
			{
				cin>>department;
				if(department == "BCS" || department == "BBA" || department == "BEE" || department == "BCE" || department == "BME")
				{
					break;
				}
				
				else
				{
					cout<<"\nInvalid input or small characters. Please give correct Department and write in capital characters. "<<endl
						<<"************************************* "<<endl<<"\n";
				}
			}
			
        	cout<<"Enter Roll number (0-200): ";
        	string input;
        	
			while(true)
			{
				cin>>input;
				stringstream ss(input);

				if(ss >> rollN && rollN > 0 && rollN < 200 && ss.eof())
				{
					break;
				}
				
				else
				{
					cout<<"\nInvalid input. Please give correct roll number. "<<endl
						<<"************************************* "<<endl<<"\n";
				}
        	}
			
			regNo = season + to_string(seasonNo) + "-" + department + "-" + to_string(rollN);
			
        	cout<<"\n";
			bus.displayBuses();
			cout<<"Enter student bus number (ABC-123): ";
        	
        	while(true)
        	{
        		cin>>busNo;
				if(busNo == "RIA-1397" || busNo == "RIA-1398" || busNo == "RIA-460" || busNo == "RIA-419" || busNo == "RIB-395" || busNo == "RIA-2035")
				{	
					break;
				}
				
				else
				{
					cout<<"\nInvalid input . Please give correct Bus number. "<<endl
						<<"************************************* "<<"\n";
				}
			}
			
       		// Create a new Student object and add it to the students vector
       		Student student(name, regNo, busNo);
       		students.push_back(student);

       		cout<<"\nStudent added successfully. "<<endl
       			<<"************************************* "<<endl<<"\n";
   		}
 
   		void searchStudentByRegNo(const string& regNo) 
       	{
           	bool found = false;
           	for(const auto& student : students) 
           	{
               	if(student.getRegNo() == regNo) 
               	{
                   	cout<<"\nStudent found: "<<endl
                   		<<"Name: "<<student.getName()<<endl
                   		<<"Registration Number: "<<student.getRegNo()<<endl
                   		<<"Bus Number: "<<student.getBusNo()<<endl
                   		<<"************************************* "<<endl<<"\n";
                   	found = true;
                   	break;
               	}
           	}
           	
           	if(!found) 
           	{
               	cout<<"\n"<<"Student with registration number "<<regNo<<" not found. "<<endl
               		<<"*********************************************** "<<endl<<"\n";
       		}
       	}
       	
       	void updateRecord(const string& regNo) 
		{
			bool found = false;
			for(auto& student : students) 
			{
				if(student.getRegNo() == regNo)
				{
					cout<<"\nStudent found: "<<endl
                   		<<"Name: "<<student.getName()<<endl
                   		<<"Registration Number: "<<student.getRegNo()<<endl
                   		<<"Bus Number: "<<student.getBusNo()<<endl
                   		<<"************************************* "<<endl<<"\n";
                   		
					cout<<"\nEnter updated student information: "<<endl;
					string newName, newBusNo;
					cout<<"Enter updated student name: ";
					cin.ignore(); // Ignore the newline character from previous input
					getline(cin, newName);
					cout<<"Enter updated student bus number: ";
					cin>>newBusNo;

					// Update student information
					student.setName(newName);
					student.setBusNo(newBusNo);

					cout<<"\nRecord updated successfully. "<<endl
						<<"*********************************************** "<<endl<<"\n";
					found = true;
					break;
				}
			}
			
			if(!found) 
			{
				cout<<"\nStudent with registration number "<<regNo<<" not found. "<<endl
					<<"*********************************************** "<<endl<<"\n";
			}
		}
       	
        void deleteRecord(const string& regNo) 
		{
			auto it = students.begin();
			while(it != students.end()) 
			{
				if(it->getRegNo() == regNo) 
				{
					it = students.erase(it);
					cout<<"\nRecord deleted successfully. "<<endl
						<<"*********************************************** "<<endl<<"\n";	
					return;
				}
				else 
				{
					++it;
				}
			}
			cout<<"\nStudent with registration number "<<regNo<<" not found. "<<endl
				<<"*********************************************** "<<endl<<"\n";
		}
		
		void viewRecords() 
		{
    		if(students.empty()) 
    		{
        		cout<<"No student records found."<<endl
        			<<"*********************************************** "<<endl<<"\n";
        		return;
    		}

    		cout<<"Student Records: "<<endl;
    		for(const auto& student : students) 
    		{
        		cout<<"Name: "<<student.getName()<<endl
        			<<"Registration Number: "<<student.getRegNo()<<endl
        			<<"Bus Number: "<<student.getBusNo()<<endl
        			<<"*********************************************** "<<endl<<"\n";
    		}
		}

		void signOut(string) 
    	{	
        	loggedIn = false; // Reset the login status
        	cout<<"Signed out of Admin Panel. "<<endl
        		<<"*********************************************** "<<endl<<"\n";
    	}
};

int main()
{
	
	//vector to hold student data
    vector<Student> students;
    
    //creating objects
	BusSystem busSystem(students);
    Route route;
	UserInterface ui;
	Student student;
	Bus bus;

	busSystem.loadStudentDataFromFile("students.txt");
	
	//logical sequence
	int choice;
	while(choice != 3)
	{
		ui.displayMainMenu();
		
		int choice = ui.mainMenuInputCheck();
		
		if(choice == -1) 
		{
			getch();
    	    system("cls");
			continue;
		}
		
		else if(choice == 1)
		{
			system("cls");
			cout<<"YOU ENTERED STUDENT PANEL SUCCESSFULLY! "<<endl
				<<"************************************* "<<endl
				<<"\n";
				
			while(true) 
			{
				ui.displayStudentPanel();
			
				int studentChoice = ui.studentInputCheck();
        		
				if(studentChoice == -1) 
				{
					getch();
					system("cls");
            		continue;
        		}
						
				else if(studentChoice == 1)
				{
					system("cls");
					string reg;
					cout<<"Enter the registration number of the student you want to search: ";
					cin>>reg;
					busSystem.searchStudentByRegNo(reg);
					cout<<"\n";
				}
				
				else if(studentChoice == 2)
				{
    				system("cls");
					route.displayRoutes();
					cout<<"\n";
				}
				
				else if(studentChoice == 3)
				{
					system("cls");
					bus.displayBuses();
					cout<<"\n";
				}
				
				else if(studentChoice == 4)
				{
					system("cls");
					student.signOut(1);
					break;
				}
				
				else
				{
					system("cls");
					cout<<"Invalid choice! "<<endl;
					cout<<"\n";
				}
			}
		}
		
		else if(choice == 2)
		{
			system("cls");
			string username, password;
    		cout<<"Enter username: ";
    		cin>>username;
    		cout<<"Enter password: ";
    		cin>>password;
		
			if(username == "admin" && password == "comsats") 
			{
        		cout<<"\nLogin successful!"<<endl
        			<<"************************************* "<<endl
        			<<"\n";
        			
				while(true)
				{
					ui.displayAdminPanel();
					
					int adminChoice = ui.adminInputCheck();
        		
					if(adminChoice == -1) 
					{
            			getch();
            			system("cls");
						continue;
        			}
        			
					else if(adminChoice == 1)
					{
						system("cls");
						int studentCount, i;
						string countCheck;
						
						cout<<"Enter the number of students you want to add: ";
						cin>>countCheck;
						
						stringstream ss(countCheck);
						if(!(ss >> studentCount) || studentCount <= 0 || !ss.eof()) 
						{
        					cout<<"\nInvalid input. Please enter a correct input. "<<endl
        						<<"************************************* "<<endl<<"\n";
        					cin.clear();
        					continue;
        				}
        				
						while(i < studentCount)
						{
							busSystem.addStudent();
							++i;
						}
					}
					
					else if(adminChoice == 2)
					{
						system("cls");
						string regNoToFind;
    					cout<<"Enter registration number you want to find: ";
    					cin>>regNoToFind;
    					busSystem.searchStudentByRegNo(regNoToFind);
					}
					
					else if(adminChoice == 3)
					{
						system("cls");
						string update;
    					cout<<"Enter the Registration Number of the tudent you want to update: ";
    					cin>>update;
						busSystem.updateRecord(update);
					}
					
					else if(adminChoice == 4)
					{
						system("cls");
						string regNoToDelete;
						busSystem.viewRecords();
						
						cout<<"Enter the Registration Number you want to delete: ";
						cin>>regNoToDelete;
						busSystem.deleteRecord(regNoToDelete);
					}

					else if(adminChoice == 5)
					{
						system("cls");
						busSystem.viewRecords();					
					}
					
					else if(adminChoice == 6)
					{
						system("cls");
						busSystem.signOut("signOut");
						break;
					}
					
					else
					{
						system("cls");
						cout<<"Invalid Choice! "<<endl;
					}
				}
			}
			
			else if(username != "admin" || password != "comsats")
    		{
    			cout<<"\nIncorrect username or password combination. Please try again. "<<endl
    				<<"************************************* "<<endl
        			<<"\n";
        		cin.clear();
			}			
		}
		
		else if(choice == 3)
		{
			break;
		}
		
		else
		{
			cout<<"Invalid Input. please give correct input. ";
			return 1;
		}
	} 
			
	busSystem.saveStudentDataToFile("students.txt");
	cout<<"\n************************************* "<<endl
		<<"Exiting the system. "<<endl
		<<"************************************* "<<endl;
	return 0;
}