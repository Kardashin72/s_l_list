#include "sll.h"

void main()
{
	sl_list a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(5);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.print();
	a.remove(2);
	a.print();
	

}