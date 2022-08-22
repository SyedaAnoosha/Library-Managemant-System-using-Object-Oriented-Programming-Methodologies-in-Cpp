//Library Managemant System By Syeda Anoosha Iqtidar
//Using Object Oriented Programming Methodologies in C++

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void student();
void lib();
void AddBook();
void BookListLib();
void optionLib();
void optionStud();
void searchBookID();
void searchBookName();
void BookListStud();
void ReqBook();
void IssueBook();

string bookID;
string title;
string author;
int edition;
int quantity;
	
class Book{
	private:
		string bookID ;
		string title ;
		string author ;
		int edition;
		int quantity;
	
	public:
		void setBookID(string b){
			bookID=b;
		}
		void setTitle(string t){
			title=t;
		}
		void setAuthor(string a){
			author=a;
		}
		void setEdition(int e){
			edition=e;
		}
		void setQuantity(int q){
			quantity=q;
		}
		string getBookID(){
			return bookID;
		}
		string getTitle(){
			return title;
		}
		string getAuthor(){
			return author;
		}
		int getEdition(){
			return edition;
		}
		int getQuantity(){
			return quantity;
		}
		
}; 

class User{
	private:
		int id;
		string name;
	public:
		void setId(int i){
			id=i;
		}
		void setName(string n){
			name=n;
		}
		int getId(){
			return id;
		}
		string getName(){
			return name;
		}
};

class Librarian: public User{
	private:
		string status;
	public:
		void setStatus(string s){
			status=s;
		}
		string getStatus(){
			return status;
		}
		void Display(){
			cout<<endl<<"Employee's Data Entered:"<<endl;
			cout<<"Name: "<<getName()<<endl;
			cout<<"ID:"<<getId()<<endl;
			cout<<"Desgnationn: "<<getStatus()<<endl;
		}
		
};

class Student: public User{

	private:
		string depart;
		int batch;
	public:
		void setDepart(string d){
			depart=d;
		}
		void setBatch(int b){
			batch=b;
		}
	
		string getDepart(){
			return depart;
		}
		int getBatch(){
			return batch;
		}
		void Display(){
			cout<<endl<<"Student's Data Entered:"<<endl;
			cout<<"Name: "<<getName()<<endl;
			cout<<"ID:"<<getId()<<endl;
			cout<<"Department: "<<getDepart()<<endl;
			cout<<"Batch: "<<getBatch()<<endl;
		}
	
};

void intro(){
	char x;
	cout<<"\t\t\t Please choose one option:\n\n";
	cout<<"\t\t1. Student\n\n";
	cout<<"\t\t2. Librarian\n\n";
	cout<<"\t\t3. Close Application\n";

	cout<<"\n\n\t\tEnter any choice: ";
	cin>>x;

	switch(x){
		case '1':{
			student();
			break;
			}
		case '2':{
			lib();
			break;
			}
		case '3':{
			exit(0);
		}	
		default:{
			cout<<"Invalid input ";
			break;
		}
	}
}

void optionLib(){
	char c;
	char ch;
	cout<<endl<<"Press any key to continue:";
	c=getch();
	system("cls");
	cout<<"\t\t\t  Choose any option: \n\n";
	cout<<"\t\t1. Add a book\n\n";
	cout<<"\t\t2. View book list\n\n";
	cout<<"\t\t3. Issue a book\n\n";
    cout<<"\t\t4. Close the application\n\n";
    cout<<"\t\t   Enter any option: ";
    cin>>ch;
    
    switch(ch){
	    case '1':{
	    	AddBook();
           	break;
       	}
     
        case '2':{
        	BookListLib();
		    break;
	    }
	        
	    case'3':{
	    	IssueBook();
	        break;
	    }
	    case '4':{
			exit(0);
		}
	}
}

void optionStud(){
	char ch;
	int x;
	char c;
	cout<<endl<<"Press any key to continue:";
	c=getch();
	system("cls");
	cout<<"\t\t\t Choose any option: \n";
	cout<<"\t\t1. View book list\n\n";
	cout<<"\t\t2. Request to issue a book\n\n";
	cout<<"\t\t3. Search for a book\n\n";
    cout<<"\t\t4. Close the application\n\n";
    cout<<"\t\t   Enter any option: ";
    cin>>ch;
    
    switch(ch){
	    case '1':{
	    	BookListStud();
           	break;
       	}
        case '2':{
        	ReqBook();
		    break;
	    }
	    case'3':{
	    	cout<<endl<<endl<<"Enter 1 to search by BookID and 2 for searching by Book Name: ";
	    	cin>>x;
	    	if(x==1){
	    		searchBookID();
			}
			else{
				searchBookName();
			}
	        break;
	    }
	    case'4':{
	    	exit(0);
		} 
	}
}

void student(){
	Student Stud;
	string s,d;
	int r,b;
	cout<<"Enter your name: ";
	cin>>s;
	cout<<"Enter your ID: ";
	cin>>r;
	cout<<"Enter your department: ";
	cin>>d;
	cout<<"Enter your batch: ";
	cin>>b;
	Stud.setName(s);
	Stud.setId(r);
	Stud.setDepart(d);
	Stud.setBatch(b);
	Stud.Display();
	optionStud();

}
void lib(){
	Librarian Lib;
	string s,d,u,p;
	string pass,completePass;
	int r;
	cout<<"Enter your name: ";
	cin>>s;
	cout<<"Enter your ID: ";
	cin>>r;
	cout<<"Enter your designation: ";
	cin>>d;
	cout<<"Enter username: ";
	cin>>u;
	cout<<"Enter password: ";
	for(int i=1;i<=4;i++){
		pass=getch();
		cout<<"*";
		completePass+=pass;
	}
	
	cout<<endl<<"Login Successful";
	Lib.setId(r);
	Lib.setName(s);
	Lib.setStatus(d);
	Lib.Display();
	if(u=="admin"&&completePass=="muet"){
		optionLib();
	}
	else{
    	cout<<"Incorrect ID or password Try again!!"<<endl<<endl;
		intro();
	}
	
}
void ReqBook(){
	Student Stud;
	ifstream issue1;
	ofstream issue2;
	string line,word,id;
	vector<string> row;
	char ch;
	cout<<"Enter book id: ";
	cin>>id;
	issue1.open("C:\\Users\\\\OneDrive\\Desktop\\Book4.csv",ios_base::in);
	if(issue1.is_open()){
		while(getline(issue1,line)){
			stringstream str(line);
			row.clear();
			while(getline(str,word,',')){
				row.push_back(word);
			}
			if(id==row[0]){
				issue2.open("C:\\Users\\Desktop\\RequestBook.csv",ios_base::app);
				issue2<<row[0]<<','<<row[1]<<','<<row[2]<<','<<"Initiated"<<Stud.getName()<<"\n";
				issue2.close();
			}
		
		}	
	}
	cout<<endl<<"Return to main menu(y/n)"<<endl;
	cin>>ch;
	if(ch=='y'|| ch=='Y'){
	    system("cls");
	    optionStud();
	}
    else{
	    exit(0);
	}
}
void BookListStud(){
	char c;
	cout<<endl<<"Press any key to continue:";
	c=getch();
	system("cls");
    char ch;
    ifstream read;
	vector<vector<string> > content;
	vector<string> row;
	string line, word;
    cout<<"\t\t\t---***Details of all books in library***---"<<endl;
	
	read.open("C:\\Users\\Desktop\\Book4.csv",ios_base::in);
	if(read.is_open()){
		while(getline(read, line)){
			row.clear();
			stringstream str(line);
			while(getline(str,word,',')){
				row.push_back(word);
			}
			content.push_back(row);
		}
	}

	for(int i=0;i<content.size();i++){
	
		for(int j=0;j<content[i].size();j++)
		{
			cout<<content[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<endl<<"Return to main menu(y/n)"<<endl;
	cin>>ch;
	if(ch=='y'|| ch=='Y'){
	    system("cls");
	    optionStud();
	}
    else{
	    exit(0);
	}
	
}
void BookListLib(){
	char c;
	cout<<endl<<"Press any key to continue:";
	c=getch();
	system("cls");
    char ch;
    ifstream read;
	vector<vector<string> > content;
	vector<string> row;
	string line, word;
	
    cout<<"\t\t\t\t---***Details of all books in library***---"<<endl;
	
	read.open("C:\\Users\\Desktop\\Book4.csv",ios_base::in);
	if(read.is_open()){
		while(getline(read, line)){
			row.clear();
			stringstream str(line);
			while(getline(str,word,',')){
				row.push_back(word);
				
			}
			content.push_back(row);
		}
	}

	for(int i=0;i<content.size();i++){
	
		for(int j=0;j<content[i].size();j++)
		{
			cout<<content[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<endl<<"Return to main menu(y/n)"<<endl;
	cin>>ch;
	if(ch=='y'|| ch=='Y'){
	    system("cls");
	    optionLib();
	}
    else{
	    exit(0);
	}
	
}
void AddBook(){
	Book b1;
	ofstream myFile;

	system("cls");
	char ch;
    cout<<"\n\n\t\t\t***Enter the Details of Books***\n\n"<<endl;
    cout<<"Enter book ID="<<endl;
	cin>>bookID;
	cout<<endl<<"Enter book title="<<endl;
	cin>>title;
	cout<<endl<<"Enter name of author="<<endl;
    cin>>author;
	cout<<endl<<"Enter the edition of book="<<endl;
	cin>>edition;
	cout<<endl<<"Enter the quantity of book="<<endl;
	cin>>quantity;
	    
    b1.setBookID(bookID);
    b1.setAuthor(author);
    b1.setTitle(title);
    b1.setEdition(edition);
    b1.setQuantity(quantity);
    
	myFile.open("C:\\Users\\Desktop\\Book4.csv", ios_base::app);
	myFile<<b1.getBookID()<<','<<b1.getTitle()<<','<<b1.getAuthor()<<','<<b1.getQuantity()<<','<<b1.getEdition();
	myFile.close();
	cout<<endl<<"Book/s entered successfully!!";
    cout<<endl<<"Return to main menu(y/n)"<<endl;
	cin>>ch;
	if(ch=='y'|| ch=='Y'){
	    system("cls");
	    optionLib();
	}
    else{
	    exit(0);
	}
}

void IssueBook(){
	char ch;
	vector<string>row;
	vector<vector<string> >content;
	string line,word,id,status;
	ifstream issue;
	ifstream find;
	ofstream File;

	issue.open("C:\\Users\\Desktop\\RequestBook.csv");
	if(issue.is_open()){
		while(getline(issue,line)){
			row.clear();
			stringstream str(line);
			while(getline(str,word,',')){
				row.push_back(word);
			}
			content.push_back(row);
		}
	}

	for(int i=0;i<content.size();i++){
	
		for(int j=0;j<content[i].size();j++)
		{
			cout<<content[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\nEnter bookID to grant or reject: ";
	cin>>id;
	cout<<endl;
	find.open("C:\\Users\\Desktop\\Book4.csv",ios_base::in);
	
	if(find.is_open()){
		while(getline(find,line)){
			stringstream str(line);
			row.clear();
			while(getline(str,word,',')){
				row.push_back(word);
			}
			if(id==row[0]){
				cout<<"Book ID: "<<row[0];
				cout<<endl<<"Book name is: "<<row[1];
				cout<<endl<<"Author: "<<row[2];
				cout<<endl<<"Quantity: "<<row[3];
				cout<<endl<<"Edition: "<<row[4];
			}
		}
			
	}
	cout<<"\n\nAccepted or Rejected Book: ";
	cin>>status;
	issue.open("C:\\Users\\Desktop\\RequestBook.csv");
	if(issue.is_open()){
		while(getline(issue,line)){
			row.clear();
			stringstream str(line);
			while(getline(str,word,',')){
				row.push_back(word);
			}
			cout<<id<<endl<<row[0];
			if(id==row[0]){
				File.open("C:\\Users\\Desktop\\IssuedBooks.csv",ios_base::app);
				File<<row[0]<<','<<row[1]<<','<<row[2]<<','<<status<<"\n";
				File.close();
			}
		}		
	}	
	cout<<endl<<"Return to main menu(y/n)"<<endl;
	cin>>ch;
	if(ch=='y'|| ch=='Y'){
	    system("cls");
	    optionLib();
	}
    else{
	    exit(0);
	}
}
void searchBookID(){
	system("cls");
	char ch;
	string line,word,id;
	vector<string> row;
	bool found;
	ifstream find;
	cout<<"Enter book id: ";
	cin>>id;
	find.open("C:\\Users\\Desktop\\Book4.csv",ios_base::in);
	
	if(find.is_open()){
		while(getline(find,line)){
			stringstream str(line);
			row.clear();
			while(getline(str,word,',')){
				row.push_back(word);
			}
			if(id==row[0]){
				cout<<"Book ID: "<<row[0];
				cout<<endl<<"Book name is: "<<row[1];
				cout<<endl<<"Author: "<<row[2];
				cout<<endl<<"Quantity: "<<row[3];
				cout<<endl<<"Edition: "<<row[4];
			}
		}	
	}
	cout<<endl<<"Return to main menu(y/n)"<<endl;
	cin>>ch;
	if(ch=='y'|| ch=='Y'){
	    system("cls");
	    optionStud();
	}
    else{
	    exit(0);
	}	
}

void searchBookName(){
	system("cls");
	string line,word;
	char ch;
	char search[100];
	vector<string> row;
	bool found;
	ifstream find;
	cout<<"Enter book name: "<<endl;
	cin.ignore();
	cin.getline(search,100);
	find.open("C:\\Users\\Desktop\\Book4.csv",ios_base::in);
	
	if(find.is_open()){
		while(getline(find,line)){
			stringstream str(line);
			row.clear();
			while(getline(str,word,',')){
				row.push_back(word);
			}
			if(search==row[1]){
				cout<<"Book ID: "<<row[0];
				cout<<endl<<"Book name is: "<<row[1];
				cout<<endl<<"Author: "<<row[2];
				cout<<endl<<"Quantity: "<<row[3];
				cout<<endl<<"Edition: "<<row[4];
			}
		}	
	}
	cout<<endl<<"Return to main menu(y/n)"<<endl;
	cin>>ch;
	if(ch=='y'|| ch=='Y'){
	    system("cls");
	    optionStud();
	}
    else{
	    exit(0);
	}	
}
int main(){
	
	cout<<"\t\t\t\t    ****************************************"<<endl;
	cout<<"\t\t\t\t    ***************WELCOME TO***************"<<endl;
	cout<<"\t\t\t\t    ********LIBRARY MANAGEMENT SYSTEM*******"<<endl;
	cout<<"\t\t\t\t    ****************************************"<<endl<<endl;
	cout<<"\t\t\t\t      Made By: Syeda Anoosha Iqtidar\n\n";
	cout<<"\t\t\t\t      Roll number:21SW004"<<endl<<endl<<endl;
	intro();

	return 0;
}

