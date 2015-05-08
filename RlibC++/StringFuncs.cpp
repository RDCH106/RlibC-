#include "StringFuncs.h"

namespace RlibC_String
{
	StringFuncs::StringFuncs(void)
	{
	}


	StringFuncs::~StringFuncs(void)
	{
	}

	std::vector<std::string> StringFuncs::split (std::string string_to_split, std::string delimiter){
		std::vector<std::string> words;

		char s[100];
		char *word;
		std::string delim = delimiter;
		strcpy(s, string_to_split.c_str());
		word = strtok(s, delim.c_str());
		while (word != NULL){
			words.push_back(word);
			word = strtok (NULL, delim.c_str());
		}

		return words;
	}

	int StringFuncs::isInCharString (std::string str1, std::string search){
		const char *str1_c = str1.c_str();
		const char *search_c = search.c_str();
		int occurrences = 0;
		for (int i = 0; i < strlen(str1_c); ++i)
		{
			if (strncmp(&str1_c[i], search_c, strlen(search_c)) == 0)
				occurrences++;
		}

		return occurrences;
	}

	void StringFuncs::saveDATA(std::string filename, std::string data, bool append){
		std::ofstream out;
		if(append){
			out.open(filename, std::ofstream::app);
		}else{
			out.open(filename);
		}
		if(out.is_open()){
			out << data << std::endl;
		}else{
			throw std::exception("(ofstream) error while opening file.");
		}
		out.close();
	}

	std::string StringFuncs::trim(std::string str1){
		std::string str_trimmed;
		for (int i=0; i<str1.length(); i++){
			if(!isspace(str1.at(i))){
				str_trimmed = str_trimmed + str1.at(i);
			}
		}
		return str_trimmed;
	}

	std::string StringFuncs::toUpperCase(std::string str1){
		for(int i=0; i<str1.length(); i++){
			str1[i] = toupper(str1[i]);
		}
		return str1;
	}

	std::string StringFuncs::toLowerCase(std::string str1){
		for(int i=0; i<str1.length(); i++){
			str1[i] = tolower(str1[i]);
		}
		return str1;
	}

}