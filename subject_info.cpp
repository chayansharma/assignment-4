/*
 * subject_info.cpp
 *
 *  Created on: 05-Feb-2015
 *      Author: Chayan
 */
#include<iostream>
#include <string>
#include <list>
using namespace std;
//! Subject info class
/*!
Class to store the information of a subject
*/
class subject_info
{
public:
	string subject_id;	/*!< string variable to store the subject id  */
	string subject_name;	/*!< string variable to store the subject name  */
	string credits; /*!< string variable to store the number of credits  */
	list<string> students;	/*!< string list to store the entry numbers of students registered  */

};



