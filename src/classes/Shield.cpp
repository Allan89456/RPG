#include "Shield.hpp"

/** \fn Shield()
 *  \brief : an empty constructor for Shield.
 */
Shield::Shield():Equipment(){
	resistance = -1;
	element = "vide";
}

/** \fn Shield()
 *  \brief : a constructor for Shield.
 *  \param : n : the name of the shield.
 *  \param : w : the weight of the shield.
 *  \param : d : the description of the shield.
 *  \param : r : the resistance of the shield.
 *  \param : e : the element of the shield.
 */
Shield::Shield(string n="vide", float w=-1, string d="vide", float r=-1, string e="vide"):Equipment(n, w, d){
	resistance = r;
	element = e;
}

/** \fn init_empty()
 *  \brief : initialize an empty shield.
 */
Shield Shield::init_empty(){
	return Shield("vide", -1, "vide",  -1, "vide");
}

/** \fn is_empty()
 *  \brief : true if the shield is empty, otherwise false.
 */
bool Shield::is_empty() const{
	return element.compare("vide") == 0;
}

/** \fn operator<<()
 *  \brief : display info about the shield.
 */
ostream& operator<<(ostream& stream, const Shield& s){
	Equipment e(s.name, s.weight, s.description);
	stream<<e<<endl;
	stream<<"   Résistance : "<<s.resistance<<endl;
	return stream<<"   Élément : "<<s.element;
}