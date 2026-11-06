#include "Object.hpp"
#include "Hand.hpp"
#include "Weapon.hpp"
#include "Shield.hpp"

#ifndef DEF_HERO
#define DEF_HERO

template<class T>
class Hero{
	string pseudo;
	Object * inventory;
	unsigned int size_bag;
	unsigned int nb_objects;
	bool is_right_handed;
	Hand<Weapon> main_hand;
	Hand<T> secondary_hand;

	template <typename U>
	friend void change_main_hand(Hero<U>&);

public:
	/** \fn Hero()
	 *  \brief : an empty constructor for Hero.
	 */
	Hero(){
		pseudo = "Toto";
		is_right_handed = true;
		nb_objects = 0;
		size_bag = 5;
		inventory = new Object[size_bag];
		main_hand.init_empty();
		secondary_hand.init_empty();
		for(unsigned int i = 0; i < size_bag; i++){
			inventory[i].init_empty();
		}
	}

	/** \fn Hero()
	 *  \brief : a constructor for Hero.
	 *  \param : p : the pseudo of the hero.
	 *  \param : m : the main hand of the hero.
	 *  \param : e : the equipment type of the hero.
	 *  \param : s : the size of the inventory of the hero.
	 */
	Hero(string p="Toto", bool m=true, unsigned int s=5){
		pseudo = p;
		is_right_handed = m;
		nb_objects = 0;
		size_bag = s;
		inventory = new Object[size_bag];
		main_hand.init_empty();
		secondary_hand.init_empty();
		for(unsigned int i = 0; i < size_bag; i++){
			inventory[i].init_empty();
		}
	}

	/** \fn Hero()
	 *  \brief : a copy constructor for Hero.
	 *  \param : h : the hero to copy.
	 */
	Hero(const Hero& h){
		pseudo = h.pseudo;
		is_right_handed = h.is_right_handed;
		nb_objects = h.nb_objects;
		size_bag = h.size_bag;
		inventory = new Object[size_bag];
		main_hand = h.main_hand;
		secondary_hand = h.secondary_hand;
		for(unsigned int i = 0; i < size_bag; i++){
			inventory[i] = h.inventory[i];
		}
	}

	/** \fn ~Hero()
	 *  \brief : a destructor for Hero.
	 */
	~Hero(){
		delete[](inventory);
	}

	Hand<Weapon> get_main_hand() const;
	Hand<T> get_secondary_hand() const;
	unsigned int get_nb_objects() const;
	Object operator[](const unsigned int) const;
	bool is_inventory_full() const;

	void drop_main_hand();
	void drop_secondary_hand();
	bool echange_weapons_hands();

	bool add_object(const Object&);

	/** \fn add_object()
	 *  \brief : add an object into the inventory.
	 *  \param : u : the object to add.
	 */
	template<typename U>
	bool add_object(const U& u){
		return false;
	}
	
	void remove_object_inventory(unsigned int);
	unsigned int search_objet(const string) const;
	bool drop_object(const string);
	bool store_object();

	bool carry_object(unsigned int);
	void carry_shield(const Shield&);
	void carry_weapon(const Weapon&);
	
	/** \fn operator<<()
	 *  \brief : display info about the hero.
	 */
	friend ostream& operator<<(ostream& stream, const Hero<T>& h){
		stream<<"Nom : "<<h.pseudo<<endl<<endl;
		if(h.nb_objects != 0){
			stream<<"Inventaire : "<<endl;
			for(unsigned int i = 0; i < h.nb_objects; i++){
				stream<<(i+1)<<") "<<h.inventory[i]<<endl;
			}
		}else{
			stream<<"L'inventaire est vide"<<endl;
		}
		stream<<endl<<"Main principale ("<<(h.is_right_handed ? "droite":"gauche")<<") : ";
		stream<<h.main_hand<<endl<<endl;
		stream<<"Main secondaire : "<<h.secondary_hand;
		
		return stream<<endl;
	}
};
#endif