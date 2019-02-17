#include "MusicShop.h"
using namespace std;




bool information::operator > (const information &operand) {
	return this->releaseYear > operand.releaseYear;
}

bool information::operator < (const information &operand) {
	return this->releaseYear < operand.releaseYear;
}


vector<Artist> readArtists(ifstream & is)
{
	int n = 0;
	vector<Artist> res;

	is >> n;

	for (int i = 0; i < n; i++)
	{
		string temp;
		is >> temp;
		// cout << temp << endl;
		res.push_back(Artist(temp));
	}

	return res;
}

void readInformation(ifstream & is, vector<Artist>& vect)
{
	int n = 0;
	is >> n;
	for (int i = 0; i < n; i++)
	{
		int releaseYear;
		string temp;

		is >> temp;

		vector<Artist>::iterator value = find_if(begin(vect), end(vect), [&](Artist x) {
			return temp == x.getName();
		});
		//cout << value->getName() << endl;

		is >> temp;
		is >> releaseYear;
		information info(temp, releaseYear, *value);
	}
}

ostream & operator<<(std::ostream & obj, information & operand)
{
	obj << operand.releaseYear;
	return obj;
}

information::information(): album("null")
{
	artist = nullptr;
	releaseYear = 0;
}

information::information(string album, int releaseYear, Artist &artist) :releaseYear(releaseYear), album(album)
{
	this->artist = &artist;
	artist.add(*this);
}