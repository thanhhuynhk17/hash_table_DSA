#include <iostream>
#include "company.h"
using namespace std;


int main() {

	string fname = "MST.txt";

	vector<Company> lsCompany = readCompanyList(fname);
	
	Company* pCompany = createHashTable(lsCompany);

	// print test
	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		if (pCompany->name == "") {

		}
	}

	if (pCompany != NULL){
		delete[]pCompany;
	}

	return 0;
}