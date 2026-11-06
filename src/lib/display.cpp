#include "display.hpp"
#include <iostream>
using namespace std;

/** \fn clear_display()
 *  \brief : clear screen.
 */
void clear_display(){
	system("@cls||clear");
}

/** \fn display_continue()
 *  \brief : display a continue message.
 */
void display_continue(){
	cout<<endl<<"Appuyez sur une touche pour continuer";
	flush_stdin_buffer();
}