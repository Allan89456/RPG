#include "Equipment.hpp"

#ifndef DEF_SHIELD
#define DEF_SHIELD

class Shield : public Equipment{
	float resistance;
	string element;

public:
	Shield();
	Shield(string, float, string, float, string);

	Shield init_empty();
	bool is_empty() const;

	friend ostream& operator<<(ostream&, const Shield&);
};
#endif