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
#include "TA_info.cpp"

using namespace std;


bool flag = true;
student_info obj_student;
TA_info obj_TA;
subject_info obj_subject;
ifstream file;
ofstream myfile;
ofstream myfile_2;
list<string> mylist;
list<string> mylist_2;
int count;
int choice;
string prefix_student = "./student/";
string prefix_TA = "./TA/";
string index_subject = "./subject/index.txt";
string index_student = "./student/index.txt";
string prefix_subject = "./subject/";
string suffix = ".txt";
stringstream stream_string;
list<string>::iterator iter;
/** Function to write the contents in the object of subject_info class into the corresponding text file
    @param sub_name first parameter
*/
void update_subject_info(string sub_name)
{
	int counter = 0;
	myfile.open(prefix_subject+sub_name+suffix);
	myfile<<obj_subject.subject_id<<endl;
	myfile<<obj_subject.subject_name<<endl;
	myfile<<obj_subject.credits<<endl;
	myfile<<"Students Registered : "<<endl;
	for(iter = obj_subject.students.begin(); iter != obj_subject.students.end(); iter++)
		{
									if((counter+1) == obj_subject.students.size())
										myfile<<*iter;
									else
										myfile<<*iter<<endl;
									counter++;
		}
		myfile.close();
}

void grade_the_subject()
{
	string line,e_no,marks,inp_entry,sub_name,temp,grade;
	mylist.clear();
	int counter = 0;
	int ind_marks;
	cout<<"Enter the subject code : ";
	getline(cin,sub_name);
	file.open(prefix_subject+sub_name+suffix);
	getline(file,line);
	obj_subject.subject_id  =line;
	getline(file,line);
	obj_subject.subject_name  = line;
	getline(file,line);
	obj_subject.credits  = line;
	getline(file,line);
	obj_subject.students.clear();
	while ( getline (file,line) )
		{
			obj_subject.students.push_back(line);
		}
	file.close();
	initial:
	//system("clear");
	cout<<"--------------------------  Students registered -------------------"<<endl;
	for(iter = obj_subject.students.begin(); iter != obj_subject.students.end(); ++iter)
		cout<<*iter<<endl;
	cout<<"Input the entry number of student : ";
	getline(cin,inp_entry);
	flag = true;
	for(iter = obj_subject.students.begin(); iter != obj_subject.students.end(); ++iter)
	{
		stream_string.str(string() );
		stream_string.clear();
		stream_string<<*iter;
		stream_string>>e_no;
		if(e_no.compare(inp_entry)==0)
		{
			ind_marks = 0;
			flag = false;
			stream_string.str(string() );
			stream_string.clear();
			stream_string<<*iter;
			getline(stream_string,marks,' ');
			while(getline(stream_string,marks,' '))
			{
				ind_marks = ind_marks +  atoi(marks.c_str());
			}
			*iter = *iter + "total marks : " + to_string(ind_marks);
			cout<<" Total marks : "<<ind_marks<<endl;
			cout<<"Enter the grade of the student : ";
			getline (cin,grade);
			*iter = *iter + " Grade : " + grade;
		}
	}
	if(flag)
	{
		cout<<"Entry Number doesn't exist ... "<<endl;
		goto initial;
	}

	counter = 0;
	file.open(prefix_student+inp_entry+suffix);
		while ( getline (file,line) )
		{
			temp = line;
			stream_string.str(string() );
			stream_string.clear();
			stream_string<<line;
			stream_string>>line;
			if(sub_name.compare(line)!=0)
				mylist.push_back(temp);
			else
				mylist.push_back(temp+" Total marks : " + to_string(ind_marks)+ " Grade : " + grade);
		}
		file.close();

		myfile.open(prefix_student+inp_entry+suffix);

		for(iter = mylist.begin(); iter != mylist.end(); ++iter)
		{
			if(counter+1 == mylist.size())
				myfile<<*iter;
			else
				myfile<<*iter<<endl;
			counter++;
		}
		myfile.close();
		mylist.clear();
		flag = true;
		while(flag)
		{
			cout<<"If you want continue press Y or N : ";
			getline(cin,line);
			if(line.compare("Y")==0)
			{	flag = false;
				goto initial;
			}
			else if(line.compare("N")==0)
			{
				flag = false;
				update_subject_info(sub_name);
			}
			else
				cout<<"Invalid choice .."<<endl;
		}
}

/**Function which allows the TA to enter the marks
 *
 */
void Enter_marks()
{

	string line,e_no,marks,inp_entry,sub_name,temp;
	mylist.clear();
	int counter = 0;
	cout<<"Enter the subject code : ";
	getline(cin,sub_name);
	file.open(prefix_subject+sub_name+suffix);
	getline(file,line);
	obj_subject.subject_id  =line;
	getline(file,line);
	obj_subject.subject_name  = line;
	getline(file,line);
	obj_subject.credits  = line;
	getline(file,line);
	obj_subject.students.clear();
	while ( getline (file,line) )
		{
			obj_subject.students.push_back(line);
		}
	file.close();
	initial:
	//system("clear");
	cout<<"--------------------------  Students registered -------------------"<<endl;
	for(iter = obj_subject.students.begin(); iter != obj_subject.students.end(); ++iter)
		cout<<*iter<<endl;
	cout<<"Input the entry number of student : ";
	getline(cin,inp_entry);
	cout<<"Enter the marks : ";
	getline(cin,marks);
	flag = true;
	for(iter = obj_subject.students.begin(); iter != obj_subject.students.end(); ++iter)
	{
		stream_string.str(string() );
		stream_string.clear();
		stream_string<<*iter;
		stream_string>>e_no;
		if(e_no.compare(inp_entry)==0)
		{
			flag = false;
			*iter = *iter + " " + marks;
		}
	}
	if(flag)
	{
		cout<<"Entry Number doesnt exist ... "<<endl;
		goto initial;
	}

	counter = 0;
	file.open(prefix_student+inp_entry+suffix);
		while ( getline (file,line) )
		{
			temp = line;
			stream_string.str(string() );
			stream_string.clear();
			stream_string<<line;
			stream_string>>line;
			if(sub_name.compare(line)!=0)
				mylist.push_back(temp);
			else
				mylist.push_back(temp+" "+marks);
		}
		file.close();

		myfile.open(prefix_student+inp_entry+suffix);

		for(iter = mylist.begin(); iter != mylist.end(); ++iter)
		{
			if(counter+1 == mylist.size())
				myfile<<*iter;
			else
				myfile<<*iter<<endl;
			counter++;
		}
		myfile.close();
		mylist.clear();
		flag = true;
		while(flag)
		{
			cout<<"If you want continue press Y or N : ";
			getline(cin,line);
			if(line.compare("Y")==0)
			{	flag = false;
				goto initial;
			}
			else if(line.compare("N")==0)
			{
				flag = false;
				update_subject_info(sub_name);
			}
			else
				cout<<"Invalid choice .."<<endl;
		}
}
/**Function to register a subject for a TA
 *
 */
void register_subject_TA()
{
	string line,subject_1;
		flag = true;
		//system("clear");
		cout<<"---------------------------------- Courses Offered -----------------"<<endl;
		file.open(index_subject);
		while ( getline (file,line) )
		    {
				flag = true;
			for(iter = obj_TA.subjects.begin(); iter != obj_TA.subjects.end(); ++iter)
				{		subject_1 = *iter;
						stream_string.str(string() );
						stream_string.clear();
						stream_string<<subject_1;
						stream_string>>subject_1;
						if(line.compare(subject_1)==0)
							flag = false;
				}
			  if (flag)
		      cout<<line<<endl;
		    }
		file.close();
		cout<<"Enter the course number to be registered : ";
		getline (cin,line);
		obj_TA.subjects.push_back(line);
		int counter = 0;
			myfile.open(prefix_TA+obj_TA.Entry_No+suffix);
			myfile<<obj_TA.Entry_No<<endl;
			myfile<<obj_TA.Name<<endl;
			myfile<<obj_TA.password<<endl;
			myfile<<"Subjects registered : "<<endl;
			for(iter = obj_TA.subjects.begin(); iter != obj_TA.subjects.end(); iter++)
			{
										if((counter+1) == obj_TA.subjects.size())
											myfile<<*iter;
										else
											myfile<<*iter<<endl;
										counter++;
			}
			myfile.close();
}
/**
 * Function to create TA login menu
 */
void TA_login()
{
		string in_1,in_2,line;
		int counter;
		start_TA_login_func:
		cout<<"------------------------------- T.A. Login ---------------------------------- "<<endl;
		//system("clear");
		cout<<"Enter the entry number : ";
		getline (cin, in_1);
		cout<<"Enter your password : ";
		getline (cin, in_2);
		file.open(prefix_TA+in_1+suffix);
		if(!file)
		{
			file.close();
			cout<<"Wrong Entry number/password"<<endl;
			goto start_TA_login_func;
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
				goto start_TA_login_func;
			}
			else
			{
				file.close();
				file.open(prefix_TA+in_1+suffix);

				getline (file,line);
				obj_TA.Entry_No = line;
				getline (file,line);
				obj_TA.Name = line;
				getline (file,line);
				obj_TA.password = line;
				getline (file,line);
				obj_TA.subjects.clear();
				while ( getline (file,line) )
				{
					obj_TA.subjects.push_back(line);
				}
				file.close();
				TA_login:
				//system("clear");
				cout<<"---------------- Personal Information --------------------"<<endl;
				cout<<"Entry Number : "<<obj_TA.Entry_No<<endl;
				cout<<"Name : "<<obj_TA.Name<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				cout<<"-------------------- Subjects registered as TA --------------------"<<endl;
				for(iter = obj_TA.subjects.begin(); iter != obj_TA.subjects.end(); ++iter)
					cout<<*iter<<endl;
				cout<<"---------------------- TA Menu --------------------------------"<<endl;
				cout<<"1. Register the subject for TA duties"<<endl;
				cout<<"2. Enter the marks "<<endl;
				cout<<"3. Grade the Subjects "<<endl;
				cout<<"4. Return to main menu "<<endl;
				cout<<"Enter your choice : ";
				cin>>choice;
				cin.ignore();
				switch(choice)
				{
					case 1 :{
								register_subject_TA();
								goto TA_login;
								break;
							}
					case 2 :{
								Enter_marks();
								goto TA_login;
								break;
							}
					case 3 :{
								grade_the_subject();
								break;
							}
					case 4 : break;
					default :	{	cout<<"Invalid choice !!!\n";
									//system("clear");
									goto TA_login;
								}

				}

			}
		}
}
/**
 * Function which allows a student to withdraw the course
 */
void withdraw_course()
{
	string line,subject_1,subject_2;
	int counter = 0;
	//system("clear");
	flag = true;
	while(flag)
	{
	cout<<"---------------------- Subjects Registered ---------------------"<<endl;
	for(iter = obj_student.subjects.begin(); iter != obj_student.subjects.end(); ++iter)
									cout<<*iter<<endl;
	cout<<"Enter the subject id that you want to withdraw : ";
	getline(cin,line);
	subject_2 = line;
	mylist.clear();
	for(iter = obj_student.subjects.begin(); iter != obj_student.subjects.end(); ++iter)
	{
		subject_1 = *iter;
		stream_string.str(string() );
		stream_string.clear();
		stream_string<<subject_1;
		stream_string>>subject_1;
		if(line.compare(subject_1)!=0)
			mylist.push_back(*iter);
		if(line.compare(subject_1)==0)
			flag = false;
	}
	if (flag)
		cout<<"Invlaid subject name ..."<<endl;
	}
	obj_student.subjects.clear();
	for(iter = mylist.begin(); iter != mylist.end(); ++iter)
		obj_student.subjects.push_back(*iter);

	mylist.clear();
	counter = 0;
	file.open(prefix_subject+subject_2+suffix);
	while ( getline (file,line) )
	{
		subject_1 = line;
		stream_string.str(string() );
		stream_string.clear();
		stream_string<<subject_1;
		stream_string>>subject_1;
		if(subject_1.compare(obj_student.Entry_No)!=0)
			mylist.push_back(line);
	}
	file.close();

	myfile.open(prefix_subject+subject_2+suffix);
	for(iter = mylist.begin(); iter != mylist.end(); ++iter)
	{	if(counter+1 == mylist.size())
			myfile<<*iter;
		else
			myfile<<*iter<<endl;
		counter++;
	}
	myfile.close();
	mylist.clear();
}
/**
 * Function which allows a student to register a course
 * @param in_1 Entry number of a student registering a course
 */
void register_course(string in_1)
{
	string line,subject_1;
	bool flag = true;
	cout<<"---------------------------------- Courses Offered -----------------"<<endl;
	file.open(index_subject);
	while ( getline (file,line) )
	    {
			flag = true;
		for(iter = obj_student.subjects.begin(); iter != obj_student.subjects.end(); ++iter)
			{		subject_1 = *iter;
					stream_string.str(string() );
					stream_string.clear();
					stream_string<<subject_1;
					stream_string>>subject_1;
					if(line.compare(subject_1)==0)
						flag = false;
			}
		  if (flag)
	      cout<<line<<endl;
	    }
	file.close();
	cout<<"Enter the course number to be registered : ";
	getline (cin,line);
	myfile.open(prefix_subject+line+suffix,ios::app);
	myfile<<endl;
	myfile<<in_1;
	myfile.close();
	obj_student.subjects.push_back(line);

}
/**
 * Function to write the contents in the object of student_info class into the corresponding text file
 * @param in_1 Entry number of a student
 */
void write_info(string in_1)
{
	int counter = 0;
	myfile.open(prefix_student+in_1+suffix);
	myfile<<obj_student.Entry_No<<endl;
	myfile<<obj_student.Name<<endl;
	myfile<<obj_student.DOB<<endl;
	myfile<<obj_student.Department<<endl;
	myfile<<obj_student.Degree<<endl;
	myfile<<obj_student.password<<endl;
	myfile<<"Subjects registered : "<<endl;
	for(iter = obj_student.subjects.begin(); iter != obj_student.subjects.end(); iter++)
	{
								if((counter+1) == obj_student.subjects.size())
									myfile<<*iter;
								else
									myfile<<*iter<<endl;
								counter++;
	}
	myfile.close();

}
/**
 * Function to create a student login menu
 */
void student_login()
{
	string in_1,in_2,line;
	int counter;
	start_func:
	//system("clear");
	cout<<"------------------------------- Student Login -----------------------"<<endl;
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
			obj_student.Entry_No = mylist.front();
			mylist.pop_front();
			obj_student.Name = mylist.front();
			mylist.pop_front();
			obj_student.DOB = mylist.front();
			mylist.pop_front();
			obj_student.Department = mylist.front();
			mylist.pop_front();
			obj_student.Degree = mylist.front();
			mylist.pop_front();
			obj_student.password = line;
			getline (file,line);
			obj_student.subjects.clear();
			while ( getline (file,line) )
			{
					obj_student.subjects.push_back(line);
			}
			file.close();
			stlogin_menu :
			//system("clear");
			cout<<"---------------- Personal Information --------------------"<<endl;
			cout<<"Entry Number : "<<obj_student.Entry_No<<endl;
			cout<<"Name : "<<obj_student.Name<<endl;
			cout<<"Date of Birth : "<<obj_student.DOB<<endl;
			cout<<"Department : "<<obj_student.Department<<endl;
			cout<<"Degree : "<<obj_student.Degree<<endl;
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"---------------------Subjects Registered -------------------"<<endl;
			for(iter = obj_student.subjects.begin(); iter != obj_student.subjects.end(); ++iter)
								cout<<*iter<<endl;

			cout<<"-----------------------  Student login Menu ------------------------"<<endl;
			cout<<"1. Register a new course "<<endl;
			cout<<"2. Withdraw a course "<<endl;
			cout<<"3. Return to main menu "<<endl;
			cout<<"Enter your choice : ";
			cin>>choice;
			cin.ignore();
			switch(choice)
			{
				case 1 :{	register_course(in_1);
							goto stlogin_menu;
							break;
						}
				case 2 :{	withdraw_course();
							goto stlogin_menu;
								break;
						}
				case 3 : break;
				default : { cout<<"Invalid choice !!!\n";
							////system("clear");
							goto stlogin_menu; }

			}

		}

	}
	write_info(in_1);
}
/**
 * Function to register a new student
 */
void new_student_entry()
{
	string in;
	//system("clear");
	cout<<"------------------------------ New Student Entry -------------------"<<endl;
	cout<<"Enter the entry number : ";
	getline (cin, in);
	file.open(prefix_student+in+suffix);
	if(!file)
	{
		file.close();
		myfile.open(prefix_student+in+suffix);
		myfile_2.open(index_student,ios::app);
		myfile<<in<<endl;
		myfile_2<<in;
		cout<<"Enter the name : ";
		getline (cin, in);
		myfile<<in<<endl;
		myfile_2<<","<<in;
		cout<<"Enter the Date Of Birth (dd/mm/yy): ";
		getline (cin, in);
		myfile<<in<<endl;
		myfile_2<<","<<in;
		cout<<"Enter your department : ";
		getline (cin, in);
		myfile<<in<<endl;
		myfile_2<<","<<in;
		cout<<"Enter your degree programme : " ;
		getline (cin, in);
		myfile<<in<<endl;
		myfile_2<<","<<in<<endl;
		cout<<"Enter your account password : ";
		getline (cin, in);
		myfile<<in<<endl;
		myfile<<"Subjects Registered"<<endl;
		myfile.close();
		myfile_2.close();
	}
	else
	{
		file.close();
		cout<<"Entry number already exist"<<endl;
	}

}
/**
 * Function to register a new subject
 */
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
/**
 * Function to register a new TA
 */
void new_TA_entry()
{
	string in;

	cout<<"Enter the entry number : ";
	getline (cin, in);
	file.open(prefix_TA+in+suffix);
	if(!file)
	{
		file.close();
		myfile.open(prefix_TA+in+suffix);
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
/**
 * Function to search the records
 */
void search_records()
{
	string input,token;
	int count;
	cout<<"Enter the credentials to be searched (separated by comma) : ";
	getline(cin,input);
	stream_string<<input;
	while(getline(stream_string,token,','))
	{
		mylist.push_back(token);
	}

	file.open(index_student);
	while(getline(file,token))
	{
		count=0;
		for(iter = mylist.begin(); iter != mylist.end(); ++iter)
		if(token.find((*iter)) != std::string::npos)
		{
			count++;
		}
		if(count==mylist.size())
			cout<<token<<endl;
	}
	file.close();
}


int main()
{
	start :
	//system("clear");
	cout<<"--------------------- MENU -----------------\n";
	cout<<"1. Student Login \n";
	cout<<"2. TA Login \n";
	cout<<"3. Register as new student\n";
	cout<<"4. Register the new subject\n";
	cout<<"5. Register the new TA\n";
	cout<<"6. Search\n";
	cout<<"7. Quit\n";
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
		case 6: {
					search_records();
					goto start;
				}
		case 7: break;
		default :	{ cout<<"Invalid choice !!!\n";
					//system("clear");
						goto start; }
	}

	return 0;
}


