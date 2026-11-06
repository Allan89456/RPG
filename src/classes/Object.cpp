#include "Object.hpp"

/** \fn Object()
 *  \brief : an empty constructor for Object.
 */
Object::Object(){
	name = "vide";
	type = "vide";
	is_equipable = false;
	efficiency = 0;
}

/** \fn Object()
 *  \brief : a constructor for Object.
 *  \param : n : the name of the object.
 *  \param : t : the type of the object.
 *  \param : equi : is the object equipable?
 *  \param : eff : the efficiency of the object.
 */
Object::Object(string n="vide", string t="vide", bool equi=false, int eff=0){
	name = n;
	type = t;
	is_equipable = equi;
	efficiency = eff;
}

/** \fn init_empty()
 *  \brief : initialize an empty object.
 */
Object Object::init_empty(){
	return Object("vide", "vide",  false, 0);
}

/** \fn get_name()
 *  \brief : get the name of the object.
 */
string Object::get_name() const{
	return name;
}

/** \fn get_is_equipable()
 *  \brief : get the info on if the object is equippable.
 */
bool Object::get_is_equipable() const{
	return is_equipable;
}

/** \fn is_empty()
 *  \brief : true if the object is empty, otherwise false.
 */
bool Object::is_empty() const{
	return type.compare("vide") == 0;
}

/** \fn operator==()
 *  \brief : compare this with a string.
 */
bool Object::operator==(const string& s){
	return name.compare(s) == 0;
}

/** \fn operator<<()
 *  \brief : display info about the object.
 */
ostream& operator<<(ostream& stream, const Object& o){
	stream<<"Nom : "<<o.name<<endl;
	stream<<"   Type : "<<o.type<<endl;
	if(o.is_equipable){
		stream<<"   L'objet peut être équipé"<<endl;
	}else{
		stream<<"   L'objet ne peut pas être équipé"<<endl;
	}
	return stream<<"   Efficacité : "<<o.efficiency<<endl;
}