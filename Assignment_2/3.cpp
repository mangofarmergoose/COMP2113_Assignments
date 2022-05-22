#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string combinations[36] = {"._", "_...", "_._.", "_..", ".", ".._.", "__.", "....", "..", ".___", "_._", "._..", "__", "_.", "___", ".__.", "__._", "._.", "...", "_", ".._", "..._", ".__", "_.._", "_.__", "__..", ".____", "..___", "...__", "...._", ".....", "_....", "__...", "___..", "____.", "_____"};

string mapping[36] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
					  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

string lettersearch(string undecoded_letter)
{
	string lettersum = "";
	for (int i = 0; i < 36; ++i)
	{
		if (undecoded_letter == combinations[i])
		{
			lettersum += mapping[i];
		}
	}
	return lettersum;
}
//wordOp works fine
string wordOp(string word)
{
	int prev_lbr = -1; // records previous letter break pos
	int curr_lbr = 0;  // records current letter break pos
	string final_word = "";
	string undecoded_letter = "";
	for (int i = 0; i < word.length(); ++i)
	{
		if (word[i] == '|')
		{
			curr_lbr = i;
			if (curr_lbr > prev_lbr)
			{
				int diff = curr_lbr - (prev_lbr + 1);
				undecoded_letter = word.substr(prev_lbr + 1, diff);

				prev_lbr = curr_lbr;
				final_word += lettersearch(undecoded_letter);
			}

		}
		
		
	}
		
		undecoded_letter = word.substr(curr_lbr + 1);
		final_word += lettersearch(undecoded_letter);

	
	return final_word; //this returns a word
}
//./3 < test.txt
string morseCodeToText(string s)
{
	string text = "";
	string word = "";
	int prev_pos = -1;
	int curr_pos = 0;
	for (int i = 0; i < s.length(); ++i)
	{	
		if (s.substr(i, 2) == "||")
		{
			curr_pos = i + 1;
	
			if (curr_pos > prev_pos)
			{
				int diff = curr_pos - (2 + prev_pos);
				word = s.substr(prev_pos + 1, diff);
				prev_pos = curr_pos;
				text += wordOp(word);
				text += " ";
			}
			
		}
		
		
	}
	if(prev_pos == -1){
		int diff = curr_pos - (2 + prev_pos);
		word = s.substr(prev_pos + 1, diff);
	}
	else{
		word = s.substr(curr_pos + 1);
	}
	
	//done debugging
	text+=wordOp(word);
	

	return text; // this returns the whole text
	
}

int main()
{
	string s;
	cin >> s;
	cout << morseCodeToText(s) << '\n';

	return 0;
}
