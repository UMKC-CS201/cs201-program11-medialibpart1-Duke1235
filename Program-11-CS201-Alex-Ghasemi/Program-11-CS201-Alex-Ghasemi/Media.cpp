#include "Media.h"


Media::Media() : type('\0'), rating(0), length(0), yearReleased(0) {}

Media::Media(char type, string title, string keyName, int rating, string genre, int length, int yearReleased) : type(type), title(title), keyName(keyName), rating(rating), genre(genre), length(length), yearReleased(yearReleased) {

}


int readMediaList(istream& i, ostream& outErr, vector<Media>& m) {
	vector<string> allLines;
	string line, temp;

	while (getline(i, line)) {
		allLines.push_back(line);
	}
	for (int x = 0; x < allLines.size(); x++) {
		try {
			Media tempM;
			stringstream linestream(allLines[x]);
			getline(linestream, temp, ',');
			if (temp[0] == 'M') {
				tempM.setType(temp[0]);
				for (int j = 0; j < 6; j++) {
					getline(linestream, temp, ',');
					if (j == 0) {
						tempM.setTitle(temp);
					}
					if (j == 1) {
						tempM.setKeyName(temp);
					}
					if (j == 2) {
						int tempInt = stoi(temp);
						if (!(tempInt <= 10 && tempInt >= 0)) {
							throw runtime_error("invalid rating value");
						}
						tempM.setRating(tempInt);
					}
					if (j == 3) {
						tempM.setGenre(temp);
					}
					if (j == 4) {
						tempM.setLength(stoi(temp));
					}
					if (j == 5) {
						int tempInt = stoi(temp);
						if (!(tempInt <= 2023 && tempInt >= 1500)) {
							throw runtime_error("invalid year value");
						}
						tempM.setYearReleased(stoi(temp));
					}
				}
			}
			if (temp[0] == 'B') {
				tempM.setType(temp[0]);
				for (int j = 0; j < 6; j++) {
					getline(linestream, temp, ',');
					if (j == 0) {
						tempM.setTitle(temp);
					}
					if (j == 1) {
						tempM.setKeyName(temp);
					}
					if (j == 2) {
						int tempInt = stoi(temp);
						if (!(tempInt <= 10 && tempInt >= 0)) {
							throw runtime_error("invalid rating value");
						}
						tempM.setRating(tempInt);
					}
					if (j == 3) {
						tempM.setGenre(temp);
					}
					if (j == 4) {
						tempM.setLength(stoi(temp));
					}
					if (j == 5) {
						int tempInt = stoi(temp);
						if (!(tempInt <= 2023 && tempInt >= 1500)) {
							throw runtime_error("invalid year value");
						}
						tempM.setYearReleased(stoi(temp));
					}
				}
			}
			if (temp[0] == 'S') {
				tempM.setType(temp[0]);
				for (int j = 0; j < 6; j++) {
					getline(linestream, temp, ',');
					if (j == 0) {
						tempM.setTitle(temp);
					}
					if (j == 1) {
						tempM.setKeyName(temp);
					}
					if (j == 2) {
						int tempInt = stoi(temp);
						if (!(tempInt <= 10 && tempInt >= 0)) {
							throw runtime_error("invalid rating value");
						}
						tempM.setRating(tempInt);
					}
					if (j == 3) {
						tempM.setGenre(temp);
					}
					if (j == 4) {
						tempM.setLength(stoi(temp));
					}
					if (j == 5) {
						int tempInt = stoi(temp);
						if (!(tempInt <= 2023 && tempInt >= 1500)) {
							throw runtime_error("invalid year value");
						}
						tempM.setYearReleased(stoi(temp));
					}
				}
			}
			m.push_back(tempM);

		}
		catch (runtime_error& e) {
			outErr << "ERROR: " << allLines[x] << endl;
			outErr << e.what() << endl;
			continue;
		}
		catch (invalid_argument& e) {
			outErr << "ERROR: " << allLines[x] << endl;
			outErr << e.what() << endl;
			continue;
		}
	}
	m.pop_back();
	return 0;
}

void printAllMedia(string data, ostream& out, ostream& outErr, vector <Media>& m) {
	int ratingsort;
	bool sortedprint = false, error = false;
	if (data.length() > 1 && isdigit(data[data.length() - 1])) {

		data.erase(0, 2);
		ratingsort = stoi(data);
		if (ratingsort > 10 || ratingsort <= 0) {
			outErr << "Unable to process command.The rating of : " << ratingsort << " is invalid" << endl;
			error = true;
		}
		else { sortedprint = true; }
	}
	if (sortedprint) {
		out << setw(63) << setfill('+') << "" << endl;
		out << "      YOUR MEDIA LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(6) << right << "TYPE" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getRating() >= ratingsort) {
				out << setw(3) << left << i + 1 << setw(40) << left << m[i].getTitle() << setw(6) << left << m[i].getYearReleased() << setw(8) << right << m[i].getRating() << setw(6) << right << m[i].getType() << endl;
			}
		}
	}
	else if (!error) {


		out << setw(63) << setfill('+') << "" << endl;
		out << "      YOUR MEDIA LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << setw(6) << right << "TYPE" << endl;
		for (int i = 0; i < m.size(); i++) {

			out << setw(3) << left << i + 1 << setw(40) << left << m[i].getTitle() << setw(6) << left << m[i].getYearReleased() << setw(8) << right << m[i].getRating() << setw(6) << right << m[i].getType() << endl;

		}
	}
	out << endl << endl;
	
}

void printMovieList(string data, ostream& out, ostream& outErr, vector <Media>& m) {
	int ratingsort;
	bool sortedprint = false, error = false;
	if (data.length() > 1 && isdigit(data[data.length() - 1])) {
		data.erase(0, 2);
		ratingsort = stoi(data);
		if (ratingsort > 10 || ratingsort <= 0) {
			outErr << "Unable to process command.The rating of : " << ratingsort << " is invalid" << endl;
			error = true;
		}
		else { sortedprint = true; }
	}

	if (sortedprint) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR MOVIE LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'M' && m[i].getRating() >= ratingsort) {
				out << setw(3) << left << i + 1 << setw(40) << left << m[i].getTitle() << setw(6) << left << m[i].getYearReleased() << setw(8) << right << m[i].getRating() << endl;
			}
		}
	}
	else if (!error) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR MOVIE LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'M') {
				out << setw(3) << left << i + 1 << setw(40) << left << m[i].getTitle() << setw(6) << left << m[i].getYearReleased() << setw(8) << right << m[i].getRating() << endl;
			}
		}
	}
	out << endl << endl;
	
}

void printBookList(string data, ostream& out, ostream& outErr, vector <Media>& m) {
	int ratingsort;
	bool sortedprint = false, error = false;
	if (data.length() > 1 && isdigit(data[data.length() - 1])) {
		data.erase(0, 2);
		ratingsort = stoi(data);
		if (ratingsort > 10 || ratingsort <= 0) {
			outErr << "Unable to process command.The rating of : " << ratingsort << " is invalid" << endl;
			error = true;
		}
		else { sortedprint = true; }
	}
	if (sortedprint) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR BOOK LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'B' && m[i].getRating() >= ratingsort) {
				out << setw(3) << left << i + 1 << setw(40) << left << m[i].getTitle() << setw(6) << left << m[i].getYearReleased() << setw(8) << right << m[i].getRating() << endl;
			}
		}
	}
	else if (!error) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR BOOK LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'B') {
				out << setw(3) << left << i + 1 << setw(40) << left << m[i].getTitle() << setw(6) << left << m[i].getYearReleased() << setw(8) << right << m[i].getRating() << endl;
			}
		}
	}
	out << endl << endl;
	
}

void printSongList(string data, ostream& out, ostream& outErr, vector <Media>& m) {
	int ratingsort;
	bool sortedprint = false, error = false;
	if (data.length() > 1 && isdigit(data[data.length() - 1])) {
		data.erase(0, 2);
		ratingsort = stoi(data);
		if (ratingsort > 10 || ratingsort <= 0) {
			outErr << "Unable to process command.The rating of : " << ratingsort << " is invalid" << endl;
			error = true;
		}
		else { sortedprint = true; }
	}
	if (sortedprint) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR SONG LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'S' && m[i].getRating() >= ratingsort) {
				out << setw(3) << left << i + 1 << setw(40) << left << m[i].getTitle() << setw(6) << left << m[i].getYearReleased() << setw(8) << right << m[i].getRating() << endl;
			}
		}
	}
	else if (!error) {
		out << setw(57) << setfill('+') << "" << endl;
		out << "      YOUR SONG LIST" << endl << setfill(' ') << endl;
		out << setw(3) << left << "#" << setw(40) << left << "TITLE" << setw(6) << left << "YEAR" << setw(8) << right << "RATING" << endl;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].getType() == 'S') {
				out << setw(3) << left << i + 1 << setw(40) << left << m[i].getTitle() << setw(6) << left << m[i].getYearReleased() << setw(8) << right << m[i].getRating() << endl;
			}
		}
	}
	out << endl << endl;
	
}

void printTotals(ostream& out, vector<Media>& m) {
	int mtotal = 0;
	int btotal = 0;
	int stotal = 0;
	for (int i = 0; i < m.size(); i++) {
		if (m[i].getType() == 'M') {
			mtotal += 1;
		}
		else if (m[i].getType() == 'B') {
			btotal += 1;
		}
		else if (m[i].getType() == 'S') {
			stotal += 1;
		}
	}
	out << "YOUR MEDIA LIBRARY" << endl;
	out << setw(4) << left << "#" << setw(8) << left << "TYPE" << endl;
	out << setw(4) << left << mtotal << setw(8) << left << "Movies" << endl;
	out << setw(4) << left << btotal << setw(8) << left << "Books" << endl;
	out << setw(4) << left << stotal << setw(8) << left << "Songs" << endl;
	out << setw(4) << left << mtotal + btotal + stotal << setw(8) << left << "Items" << endl;
}

void addNewMedia(string media, ostream& out, ostream& outErr, vector<Media>& m) {
	string line,temp;
	Media tempM;
	
	media.erase(0, 2);
	stringstream linestream(media);
	try {
		for (int j = 0; j < 7; j++) {
			getline(linestream, temp, ',');
			if (j == 0) {
				if (!(temp[0] == 'M' || temp[0] == 'S' || temp[0] == 'B')) {
					throw runtime_error("error");
				}
				tempM.setType(temp[0]);
			}
			if (j == 1) {
				tempM.setTitle(temp);
			}
			if (j == 2) {
				tempM.setKeyName(temp);
			}
			if (j == 3) {
				int tempInt = stoi(temp);
				if (!(tempInt <= 10 && tempInt >= 0)) {
					throw runtime_error("error");
				}
				tempM.setRating(tempInt);
			}
			if (j == 4) {
				tempM.setGenre(temp);
			}
			if (j == 5) {
				tempM.setLength(stoi(temp));
			}
			if (j == 6) {
				int tempInt = stoi(temp);
				if (!(tempInt <= 2023 && tempInt >= 1500)) {
					throw runtime_error("error");
				}
				tempM.setYearReleased(stoi(temp));
			}
		}
		m.push_back(tempM);
		out << tempM.getTitle() << " was added to your list" << endl << endl;
	}
	catch (...) {
		outErr << line << endl;
	}
	
}