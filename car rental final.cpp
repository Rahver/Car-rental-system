#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip> 
//Project created by Rahul verma
// included required library files
using namespace std;
class customer // customer class
{
	private:
	public:
	string customername;
    string carmodel;
    string carnumber;
    char data;
    // variables defined in this class in public mode.
};
class rent : public customer // inhereted class from customer class
{
	public:
	int days=0,rentalfee=0; // additional int vatiables defined
	void data()
	{
	cout << "Please Enter your Name: "; //taking data from the user
    cin >> customername;
    cout<<endl;
    do
    {
        cout <<"Please Select a Car"<<endl; //giving user a choice to select among three different models
        cout<<"Enter 'A' for Tesla 2009."<<endl;
        cout<<"Enter 'B' for Tesla 2010."<<endl;
        cout<<"Enter 'C' for Tesla 2011."<<endl;
        cout<<endl;
        cout<<"Choose a Car from the above options: ";
        cin >>carmodel;
        cout<<endl;
 cout<<"--------------------------------------------------------------------------"<<endl;
 if(carmodel=="A")
 {
 
		cout<<"You have choosed Tesla model 2009"<<endl;
		 ifstream inA("A.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
}
sleep(2);
  }
  if(carmodel=="B")
  {
  
		cout<<"You have choosed Tesla model 2010"<<endl;
		 ifstream inB("B.txt"); //displaying details of model B
         char str[200];
         while(inB) {
         inB.getline(str, 200);  
         if(inB) cout << str << endl;
         
     }
     sleep(2);
 }
 if(carmodel=="C")
 {
	     cout<<"You have choosed Tesla model 2011"<<endl;
		 ifstream inC("C.txt"); //displaying details of model C
         char str[200];
         while(inC) {
         inC.getline(str, 200);  
         if(inC) cout << str << endl;
     }
     sleep(2);
}  
if(carmodel !="A" && carmodel !="B" &&  carmodel !="C" )
     
      cout<<"Invaild Car Model. Please try again!"<<endl;
        }
while(carmodel !="A" && carmodel !="B" &&  carmodel !="C" );
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout << "Please provide following information: "<<endl; 
	//getting data from user related to rental service
    cout<<"Please select a Car No. : ";
    cin >> carnumber;
    cout<<"Number of days you wish to rent the car : ";
    cin >> days;
    cout<<endl;
	}
	void calculate()
	{
		sleep(1);
		system ("CLS");
		cout<<"Calculating rent. Please wait......"<<endl;
		sleep(2);
		if(carmodel == "A"||carmodel=="a")
        rentalfee=days*30;
        if(carmodel == "B" ||carmodel=="b")
        rentalfee=days*40;
        if(carmodel == "C" ||carmodel=="c")
        rentalfee=days*50;
    }
void showrent()
    {
    cout << "                             Customer Invoice                  "<<endl;
    cout << "	///////////////////////////////////////////////////////////"<<endl;
    cout << "	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Fty90109"<<" |"<<endl;
    cout << "	| Customer Name:"<<"-----------------|"<<setw(10)<<customername<<" |"<<endl;
    cout << "	| Car Model :"<<"--------------------|"<<setw(10)<<carmodel<<" |"<<endl;
    cout << "	| Car No. :"<<"----------------------|"<<setw(10)<<carnumber<<" |"<<endl;
    cout << "	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
    cout << "	| Your Rental Amount is :"<<"--------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "	| Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "	 ________________________________________________________"<<endl;
    cout <<"\n";
    cout << "	| Total Rental Amount is :"<<"-------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "	 ________________________________________________________"<<endl;
    cout << "	 # This is a computer generated invoce and it does not"<<endl;
    cout << "	 require an authorised signture #"<<endl;
    cout <<" "<<endl;
    cout << "	///////////////////////////////////////////////////////////"<<endl;
    cout << "	You are advised to pay up the amount before due date."<<endl;
    cout << "	Otherwise penelty fee will be applied"<<endl;
    cout << "	///////////////////////////////////////////////////////////"<<endl;
    int f;
    cout<<"Press any key to continue"<<endl;
    cin>>f;
    
    system ("CLS");
    
     ifstream inf("thanks.txt");

  
  char str[300];

  while(inf) {
    inf.getline(str, 300);
    if(inf) cout << str << endl;
  }
  inf.close();
	}
};
class welcome //welcome class
{
	public:
	int welcum()
	{
 ifstream in("welcome.txt"); //displaying welcome ASCII image text on output screen

  if(!in) {
    cout << "Cannot open input file.\n";
  }
  char str[1000];
  while(in) {
    in.getline(str, 1000);  // delim defaults to '\n'
    if(in) cout << str << endl;
  }
  in.close();
  sleep(1);
  cout<<"\nStarting the program please wait....."<<endl;
  sleep(1);
  cout<<"\nloading up files....."<<endl;
  sleep(1); //function which waits for (n) seconds
  system ("CLS"); //cleares screen
}

};
int main()
{
welcome obj1; //object created for welcome class
obj1.welcum(); //welcum function is called
rent obj2; 
//object created for rent class and further member functions are called
obj2.data();
obj2.calculate();
obj2.showrent();

return 0; //end of the program
}

