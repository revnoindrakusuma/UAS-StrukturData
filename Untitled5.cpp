#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
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
	
	string userAndPass = email+"#"+username+"#"+password; // Search pattern

	int offset;
	string line;
	ifstream usersFile;
	usersFile.open ("Data.txt");

	bool found = false;
	if(usersFile.is_open()) 
	{
		while(getline(usersFile,line) && !found) 
		{
			if (line.compare(userAndPass) == 0) //match strings exactly!
			{ 
				found = true; // found is true => break loop
			}	    
		}
		usersFile.close(); //close the file before recursivly opening it again later
		
		if(found) 
		{
			cout << "Welcome "<< username << '\n';
		}
		else 
		{
			cout << "\nUsername and/or password incorrect!\n\n\n\n";
			login(); //ok we didn't find them, lets redue this!
	    }
		usersFile.close();
	}
	else
	cout << "Unable to open userData.txt file." << endl;
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
