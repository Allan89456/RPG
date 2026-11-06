#include <iostream>
using namespace std;

#ifndef DEF_EQUIPMENT
#define DEF_EQUIPMENT

class Equipment{
protected:
	string name;
	float weight;
	string description;

public:
	Equipment();
	Equipment(string, float, string);

	string get_name() const;

	friend ostream& operator<<(ostream&, const Equipment&);
};
#endif