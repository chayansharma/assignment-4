/*
 * student_info.cpp
 *
 *  Created on: 04-Feb-2015
 *      Author: Chayan
 */
#include<iostream>
#include <string>
#include <list>

using namespace std;
//!Student info class
/*!
Class to store the information of a student
*/
class student_info
{
public:
	string Entry_No ; /*!< string variable to store entry number  */
	string Name; /*!< string variable to store the name  */
	string DOB; /*!< string variable to store the date of birth  */
	string Department; /*!< string variable to store the department  */
	string Degree; /*!< string variable to store the degree  */
	string password; /*!< string variable to store the profile password  */
	list<string> subjects; /*!< string list to store subjects  */
};



