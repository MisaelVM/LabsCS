#include "Lab6/LinkedList.h"

int main()
{
	LinkedList<int> lnk;
	
	lnk.insert(lnk.begin(), 7);
	lnk.insert(lnk.begin(), 4);
	lnk.insert(lnk.begin(), 9);
	for (LinkedList<int>::Iterator iter = lnk.begin(); iter != lnk.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << "\n";
	lnk.erase(lnk.end());
	lnk.pop_back();
	lnk.erase(lnk.end());
	lnk.pop_front();
	lnk.erase(lnk.end());
	lnk.insert(lnk.end(), 7);
	lnk.insert(lnk.end(), 4);
	lnk.insert(lnk.end(), 9);
	for (LinkedList<int>::Iterator iter = lnk.begin(); iter != lnk.end(); ++iter)
		std::cout << *iter << " ";
	lnk.clear();
	return 0;
}