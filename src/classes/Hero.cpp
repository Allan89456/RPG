#include "Hero.hpp"

/** \fn get_main_hand()
 *  \brief : return the main hand of the hero.
 */
template<typename T>
Hand<Weapon> Hero<T>::get_main_hand() const{
	return main_hand;
}

/** \fn get_secondary_hand()
 *  \brief : return the secondary hand of the hero.
 */
template<typename T>
Hand<T> Hero<T>::get_secondary_hand() const{
	return secondary_hand;
}

/** \fn get_nb_objects()
 *  \brief : return the number of objects in the inventory of the hero.
 */
template<typename T>
unsigned int Hero<T>::get_nb_objects() const{
	return nb_objects;
}

/** \fn operator[]()
 *  \brief : return an object from the hero's inventory if the pocket is within the limit; otherwise, return an empty object.
 *  \param : pocket : the case of the inventory.
 */
template<typename T>
Object Hero<T>::operator[](const unsigned int pocket) const{
	if(pocket >= nb_objects){
		Object empty;
		return empty;
	}
	return inventory[pocket];
}

/** \fn drop_main_hand()
 *  \brief : drop weapon from the main hand.
 */
template<typename T>
void Hero<T>::drop_main_hand(){
	if(typeid(T) == typeid(Weapon) && !secondary_hand.is_empty()){
		main_hand = secondary_hand;
		secondary_hand.init_empty();
	}else{
		main_hand.init_empty();
	}
}

/** \fn drop_secondary_hand()
 *  \brief : drop equipment from the main hand.
 */
template<typename T>
void Hero<T>::drop_secondary_hand(){
	secondary_hand.init_empty();
}

/** \fn echange_weapons_hands()
 *  \brief : exchange weapons from the two hands if the equipment type allows it.
 */
template<typename T>
bool Hero<T>::echange_weapons_hands(){
	if(typeid(T) == typeid(Weapon) && !secondary_hand.is_empty()){
		Weapon tmp = main_hand.get_holding();
		main_hand.set_holding(secondary_hand.get_holding());
		secondary_hand.set_holding(tmp);
		return true;
	}
	return false;
}

/** \fn is_inventory_full()
 *  \brief : return true if the inventory is full, otherwise false.
 */
template<typename T>
bool Hero<T>::is_inventory_full() const{
	return size_bag == nb_objects;
}

/** \fn add_object()
 *  \brief : add an object into the inventory.
 *  \param : o : the object to add.
 */
template<typename T>
bool Hero<T>::add_object(const Object& o){
	if(nb_objects < size_bag && !o.is_empty()){
		inventory[nb_objects] = o;
		nb_objects++;
		return true;
	}
	return false;
}

/** \fn remove_object_inventory()
 *  \brief : remove an object from the inventory.
 *  \param : location : the location of the object to remove.
 */
template<typename T>
void Hero<T>::remove_object_inventory(unsigned int location){
	for(unsigned int j = location + 1; j < nb_objects; j++){
		inventory[location] = inventory[j];
		location++;
	}
	inventory[location].init_empty();
	nb_objects--;
}

/** \fn search_objet()
 *  \brief : search for the first instance of an object in the inventory. Return size_bag if the object isn't present.
 *  \param : name : the name of the object researched.
 */
template<typename T>
unsigned int Hero<T>::search_objet(const string name) const{
	unsigned int i = 0;
	bool found = false;
	while(i < nb_objects && !found){
		found = inventory[i] == name;
		i++;
	}
	if(found){
		i--;
	}
	return i;
}

/** \fn drop_object()
 *  \brief : drop an object.
 *  \param : name : the name of the object that will be dropped.
 */
template<typename T>
bool Hero<T>::drop_object(const string name){
	unsigned int i = search_objet(name);
	if(i < nb_objects){
		remove_object_inventory(i);
		return true;
	}
	return false;
}

/** \fn store_weapon()
 *  \brief : store the equipped object.
 */
template<typename T>
bool Hero<T>::store_object(){
	if(typeid(T) == typeid(Object) && nb_objects < size_bag){
		if(add_object(secondary_hand.get_holding())){
			drop_secondary_hand();
			return true;
		}
	}
	return false;
}

/** \fn carry_object()
 *  \brief : carry an object if the equipment type allows it and if the object is equipable.
 *  \param : location : the location of the object in the inventory.
 */
template<typename T>
bool Hero<T>::carry_object(unsigned int location){
	if(location < nb_objects && typeid(T) == typeid(Object) && inventory[location].get_is_equipable()){
		T tmp = secondary_hand.get_holding();
		secondary_hand.set_holding(inventory[location]);
		remove_object_inventory(location);
		add_object(tmp);
		return true;
	}
	return false;
}

/** \fn carry_shield()
 *  \brief : carry a shield if the equipment type allows it.
 *  \param : s : the shield to carry.
 */
template<typename T>
void Hero<T>::carry_shield(const Shield& s){
	if(typeid(T) == typeid(Shield) && !s.is_empty()){
		secondary_hand.set_holding(s);
	}
}

/** \fn carry_object()
 *  \brief : carry an weapon.
 *  \param : weapon : the weapon to carry.
 */
template<typename T>
void Hero<T>::carry_weapon(const Weapon& w){
	if(!w.is_empty()){
		if(main_hand.is_empty() || typeid(T) != typeid(Weapon) || !secondary_hand.is_empty()){
			main_hand.set_holding(w);
		}else{
			secondary_hand.set_holding(w);
		}
	}
}

template class Hero<Weapon>;
template class Hero<Shield>;
template class Hero<Object>;