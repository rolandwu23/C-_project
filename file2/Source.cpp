#include<iostream>
#include<fstream>
#include<string>
using namespace std;

	
class member {
public:
	string item, it;
	string str[100];
	int found, i = 0;

	string line;
	string write_st[100];
	string name, id, type, point;
	string total;
	

public:
	void write_member();
	void display_member();
	void modify_member();
	int validate_name(string userName);
	int validate_memberID(string memberID);
	int validate_level(string level);

};

void member::write_member() {
	int flag;
	do {

		cout << "Enter member name" << endl;
	cin >> name;
	cout << "Enter member id" << endl;
	cin >> id;
	cout << "Enter member type" << endl;
	cin >> type;
	cout << "Enter credit point" << endl;
	cin >> point;
	cout << endl;

	int flag_name = validate_name(name);
	int flag_id = validate_memberID(id);
	int flag_type = validate_level(type);

	

	if (flag_name == 0) {
		cout << "Enter only A-Z" << endl;
		cout << endl;
		flag = 0;

	}
	else { flag = 1; }
	if (flag_id == 0) {
		cout << "Wrong ID" << endl;
		cout << endl;
		flag = 0;
	}
	else { flag = 1; }
	if (flag_type == 0) {
		cout << "Wrong member type" << endl;
		cout << endl;
		flag = 0;
	}
	else { flag = 1; }
	} while (flag == 0);

	 total = name + " " + id + " " + type + " " + point;

	int count = 0;
	ifstream inFile("list.txt");
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			write_st[count] = line;
			count++;

		}
		inFile.close();

	}
	

	ofstream file("list.txt");

	if (file.is_open())
	{
		for (int i = 0;i < count;i++)
		{
			file << write_st[i] << endl;

		}

		file << total << endl;
		file.close();
		cout << "Successfully recorded" << endl;

	}
	else cout << "Unable to open file";
	

	system("pause");
};

void member::display_member() {

	ifstream inFile("list.txt");
	if (inFile.is_open()) {

		while (getline(inFile, it))
		{
			item = it + " ";

			while (item != "\0")
			{
				found = item.find(" ");
				for (int f = 0;f < found;f++)
				{
					str[i] += item[f];
				}
				item.erase(0, found + 1);
				i++;
			}

		}
		inFile.close();

		int person = i / 4;
		cout << "There are " << person << " members" << endl;
		cout << endl;
		int t[] = { 0,4,8,12,16,20,24,28,32,36,40,44,48,52,56 };
		int u[] = { 1,5,9,13,17,21,25,29,33,37,41,45,49,53,57 };
		int v[] = { 2,6,10,14,18,22,26,30,34,38,42,46,50,54,58 };
		int w[] = { 3,7,11,15,19,23,27,31,35,39,43,47,51,55,59};

		for (int d = 0;d < i;d++)
		{
			for (int x = 0;x < 14;x++)
			{
				if (d == t[x])
				{
					cout << "Name: " << str[d] << endl;
				}
			}


			for (int x = 0;x < 14;x++)
			{
				if (d == u[x])
				{
					cout << "ID: " << str[d] << endl;
				}

			}


			for (int x = 0;x < 14;x++)
			{
				if (d == v[x])
				{
					cout << "Member Type: " << str[d] << endl;
				}
			}

			for (int x = 0;x < 14;x++)
			{
				if (d == w[x])
				{
					cout << "Credit Point: " << str[d] << endl;
					cout << endl;
				}
			}
		}

		system("pause");
	}

	else cout << "Unable to open file" << endl;

};

void member::modify_member() {
	ifstream inFile("list.txt");
	string name;
	cout << "Enter member's name to modify" << endl;
	cin >> name;


	if (inFile.is_open()) {

		while (getline(inFile, it))
		{
			item = it + " ";

			while (item != "\0")
			{
				found = item.find(" ");
				for (int f = 0;f < found;f++)
				{
					str[i] += item[f];
				}
				item.erase(0, found + 1);
				i++;
			}

		}
		inFile.close();

		for (int d = 0;d < i;d++) {
			if (str[d] == name) {
				cout << "Name found" << endl;
				cout << "Enter name" << endl;
				cin >> str[d];
				d++;
				cout << "Enter id" << endl;
				cin >> str[d];
				d++;
				cout << "Enter type" << endl;
				cin >> str[d];
				d++;
				cout << "Enter point" << endl;
				cin >> str[d];
				break;
			}
			else {
				cout << "Name not found" << endl;
			}
		}

		

	}

	else cout << "Unable to open file" << endl;

	ofstream file("list.txt");

	if (file.is_open())
	{
		//int len = sizeof(str) / sizeof(str[0]);

		int a = 0;
		int b = 1;
		int c = 2;
		int d = 3;
		string write[100];
		int g = 0;
		while (d<i) {
			write[g] = str[a] + " " + str[b] + " " + str[c] + " " + str[d];
			g++;
			a = a + 4;
			b = b + 4;
			c = c + 4;
			d = d + 4;
		}
		//int len_write = sizeof(write) / sizeof(write[0]);
		for (int z = 0;z < g;z++) {
			file << write[z] << endl;
		}
		file.close();
		cout << "Successfully recorded" << endl;
		cout << endl;
		system("pause");

	}
	else cout << "Unable to open file";
};
int main() {
	int menu;
	do{
	
	member m;

	cout << "Enter menu option no:1,2,3 or 4" << endl;
	cout << "No.1 :Add a new member to the file." << endl;
	cout << "No.2 :Modifies the details of an existing member." << endl;
	cout << "No.3 :Displays the member details from the file." << endl;
	cout << "No.4 :Exit the program" << endl;
	cin >> menu;
	cout << endl;
	
		switch (menu)
		{

		case 1:
		{
			m.write_member();
			break;

		}

		case 2:
		{
			m.modify_member();
			break;
		}

		case 3:
		{
			m.display_member();
			break;
		}


		}
	}while(menu != 4);
	return 0;

}


int member::validate_name(string userName) {
	bool rejected = false; //set a boolean to check against
	for (unsigned int i = 0; i < userName.length() && !rejected; i++) {

		if (isalpha(userName[i]) || userName[i] == ' ')
			continue;  //if correct, go on to next char

		return rejected;  //not correct, return false

	}
	return !rejected; //correct, return true
};

int member::validate_memberID(string memberID) {
	bool rejected = false; //set a boolean to check against

	if ((memberID[0] == 'T') and (memberID[1] == 'M')) {
		for (unsigned int i = 2; i < memberID.length() && !rejected; i++) {

			if (isalpha(memberID[i]) || memberID[i] == ' ' || isdigit(memberID[i]))
				continue;
			else
				return rejected;
		}
	}
	else
		return rejected;
	return !rejected;
};

int member::validate_level(string level) {
	bool rejected = false; //set a boolean to check against
	string g = "GOLD";
	string s = "SILVER";
	string upuserlevel;
	char tempstr[10];

	for (unsigned int i = 0; i<level.length() && !rejected && level[i] != '\0'; i++)
		tempstr[i] = toupper(level[i]);

	upuserlevel = tempstr;
	string compstr = upuserlevel.substr(0, level.length()); //retrieve only the desired amt

	if (!g.compare(compstr)) {
		return !rejected;
	}
	else {
		if (!s.compare(compstr)) {
			return !rejected;
		}
		else {
			return rejected;
		}
	}
};

