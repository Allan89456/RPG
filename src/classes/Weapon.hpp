#include "Equipment.hpp"

#ifndef DEF_WEAPON
#define DEF_WEAPON

class Weapon : public Equipment{
	string type;
	float power;

public:
	Weapon();
	Weapon(string, float, string, string, float);

	Weapon init_empty();
	bool is_empty() const;

	friend ostream& operator<<(ostream&, const Weapon&);
};
#endif