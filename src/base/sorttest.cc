#include <base/inc.hh>


int main()
{
	List *list = new List();

	for ( int i = 1000000; i > 0; --i )
		list->add(new Int(i));


	cerr << "Sorting..." << flush;

	list->sort();

	cerr << "done." << endl;

	cout << *list << endl;

	return 0;
}
