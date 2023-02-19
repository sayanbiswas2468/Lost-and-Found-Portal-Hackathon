#include<iostream>
#include<string>
#include<fstream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

using namespace std;
bool process = true;

void showMissingItems(){
	vector<string> v;
		string line;
	fstream f("missingItems.txt",ios::in);
	if(f.is_open()){
		getline(f,line);
		while(f){
		
			v.push_back(line);
			getline(f,line);
		}
		f.close();

			for(int i =0;i<v.size();i++){
			cout<<'\t'<< i+1<<". "<<v[i]<<endl;
		}
	}
	else{
		cout<<endl<<"\tNo missing items!! "<<endl;
	}

		
}
vector<string> readItemFile(string item){
	fstream f(item,ios::in);
	vector<string> v;
	string line = "Owner details not available ";
		if(f.is_open()){
		getline(f,line);
		while(f){
		
			v.push_back(line);
			getline(f,line);
		}
		f.close();

		
		
	}
	else{
		cout<<endl<<"\tNo Owner Found!! "<<endl;
	}
	return v;
	
}

void sendNotification(string owner,string founder,string contact,string item,string ownerName){
	string notify = "Hey "+ownerName+", Your missing "+item+" has been found by "+founder+" his contact number is "+contact+"(issue resolved)";
	
	string ownerAcc =  owner+".txt";
	fstream f(ownerAcc,ios::app | ios::out);
	if(f.is_open())	{
		f.put('\n');
		for(int i =0;notify[i]!='\0';i++)
		f.put(notify[i]);
		f.put('\n');
		
		
	}
	f.close();
}
void foundForm(){
	
	system("cls");
	cout<<endl;
		printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MISSING ITEM FORM ";
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB");
	cout<<endl<<endl;
	showMissingItems();
    string temp1;
    string temp2;
    string temp3;
    string founder,contact;
    string none;
    cout<<endl<<endl<<"\tPlease Enter the below details carefully..."<<endl; 
 
    cout<<"\tYour Name : ";
    cin>>founder;
    cout<<"\tYour Contact Number : ";
    cin>>contact;
    cout << "\tWhat is the item you found?(Enter full name from the menu) : ";
    cin >> temp1;
    //open the name of user who reported that item
    string item = temp1 + ".txt";
    vector<string> v= readItemFile(item);
    string ownerID = v[0];
    string ownerName = v[1];
    
    cout<<endl<<endl;
    cout<<"\tThis product is of : "<<ownerName<<endl;
	cout<<"\tWe will notify him regarding this, you may get a call from him"<<endl;
	cout<<"\tThanks for helping :)"<<endl;
    sendNotification(ownerID,founder,contact,temp1,ownerName);
    getch();
    
    


	
	
}


void createItemFile(string name,string itemName,string place,string status,string contact,string owner,string ownerName){
		fstream f(itemName,ios::out | ios::app);
	if(f.is_open()){
		for(int i =0;owner[i]!='\0';i++){
			f.put(owner[i]);
		}
		f.put('\n');
		for(int i =0;ownerName[i]!='\0';i++){
			f.put(ownerName[i]);
		}
		f.put('\n');
		for(int i =0;contact[i]!='\0';i++){
			f.put(contact[i]);
		}
		f.put('\n');
		for(int i =0;name[i]!='\0';i++){
			f.put(name[i]);
		}
		f.put('\n');
		for(int i =0;place[i]!='\0';i++){
			f.put(place[i]);
		}
		f.put('\n');
		for(int i =0;status[i]!='\0';i++){
			f.put(status[i]);
		}
	}
	
}

void missingForm(){
	system("cls");
	cout<<endl;
		printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MISSING FORM ";
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB");
	cout<<endl<<endl;
	string userName,userNumber,name,place,userNName;
	cout<<"\tEnter registration Number:  ";
	cin>>userName;
	cout<<"\tEnter Your Name:  ";
	cin>>userNName;
	cout<<"\tEnter Your contact : ";
	cin>>userNumber;
	cout<<"\tEnter the Lost item name: ";
	cin>>name;
	cout<<"\tEnter the Location of missing item: ";
	cin>>place;
	system("cls");
	fstream f("missingItems.txt",ios::out | ios::app);
	if(f.is_open()){
	for(int i =0;name[i]!='\0';i++)
	f.put(name[i]); 
	f.put('\n');
	}
	else{
		cout<<"Not found missing tems";
	}
	string status = "Not found";
	string itemName = name+".txt";
	
		          
		               
		cout<<endl<<endl<<"\t\tYour missing report is submitted"<<endl;
		cout<<"\t\tWe will notify you if found anything..."<<endl;
		cout<<endl<<"\t\tPress any key to continue..";
		getch();
		
		createItemFile(name,itemName,place,status,userNumber,userName,userNName);
}
	
	
	
	

void reportMenu(){
	
	while(process){
		system("cls");
		cout<<endl;
		printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MISSING ITEMS PORTAL ";
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB");
	cout<<endl<<endl;
	
	cout<<"\t1. Report the missing item"<<endl;
	cout<<"	2. Report the Found item"<<endl;
	cout<<"\t3. exit"<<endl<<endl;
	int n;
	cout<<"\tEnter your choice : ";
	cin>>n;
	switch(n){
		case 1:
			missingForm();
			break;
		
		case 2:
			foundForm();
			break;
		case 3:
			exit(1);
			break;
	
		default:
			
			break;
		
	}
		
	}
	
}
void report(vector<string> v){
printf("\n\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB WELCOME " <<v[2];
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\xDB\xDB\xDB\xDB\xDB\xDB");
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t\tHOME"<<endl<<endl;
	for(int i =0;i<v.size();i++){
		cout<<"\t"<<v[i]<<endl;
	}
	if(v.size()==4){
		cout<<endl<<"/tNo Reports yet "<<endl;
	}
	
	cout<<"             -------------------------------------             ";
	cout<<endl;
	cout<<"\tBelow are the Items Missing Please report if found anything"<<endl<<endl;
	
	
	showMissingItems();
	cout<<endl<<endl;
	cout <<"\tPress any key to report section...";
	getch();
	
	
	reportMenu();


	
}
void login(){
	string name;
	string pass;
	cout<<endl<<endl;
	cout<<"			 	=============================================="<<endl;
	cout<<"         			 		Missing Items Portal    "<<endl;
	cout<<"		    		=============================================="<<endl;
	cout<<endl;
	cout<<endl<<endl<<endl;
	cout<<"				    Regitration Number : ";
	cin>>name;
	cout<<endl;
	cout<<"				   	DOB(XX-Mon-XX) : ";
	cin>>pass;
	string accName = name+".txt";
	fstream f(accName,ios::in);
	string line;
	vector<string> v;
	if(f.is_open()){
		
		getline(f,line);
		while(f){
//			cout<<line<<endl;
			v.push_back(line);
			getline(f,line);
		}
		f.close();
		
		if(pass != v[1]){
			cout<<endl<<endl<<"\a\t\tWrong Password!";
			cout<<endl<<"\t\tPress any Key to exit the program...";
			
			getch();
			cout<<endl<<endl;
			exit(1);
		}else{
			system("cls");
				report(v);
		}
	}
	else{
		
		cout<<endl<<endl<<"\a\t\tUser dont exist!";
		cout<<endl<<"\t\tPress any Key to exit the program...";
		
		getch();
		cout<<endl<<endl;
	}
	system("cls");
	
          

	  
}

int main(){

	login();
	return 0;
	
}

          