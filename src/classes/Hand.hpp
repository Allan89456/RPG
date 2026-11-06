#include <iostream>
using namespace std;

#ifndef DEF_HAND
#define DEF_HAND

template<class T>
class Hand{
	T holding;

public:
	/** \fn Hand()
	 *  \brief : an empty constructor for Hand.
	 */
	Hand(){
		holding.init_empty();
	}

	/** \fn Hand()
	 *  \brief : a constructor for Hand.
	 *  \param : h : the item to hold.
	 */
	Hand(const T h){
		holding = h;
	}

	void init_empty();
	T get_holding() const;
	void set_holding(const T&);
	bool is_empty() const;


	/** \fn set_holding()
	 *  \brief : set the holding item.
	 *  \param : u : the new item to hold.
	 */
	template<typename U>
	void set_holding(const U& u){
		cout<<"Impossible"<<endl;
	}

	/** \fn operator=()
	 *  \brief : affect a hand.
	 *  \param : h : the new hand.
	 */
	template<typename U>
	Hand operator=(const Hand<U>& h){
		return Hand();
	}

	/** \fn operator<<()
	 *  \brief : display info about the hand.
	 */
	friend ostream& operator<<(ostream& stream, const Hand<T>& h){
		if(h.is_empty()){
			stream<<"La main ne tient rien"<<endl;;
		}else{
			stream<<endl<<h.holding;
		}
		return stream;
	}
};
#endif