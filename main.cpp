/*
 * main.cpp
 *
 *  Created on: 05-Feb-2015
 *      Author: Chayan
 */
#include<iostream>
#include <string>
#include <list>
#include "student_info.cpp"
#include "subject_info.cpp"
#include <fstream>

ofstream myfile;
ifstream file;
list<string> mylist;
int count;
int choice;
string prefix_student = "./student/";
string index_subject = "./subject/index.txt";
string prefix_subject = "./subject/";
string suffix = ".txt";
void register_course(string in_1)
{
	string line;
	cout<<"---------------------------------- Courses Offered -----------------"<<endl;
	file.open(index_subject);
	while ( getline (file,line) )
	    {
	      cout<<line<<endl;
	    }
	file.close();
	cout<<"Enter the course number to be registered : "<<endl;
	getline (cin,line);
	myfile.open(prefix_subject+line+suffix);
	myfile<<in_1;
	myfile.close();
	myfile.open(prefix_student+in_1+suffix);
	myfile<<line;
	myfile.close();

}

void student_login()
{
	string in_1,in_2,line;
	start_func:
	cout<<"Enter the entry number : ";
	getline (cin, in_1);
	cout<<"Enter your password : ";
	getline (cin, in_2);
	file.open(prefix_student+in_1+suffix);
	if(!file)
	{
		file.close();
		cout<<"Wrong Entry number/password"<<endl;
		goto start_func;
	}
	else
	{
		count = 0;
		while(count<5)
		{
			count++;
			getline (file,line);
			mylist.push_back(line);
		}
		getline (file,line);
		if(line.compare(in_2)!=0)
		{
			mylist.clear();
			file.close();
			cout<<"Wrong Entry number/password"<<endl;
			goto start_func;
		}
		else
		{
			file.close();
			cout<<"---------------- Personal Information --------------------"<<endl;
			cout<<"Entry Number : "<<mylist.front()<<endl;
			mylist.pop_front();
			cout<<"Name : "<<mylist.front()<<endl;
			mylist.pop_front();
			cout<<"Date of Birth : "<<mylist.front()<<endl;
			mylist.pop_front();
			cout<<"Department : "<<mylist.front()<<endl;
			mylist.pop_front();
			cout<<"Degree : "<<mylist.front()<<endl;
			mylist.pop_front();
			cout<<"------------------------------------------------------------"<<endl;
			//----------------------------------- marks
			stlogin_menu :
			cout<<"-----------------------  Student login Menu ------------------------"<<endl;
			cout<<"1. Register a new course "<<endl;
			cout<<"2. Withdraw a course "<<endl;
			cout<<"3. Quit"<<endl;
			cout<<"Enter your choice : ";
			cin>>choice;
			cin.ignore();
			switch(choice)
			{
				case 1 :{	register_course(in_1);
							break;
						}
				case 2 : break;
				case 3 : break;
				default : { cout<<"Invalid choice !!!\n";
							//system("clear");
							goto stlogin_menu; }

			}

		}

	}

}

void new_student_entry()
{
	string in;

	cout<<"Enter the entry number : ";
	getline (cin, in);
	file.open(prefix_student+in+suffix);
	if(!file)
	{
		file.close();
		myfile.open(prefix_student+in+suffix);
		myfile<<in<<endl;

		cout<<"Enter the name : ";
		getline (cin, in);
		myfile<<in<<endl;
		cout<<"Enter the Date Of Birth : ";
		getline (cin, in);
		myfile<<in<<endl;
		cout<<"Enter your department : ";
		getline (cin, in);
		myfile<<in<<endl;
		cout<<"Enter your degree programme : " ;
		getline (cin, in);
		myfile<<in<<endl;
		cout<<"Enter your account password : ";
		getline (cin, in);
		myfile<<in<<endl;
		myfile<<"Subjects Registered"<<endl;
		myfile.close();
	}
	else
	{
		file.close();
		cout<<"Entry number already exist"<<endl;
	}

}

void new_subject_entry()
{
	string in,id;

	cout<<"Enter the subject id : ";
	getline (cin, id);
	file.open(prefix_subject+id+suffix);
	if(!file)
	{
		file.close();
		myfile.open(prefix_subject+id+suffix);
		myfile<<id<<endl;
		cout<<"Enter the name of subject : ";
		getline (cin, in);
		myfile<<in<<endl;
		cout<<"Enter the no. of credits : ";
		getline (cin, in);
		myfile<<in<<endl;
		myfile.close();
		myfile.open(index_subject);
		myfile<<id<<endl;
		myfile.close();
	}
	else
	{
		file.close();
		cout<<"subject already registered"<<endl;
	}

}

using namespace std;
int main()
{
	start :
	cout<<"--------------------- MENU -----------------\n";
	cout<<"1. Student Login \n";
	cout<<"2. TA Login \n";
	cout<<"3. Register as new student\n";
	cout<<"4. Register the new subject\n";
	cout<<"5. Quit\n";
	cout<<"Enter your choice : ";
	cin>>choice;
	cin.ignore();
	switch(choice)
	{
		case 1: {
					student_login();
					break;
				}
		case 2: break;
		case 3: {
					new_student_entry();
					break;
				}
		case 4: {
					new_subject_entry();
					break;
				}
		case 5: break;
		default :	{ cout<<"Invalid choice !!!\n";
					//system("clear");
						goto start; }
	}

	return 0;
}


