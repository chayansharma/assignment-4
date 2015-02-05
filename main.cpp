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

using namespace std;
int main()
{
	int choice;
	start :
	cout<<"--------------------- MENU -----------------\n";
	cout<<"1. Student Login \n";
	cout<<"2. TA Login \n";
	cout<<"3. Register the new student\n";
	cout<<"4. Register the new subject\n";
	cout<<"5. Quit\n";
	cout<<"Enter your choice";
	cin>>choice;
	switch(choice)
	{
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		default :	{ cout<<"Invalid choice !!!\n";
					//system("clear");
						goto start; }
	}

	return 0;
}


