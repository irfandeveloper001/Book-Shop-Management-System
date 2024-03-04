#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;
int count=0,count1=0,count2=0;
using namespace std;

struct admin 
{
	string password = "programmer";
};
admin Password(admin a , string pasword)
{
    if (a.password == pasword)
    {
    	system("cls");
        cout << "\n\n\tLogin successfully" << endl;
    }
    else
    {
        cout << "\n\n\tInvalid password" << endl;
        cout <<"\tPlease Try Again\n";
        cin >> pasword;
        return Password(a , pasword);
    }	
}
struct BookShop
{
	string Customer_name;
	string id;
	string ph_no;
	string gender;
	string age;
};

void saveInFile(BookShop s[], int n)
{
    ofstream out;
    out.open("bookshop.txt", ios::out | ios::app);
    if (out.fail() ) 
	{
        cout << "\nError Opening File." << endl;
        return;
    }

    for (int i = count2; i < n+count2; i++) 
	{
        out << s[i].id << endl;
        out << s[i].Customer_name << endl;
        out << s[i].ph_no << endl;
        out << s[i].gender << endl;
        out << s[i].age << endl;
    }
    count2 = count2+n;
    out.close();
}
int displayStudent(BookShop s[], string n)
{
			int i=0;
			ifstream display;
			display.open("bookshop.txt", ios::app | ios::in);
			if(display.fail())
			{
				cout <<"\nError Opening File\n";
				return 0;
			}
			while (!display.eof())
			{
				display >> s[i].id;
				display.ignore();
			   	getline(display, s[i].Customer_name);
			   	getline(display, s[i].ph_no);
			   	display >> s[i].gender;
			   	display >> s[i].age;
   				if ((s[i].id == n))
			    {
			    	 cout <<"\nRequired Student ID Displayed Successfully\n\n";
			    	 cout <<"Customer ID: " << s[i].id << endl;
		      		 cout <<"Customer Name: " << s[i].Customer_name << endl;
		      		 cout <<"Phone Number: " << s[i].ph_no << endl;
		      		 cout <<"Gender: " << s[i].gender << endl;
		      		 cout <<"Age: " << s[i].age << endl;
		      		 return 1;
		    	}
		    		i++;
			}
		display.close();
		if (i == 0)
		{
			cout <<"\nSorry! Customer Data Not Displayed\n";
		}
}

bool isAlphabet(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}
bool isValidName(string& ch)
{
	
	for(int i=0; ch[i]!=0; i++)
	{
		char c = ch[i];
		if(!isAlphabet(c) && c != ' ')
		{
			return false;
		}		
	}
	return true;
}

bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}
bool isValidDigit(string& ch)
{
	for(int i=0; ch[i]!= 0; i++)
	{
		char c = ch[i];
		if(!isDigit(c))
		{
			return false;
		}
	}
	return true;
}

bool is_Digit(char c)
{
	return (c >= '0' && c <= '9' || c == '+' || c == '-' || c == ' ');
}
bool isValidPhoneNumber(string& ch)
{
	for (int i=0; ch[i] != 0; i++)
	{
		char c = ch[i];
		if(!is_Digit(c)  && c != '+' && c != '-' && c != ' ')
		{
			return false;
		}
	}
	return true;
}

BookShop  inputDetails(BookShop s[], int n)
{
	for (int i=count; i <n+count; i++)
	{
		cout <<i+1 <<" . Customer Details : "<< endl; 
		bool valid_name = false;
        do
		{
            cout << "Enter the Customer Name: ";
            cin.ignore();
            getline(cin, s[i].Customer_name);
            valid_name = isValidName(s[i].Customer_name);
            if (!valid_name) 
			{
                cout << "\n\tInvalid input! \n\tName should contain only alphabets. \n\tPlease try again." << endl <<endl;
      		}
        } while (!valid_name);
        
		bool valid_id = false;
        do 
		{
        	cout <<"Enter the Customer ID: ";
			cin >> s[i].id;
			valid_id = isValidDigit(s[i].id);
			if(!valid_id)
			{
				cout << "\n\tInvalid input! \n\tID should contain only digits. \n\tPlease try again." << endl <<endl;
			}
		}while (!valid_id);
		
		bool valid_ph = false;
		do
		{
        	cout <<"Enter the customer Phone Number: ";
			cin.ignore();
			getline(cin,s[i].ph_no);
			valid_ph = isValidPhoneNumber(s[i].ph_no);
			if(!valid_ph)
			{
				cout << "\n\tInvalid input! \n\tPhone Number should contain only digits, + and -. \n\tPlease try again." << endl <<endl;
			}
		}while (!valid_ph);
		
		bool validGender = false;
		do 
		{
			cout <<"Enter the Customer gender: ";
			cin >> s[i].gender;
			validGender = isValidName(s[i].gender);
			if(!validGender)
			{
				cout << "\n\tInvalid input! \n\tGender should contain only alphabets. \n\tPlease try again." << endl << endl;
			}
		}while(!validGender);
		
		bool validAge = false;
		do
		{
			cout <<"Enter the Customer Age: ";
			cin >> s[i].age;
			validAge = isValidDigit(s[i].age);
			if(!validAge)
			{
				cout << "\n\tInvalid input!\n\\t Age should contain only digits.\n\t Please try again." << endl <<endl;
			}
		}while(!validAge);
    }
    
    count =count + n;
    return s[n];
	
}	

int idSearch(BookShop s[], string n)
{
		int i=0;
		 system("cls");
		 ifstream search;
		  search.open("bookshop.txt", ios::app |ios::in );
	
		 if (search.fail())
		  {
		  		cout <<"\nError Opening File."<< endl;
		  		return 0;
		  }	
		   	 
    while (!search.eof())
		  {
		    search >> s[i].id;
			search.ignore();
		   	getline(search, s[i].Customer_name);
		   	getline(search, s[i].ph_no);
		   	search >> s[i].gender;
		   	search >> s[i].age;
		   	
			if (s[i].id == n)
	        {
	        	cout <<"\nCongratulation! Customer Data Searched Successfully\n\n";
	            cout <<"ID: " << s[i].id << endl;
	      		cout <<"Name: " << s[i].Customer_name << endl;
	      		cout <<"Phone Number: " << s[i].ph_no << endl;
	      		cout <<"Book Name: " << s[i].gender << endl;
	      		cout <<"Book Price: " << s[i].age << endl;
	            return 1;
			}
			i++;
		  }
		  search.close();
		  if (i == 0)
		  {
		  	  cout << "Sorry, ID not found.";
		  }
	}
		  
int dltStudent(BookShop s[], string n)
{
	int i=0;
	system("cls");
	ofstream write;
	write.open("new.txt", ios::app | ios::out );
	ifstream dlt;
	dlt.open("bookshop.txt", ios::app | ios::in);
	if (write.fail() || dlt.fail())
	{
	  	cout <<"\nError Opening File."<< endl;
	  	return 0;
	}	
    while (!dlt.eof())
    {
	   	dlt >> s[i].id;
		dlt.ignore();
	   	getline(dlt, s[i].Customer_name);
	   	getline(dlt, s[i].ph_no);
	   	dlt >> s[i].gender;
	   	dlt >> s[i].age;
		if ((s[i].id != n))
        {
            write << s[i].id << endl;
	        write << s[i].Customer_name << endl;
	        write << s[i].ph_no << endl;
	        write << s[i].gender << endl;
	        write << s[i].age << endl;
		}
			i++;   
	}
	  dlt.close();
	  write.close();
	  remove("bookshop.txt");
	  rename("new.txt", "bookshop.txt");
	  if (i != 0)
	  {
	  	count--;
	  	cout <<"\nCongratulation! Data Deleted Successfully.\n\n";
	  	
	  }
	  if (i == 0)
	  {
	  	
	  	  cout << "Sorry, Customer Data not found.";
	  }
}

int updStudent(BookShop s[], string n)
{
	BookShop updt;
	system("cls");
	int i=0;
	bool valid_name = false;
        do
		{
            cout << "Enter the Customer Name: ";
            cin.ignore();
            getline(cin, updt.Customer_name);
            valid_name = isValidName(updt.Customer_name);
            if (!valid_name) 
			{
                cout << "\n\tInvalid input! \n\tName should contain only alphabets. \n\tPlease try again." << endl <<endl;
      		}
        } while (!valid_name);
        
		bool valid_id = false;
        do 
		{
        	cout <<"Enter the Customer ID: ";
			cin >> updt.id;
			valid_id = isValidDigit(updt.id);
			if(!valid_id)
			{
				cout << "\n\tInvalid input! \n\tID should contain only digits. \n\tPlease try again." << endl <<endl;
			}
		}while (!valid_id);
		
		bool valid_ph = false;
		do
		{
        	cout <<"Enter the customer Phone Number: ";
			cin.ignore();
			getline(cin,updt.ph_no);
			valid_ph = isValidPhoneNumber(updt.ph_no);
			if(!valid_ph)
			{
				cout << "\n\tInvalid input! \n\tPhone Number should contain only digits, + and -. \n\tPlease try again." << endl <<endl;
			}
		}while (!valid_ph);
		
		bool validBookName = false;
		do 
		{
			cout <<"Enter the Customer gender: ";
			cin >> updt.gender;
			validBookName = isValidName(updt.gender);
			if(!validBookName)
			{
				cout << "\n\tInvalid input! \n\tGender should contain only alphabets. \n\tPlease try again." << endl << endl;
			}
		}while(!validBookName);
		
		bool validPrice = false;
		do
		{
			cout <<"Enter the Customer Age: ";
			cin >> updt.age;
			validPrice = isValidDigit(updt.age);
			if(!validPrice)
			{
				cout << "\n\tInvalid input!\n\\t Age should contain only digits.\n\t Please try again." << endl <<endl;
			}
		}while(!validPrice);
		 
	ofstream upd_write;
	upd_write.open("file.txt", ios::app | ios::out );
	ifstream update;
	update.open("bookshop.txt", ios::app| ios::in  );
    
	if (upd_write.fail() || update.fail())
	{
	  	cout <<"\nError Opening File."<< endl;
	  	return 0;
	}	
		   	 
    while (!update.eof())
	{
	    update >> s[i].id;
		update.ignore();
	   	getline(update, s[i].Customer_name);
	   	getline(update, s[i].ph_no);
	   	update >> s[i].gender;
	   	update >> s[i].age;
		if (s[i].id != n)
	    {
			upd_write << s[i].id << endl;
	        upd_write << s[i].Customer_name << endl;
	        upd_write << s[i].ph_no << endl;
	        upd_write << s[i].gender << endl;
	        upd_write << s[i].age << endl;
		}
		else 
		{
			upd_write << updt.id << endl;
	        upd_write << updt.Customer_name << endl;
	        upd_write << updt.ph_no << endl;
	        upd_write << updt.gender << endl;
	        upd_write << updt.age << endl;
		}
			i++;
	}
	update.close();
	upd_write.close();
	remove("bookshop.txt");
	rename("file.txt", "bookshop.txt");
	if( i != 0)
	{
		cout <<"\nCongratulation! Customer Data Updatede Successfully\n\n"; 
	}
	if (i == 0)
	{
	    cout << "Sorry, Customer Data not found.";
	}
}

void AllBooks ()
{
	cout << "\n__________________________________ Books Availability ________________________________ " << endl;
	cout << "\n--------------------Books available in our centre are---------------------------------- " << endl;
	cout << "\n\t\t\t1. Physics Books" << endl;
	cout << "\t\t\t2. Chemeistry Books" << endl;
	cout << "\t\t\t3. Biology Books" << endl;
	cout << "\t\t\t4. Computer Books" << endl;
	cout << "\t\t\t5. English Books" << endl;
	cout << "\t\t\t6. Urdu Books" << endl;
	cout << "\t\t\t7. Islamiyat Books" << endl;
	cout << "\t\t\t8. History Books" << endl;
	cout << "\t\t\t9. Mathematics" << endl;
	cout << "\n\n-------------------Class Level Range--------------------------------------------------" << endl;
	cout << "\n\t\t\t1. Primary-level " << "\n\t\t\t2. Middle-level " << "\n\t\t\t3. Matric-level " << "\n\t\t\t4. Inter-level "  << endl;
	cout << "\t\t\t0. Back To Menu" << endl;
	cout << "________________________________________________________________________________________ " << endl;

}

void BooksPrice()
{
	cout << "--------------------------------------- Price Menu -------------------------------------------- " << endl;
	cout << "\n--------------------------------For Primay Level Books Price-----------------------------------" << endl;
	cout << "1. Computer Books\t\t 200" << endl;
	cout << "2. English Books\t\t 120" << endl;
	cout << "3. Urdu Books   \t\t 120" << endl;
	cout << "4. Islamiyat Books\t\t 60" << endl;
	cout << "5. History Books\t\t 80" << endl;
	cout << "6. Mathematics Books\t\t 130" << endl;
	cout << "0. Back To Main Menu" << endl;
	cout << "\n--------------------------------For Middle Level Books Price-----------------------------------" << endl;
	cout << "1. Computer Books\t\t 220" << endl;
	cout << "2. English Books\t\t 150" << endl;
	cout << "3. Urdu Books   \t\t 140" << endl;
	cout << "4. Islamiyat Books\t\t 80" << endl;
	cout << "5. History Books\t\t 100" << endl;
	cout << "6. Mathematics Books\t\t 170" << endl;
	cout << "0. Back To Main Menu" << endl;
	cout << "\n--------------------------------For Matric Level Books Price-----------------------------------" << endl;
	cout << "1. Computer Books\t\t 300" << endl;
	cout << "2. English Books\t\t 250" << endl;
	cout << "3. Urdu Books   \t\t 180" << endl;
	cout << "4. Islamiyat Books\t\t 120" << endl;
	cout << "5. History Books\t\t 130" << endl;
	cout << "6. Mathematics Books\t\t 270" << endl;
	cout << "7. Physics Books\t\t 190" << endl;
	cout << "8. Chemeistry Books\t\t 220" << endl;
	cout << "9. Biology Books\t\t 300" << endl;
	cout << "0. Back To Main Menu" << endl;
	cout << "\n--------------------------------For Inter Level Books Price------------------------------------" << endl;
	cout << "1. Computer Books\t\t 320" << endl;
	cout << "2. English Books\t\t 270" << endl;
	cout << "3. Urdu Books   \t\t 220" << endl;
	cout << "4. Islamiyat Books\t\t 150" << endl;
	cout << "5. History Books\t\t 130" << endl;
	cout << "6. Mathematics Books\t\t 280" << endl;
	cout << "7. Physics Books\t\t 230" << endl;
	cout << "8. Chemeistry Books\t\t 260" << endl;
	cout << "9. Biology Books\t\t 320" << endl;
	cout << "0. Back To Main Menu" << endl;
	cout << "__________________________________________________________________________________________________ " << endl;
}

char validateLevelChoice(char Selection_Choice)
{
	if(Selection_Choice >= '0' && Selection_Choice <='4')
	{
		return Selection_Choice;
	}
	else
	{
		cout << "\nInvalid User Choice! choice should be between 0 and 4." << endl;
        cout <<"\nPlease Enter Again : ";
        cin >> Selection_Choice;
        return validateLevelChoice(Selection_Choice);
	}
}
char validate_choice(char Book_Choice)
{
	if(Book_Choice >= '0' && Book_Choice <='6')
	{
		return Book_Choice;
	}
	else
	{
		cout << "\nInvalid User Choice! choice should be between 0 and 6." << endl;
        cout <<"\nPlease Enter Again : ";
        cin >> Book_Choice;
        return validate_choice(Book_Choice);
	}
}
char validate_Choice(char Book_Choice)
{
	if(Book_Choice >= '0' && Book_Choice <='6')
	{
		return Book_Choice;
	}
	else
	{
		cout << "\nInvalid User Choice! choice should be between 0 and 6." << endl;
        cout <<"\nPlease Enter Again : ";
        cin >> Book_Choice;
        return validate_Choice(Book_Choice);
	}
}

void MakeChoice () 
{
	ofstream fout ("Customer Details .txt" ,ios::app) ;
	char Selection_Choice , ClassLevel_Choice;
	int quantity ;
	char Book_Choice;
	while(true)
	{
	system("cls");
	AllBooks();
	cout << "Make Choice regarding Class Level range " << endl ;
	cin >> ClassLevel_Choice ;
	ClassLevel_Choice = validateLevelChoice(ClassLevel_Choice);
	system("cls");
	switch (ClassLevel_Choice)
	{
	case '1':
		cout << "You have selected Primary Level " << endl;
		cout << "Its price menu is as follow " << endl;
		while (true)
		{
		BooksPrice();
		cout <<"\n\nEnter the book Name you want: ";
		cin >> Book_Choice;
		Book_Choice = validate_choice(Book_Choice);
		system("cls");
		switch (Book_Choice)
		{
			case '1':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Computer" << endl;
					fout << "Computer " << endl;
					cout << "Class Level : " <<   "Primary" << endl;
					fout << "Class Level : " <<   "Primary" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 200  << endl;
					fout << quantity * 200 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;				
				}
			case '2':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "English" << endl;
					fout << "English " << endl;
					cout << "Class Level : " <<   "Primary" << endl;
					fout << "Class Level : " <<   "Primary" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 120  << endl;
					fout << quantity * 120 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '3':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Urdu" << endl;
					fout << "Urdu " << endl;
					cout << "Class Level : " <<   "Primary" << endl;
					fout << "Class Level : " <<   "Primary" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 120  << endl;
					fout << quantity * 120 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '4':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Islamiyat" << endl;
					fout << "Isamiyat " << endl;
					cout << "Class Level : " <<   "Primary" << endl;
					fout << "Class Level : " <<   "Primary" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 60  << endl;
					fout << quantity * 60 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '5':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "History" << endl;
					fout << "History " << endl;
					cout << "Class Level : " <<   "Primary" << endl;
					fout << "Class Level : " <<   "Primary" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 80  << endl;
					fout << quantity * 80 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '6':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Mathematics" << endl;
					fout << "Mathematics " << endl;
					cout << "Class Level : " <<   "Primary" << endl;
					fout << "Class Level : " <<   "Primary" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 130  << endl;
					fout << quantity * 130 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			default:
				cout <<"invalid choice" << endl;
		}
		if (Book_Choice == '0')
		break;
	}
		break;
	    case '2':
        cout << "You have selected Middle Level " << endl;
		cout << "Its price menu is as follow " << endl;
		while(true)
		{
		BooksPrice();
		cout <<"\n\nEnter the book Name you want: ";
		cin >> Book_Choice;
		Book_Choice = validate_choice(Book_Choice);
		system("cls");
		switch(Book_Choice)
		{
			case '1':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Computer" << endl;
					fout << "Computer " << endl;
					cout << "Class Level : " <<   "Middle" << endl;
					fout << "Class Level : " <<   "Middle" << endl;
					cout << "Enter the books you want: ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 220  << endl;
					fout << quantity * 220 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '2':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "English" << endl;
					fout << "English " << endl;
					cout << "Class Level : " <<   "Middle" << endl;
					fout << "Class Level : " <<   "Middle" << endl;
					cout << "Enter the books you want: ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 150  << endl;
					fout << quantity * 150 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '3':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Urdu" << endl;
					fout << "Urdu " << endl;
					cout << "Class Level : " <<   "Middle" << endl;
					fout << "Class Level : " <<   "Middle" << endl;
					cout << "Enter the books you want: ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 140  << endl;
					fout << quantity * 140 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '4':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Islamiyat" << endl;
					fout << "Isamiyat " << endl;
					cout << "Class Level : " <<   "Middle" << endl;
					fout << "Class Level : " <<   "Middle" << endl;
					cout << "Enter the books you want: ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 80  << endl;
					fout << quantity * 80 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '5':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "History" << endl;
					fout << "History " << endl;
					cout << "Class Level : " <<   "Middle" << endl;
					fout << "Class Level : " <<   "Middle" << endl;
					cout << "Enter the books you want: ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 100  << endl;
					fout << quantity * 100 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '6':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Mathematics" << endl;
					fout << "Mathematics " << endl;
					cout << "Class Level : " <<   "Middle" << endl;
					fout << "Class Level : " <<   "Middle" << endl;
					cout << "Enter the books you want: ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 170  << endl;
					fout << quantity * 170 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			default:
				cout <<"invalid choice" << endl;
		}
		if(Book_Choice == '0')
	    break ;
	}
		break;
	    case '3':
	    cout << "You have selected MAtric Level " << endl;
		cout << "Its price menu is as follow " << endl;
		while(true)
		{
		BooksPrice();
		cout <<"\n\nEnter the book Name you want: ";
		cin >> Book_Choice;
		Book_Choice = validate_Choice(Book_Choice);
		system("cls");
		switch(Book_Choice)
		{
			case '1':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Computer" << endl;
					fout << "Computer " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 300  << endl;
					fout << quantity * 300 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '2':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "English" << endl;
					fout << "English " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 250  << endl;
					fout << quantity * 250 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '3':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Urdu" << endl;
					fout << "Urdu " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 180  << endl;
					fout << quantity * 180 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '4':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Islamiyat" << endl;
					fout << "Isamiyat " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 120  << endl;
					fout << quantity * 120 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '5':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "History" << endl;
					fout << "History " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 130  << endl;
					fout << quantity * 130 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '6':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Mathematics" << endl;
					fout << "Mathematics " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 270  << endl;
					fout << quantity * 270 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '7':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Physics" << endl;
					fout << "Physics " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be: " << quantity* 190  << endl;
					fout << quantity * 190 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '8':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Chemistry" << endl;
					fout << "Chemistry " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be: " << quantity* 220  << endl;
					fout << quantity * 220 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '9':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Biology" << endl;
					fout << "Biology " << endl;
					cout << "Class Level : " <<   "Matric" << endl;
					fout << "Class Level : " <<   "Matric" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 300  << endl;
					fout << quantity * 300 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			default:
				cout <<"invalid input" << endl;
		}
		if(Book_Choice == '0')
	    break ;
	}
	break;
	    case '4':
	    cout << "You have selected Inter Level " << endl;
		cout << "Its price menu is as follow " << endl;
		while(true)
		{
		BooksPrice();
		cout <<"Enter the book Name you want: ";
		cin >> Book_Choice;
		Book_Choice = validate_Choice(Book_Choice);
		system("cls");
		switch(Book_Choice)
		{
			case '1':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Computer" << endl;
					fout << "Computer " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 320  << endl;
					fout << quantity * 320 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '2':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "English" << endl;
					fout << "English " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 270  << endl;
					fout << quantity * 270 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '3':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Urdu" << endl;
					fout << "Urdu " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 220  << endl;
					fout << quantity * 220 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '4':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Islamiyat" << endl;
					fout << "Isamiyat " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 150  << endl;
					fout << quantity * 150 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '5':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "History" << endl;
					fout << "History " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 130  << endl;
					fout << quantity * 130 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '6':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Mathematics" << endl;
					fout << "Mathematics " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 280  << endl;
					fout << quantity * 280 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '7':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Physics" << endl;
					fout << "Physics " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 230  << endl;
					fout << quantity * 230 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '8':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Chemistry" << endl;
					fout << "Chemistry " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 260  << endl;
					fout << quantity * 260 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			case '9':
				{
					cout << "\n----------------------------- Buying Details ------------------------------" << endl;
					cout << "Book choosed : " <<  "Biology" << endl;
					fout << "Biology " << endl;
					cout << "Class Level : " <<   "Inter" << endl;
					fout << "Class Level : " <<   "Inter" << endl;
					cout << "How many books you want? ";
					cin >> quantity;
					cout << "Your Payable amount will be " << quantity* 320  << endl;
					fout << quantity * 320 << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					break;
				}
			default:
				{
					cout <<"invalid choice " << endl;
				}
		}
		if(Book_Choice == '0')
		break;
	}
	    break;
	  
	    default : 
	    cout << "Invalid Choice" << endl ;
	}
if(ClassLevel_Choice == '0')
	break;
}

} 


string validateMainMenuChoice(string& choice)
{
	if(choice >= "1" && choice <= "6")
	{
		return choice;
	}
	else
	{
		cout << "\nInvalid User Choice! choice should be between 1 and 5." << endl;
        cout <<"\nPlease Enter Again : ";
        cin >> choice;
        return validateMainMenuChoice(choice);
	}
}
string validateMiniMenuChoice(string& choice)
{
	if(choice >= "0" && choice <= "3")
	{
		return choice;
	}
	else
	{
		cout << "\nInvalid User Choice! choice should be between 0 and 3." << endl;
        cout <<"\nPlease Enter Again : ";
        cin >> choice;
        return validateMiniMenuChoice(choice);
	}
}
void Customer_Menu()
{
					
	cout << "Select the following To Continue the Process: " << endl <<endl;
	cout << " 1.  Add: " << endl;
	cout << " 2.  Display : " << endl;
 	cout << " 3.  Search : " << endl;
	cout << " 4.  Update : " << endl;
	cout << " 5.  Delete : " << endl;
	cout << " 6.  Exit : " << endl << endl;
} 
void Book_Menu()
{
	cout << " 1.  All Books: " << endl;
	cout << " 2.  Book Price: " << endl;
	cout << " 3.  Make Chocie: " << endl;
	cout << " 0.  Back to Main Menu: " << endl;
}


int main ()
{
	BookShop s[100];
	cout<<endl<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"===   Wellcome to Muskan shop  ==="<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"====    Book Shop Center  ===="<<endl;
	cout<<"       "<<"======================================"<<endl;
	
	admin a;
    string pasword;
    cout <<"Enter the login password: ";
    cin >> pasword;
	Password(a, pasword);
	cout<<" \n\n\nPress Enter to Continue...";
	getch();
	system ("cls");
    string id;
    int n;
	string choice;

    while (true) {
        Customer_Menu();
        cout << "Enter the user choice: ";
        cin >> choice;
       choice = validateMainMenuChoice(choice);
        system("cls");
        
			if (choice == "1")
			{
                cout << "Enter the customer index: ";
                cin >> n;
                s[n] = inputDetails(s, n);
                saveInFile(s, n);
                system("cls");
                while (true) 
				{
                    Book_Menu();
                    cout << "Enter the Customer choice: ";
                    cin >> choice;
                    choice = validateMiniMenuChoice(choice);
                    system("cls");
                    if (choice == "1")
                    {
                        AllBooks();                           
                    }
                    else if (choice == "2")
                    {
                        BooksPrice();
                    }
                   else if (choice == "3")
               		{
					    MakeChoice();
					}
                    else if (choice == "0")
                    {
                       cout << "Back To Main Menu" << endl;
                    }
					else
					{
                       cout << "Invalid input" << endl;
                    }
                }
                    if (choice == "0")
                        break;
            }
            else if (choice == "2")
            {
                cout << "Enter the customer you want to display: ";
                cin >> id;
                displayStudent(s, id);
            }

           else if (choice == "3")
           {
                cout << "Enter the customer id to search: ";
                cin >> id;
                idSearch(s, id);
			}

            else if (choice == "4")
            {
                cout << "Enter the customer id to update: ";
                cin >> id;
                updStudent(s, id);
			}

            else if (choice == "5")
            {
                cout << "Enter the customer id to delete: ";
                cin >> id;
                dltStudent(s, id);
 			}
            else if (choice == "6")
			{
				cout <<"\n\nThank You For visiting My Book Center." << endl;
				exit(0);
        	}
        
    }

    return 0;
}
