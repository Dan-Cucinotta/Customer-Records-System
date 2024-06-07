#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include<string>

using namespace std;

const int NAMESIZE = 75, ADDSIZE = 100, CITSIZE = 30, 
STATESIZE = 20, ZIPSIZE = 7, PHONESIZE = 15, OUTPUT_SIZE = 20, ACC_BAL = 20, D_OF_LST_PAY = 15;

struct Zipcode{
	char code1;
	char code2;
	char code3;
	char code4;
	char code5;
};




struct CustRec {
   char name1[NAMESIZE];
   char name2[NAMESIZE];
   char address1[ADDSIZE];
   char address2[ADDSIZE];
   char city[CITSIZE];
   char state[STATESIZE];
   char zip[ZIPSIZE];
   char phone[PHONESIZE];
   char accountBalance[ACC_BAL];
   char dateOfLastPayment[D_OF_LST_PAY];
};   

int menu();
void userInput(int);
int search(); 
int display(int);
void erase(int);
void change(int);
int allRecs();
void fullName();

int option;
char again;
string record = "Record Was Not Found";  

char fName[NAMESIZE];
char lName[NAMESIZE];

fstream customer;      
fstream temp; 

CustRec cust;

	  int main() {
	  	
int position;       
char choice;


    do{
   	  
option = menu();
      
      while(option < 1 || option > 6){
         cout << "Please enter a menu option (1 - 6): ";
         cin >> option;
      }
      
      switch(option){
      	
      case 1:  
        
         cout << "\n\t-----  Enter New Record  -----\n\n";
         
userInput(0);  
       
 do{
 
  	 
   	   // Determine whether the user wants to write another record.
   	 cout << "\n";
   	 cout << "Do you want to enter a record? ";
   	 cin >> again;
   	 cout << "\n";
   
	
   	 
   	 again = toupper(again);
   	 if(again != 'Y'){
   	 	break;
   	 }
   	 
   	 userInput(0);  
   	 
    } while (again == 'Y');
 
        
         break;
         
      case 2: 	 
		 
		 cout << "\n\t-----  Display A Record  -----\n\n";

position = search();

         if(position != -1){
         	
display(position); 
         }
            	 
    	 break;
    	 
      case 3: 
      
         cout << "\n\t-----  Delete A Record  -----\n\n";
        
position = search();

         if(position != -1){
         	
display(position);

            cout << "\n----- Do you want to delete this record? ('Y' or 'N'): ";
            cin >> choice;
            
choice = toupper(choice);

            if(choice == 'Y'){
            	
erase(position);
               break;
            }
            
         }
         else{
            cout << "\n\n\t----- " << record << " -----";
         break;
    	 }
    	 
    	 break;
    	 
      case 4: 
      
         cout << "\n\t-----  Change A Record  -----\n\n";
          
position = search();
      
         if(position != -1){  
                     
display(position);
        
            cout << "\n----- Do you want to change this record? ('Y' or 'N'): ";
            cin >> choice;
            
choice = toupper(choice);

            if(choice == 'Y'){
            	
               cout << "\n\n\t-----  Please enter the changes  -----\n\n";
            	
change(position);
               break;
            }          
         }
              
      case 5: 
      
         cout << "\n\t-----  Display All Records  -----\n\n";
         
         if(position != -1){  
allRecs();
         break;
         }
         else{
            cout << "\n\n\t----- " << record << " -----";
         break;
    	 }
                  
      case 6:        	
         exit(0);
         break;
         
      default:  
         break;
      }
   } 
   while(option != 6);

	  return 0;
}




int menu(){	
	
	cout << "\n\n\n\t\t---------------------------------------------------\n";	
	cout << "\t\t---------- CUSTOMER ACCOUNT RECORDS MENU ----------\n";
	cout << "\t\t---------------------------------------------------\n\n";
	cout << "\t1: Enter new record\n";
	cout << "\t2: Search for a record\n";
	cout << "\t3: Delete a record\n";
	cout << "\t4: Change a record\n";
	cout << "\t5: Display all records\n";
	cout << "\t6: ----- EXIT -----\n";
	
	cout << "\nPlease choose an option from the menu: ";
	cin >> option;
	
	return option;
}	




void userInput(int pos)   							 // Uses a value parameter
{
    
    											 // To hold Y or N
    int flag ;
    int counter;
    
  
   	 // Get data about a person.
   	 cout << "\n";
   	 cout << "Enter the following data about a person:\n";
   	 
   	 cin.ignore();
   	 
   	 
   	 // Checking to see that something was input.
   	 do
   	 {
   	 
   	  	 
   		 flag = 0;
   		 cout << " \n";
   		 cout << "Enter 51 character first name: ";
   		 cin.getline(cust.name1, NAMESIZE);   		 // The dot (.) operator allows you to access structure members in a program.
   														 // (tempData) is a structure variable
   		 if (cust.name1[0] == '\0')
   		 {
   			 cout << "You entered nothing!" << endl;
   			 flag = 1;
   		 }
   		 
   		 cust.name1[0] = toupper(cust.name1[0]);
						
			   		 for (counter = 0; counter < NAMESIZE; counter++)
   		 {
   			 if (isdigit(cust.name1[counter]))   	 // isdigit: Returns true (a nonzero number) if the argument is a digit from 0 through 9. Otherwise it returns 0.
   			 {
   				 flag = 1;
   			 }
   			 
//   			 else if(tempData.dateOfLastPayment[][counter] == NULL)
//   			 {
//   				 flag = 1;
//   			 }
   			 
   		 }
   	 if (flag == 1)
   		 cout << "Error: Invalid name!" << endl;
   		 
   	 } while(flag == 1);
   	 //cout << tempData.name << endl;
   	 
   	 
   	   	 do
   	 {
   		 flag = 0;
   		 cout << " \n";
   		 cout << "Enter 51 character last name: ";
   		 cin.getline(cust.name2, NAMESIZE);   		 // The dot (.) operator allows you to access structure members in a program.
   														 // (tempData) is a structure variable
   		 if (cust.name2[0] == '\0')
   		 {
   			 cout << "You entered nothing!" << endl;
   			 flag = 1;
   		 }
   		 
   		 cust.name2[0] = toupper(cust.name2[0]);
   		 
   		 
   		 for (counter = 0; counter < NAMESIZE; counter++)
   		 {
   			 if (isdigit(cust.name2[counter]))   	 // isdigit: Returns true (a nonzero number) if the argument is a digit from 0 through 9. Otherwise it returns 0.
   			 {
   				 flag = 1;
   			 }
   			 
//   			 else if(tempData.dateOfLastPayment[][counter] == NULL)
//   			 {
//   				 flag = 1;
//   			 }
   			 
   		 }
   	 if (flag == 1)
   		 cout << "Error: Invalid name!" << endl;
   		 
   	 } while(flag == 1);
   	 //cout << tempData.name << endl;

   	 do
   	 {
   		 flag = 0;
   		 cout << " \n";
   		 cout << "Enter 51 character Address line 1: ";
   		 cin.getline(cust.address1, ADDSIZE);
   		 
   		 if (cust.address1[0] == '\0')
   		 {
   			 cout << "You entered nothing!" << endl;
   			 flag = 1;
   		 }
   		 //cout << tempData.address1 << endl;
   		 
   		 for (counter = 0; counter < ADDSIZE; counter++)
   		 {    
   			 //Pg.548
   			 if (ispunct(cust.address1[counter]))   	 // ispunct: Returns true (a nonzero number) if the argument is a printable character other than a digit, letter, or space. Otherwise it returns 0.
   			 {
   				 flag = 1;
   			 }
   		 }
   	 if (flag == 1)
   	 cout << "Error: Invalid address!" << endl;
   			 
   	 } while(flag == 1);
   	 //cout << tempData.address1 << endl;
   				 
   	 // ****************************************************************************************************

   	 cout << " \n";
   	 cout << "Enter 51 character Address line 2: ";
   	 cin.getline(cust.address2, ADDSIZE);
   	 if (ispunct(cust.address2[counter]))
   	 {
   		 flag = 1;
   	 }
   	 
   	 do
   	 {
   		 flag = 0;
   		 cout << " \n";
   		 cout << "Enter 15 character City: ";
   		 cin.getline(cust.city, CITSIZE);
   		 
   		 if (cust.city[0] == '\0')
   		 {
   			 cout << "You entered nothing!" << endl;
   			 flag = 1;
   		 }
   		 //cout << tempData.city << endl;
   		 
   		 for (counter = 0; counter < CITSIZE; counter++)
   		 {
   			 if (isdigit(cust.city[counter]))   	 // isdigit: Returns true (a nonzero number) if the argument is a digit from 0 through 9. Otherwise it returns 0.
   			 {
   				 flag = 1;
   			 }
   		 }
   	 if (flag == 1)
   	 cout << "Error: Invalid City!" << endl;
   		 
   	 } while(flag == 1);
   	 //cout << cust.city << endl;
   	 
   	 do
   	 {
   		 flag = 0;
   		 cout << " \n";
   		 cout << "Enter 15 character State: ";
   		 cin.getline(cust.state, STATESIZE);
   		 
   		 if (cust.state[0] == '\0')
   		 {
   			 cout << "You entered nothing!" << endl;
   			 flag = 1;
   		 }
   		 //cout << cust.state << endl;
   		 
   		 for (counter = 0; counter < STATESIZE; counter++)
   		 {
   			 if (isdigit(cust.state[counter]))   						 // isdigit: Returns true (a nonzero number) if the argument is a digit from 0 through 9. Otherwise it returns 0.
   			 {
   				 flag = 1;
   			 }
   		 }
   	 if (flag == 1)
   	 cout << "Error: Invalid State!" << endl;
   	 
   	 } while(flag == 1);
   	 //cout << cust.state << endl;
   		 
   	 do
   	 {
   		 flag = 0;
   		 cout << " \n";
   		 cout << "Enter 5-Digit Zipcode: ";
   		 cin.getline(cust.zip, ZIPSIZE);
   		 
   		 if (cust.zip[0] == '\0')
   		 {
   			 cout << "You entered nothing!" << endl;
   			 flag =1;
   		 }
   		 //cout << cust.zip << endl;
   	 
   		 for (counter = 0; counter < ZIPSIZE; counter++)
   		 {
   			 if (isalpha(cust.zip[counter]))   							 // isalpha: Returns true (a nonzero number) if the argument is a letter of the alphabet. Returns 0 if the argument is not a letter.
   			 {
   				 flag = 1;
   			 }
   		 }
   	 if (flag == 1)
   	 cout << "Error: Invalid Zipcode!" << endl;
   		 
   	 } while(flag == 1);
   	 //cout << cust.zip << endl;
    
   	 do
   	 {
   		 flag = 0;
   		 cout << " \n";
   		 cout << "Enter 10-Digit Phone number (numbers only): ";
   		 cin.getline(cust.phone, PHONESIZE);
   		 
   		 if (cust.phone[0] == '\0')
   		 {
   			 cout << "You entered nothing!" << endl;
   			 flag = 1;
   		 }
   		 //cout << cust.phone << endl;
   		 
   		 for (counter = 0; counter < PHONESIZE; counter++)
   		 {
   			 if (isalpha(cust.phone[counter]))   						 // isalpha: Returns true (a nonzero number) if the argument is a letter of the alphabet. Returns 0 if the argument is not a letter.
   			 {
   				 flag = 1;
   			 }
   		 }
   	 if (flag == 1)
   	 cout << "Error: Invalid Phone Number!" << endl;
   	 
   	 } while(flag == 1);
   	 //cout << cust.phone << endl;
   	 
   	 // ****************************************************************************************************

   	 float acctBal = 0.00;
   	 
   	 do
   	 {
   		 flag = 0;
   		 cust.accountBalance[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20] = '0';
   		 cout << " \n";
   		 cout << "Enter the Account Balance (up to $100,000.00): " << "$" << setprecision(2) << fixed;   		 // Set to 2 decimal places;
   		 cin >> acctBal;
   		 
   		 if (acctBal < 0.00 || acctBal > 100000.00)
   			 {
   				 flag = 1;
   				 cout << "Error: Invalid Account Balance!" << endl;
   			 }
   		 else
   		 sprintf(cust.accountBalance,"%-f",acctBal);
   						 
   		 if (cust.accountBalance[0] == '0')
   		 {
   			 cout << "You entered nothing!" << endl;
   			 flag = 1;
   		 }
   		 //cout << cust.accountBalance << endl;
   		 
   		 for(counter = 0; counter < ACC_BAL; counter++)
   		 {
   			 if (isalpha(cust.accountBalance[counter]))   					 // isalpha: Returns true (a nonzero number) if the argument is a letter of the alphabet. Returns 0 if the argument is not a letter.
   			 {
   				 flag = 1;
   			 }
   			 else if(cust.accountBalance[counter] == '.')
   			 {
   				 flag = 0;
   			 }    
   		 }
   		 if (flag == 1)
   			 cout << "Error: Invalid Account Balance!" << endl;
   			 
   	 } while(flag == 1);
    //    cout << cust.accountBalance << endl;

   	 do
   	 {
   		 flag = 0;
   		 cout << " \n";
   		 cout << "Enter the Date Of Last Payment (mm/dd/yyyy): ";
   		 cin.getline(cust.dateOfLastPayment, D_OF_LST_PAY);
   		 cin.getline(cust.dateOfLastPayment, D_OF_LST_PAY);
   		 
   		
   		 

   		 for(counter = 0; counter < D_OF_LST_PAY; counter++)
   		 {
   			 if (isdigit(cust.dateOfLastPayment[counter]))
   			 {
   			 }
   			 else if(cust.dateOfLastPayment[counter] == '/')
   			 {
   			 }
   			 else if(cust.dateOfLastPayment[counter] == 0)
   			 {
   			 }
   			 else if(cust.dateOfLastPayment[counter] == '-')
   				 cust.dateOfLastPayment[counter] = '/';   	 // If you see an dash, change it to a slash.

   			 else
   			 {
   				 flag = 1;
   			 }
   		 }

   	 if (flag == 1)
   	 cout << "You entered an invalid date!" << endl;
   				 
   	 } while (flag == 1);
   	 //cout << cust.dateOfLastPayment[] << endl;
   	 
   	 int dp = 0;
   	 for (counter = 0; counter < ACC_BAL; counter++)
   	 {
   		 if (cust.accountBalance[counter] == '.')
   			 dp = counter+3;
   	 }
   	 //*********************************************************************************************
   	 
   	 // I am forced to set cust.phone[PHONE_SIZE]; array from 10 to 11 or program crashes...
   	 
   	 // set up my next phoneOutput[size] array here.
   	 char phoneOutput[OUTPUT_SIZE];

   	 phoneOutput[0] = '(';
   	 phoneOutput[1] = cust.phone[0];
   	 phoneOutput[2] = cust.phone[1];
   	 phoneOutput[3] = cust.phone[2];
   	 phoneOutput[4] = ')';
   	 phoneOutput[5] = cust.phone[3];
   	 phoneOutput[6] = cust.phone[4];
   	 phoneOutput[7] = cust.phone[5];
   	 phoneOutput[8] = '-';
   	 phoneOutput[9] = cust.phone[6];
   	 phoneOutput[10] = cust.phone[7];
   	 phoneOutput[11] = cust.phone[8];
   	 phoneOutput[12] = cust.phone[9];
   	 phoneOutput[13] = '\0';   						 // Only prints until it finds a NULL Character, so I can assign the phoneOutput[20]; twenty or greater.

   	 
   	 //cout << phoneOutput << endl;
   	 //cout << strlen(phoneOutput);    // counts how many character are in the array.
   	 
   	 // Print out the length of the array
   	 cout << "\n";
    
   	 // I can place a (c) character after the percent sign %c, which tell the computer to print the character.
   	 //printf("Size in bytes = %d\n", sizeof(phoneOutput));
   	 //int len = strlen(phoneOutput);
   	 //printf("length = %d\n", len);
   	 
   	 //*********************************************************************************************

   	 // Debugging my code
   	 cout << "\n";
   	 cout << "Debugging My Code\n" << endl;
   	 cout << "Name: " << "-------------------------- " << setw(2) << cust.name1 << " " << cust.name2 << endl;
   	 cout << "address1: " << "---------------------- " << setw(2) << cust.address1 << endl;
   	 cout << "address2: " << "---------------------- " << setw(2) << cust.address2 << endl;
   	 cout << "City: " << "-------------------------- " << setw(2) << cust.city << endl;
   	 cout << "State: " << "------------------------- " << setw(2) << cust.state << endl;
   	 cout << "Zipcode: " << "----------------------- " << setw(2) << cust.zip << endl;
   	 //cout << "Phone number: " << "------------------ " << setw(2) << cust.phone << endl;    // change cust.phone to phoneOutput
   	 cout << "Phone number: " << "------------------ " << setw(2) << phoneOutput << endl;    // change cust.phone to phoneOutput

   	 cout << "Account Balance: " << "--------------- $";
   	 for (counter = 0; counter < dp; counter++)
   	 {
   		 cout << cust.accountBalance[counter];
   	 }
   	 cout << endl;
   	 cout << "Date Of Last Payment: " << "---------- " << setw(2) << cust.dateOfLastPayment << endl;
   	 
  	 customer.open("cust.dat", ios::out | ios::app | ios::binary ); 
   	 
   	 // Write the contents of the cust structure to the file.
   	 customer.write(reinterpret_cast<char *>(&cust), sizeof(CustRec));
   	 
   	 
   	  
   	  cout << "\n\n\t-----  Record Was Created  -----\n\n";
   	 

		       

customer.close();
     	 
    } 
    




int search(){
	
int pos;
   
fullName();
   
customer.open("cust.dat", ios::in | ios::binary);

   if(customer.fail()){
     
customer.close();
	  return -1;
}
   if(!customer){
   	return -1;
   }

   while(!customer.eof()){

customer.read(reinterpret_cast<char *>(&cust), sizeof(CustRec));  

      if(strstr(cust.name1, fName) != 0 && strstr(cust.name2, lName) != 0){
      	
pos = static_cast<int>(customer.tellg());
customer.close();

         return (pos - sizeof(CustRec));
    }
}

   cout << "\n\n\t----- " << record << " -----";
   
customer.close();

   return -1;
}








void erase(int pos){
   
customer.open("cust.dat", ios::in | ios::out | ios::binary);

   if (customer.fail()){
   	
      cout << "\n\n\t----- " << record << " -----";
      
customer.close();
	  exit(0);
}

   strcpy(cust.name1, "\0");  // indicates deletion of record
   
customer.seekp(pos, ios::beg);
customer.write(reinterpret_cast<char *>(&cust), sizeof(CustRec));
customer.close();
customer.open("cust.dat", ios::in | ios::binary);
temp.open("temp.dat", ios::out | ios::binary);   
customer.read(reinterpret_cast<char *>(&cust), sizeof(CustRec));

   while(customer){
      
temp.write(reinterpret_cast<char *>(&cust),sizeof(CustRec));
customer.read(reinterpret_cast<char *>(&cust), sizeof(CustRec));
}

customer.close();
temp.close();

temp.open("temp.dat", ios::in | ios::binary);
customer.open("cust.dat", ios::out | ios::binary);

   temp.read(reinterpret_cast<char *>(&cust), sizeof(CustRec));
   
   while(!temp.eof()){
   	
      if (cust.name1[0] != '\0'){      	
customer.write(reinterpret_cast<char *>(&cust), sizeof(CustRec));
      }
temp.read(reinterpret_cast<char *>(&cust), sizeof(CustRec));
}

temp.close();
customer.close();

	cout << "\n\t-----  Record Was Deleted  -----\n\n";
}




void change(int pos){

    cin.get();
  
   do{   	  
      cout << "Customer name1: ";
      cin.getline(cust.name1, NAMESIZE);      
   }
   while(strlen(cust.name1) == 0);  
   
   cust.name1[0] = toupper(cust.name1[0]);
   
   do{   	  
      cout << "Customer name2: ";
      cin.getline(cust.name2, NAMESIZE);      
   }
   while(strlen(cust.name2) == 0); 
   
   cust.name2[0] = toupper(cust.name2[0]);
   
   do{
      cout << "Customer address: ";
      cin.getline(cust.address1, ADDSIZE);    
   }
   while(strlen(cust.address1) == 0);   
   
   do{
      cout << "Customer address: ";
      cin.getline(cust.address1, ADDSIZE);    
   }
   while(strlen(cust.address2) == 0);
   
   do{
      cout << "City: ";
      cin.getline(cust.city, CITSIZE);      
   }
   while(strlen(cust.city) == 0);   
   
   do{
      cout << "State: ";
      cin.getline(cust.state, STATESIZE);    
   }
   while(strlen(cust.state) == 0);

   cout << "ZIP: ";

   do{        
      cin.get(cust.zip[0]);
	  cin.get(cust.zip[1]);
	  cin.get(cust.zip[2]);
	  cin.get(cust.zip[3]);
	  cin.get(cust.zip[4]);    
   }
   while(sizeof(cust.zip[0]) + sizeof(cust.zip[1]) + sizeof(cust.zip[2]) 
        + sizeof(cust.zip[3]) + sizeof(cust.zip[4]) < 5);
  
   cin.sync();
   
   cout << "Please enter phone number(1234567890): ";

   do{
     cin.get(cust.phone[0]);
	 cin.get(cust.phone[1]);
	 cin.get(cust.phone[2]);
	 cin.get(cust.phone[3]);
	 cin.get(cust.phone[4]);
	 cin.get(cust.phone[5]);
	 cin.get(cust.phone[6]);
	 cin.get(cust.phone[7]);
	 cin.get(cust.phone[8]);
	 cin.get(cust.phone[9]);
	 
	}
    while(sizeof(cust.phone[0]) + sizeof(cust.phone[1]) 
	     + sizeof(cust.phone[2]) + sizeof(cust.phone[3]) 
		 + sizeof(cust.phone[4]) + sizeof(cust.phone[5]) 
		 + sizeof(cust.phone[6]) + sizeof(cust.phone[7]) 
		 + sizeof(cust.phone[8]) + sizeof(cust.phone[9]) < 10);
	
	cin.sync();

    do{
      cout << "Account balance: ";
      cin >> cust.accountBalance;    
   }
   while(cust.accountBalance < 0);

	  cin.ignore();
	  
	  cout << "Enter last pay date(mmddyy)";

  	do{   
     cin.get(cust.dateOfLastPayment[0]);   
   	 cin.get(cust.dateOfLastPayment[1]);
     cin.get(cust.dateOfLastPayment[2]);   
     cin.get(cust.dateOfLastPayment[3]);
     cin.get(cust.dateOfLastPayment[4]);  
     cin.get(cust.dateOfLastPayment[5]);      
     }
     while(sizeof(cust.dateOfLastPayment[0]) + sizeof(cust.dateOfLastPayment[1]) 
	      + sizeof(cust.dateOfLastPayment[2]) + sizeof(cust.dateOfLastPayment[3]) 
		  + sizeof(cust.dateOfLastPayment[4]) + sizeof(cust.dateOfLastPayment[5]) < 6); 
	 
	cin.sync(); 
  
customer.open("cust.dat", ios::in | ios::out | ios::binary);
customer.seekp(pos, ios::beg);   
   
customer.write(reinterpret_cast<char *>(&cust), sizeof(CustRec));

    if(customer.fail()){
        cout << "\n\n\t----- " << record << " -----";
		exit(0);
    }
    else{    	
        cout << "\n\t-----  Record Was Changed  -----\n\n";     
}

   customer.close();
} 	
	
	
	

int allRecs(){
 
int count = 1;

customer.open("cust.dat", ios::in | ios::binary);

   if(!customer || customer.fail()){
   	
      cout << "\n\n\t----- " << record << " -----";
      
customer.close();
	  return -1;
}  
   
customer.read(reinterpret_cast<char *>(&cust), sizeof(CustRec));

   while(customer){
        cout << "\n\t" << count++ << ")";
       	cout << "\t" << cust.name1 << " " << cust.name2 << endl;
      	cout << "\t\t" << cust.address1 << endl;
      	cout << "\t\t" << cust.address2 << endl;
      	cout << "\t\t" << cust.city << ", " << cust.state << ", " 
	  	<< cust.zip[0] << cust.zip[1] << cust.zip[2] << cust.zip[3]
	  	<< cust.zip[4] << cust.zip[5] << endl;
      	cout << "\t\t" << cust.phone[0] << cust.phone[1] 
	  	<< cust.phone[2] << "-" << cust.phone[3] << cust.phone[4]
		<< cust.phone[5] << cust.phone[6] << cust.phone[7] << "-"  
		<< cust.phone[8] << cust.phone[9] << endl;
      	cout << fixed  << showpoint << setprecision(2);
      	cout << "\tAccount Balance: $" << cust.accountBalance << endl;
      	cout << "\tLast Payment: " << cust.dateOfLastPayment[0] << cust.dateOfLastPayment[1] 
		<<  "/" << cust.dateOfLastPayment[2] << cust.dateOfLastPayment[3] << "/" 
		<< cust.dateOfLastPayment[4] << cust.dateOfLastPayment[5] << endl;
      
customer.read(reinterpret_cast<char *>(&cust), sizeof(CustRec));
}   
customer.close();
return 0;
}




void fullName(){
        
   do{
      cout << "\nPlease input the customer's first name: ";
   	  cin.ignore();
      cin.getline(fName, NAMESIZE);
   }
   while(fName == 0);
   
   do{
   	  cout << "\nPlease input the customer's last name: ";  
   	  cin.getline(lName, NAMESIZE);
   }
   while(lName == 0);

fName[0] = toupper(fName[0]);
lName[0] = toupper(lName[0]);


}


int display(int pos){
   
customer.open("cust.dat", ios::in | ios::binary);

   if(customer.fail()){   	
      cout << "\n\n\t----- " << record << " -----";
      return -1;
}
   
   if(!customer){
   	
      cout << "\nFile is empty.\n";
      
customer.close();
      exit(0);
}

customer.seekg(pos, ios::beg);
customer.read(reinterpret_cast<char *>(&cust), sizeof(CustRec));
   
   cout << "\t" << cust.name1 << " " << cust.name2 << endl;
      	cout << "\t\t" << cust.address1 << endl;
      	cout << "\t\t" << cust.address2 << endl;
      	cout << "\t\t" << cust.city << ", " << cust.state << ", " 
	  	<< cust.zip[0] << cust.zip[1] << cust.zip[2] << cust.zip[3]
	  	<< cust.zip[4] << cust.zip[5] << endl;
      	cout << "\t\t" << cust.phone[0] << cust.phone[1] 
	  	<< cust.phone[2] << "-" << cust.phone[3] << cust.phone[4]
		<< cust.phone[5] << cust.phone[6] << cust.phone[7] << "-"  
		<< cust.phone[8] << cust.phone[9] << endl;
      	cout << fixed  << showpoint << setprecision(2);
      	cout << "\tAccount Balance: $" << cust.accountBalance << endl;
      	cout << "\tLast Payment: " << cust.dateOfLastPayment[0] << cust.dateOfLastPayment[1] 
		<<  "/" << cust.dateOfLastPayment[2] << cust.dateOfLastPayment[3] << "/" 
		<< cust.dateOfLastPayment[4] << cust.dateOfLastPayment[5] << endl;
customer.close(); 
}




