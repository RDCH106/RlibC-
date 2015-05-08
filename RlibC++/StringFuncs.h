#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

namespace RlibC_String
{
	class StringFuncs
	{
	public:
		StringFuncs(void);
		~StringFuncs(void);

		/**
		*	@author Ruben de Celis Hernandez
		*	@brief Split a string 	
		*   @version 1.0
		*	@since 28/07/2014
		*	@pre Given a string to split and a delimiter
		*	@post Split the string using the delimiter
		*	@param string_to_split String to split
		*	@param delimiter Delimiter to use in the split
		*	@return Return the splits in a string vector
		*	@note The delimiter can be one or more chars in a string
		*/
		static std::vector<std::string> split (std::string string_to_split, std::string delimiter);
		
		/**
		*	@author Ruben de Celis Hernandez
		*	@brief Search a char or word	
		*   @version 1.0
		*	@since 28/07/2014
		*	@pre Given a string and a char or wrod to search
		*	@post Find the number of occurrences in the string
		*	@param str1 String in which to search
		*	@param search The search chain to search
		*	@return Return the number of occurrences of the search
		*	@note The search can be a char or word
		*/
		static int isInCharString (std::string str1, std::string search);

		/**
		*	@author Ruben de Celis Hernandez
		*	@brief Save data in a file	
		*   @version 1.0
		*	@since 28/07/2014
		*	@pre Given a file name and the data
		*	@post Write the data in the file
		*	@param filename The filename or full path file
		*	@param data The data to write in the file
		*	@param append Overwrite or append the data in the file
		*	@return void
		*	@note -
		*/
		static void saveDATA(std::string filename, std::string data, bool append);

		/**
		*	@author Ruben de Celis Hernandez
		*	@brief Delete all the spaces in a string	
		*   @version 1.0
		*	@since 01/09/2014
		*	@pre Given a string
		*	@post Delete all the spaces
		*	@param str1 String to trim
		*	@return Return string without spaces
		*	@note -
		*/
		static std::string trim(std::string str1);

		/**
		*	@author Ruben de Celis Hernandez
		*	@brief Convert a text to uppercase
		*   @version 1.0
		*	@since 01/09/2014
		*	@pre Given a string
		*	@post Change all the lowercase letters to uppercase
		*	@param str1 String to uppercase
		*	@return Return uppercase string
		*	@note -
		*/
		static std::string toUpperCase(std::string str1);

		/**
		*	@author Ruben de Celis Hernandez
		*	@brief Convert a text to lowercase
		*   @version 1.0
		*	@since 01/09/2014
		*	@pre Given a string
		*	@post Change all the uppercase letters to lowercase
		*	@param str1 String to lowercase
		*	@return Return lowercase string
		*	@note -
		*/
		static std::string toLowerCase(std::string str1);
	};
}
