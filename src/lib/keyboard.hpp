#include <iostream>
using namespace std;

#ifndef DEF_KEYBOARD
#define DEF_KEYBOARD

void flush_stdin_buffer();

string ask_name();
string ask_type();
char ask_equipable();
int ask_efficiency();

float ask_weight();
string ask_description();
string ask_element();
float ask_resistance();

float ask_power();

char ask_equipment_type();
unsigned int ask_size_bag();
bool ask_main_hand();
string ask_pseudo();

#endif