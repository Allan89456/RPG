#include "Hand.hpp"
#include "Weapon.hpp"
#include "Shield.hpp"
#include "Object.hpp"

/** \fn init_empty()
 *  \brief : initialize an empty hand.
 */
template<typename T>
void Hand<T>::init_empty(){
	holding = holding.init_empty();
}

/** \fn get_holding()
 *  \brief : get the holding item.
 */
template<typename T>
T Hand<T>::get_holding() const{
	return holding;
}

/** \fn set_holding()
 *  \brief : set the holding item.
 *  \param : t : the new item to hold.
 */
template<typename T>
void Hand<T>::set_holding(const T& t){
	holding = t;
}

/** \fn is_empty()
 *  \brief : say if the hand is empty.
 */
template<typename T>
bool Hand<T>::is_empty() const{
	return holding.get_name().compare("vide") == 0;
}


template class Hand<Weapon>;
template class Hand<Shield>;
template class Hand<Object>;