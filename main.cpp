#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "abc123#";
const char* DB = "mydb";

class Login{
	private:
		string Id, PW;
	public:
	Login(): Id(""), PW("") {	}
	
	void setId(string id){
		Id = id;
	}
	
void setPW(string pw){
 PW = pw;
}

string getId(){
 return Id;
}


string getPW(){
 return PW;
}
	
};


int main() {
	Login l;

MYSQL* conn;

conn = mysql_init(NULL);

if(!mysql_real_connect(conn, HOST,USER,PW,DB,3306,NULL,0)){
	cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
 cout<<"Logged In Database!"<<endl;
}
Sleep(3000);
bool exit = false;
while(!exit){
	system("cls");
cout<<"1. Signup."<<endl;
cout<<"2. Login."<<endl;
cout<<"0. Exit."<<endl;	
cout<<"Enter choice: ";
int val;
cin>>val;

cout<<endl;

if(val==1){
system("cls");
 string id, pw;
		
 cout<<"Enter Email or Phone Number: ";
 cin>>id;
 l.setId(id);
 
  cout<<"Enter A Strong Password: ";
 cin>>pw;
 l.setPW(pw);
 
string Sup = "INSERT INTO password (Id, PW) VALUES ('"+l.getId()+"', '"+l.getPW()+"')";
if(mysql_query(conn,Sup.c_str())){
 cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
 cout<<"Signup Successfuly"<<endl;
}
Sleep(3000);	
}//if 1

else if(val==2){
	system("cls");
	 string id,pw;
	
 cout<<"Enter ID: ";
 cin>>id;
	
 cout<<"Enter Your password: ";
 cin>>pw;
 
string Sin= "SELECT Id,PW FROM password WHERE Id ='"+id+"' AND PW= '"+pw+"' ";

if(mysql_query(conn,Sin.c_str())){
 cout<<"Error: "<<mysql_error(conn)<<endl;
}
else{
MYSQL_RES* res;
res= mysql_store_result(conn);
if(res){
int row = mysql_num_rows(res);
if(row==1){
	cout<<"Welcome"<<endl;
	Sleep(3000);
}
else if(row==0){
	cout<<"Incorrect ID Or Password. Try Again!"<<endl;
	Sleep(3000);
}
}
}
}

else if(val==0){
	exit = true;
	cout<<"Bye!"<<endl;
	Sleep(3000);
}
else{
	cout<<"Invalid Input"<<endl;
	Sleep(3000);
}
}//while

	return 0;
}

