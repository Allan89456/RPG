#include <iostream>
using namespace std;

#ifndef DEF_OBJECT
#define DEF_OBJECT

class Object{
	string name;
	string type;
	bool is_equipable;
	int efficiency;

public:
	Object();
	Object(string, string, bool, int);

	Object init_empty();
	string get_name() const;
	bool get_is_equipable() const;
	bool is_empty() const;
	bool operator==(const string&);
	
	friend ostream& operator<<(ostream&, const Object&);
};
#endif