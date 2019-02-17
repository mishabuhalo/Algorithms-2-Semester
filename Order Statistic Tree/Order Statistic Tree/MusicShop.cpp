#include "MusicShop.h"
using namespace std;

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
		string date;
		string temp;

		is >> temp;

		vector<Artist>::iterator value = find_if(begin(vect), end(vect), [&](Artist x) {
			return temp == x.getName();
		});
		//cout << value->getName() << endl;

		is >> temp;
		is >> date;
		information info(temp, date, *value);
	}
}

ostream & operator<<(std::ostream & obj, information & operand)
{
	obj << operand.date;
	return obj;
}

information::information(): date("00.00.00")
{
	artist = nullptr;
	album = nullptr;
}

information::information(string album, string date, Artist & artist)
{
	this->artist = &artist;
	artist.add(*this);
}