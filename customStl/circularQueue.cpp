#include "circular.h"
using namespace std;



int main() {
	// your code goes here
	circular<string> doctors(6);

	doctors.push_back("Dr Jacob");
	doctors.push_back("Dr Vidhya");
	doctors.push_back("Dr Varghese");
	doctors.push_back("Dr Mahesh");
	doctors.push_back("Dr Janardhan");
	doctors.push_back("Dr Mohammed");
	doctors.push_back("Dr Amrendar");
	doctors.push_back("Dr Singh");
	doctors.push_back("Dr Aliya");
	doctors.push_back("Dr DSouza");
	doctors.push_back("Dr George");
	doctors.push_back("Dr Ramesh");
	doctors.push_back("Dr Vikram");
    
	
	//for ( circular<string>::iterator it = doctors.begin(); it != doctors.end(); it++)
	//{
	//    cout << *it << endl;
	//}
    //
	circular<int> nurses({0,1,2,3,4,5,6,7,8,9,10,11,12});
	nurses.push_back(13);

	for ( auto nurse : nurses )
	{
	    cout << nurse << endl;
	}
	return 0;
}
