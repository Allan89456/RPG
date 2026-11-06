#include "classes/Hero.hpp"
#include "classes/Equipment.hpp"
#include "lib/display.hpp"

/** \fn display_menu()
 *  \brief : display the menu.
 *  \param : equipment_type : the equipment type of the user.
 */
template <typename T>
void display_menu(Hero<T> user){
	clear_display();
	cout<<"Menu du jeu"<<endl<<endl;
	cout<<"\t1 - Ajouter un objet à l'inventaire"<<endl;
	cout<<"\t2 - Retirer un objet de l'inventaire"<<endl;
	cout<<"\t3 - Afficher l'équipement"<<endl;
	cout<<"\t4 - Déséquiper une main"<<endl;
	cout<<"\t5 - Changer de main principale"<<endl;
	cout<<"\t6 - Équiper une arme"<<endl;
	if(typeid(T) == typeid(Shield)){
		cout<<"\t7 - Équiper un bouclier"<<endl;
	}else if(typeid(T) == typeid(Object)){
		cout<<"\t7 - Équiper un objet"<<endl;
		cout<<"\t8 - Ranger l'objet équipé"<<endl;
	}else{
		cout<<"\t7 - Échanger vos armes de main"<<endl;
	}
	cout<<endl<<"\t0 - Quitter"<<endl;
	cout<<endl<<"Votre choix : ";
}

/** \fn create_object()
 *  \brief : create the object wanted by the user.
 */
Object create_object(){
	cout<<"\t\tCréation de l'objet"<<endl;
	Object object;
	string name = ask_name();

	if(name.compare("0") != 0){
		string type = ask_type();

		if(type.compare("0") != 0){
			char choice = ask_equipable();
			bool is_equipable = choice == 'o';

			if(choice != '0'){
				int efficiency = ask_efficiency();
				object = {name, type, is_equipable, efficiency};
			}
		}
	}
	return object;
}

/** \fn create_shield()
 *  \brief : create the shield wanted by the user.
 */
Shield create_shield(){
	cout<<"\t\tCréation du bouclier"<<endl;
	Shield shield;
	string name = ask_name();

	if(name.compare("0") != 0){
		float weight = ask_weight();

		if(weight >= 0){
			string description = ask_description();

			if(description.compare("0") != 0){
				string element = ask_element();

				if(element.compare("0") != 0){
					float resistance = ask_resistance();
					shield = {name, weight, description, resistance, element};
				}
			}
		}
	}
	return shield;
}

/** \fn create_weapon()
 *  \brief : create the weapon wanted by the user.
 */
Weapon create_weapon(){
	cout<<"\t\tCréation de l'arme"<<endl;
	Weapon weapon;
	string name = ask_name();

	if(name.compare("0") != 0){
		float weight = ask_weight();

		if(weight >= 0){
			string description = ask_description();

			if(description.compare("0") != 0){
				string type = ask_type();

				if(type.compare("0") != 0){
					float power = ask_power();
					weapon = {name, weight, description, type, power};
				}
			}
		}
	}
	return weapon;
}

/** \fn add_object_inventory()
 *  \brief : add an object into the user's hero's inventory.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void add_object_inventory(Hero<T> * user){
	clear_display();
	if(user->is_inventory_full()){
		cout<<"L'inventaire est plein"<<endl;
	}else{
		Object objet = create_object();
		if(user->add_object(objet)){
			cout<<endl<<"L'objet a été ajouté à l'inventaire"<<endl;
		}else{
			cout<<endl<<"L'objet n'a pas pu être ajouté à l'inventaire"<<endl;
		}
	}
	display_continue();
}

/** \fn display_inventory()
 *  \brief : display the user's hero's inventory.
 *  \param : user : the user's hero.
 */
template <typename T>
void display_inventory(Hero<T> user){
	unsigned int nb_object = user.get_nb_objects();
	if(nb_object > 0){
		for(unsigned int i = 0; i < nb_object; i++){
			cout<<(i+1)<<") "<<user[i]<<endl;
		}
	}else{
		cout<<"Aucun objet dans l'inventaire"<<endl;
	}
}

/** \fn remove_object()
 *  \brief : remove an object from the user's hero's inventory.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void remove_object(Hero<T> * user){
	clear_display();
	cout<<"\tSuppression d'un objet de l'inventaire"<<endl;
	display_inventory(*user);
	if(user->get_nb_objects() > 0){
		string name = ask_name();
		cout<<endl;
		if(user->drop_object(name)){
			cout<<"L'objet a bien été enlevé de l'inventaire"<<endl;
		}else{
			cout<<"L'objet n'a pas pu être enlevé de l'inventaire"<<endl;
		}
	}
	display_continue();		
}

/** \fn display_hero()
 *  \brief : display the user's hero.
 *  \param : user : the user's hero.
 */
template <typename T>
void display_hero(Hero<T> user){
	clear_display();
	cout<<user;
	display_continue();
}

/** \fn get_hand_number()
 *  \brief : get the number of the hand which will be de-equipped.
 *  \param : main_hand : the user's hero's main hand.
 *  \param : secondary_hand : the user's hero's secondary hand.
 */
template <typename T>
char get_hand_number(Hand<Weapon> main_hand, Hand<T> secondary_hand){
	char choice = 'a';
	while(choice < '0' || choice > '2'){
		clear_display();
		cout<<"Main princiaple : "<<main_hand<<endl;
		cout<<endl<<"Main secondaire : "<<secondary_hand<<endl<<endl;
		cout<<"Quelle main voulez-vous déséquiper ?"<<endl<<endl;
		cout<<"\t1 - La main principale"<<endl;
		cout<<"\t2 - La main secondaire"<<endl;
		cout<<endl<<"\t0 - Quitter"<<endl;
		cout<<endl<<"Votre choix : ";
		cin>>choice;
		flush_stdin_buffer();
	}
	return choice;
}

/** \fn remove_equipment()
 *  \brief : remove equipment from the user's hero's hand.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void remove_equipment(Hero<T> * user){
	char choice = get_hand_number(user->get_main_hand(), user->get_secondary_hand());
	if(choice == '1'){
		user->drop_main_hand();
		cout<<"La main principale est désormais vide";
		if(typeid(T) == typeid(Weapon)){
			cout<<" ou tient l'arme précédemment tenue par la main secondaire";
		}
	}else if(choice == '2'){
		user->drop_secondary_hand();
		cout<<"La main secondaire est désormais vide";
	}
	cout<<endl;
	display_continue();
}

/** \fn change_weapons()
 *  \brief : inverse weapons in the hands of the user's hero.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void change_weapons(Hero<T> * user){
	clear_display();
	if(user->echange_weapons_hands()){
		cout<<"Vous avez échangé vos armes de main"<<endl;
	}else{
		cout<<"Les armes n'ont pas pu être échangées de main"<<endl;
	}
	display_continue();
}

/** \fn take_weapon_hand()
 *  \brief : take a weapon in the user's hero's hand.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void take_weapon_hand(Hero<T> * user){
	clear_display();
	Weapon weapon = create_weapon();
	user->carry_weapon(weapon);
	display_continue();
}

/** \fn take_shield_hand()
 *  \brief : take a shield in the secondary hand of the user's hero.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void take_shield_hand(Hero<T> * user){
	clear_display();
	Shield shield = create_shield();
	user->carry_shield(shield);
	display_continue();
}

/** \fn take_object_hand()
 *  \brief : take an object in the secondary hand of the user's hero from their inventory.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void take_object_hand(Hero<T> * user){
	clear_display();
	display_inventory(*user);
	if(user->get_nb_objects() > 0){
		unsigned int pocket = 0;
		cout<<"Entrez le numéro de l'objet à équiper : ";
		cin>>pocket;
		flush_stdin_buffer();
		cout<<endl;
		if(user->carry_object(pocket - 1)){
			cout<<"L'objet a bien été équipé"<<endl;
		}else{
			cout<<"L'objet n'a pas pu être équipé"<<endl;
		}
	}
	display_continue();
}

/** \fn store_weapon()
 *  \brief : store the equipped object.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void store_object(Hero<T> * user){
	clear_display();
	if(user->store_object()){
		cout<<endl<<"L'objet a été rangé dans l'inventaire"<<endl;
	}else{
		cout<<"L'objet n'a pas pu être rangé dans l'inventaire"<<endl;
	}
	display_continue();
}

/** \fn change_main_hand()
 *  \brief : change the main hand of the user's hero.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void change_main_hand(Hero<T> &user){
	clear_display();
	user.is_right_handed = !user.is_right_handed;
	cout<<"Vous avez changé de main principale"<<endl;
	display_continue();
}

/** \fn play()
 *  \brief : play the game.
 *  \param : user : a pointer of the user's hero.
 */
template <typename T>
void play(Hero<T> * user){
	char choice = '1';
	while(choice != '0'){
		display_menu(*user);
		cin>>choice;
		flush_stdin_buffer();
		switch(choice){
			case '1' :
				add_object_inventory(user);
				break;
			case '2' : 
				remove_object(user);
				break;
			case '3' :
				display_hero(*user);
				break;
			case '4' :
				remove_equipment(user); 
				break;
			case '5' :
				change_main_hand(*user);
				break;
			case '6' :
				take_weapon_hand(user);
				break;
			case '7' : 
				if(typeid(T) == typeid(Shield)){
					take_shield_hand(user);
				}else if(typeid(T) == typeid(Object)){
					take_object_hand(user);
				}else{
					change_weapons(user);
				}
				break;
			case '8' :
				store_object(user);
				break;
		}
	}
}

/** \fn init_game()
 *  \brief : initialize the game.
 */
void init_game(){
	string pseudo = ask_pseudo();
	bool is_right_handed = ask_main_hand();
	unsigned int size_bag = ask_size_bag();
	char choice = ask_equipment_type();

	if(choice == '1'){
		Hero<Weapon> user(pseudo, is_right_handed, size_bag);
		play(&user);
	}else if(choice == '3'){
		Hero<Object> user(pseudo, is_right_handed, size_bag);
		play(&user);
	}else{
		Hero<Shield> user(pseudo, is_right_handed, size_bag);
		play(&user);
	}
}

int main(){
	clear_display();
	cout<<"\tBienvenue dans ce RPG !"<<endl;
	init_game();
	clear_display();
	cout<<"Merci d'avoir joué !"<<endl;
	return EXIT_SUCCESS;
}