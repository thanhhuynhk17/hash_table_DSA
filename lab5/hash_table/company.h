#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct Company
{
	string name;
	string profit_tax;
	string address;

	Company() {
		name = "";
		profit_tax = "";
		address = "";
	}
};


// 1. Viết hàm đọc thông tin các công ty từ tập tin cho trước:
vector<Company> readCompanyList(string file_name);

// 2. Viết hàm băm chuỗi (tên công ty):
long long hashString(string company_name);

// 3. Viết hàm tạo một bảng băm kích thước 2000, được tạo từ danh sách các công ty:
Company* createHashTable(vector<Company> list_company);

// 4. Viết hàm thêm thông tin của một công ty vào bảng băm có sẵn:
void insert(Company* hash_table, Company company);

// 5. Hàm tìm kiếm công ty dựa vào tên công ty:
Company* search(Company* hash_table, string company_name);




