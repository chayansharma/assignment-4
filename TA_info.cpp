/*
 * TA_info.cpp
 *
 *  Created on: 08-Feb-2015
 *      Author: Chayan
 */

#include<iostream>
#include <string>
#include <list>
using namespace std;
//! TA info class
/*!
Class to store the information of a TA
*/
class TA_info
{
public:

	string Entry_No ; /*!< string variable to store entry number  */
	string Name; /*!< string variable to store the name */
	string password; /*!< string variable to store the profile password  */
	list<string> subjects; /*!< string list to store the subjects  */
};




