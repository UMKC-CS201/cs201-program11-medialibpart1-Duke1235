#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stdexcept>
using namespace std;



class Media {
protected:
	char type;
	string title;
	string keyName;
	int rating;
	string genre;
	int length;
	int yearReleased;
public:
	Media();
	Media(char type, string title, string keyName, int rating, string genre, int length, int yearReleased);

	char getType() { return type; };
	string getTitle() { return title; };
	string getKeyName() { return keyName; };
	int getRating() { return rating; };
	string getGenre() { return genre; };
	int getLength() { return length; };
	int getYearReleased() { return yearReleased; };

	void setType(char ntype) { type = ntype; };
	void setTitle(string ntitle) { title = ntitle; };
	void setKeyName(string nkeyName) { keyName = nkeyName; };
	void setRating(int nrating) { rating = nrating; };
	void setGenre(string ngenre) { genre = ngenre; };
	void setLength(int nlength) { length = nlength; };
	void setYearReleased(int nyear) { yearReleased = nyear; };
};


int readMediaList(istream& i, ostream& outErr, vector<Media>& m);

void printAllMedia(string data, ostream& out,ostream& outErr,vector <Media>& m);

void printMovieList(string data, ostream& out,ostream& outErr,vector <Media>& m);

void printBookList(string data, ostream& out,ostream& outErr,vector <Media>& m);

void printSongList(string data, ostream& out,ostream& outErr,vector <Media>& m);

void printTotals(ostream& out,vector<Media>& m);

void addNewMedia(string media, ostream& out, ostream& outErr, vector<Media>& m);