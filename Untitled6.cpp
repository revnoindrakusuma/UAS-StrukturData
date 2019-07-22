#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <algorithm>

using namespace std;

void mainmenu();

int choice; 
bool cinfail; 
int confirmation; 
string email, username, password, password2;

void writetofile(string username)
{
    ofstream OFileObject;  // Create Object of Ofstream
    OFileObject.open ("Data.txt", ios::app); // Append mode
	OFileObject <<email+"#"+username+"#"+password<<"\n"; // Writing data to file
    OFileObject.close(); // Closing the file
    mainmenu();
}

//void sortfile()


void registerpassword()
{
    cout << "Please enter the password:" << endl;
    cin >> password;
    cout << "Please renter your password:" << endl;
    cin >> password2;
    if (password == password2)
	{
        cin.clear();
        cin.ignore(10000,'\n');
        writetofile(username);
        exit(1);
    }
    else;
	{
        cout << "Sorry invalid" << endl;
        registerpassword();
    }
}

void registerme()
{
	//string email;
    cout << "Enter your email address\n";
    getline(cin, email);

    size_t at = email.find('@');
    if (at == string::npos)
    {
        cout << "Missing @ symbol\n";
        registerme();
    }

    size_t dot = email.find('.', at + 1);
    if (dot == string::npos)
    {
        cout << "Missing . symbol after @\n";
        registerme();
    }

    cout << "Email accepted.\n";
    cout << "Please enter your username: " << endl;
    getline(cin, username);
    cout << "\nUsername -  \""<< username << "\"\nConfirm? \n\n[1] Yes\n[2] No" << endl;
    cin >> confirmation;
    if (confirmation == 1)
	{
        registerpassword();
    }

    else; 
	{
        cout << "Sorry invalid input, Please try again" << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        registerme();
    }

}

void login()
{
	cout << "Please enter your username:\n";
	cin >> username;
	cout << "\nPlease enter your password:\n";
	cin >> password;
	
	bool authenticate(string &username, string &password) 
	{
    	ifstream file("Data.txt");
    	string fusername, fpassword;

    	while (file) 
		{
        	std::getline(file, fusername, ';'); // use ; as delimiter
        	std::getline(file, fpassword); // use line end as delimiter
        	// remember - delimiter readed from input but not added to output
        	if (fusername == username && fpassword == password)
            return true;
    	}
    	return false;
	}
}


void exit()
{
    exit(0);
}

void mainmenu()
{ 
	cout << "Hello, what you like to do? \n[1] Register \n[2] Login \n[3] Exit" <<endl; 
	cin >> choice; 
	do
	{
    	cinfail = cin.fail();
    	cin.clear();
    	cin.ignore(10000,'\n');
	}
	while(cinfail == true);
	{
        switch(choice)
		{
            case 1:
            	system("cls");
                registerme();
                break;

            case 2:
            	system("cls");
                login();
                break;

            case 3:
                exit();
		}
	}
} 

main()
{ 
	mainmenu(); 
}
