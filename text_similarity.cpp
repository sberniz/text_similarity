/*
Text Similarity manual with c++ . Mostly works. Some bugs fixes to be done. 
1. better dynamic array assignment to prevent program from crashing when only 2 characters are typed. .(try to do it without using vectors
2. more through test to make sure all works fine. */

//Standards Includes. 
#include "stdafx.h"
#include <iostream>
#include <iostream>
#include <string>
#include<cctype>
#include <stdio.h>
#include <ctype.h>
#include <locale>
#include <algorithm>
#include <conio.h>
using namespace std; //using this since is a short program. better practice is line below. adjust accordingtly. 
//using std::cout, std::cin, std::string, std::tolower;
// function declaration 

//function prototypes
float similarity(string&, string&);
string fixer(string&);
void createArrays(string *, string&, int&);
bool stop_words_check(string);

//main function
int main() {
	char selection; //selection for menu driven option 
	//Declare sample texts
	string test1 = "hello how are you.";
	string test2 = "hello how are you.";
	string test3 = "goodbye everyone. for the best points Rewards ever";
	string sample1 = "The easiest way to earn points with Fetch Rewards is to just shop for the products you already love. If you have any participating brands on your receipt, you'll get points based on the cost of the products. You don't need to clip any coupons or scan individual barcodes. Just scan each grocery receipt after you shop and we'll find the savings for you.";
	string sample2 = "The easiest way to earn points with Fetch Rewards is to just shop for the items you already buy. If you have any eligible brands on your receipt, you will get points based on the total cost of the products. You do not need to cut out any coupons or scan individual UPCs. Just scan your receipt after you check out and we will find the savings for you.";
	string sample3 = "We are always looking for opportunities for you to earn more points, which is why we also give you a selection of Special Offers. These Special Offers are opportunities to earn bonus points on top of the regular points you earn every time you purchase a participating brand. No need to pre-select these offers, we'll give you the points whether or not you knew about the offer. We just think it is easier that way.";

	// Declares Input Text
	string text1 = {}, text2 = {};
	//declare scores
	float score;

	//Menu
	cout << "Please Enter your Selection: \n\n\t1. Use Built In Sampler Text\n\t2. Enter your own Texts to compare\n\nSelection: ";
	selection = _getch();
	switch (selection) {
	case '1':
	{
		cout << "\n\n\n\n";
	//	cout << "test1 and test2: " << similarity(test1, test2);
		cout << "\nsmaple1 and sample2 " << similarity(sample1, sample2) <<"\n";
		cout << "\nsample1 and sample3 " << similarity(sample1, sample3) << "\n";
	//	cout << "\nTest1 and Test3 " << similarity(test1, test3);
	//////	cout << "\nTest1 and sample1 " << similarity(test1, sample1);
	//	cout << "\ntest2 and sample 2 " << similarity(test2, sample2);
	//	cout << " \nTest3 and sample3 " << similarity(test3, sample3);
		break;

	}
	case '2':
		{
		//Ask and gets Text for 1 and 2 via getline
		cout << "\r\nEnter Text1: ";
		getline(cin, text1);
		cout << " Enter Text2: ";
		getline(cin, text2);
		score = similarity(text1, text2);
		cout << "Similarity Score is: " << score;
		break;
	
	}
	default:
	{
		cout << "Invalid Selection";
	}
	}


	_getch();
	return 0;
}

//removes punctuation from sentences
string fixer(string &text) {

	std::locale loc;
	int size1 = text.length();
	for (int j = 0; j< text.length();)
	{
		if (text[j] == ',' || text[j] == '.') {
			text.erase(j, 1);
		}
		else {

			text[j] = tolower(text[j], loc);
			j++;
		}

	}
	return text;

}

//checks for text similarity
float similarity(string &text1, string &text2)
{
	
	float points = 0, score = 0;
	float same_words_counter = 0;
	bool checker = 0;
	text1 = fixer(text1);
	text2 = fixer(text2);
	int size1 = text1.length();
	int size2 = text2.length();
	string *text1arr = new string[size1]; //declare texts arrays. needs to be fixeddd
	string *text2arr = new string[size2];//same as above 

	//calls function to create arrys
	createArrays(text1arr, text1, size1);
	createArrays(text2arr, text2, size2);
	cout << "\n";

	for (int m = 0; m < (sizeof text1arr) - 1; m++) {
		for (int x = 0; x < (sizeof text2arr - 1); x++) {
			checker = stop_words_check(text1arr[m]);
			if ((text1arr[m] == text2arr[x]) && (checker == 0)) {
				same_words_counter++;
				if (m == x) {
					points += 1;
				}
				else {
					cout << m << " " << x;
					points += 0.5;
				}
			}

		}
	}


	return score;
}

//create an array of words (list) from the sentences
void createArrays(string *textarr, string &text,int &size)
{
	int j = 0;
	string word = "";
	for (int i = 0; i <= size; i++) {

		if (text[i] == ' ' || i == size) {
			textarr[j] = word;
			word = "";
			j++;
		}
		else {


			word = word + text[i];

		}
	}
	for (int n = 0; n <= size;n++) {
		cout << textarr[n] << "  ";
	}
}

//stop words to not include
bool stop_words_check(string value)
{
	string stop_words[] = { "the", "to", "is", "for", "on", "you", "your", "just", "way", "with", "if", "any", "you", "already", "we", "we'll" };
	int stop_words_size = sizeof(stop_words) / sizeof(stop_words[0]);
	for(int j = 0; j < stop_words_size; j++) {
		if (value == stop_words[j]) {
			return 1;
		}

	}
	return 0;
}
