#include "Equipment.hpp"

/** \fn Equipment()
 *  \brief : an empty constructor for Equipment.
 */
Equipment::Equipment(){
	name = "vide";
	weight = -1;
	description = "vide";
}

/** \fn Equipment()
 *  \brief : a constructor for Equipment.
 *  \param : n : the name of the equipment.
 *  \param : w : the weight of the equipment.
 *  \param : d : the description of the equipment.
 */
Equipment::Equipment(string n="vide", float w=-1, string d="vide"){
	name = n;
	weight = w;
	description = d;
}

/** \fn get_name()
 *  \brief : get the name of the equipment.
 */
string Equipment::get_name() const{
	return name;
}

/** \fn operator<<()
 *  \brief : display info about the equipment.
 */
ostream& operator<<(ostream& stream, const Equipment& e){
	stream<<"   Nom : "<<e.name<<endl;
	stream<<"   Poids : "<<e.weight<<endl;
	return stream<<"   Description : "<<e.description;
}