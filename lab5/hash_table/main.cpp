#include <iostream>
#include "company.h"
using namespace std;


int main() {

	string fname = "MST.txt";

	vector<Company> lsCompany = readCompanyList(fname);
	
	hashString(lsCompany[1].name);

	return 0;
}