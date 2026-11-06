#include "Weapon.hpp"

/** \fn Weapon()
 *  \brief : an empty constructor for Weapon.
 */
Weapon::Weapon():Equipment(){
	type = "vide";
	power = -1;
}

/** \fn Weapon()
 *  \brief : a constructor for Weapon.
 *  \param : n : the name of the weapon.
 *  \param : w : the weight of the weapon.
 *  \param : d : the description of the weapon.
 *  \param : t : the type of the weapon.
 *  \param : p : the power of the weapon.
 */
Weapon::Weapon(string n="vide", float w=-1, string d="vide", string t="vide", float p=-1):Equipment(n, w, d){
	type = t;
	power = p;
}

/** \fn init_empty()
 *  \brief : initialize an empty weapon.
 */
Weapon Weapon::init_empty(){
	return Weapon("vide", -1, "vide", "vide", -1);
}

/** \fn is_empty()
 *  \brief : true if the weapon is empty, otherwise false.
 */
bool Weapon::is_empty() const{
	return power < 0;
}

/** \fn operator<<()
 *  \brief : display info about the weapon.
 */
ostream& operator<<(ostream& stream, const Weapon& w){
	Equipment e(w.name, w.weight, w.description);
	stream<<e<<endl;
	stream<<"   Type : "<<w.type<<endl;
	return stream<<"   Puissance : "<<w.power;
}