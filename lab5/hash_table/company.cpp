#include "company.h"
#include <fstream>
#include <string>
#include <math.h>


#pragma region Helper functions

vector<string> splitStr(const string& str, const char& delim) {
	vector<string> lsAttr;

	int start = 0;
	int len = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == delim || i == str.length() - 1) {
			// get sub string length
			len = i - start;
			if (i == str.length() - 1) {
				len += 1;
			}

			string subStr = str.substr(start, len);
			lsAttr.push_back(subStr);

			// update start
			start = i + 1;
		}
	}

	return lsAttr;
}

Company readCompany(string line_info) {
	Company company;

	vector<string> lsInfo = splitStr(line_info, '|');

	company.name = lsInfo[0];
	company.profit_tax = lsInfo[1];
	company.address = lsInfo[2];

	return company;
}

long long calcLargePowModulo(int base, int exp, int mod) {
	long long result = 1;

	for (int  i = 0; i < exp; i++){
		result = result * base;
		result = result % mod;
	}

	return result;
}
#pragma endregion



// 1. Viết hàm đọc thông tin các công ty từ tập tin cho trước:
vector<Company> readCompanyList(string file_name) {
	vector<Company> lsCompany;

	// Open file
	ifstream infile(file_name);
	if (infile) {
		string line; 		// Get line
		bool isHeader = true;

		while (!infile.eof()) {
			getline(infile, line);
			if (!isHeader) {
				Company company = readCompany(line);
				lsCompany.push_back(company);
			}
			else { // skip header
				isHeader = false;
				// do nothing
			}
		}
	}
	else {
		// Open file failed, do nothing.
	}

	// Close file
	infile.close();
	return lsCompany;
}

// 2. Viết hàm băm chuỗi (tên công ty):
long long hashString(string company_name) {
	long long hashCode = 0;

	int p = 31;
	long long m = pow(10,9) + 9;
	int len = company_name.length();
	int loop = (len > 20) ? 20 : len;

	// Calculating hash equation
	for (int i = 0; i < len; i++)
	{
		if (i >= (len - loop)){
			long long powInModule = calcLargePowModulo(p,i,m);
			hashCode += (int)company_name[i]* powInModule % m;
		}
	}

	return hashCode;
}

// 3. Viết hàm tạo một bảng băm kích thước 2000, được tạo từ danh sách các công ty:
Company* createHashTable(vector<Company> list_company) {
	Company* pCompany = new Company[HASH_TABLE_SIZE];
	pCompany[0];
	for (int i = 0; i < list_company.size(); i++){
		int hashCode = hashString(list_company[i].name) % HASH_TABLE_SIZE;

		/// INSERT INTO HASH TABLE
		// get unuse index in hash table
		int index = hashCode;
		int k = 0;
		while (pCompany[index].name != ""){
			index = (index + 1) % HASH_TABLE_SIZE;
		}
		// insert company data
		pCompany[index].name = list_company[i].name;
		pCompany[index].profit_tax = list_company[i].profit_tax;
		pCompany[index].address = list_company[i].address;
	}

	return pCompany;
}

// 4. Viết hàm thêm thông tin của một công ty vào bảng băm có sẵn:
void insert(Company* hash_table, Company company) {

}

// 5. Hàm tìm kiếm công ty dựa vào tên công ty:
Company* search(Company* hash_table, string company_name) {
	Company* company_ptr = new Company();

	return company_ptr;
}
