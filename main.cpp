/*
 * main.cpp
 *
 *  Created on: 05-Feb-2015
 *      Author: Chayan
 */
#include<iostream>
#include <string>
#include <list>
#include<stdio.h>
#include<sstream>
#include <fstream>
#include "student_info.cpp"
#include "subject_info.cpp"

using namespace std;
ofstream myfile;
char file_1[1024];
char file_2[1024];
ifstream file;
list<string> mylist;
int count;
int choice;
string prefix_student = "./student/";
string prefix_TA = "./TA/";
string index_subject = "./subject/index.txt";
string prefix_subject = "./subject/";
string suffix = ".txt";
stringstream stream_string;

void Enter_marks(string sub_name)
{
	start_func:
	string line,e_no,marks,temp;
	mylist.clear();
	int counter = 0;
	file.open(prefix_subject+sub_name+suffix);
	while ( getline (file,line) )
		    {
		      cout<<line<<endl;
		      if(counter>3)
		    	  mylist.push_back(line);
		      else
		    	  counter++;
		    }
	cout<<"Input the entry number of student : ";
	getline(cin,line);
	while (!mylist.empty())
	{
		stream_string.str("");
		stream_string<<mylist.front();
		stream_string>>e_no;
		if(e_no.compare(line)==0)
		{
			counter = -1;
		}
	}
	if(counter>0)
	{
		cout<<"Student not registered !!!!";
		goto start_func;
	}
	cout<<"Enter the marks : ";
	getline(cin,marks);
	file.open(prefix_subject+sub_name+suffix);
	myfile.open("temp.txt");
	while ( getline (file,temp) )
	{
		stream_string.str("");
		stream_string<<temp;
		stream_string>>e_no;
		if((e_no).compare(line)==0)
			myfile<<temp<<" "<<marks<<endl;
		else
			myfile<<temp;
	}
	file.close();
	myfile.close();
	strcpy(file_1, (prefix_subject+sub_name+suffix).c_str());
	remove(file_1);
	rename("temp.txt",file_1);


}


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
	cout<<"Enter the course number to be registered : ";
	getline (cin,line);
	myfile.open(prefix_subject+line+suffix,ios::app);
	myfile<<in_1;
	myfile.close();
	myfile.open(prefix_student+in_1+suffix,ios::app);
	myfile<<line;
	myfile.close();

}


void TA_login()
{
		string in_1,in_2,line;
		int counter;
		start_func:
		cout<<"Enter the entry number : ";
		getline (cin, in_1);
		cout<<"Enter your password : ";
		getline (cin, in_2);
		file.open(prefix_TA+in_1+suffix);
		if(!file)
		{
			file.close();
			cout<<"Wrong Entry number/password"<<endl;
			goto start_func;
		}
		else
		{
			counter = 0;
			while(counter<2)
			{
				counter++;
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
				file.open(prefix_TA+in_1+suffix);
				counter = 0;
				while(counter<2)
				{
					counter++;
					getline (file,line);
					mylist.push_back(line);
				}
				getline (file,line);
				cout<<"---------------- Personal Information --------------------"<<endl;
				cout<<"Entry Number : "<<mylist.front()<<endl;
				mylist.pop_front();
				cout<<"Name : "<<mylist.front()<<endl;
				mylist.pop_front();
				cout<<"----------------------------------------------------------"<<endl;
				cout<<"-------------------- Subjects registered as TA --------------------"<<endl;
				mylist.clear();
				while ( getline (file,line) )
				{
					      cout<<line<<endl;
					      mylist.push_back(line);
				}
				file.close();
				cout<<"---------------------- TA Menu --------------------------------"<<endl;
				cout<<"1. Enter the marks "<<endl;
				cout<<"2. Grade the Subjects "<<endl;
				cout<<"3. Return to main menu "<<endl;
				cout<<"Enter your choice : ";
				cin>>choice;
				cin.ignore();
				switch(choice)
				{
					case 1 :{	cout<<"Enter the subject : ";
								getline (cin,line);
								Enter_marks(line);
								break;
							}
					case 2 :{	//withdraw_course(in_1);
								break;
							}
					case 3 : break;
					default :	{	cout<<"Invalid choice !!!\n";
									//system("clear");
									//goto stlogin_menu;
								}

				}

			}
		}
}



void withdraw_course(string in_1)
{
	string line;
	file.open(prefix_student+in_1+suffix);
	//count = 0;
	//while(count<7)
		//-----------
}

void student_login()
{
	string in_1,in_2,line;
	int counter;
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
		counter = 0;
		while(counter<5)
		{
			counter++;
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
				case 2 :{	withdraw_course(in_1);
								break;
						}
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
		myfile<<in<<" credits"<<endl;
		myfile<<"Students Registered : "<<endl;
		myfile.close();
		myfile.open(index_subject,ios::app);
		myfile<<id<<endl;
		myfile.close();
	}
	else
	{
		file.close();
		cout<<"subject already registered"<<endl;
	}

}

void new_TA_entry()
{
	string in;

	cout<<"Enter the entry number : ";
	getline (cin, in);
	file.open(prefix_TA+in+suffix);
	if(!file)
	{
		file.close();
		myfile.open(prefix_student+in+suffix);
		myfile<<in<<endl;
		cout<<"Enter the name : ";
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


int main()
{
	start :
	cout<<"--------------------- MENU -----------------\n";
	cout<<"1. Student Login \n";
	cout<<"2. TA Login \n";
	cout<<"3. Register as new student\n";
	cout<<"4. Register the new subject\n";
	cout<<"5. Register the new TA\n";
	cout<<"6. Quit\n";
	cout<<"Enter your choice : ";
	cin>>choice;
	cin.ignore();
	switch(choice)
	{
		case 1: {
					student_login();
					goto start;
				}
		case 2: {
					TA_login();
					goto start;
				}
		case 3: {
					new_student_entry();
					goto start;
				}
		case 4: {
					new_subject_entry();
					goto start;
				}
		case 5: {
					new_TA_entry();
					goto start;
				}
		case 6: break;
		default :	{ cout<<"Invalid choice !!!\n";
					//system("clear");
						goto start; }
	}

	return 0;
}


