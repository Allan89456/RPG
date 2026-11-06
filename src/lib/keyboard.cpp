#include "keyboard.hpp"

/** \fn flush_stdin_buffer()
 *  \brief : flush stdin.
 */
void flush_stdin_buffer(){
	int c = -1;
	do{
		c = getchar();
	}while(c != '\n' && c != EOF);
}

/** \fn ask_name()
 *  \brief : ask the user for the creation's name.
 */
string ask_name(){
	string name = "vide";
	cout<<"Entrez son nom (0 pour annuler) : ";
	getline(cin, name);
	return name;
}

/** \fn ask_type()
 *  \brief : ask the user for the creation's type.
 */
string ask_type(){
	string type = "vide";
	cout<<endl<<"Entrez son type (0 pour annuler) : ";
	getline(cin, type);
	return type;
}

/** \fn ask_equipable()
 *  \brief : ask the user if the creation can be equipped.
 */
char ask_equipable(){
	char choice = 'a';
	do{
		cout<<endl<<"Est-il équipable (o/n) (0 pour annuler) ? ";
		cin>>choice;
		flush_stdin_buffer();
	}while(choice != '0' && choice != 'o' && choice != 'n');
	return choice;
}

/** \fn ask_efficiency()
 *  \brief : ask the user for the creation's efficiency.
 */
int ask_efficiency(){
	int efficiency = 0;
	cout<<endl<<"Entrez son efficacité : ";
	cin>>efficiency;
	flush_stdin_buffer();
	return efficiency;
}

/** \fn ask_weight()
 *  \brief : ask the user for the creation's weight.
 */
float ask_weight(){
	float weight = 0;
	cout<<endl<<"Entrez son poids (-1 pour annuler) : ";
	cin>>weight;
	flush_stdin_buffer();
	return weight;
}

/** \fn ask_description()
 *  \brief : ask the user for the creation's description.
 */
string ask_description(){
	string description = "vide";
	cout<<endl<<"Entrez sa description (0 pour annuler) : ";
	getline(cin, description);
	return description;
}

/** \fn ask_element()
 *  \brief : ask the user for the creation's element.
 */
string ask_element(){
	char choice = 'a';
	do{
		cout<<endl<<"Quel sera son élémént ?"<<endl;
		cout<<"\t1 - Feu"<<endl;
		cout<<"\t2 - Air"<<endl;
		cout<<"\t3 - Eau"<<endl;
		cout<<"\t4 - Terre"<<endl<<endl;
		cout<<"\t0 - Annuler"<<endl;
		cout<<"Votre choix : ";
		cin>>choice;
		flush_stdin_buffer();
	}while(choice < '0' || choice > '4');
	string element[] = {"0", "Feu", "Air", "Eau", "Terre"};
	return element[choice - '0'];
}

/** \fn ask_resistance()
 *  \brief : ask the user for the creation's resistance.
 */
float ask_resistance(){
	float resistance;
	cout<<endl<<"Entrez sa résistance : ";
	cin>>resistance;
	flush_stdin_buffer();
	return resistance;
}

/** \fn ask_power()
 *  \brief : ask the user for the creation's power.
 */
float ask_power(){
	float power;
	cout<<endl<<"Entrez sa puissance : ";
	cin>>power;
	flush_stdin_buffer();
	return power;
}

/** \fn ask_equipment_type()
 *  \brief : ask the user for the type of the creation's equipment.
 */
char ask_equipment_type(){
	char choice = 'a';
	cout<<endl<<"Quel type d'équipement voulez-vous transporter ?"<<endl;
	cout<<"\t1 - Deux armes"<<endl<<"\t2 - Une arme et un bouclier"<<endl<<"\t3 - Une arme et un objet"<<endl<<"Votre choix : ";
	cin>>choice;
	flush_stdin_buffer();
	return choice;
}

/** \fn ask_size_bag()
 *  \brief : ask the user for the size of the creation's bag.
 */
unsigned int ask_size_bag(){
	unsigned int size_bag = 0;
	cout<<endl<<"Entrez la taille de votre inventaire : ";
	cin>>size_bag;
	flush_stdin_buffer();
	return size_bag;
}

/** \fn ask_main_hand()
 *  \brief : ask the user for the creation's main hand.
 */
bool ask_main_hand(){
	char choice = '0';
	cout<<endl<<"Quelle main votre héro utilise-t-il ?"<<endl<<"\t1 - La droite"<<endl<<"\t2 - La gauche"<<endl<<"Votre choix : ";
	cin>>choice;
	flush_stdin_buffer();
	return choice != '2';
}

/** \fn ask_pseudo()
 *  \brief : ask the user for the creation's name.
 */
string ask_pseudo(){
	string name = "vide";
	cout<<"Entrez le pseudo de votre héro : ";
	getline(cin, name);
	return name;
}