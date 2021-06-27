#include<iostream>
#include <conio.h>
#include<fstream>
#include<cstring>
#include<stack>
#include<queue>
#include <sstream> 
using namespace std;

struct train
{
		string trainid;
		string trainname;
		string departure;
		string arrival;
		string time;
		string type;
		string price;
		string seats;
		train *next;
		train()
		{
			next=NULL;
		}
};


class traindata 
{
	public:
	train *head;
	fstream ofstrain;
	void settrain()
	{
		ofstrain.open("TRAIN.txt",ios::in|ios::out|ios::app);
		do
		{
			string line;
			getline(ofstrain,line);
			if(line.size()!=0)
			{
			    train *data=new train();
				data->trainid=line;
				getline(ofstrain,line);
				data->trainname=line;
				getline(ofstrain,line);
				data->departure=line;
				getline(ofstrain,line);
				data->arrival=line;
				getline(ofstrain,line);
				data->time=line;
				getline(ofstrain,line);
				data->type=line;
				getline(ofstrain,line);
				data->seats=line;
				getline(ofstrain,line);
				data->price=line;
				getline(ofstrain,line);
				if(head==NULL)
				{
					head=data;
					continue;
				}
				train *temp=head;
		        while(temp->next!=NULL)
		        {
			        temp=temp->next;
		        }
			        temp->next=data;	
			}
		}while(!ofstrain.eof());
		
		ofstrain.close();
	}


	void addtrain()
	{
		train *data=new train();
		cout<<"ENTER ID OF THE TRAIN: ";
		cin>>data->trainid;
		train *temp=head;		
		while(temp!=NULL)
		{
			if(temp->trainid==data->trainid)
			{
				cout<<"THIS ID IS ALREADY CHOSEN"<<endl;
				return;
			}
			temp=temp->next;
		}
			int a;
			cout<<"ENTER THE NAME OF TRAIN : ";
			cin>>data->trainname;
			cout<<"ENTER DEPARTURE PLACE : ";
			cin>>data->departure;
			cout<<"ENTER ARRIVAL PLACE : ";
			cin>>data->arrival;
			cout<<"ENTER TIME OF DEPARTURE : ";
			cin>>data->time;
			cout<<"ENTER THE TYPE OF TRAIN :"<<endl;
			cout<<"CHOOSE ONE OPTION : "<<endl;
			cout<<"1-ECONOMY CLASS"<<endl;
			cout<<"2-AC STANDARD"<<endl;
			cout<<"3-AC BUSINESS"<<endl;
			cin>>a;
			while(a>3)
			{
				cout<<"ENTER VALID VALUE";
				cin>>a;
			}
			if(a==1)
			{
				data->type="ECONOMY CLASS";
			}
			else if(a==2)
			{
				data->type="AC STANDARD";
			}
			else if(a==3)
			{
				data->type="AC BUSINESS";
			}
			cout<<"ENTER PRICE PER TICKET : ";
			cin>>data->price;
			cout<<"ENTER TOTAL NUMBER OF SEATS IN THE TRAIN : ";
			cin>>data->seats;		
			if(head==NULL)
			{
				head=data;
				system("cls");
				return;
			}	
			train *temp1=head;
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
			}
			temp1->next=data;
			system("cls");
	}
	
	
	void DisplayTrainData(int check)
	{
		if(check==0)
		{
			int n;
			cout<<"========================================="<<endl;
			cout<<"*******RAILWAY RESERVATION SYSTEM*******"<<endl;
			cout<<"========================================="<<endl;
			cout<<"1-DISPLAY DATA IN DESCENDING ORDER ( USING STACK )"<<endl;
			cout<<"2-DISPLAY DATA IN ASSENDING ORDER ( USING QUEUE )"<<endl;
			cout<<"========================================="<<endl;
			cin>>n;
			if(n==1)
			{
				if(head==NULL)
				{
					cout<<"NO RECORD AVALIABLE !!"<<endl;
					return;
				}
				stack <train*> obj;
			    train *data=head;
				while(data!=0)
			   	{
		    		obj.push(data);
		    		data=data->next;
		    		
		    	}
		    	while(!obj.empty())
				{
					data=obj.top();
                    obj.pop();
                    cout<<endl;
                    cout<<"TRAIN ID :";
					cout<<data->trainid;
					cout<<endl<<"TRAIN NAME : ";
					cout<<data->trainname;
					cout<<endl<<"DEPARTURE : ";
					cout<<data->departure;
					cout<<endl<<"ARRIVAL :";
					cout<<data->arrival;
					cout<<endl<<"TIME :";
					cout<<data->time;
					cout<<endl<<"TYPE :";
					cout<<data->type;
					cout<<endl<<"SEATS :";
					cout<<data->seats;
					cout<<endl<<"PRICE :";
					cout<<data->price;
					cout<<endl;		
					cout<<endl<<endl;
				}	
			}
		
		else if(n==2)
		{
			if(head==NULL)
			{
				cout<<"NO RECORD AVALIABLE !!"<<endl;
				return;
			}
			queue <train*> obj;
		    train *data=head;
			while(data!=0)
		    {
		    	obj.push(data);
		    	data=data->next;		
		    }
		    while(!obj.empty())
			{
				data=obj.front();
                obj.pop();
       		    cout<<endl;
                cout<<"TRAIN ID :";
				cout<<data->trainid;
				cout<<endl<<"TRAIN NAME : ";
				cout<<data->trainname;
				cout<<endl<<"DEPARTURE : ";
				cout<<data->departure;
				cout<<endl<<"ARRIVAL :";
				cout<<data->arrival;
				cout<<endl<<"TIME :";
				cout<<data->time;
				cout<<endl<<"TYPE :";
				cout<<data->type;
				cout<<endl<<"SEATS :";
				cout<<data->seats;
				cout<<endl<<"PRICE :";
				cout<<data->price;
				cout<<endl;
				cout<<endl<<endl;
			}
		}
		else if(n>2)
		{
			cout<<"INVALID ENTRY !"<<endl;
		}
	}
	
	else if(check==1)
	{
		if(head==NULL)
		{
			cout<<"NO DATA AVAILABLE !!"<<endl;
			return;
		}
		train *data=head;
		while (data!=NULL)
		{
			cout<<"TRAIN ID :";
			cout<<data->trainid;
			cout<<endl<<"TRAIN NAME : ";
			cout<<data->trainname;
			cout<<endl<<"DEPARTURE : ";
			cout<<data->departure;
			cout<<endl<<"ARRIVAL :";
			cout<<data->arrival;
			cout<<endl<<"TIME :";
			cout<<data->time;
			cout<<endl<<"TYPE :";
			cout<<data->type;
			cout<<endl<<"SEATS :";
			cout<<data->seats;
			cout<<endl<<"PRICE :";
			cout<<data->price;
		
			cout<<endl<<endl;
			data=data->next;
		}
	}
	
	
	}
	
	
	void searchtrain()
	{
		if(head==0)
		{
			cout<<"NO RECORD AVALIABLE !!"<<endl;
			return;
		}
		string n;
		cout<<"ENTER THE ID OF TRAIN YOU WANT TO SEARCH :";
		cin>>n;
		train *data=head;
		while(data!=NULL)
		{
			if(data->trainid==n)
			{
				cout<<endl<<"TRAIN NAME : ";
				cout<<data->trainname;
				cout<<endl<<"DEPARTURE : ";
				cout<<data->departure;
				cout<<endl<<"ARRIVAL :";
				cout<<data->arrival;
				cout<<endl<<"TIME :";
				cout<<data->time;
				cout<<endl<<"TYPE :";
				cout<<data->type;
				cout<<endl<<"SEATS :";
				cout<<data->seats;
				cout<<endl<<"PRICE :";
				cout<<data->price;
				cout<<endl;
				return;
			}
			data=data->next;
		}
		cout<<"NO RECORD AVAILABLE !!"<<endl;
	}
	
	
	void removetrain()
	{
		if(head==NULL)
		{
			cout<<"NO RECORD AVALIABLE !!"<<endl;
			return;
		}
		string n;
		cout<<"ENTER THE ID OF TRAIN YOU WANT TO DELETE :";
		cin>>n;
		if(head->trainid==n)
		{
			train *temp=head;
			head=head->next;
			cout<<"DELETED SUCESSFULLY !!"<<endl;
			return;
		}
		train *temp=head;
		train *prev;
		while(temp!=NULL)
		{
			if(temp->trainid==n)
			{
				prev->next=temp->next;
				cout<<"DELETED SUCESSFULLY !!"<<endl;
				return;
			}
			prev=temp;
			temp=temp->next;
		}
	}
	
	
	void changetraindata()
	{
		if(head==0)
		{
			cout<<"NO RECORD AVALIABLE !!"<<endl;
			return;
		}
		string n;
		int opt;
		cout<<"ENTER THE ID OF TRAIN TO MAKE CHANGES :" ;
		cin>>n;
		train *data=head;
		while(data!=NULL)
		{
			if(data->trainid==n)
			{
				cout<<"1-CHANGE ID"<<endl;
				cout<<"2 CHANGE NAME"<<endl;
				cout<<"3-CHANGE DEPARTURE"<<endl;
				cout<<"4-CHANGE ARRIVAL"<<endl;
				cout<<"5-CHANGE TIME"<<endl;
				cout<<"6-CHANGE TYPE"<<endl;
				cout<<"7-CHANGE NO. OF SEATS"<<endl;
				cout<<"8-CHANGE TICKET PRICE"<<endl;
				cout<<"9-EXIT"<<endl;
				cin>>opt;
				if(opt==1)
				{
					cout<<"ENTER NEW ID OF TRAIN : ";
					cin>>n;
					data->trainid=n;
				}
				if(opt==2)
				{
					cout<<"ENTER NEW NAME OF TRAIN : ";
					cin>>n;
					data->trainname=n;
				}
				if(opt==3)
				{
					cout<<"ENTER NEW DEPARTURE PLACE : ";
					cin>>n;
					data->departure=n;
				}
				if(opt==4)
				{
					cout<<"ENTER NEW ARRIVAL PLACE : ";
					cin>>n;
					data->arrival=n;
				}
				if(opt==5)
				{
					cout<<"ENTER NEW TIME OF TRAIN : ";
					cin>>n;
					data->time=n;
				}
				if(opt==6)
				{
					cout<<"::ENTER THE TYPE OF TRAIN:"<<endl;
					cout<<"1-ECONOMY CLASS"<<endl;
					cout<<"2-AC STANDARD"<<endl;
					cout<<"3-AC BUSINESS"<<endl;
					cin>>opt;
					while(opt>3)
					{
						cout<<"ENTER VALID VALUE"<<endl;
						cin>>opt;
					}
					if(opt==1)
					{
						data->type="ECONOMY CLASS";
					}
					else
					if(opt==2)
					{
						data->type="AC STANDARD";
					}
					else if(opt==3)
					{
						data->type="AC BUSINESS";
					}
				}
				if(opt==7)
				{
					cout<<"ENTER NEW NO. OF SEATS : ";
					cin>>n;
					data->seats=n;
				}
				if(opt==8)
				{
					cout<<"ENTER NEW TICKET PRICE: ";
					cin>>n;
					data->price=n;
				}
				if(opt==9)
				{
					return;
				}
			}
			data=data->next;
		}			
	}
	
	
	void savetrain()
	{
		ofstream file;
		file.open("temp.txt");
		train *temp=head;
		while(temp!=NULL)
		{
			file<<temp->trainid<<endl;
			file<<temp->trainname<<endl;
		    file<<temp->departure<<endl;
			file<<temp->arrival<<endl;
		    file<<temp->time<<endl;
			file<<temp->type<<endl;
			file<<temp->seats<<endl;
			file<<temp->price<<endl<<endl;
			temp=temp->next;
		}
		file.close();
		remove("TRAIN.txt");
		rename("temp.txt","TRAIN.txt");
	}
};


struct customer
{
	string cid;
	string cname;
	string cnic;
	string cell_number;
	string gender;
	string age;
	string cseats;
	string rute;
	customer *next;
	customer()
	{
		next=NULL;
	}
};


class customerdata : public traindata
{
	public:
	customer *root;
	fstream ofscustomer;
	customerdata()
	{
		head=NULL;
		root=NULL;
	}
	
	
	void setcustomer()
	{
		ofscustomer.open("CUSTOMER.txt",ios::in|ios::out|ios::app);
		
		do
		{
			string line;
		    getline(ofscustomer,line);
			if(line.size()!=0)
			{
			    customer *data=new customer;
				data->cnic=line;
				getline(ofscustomer,line);
				data->cname=line;
				getline(ofscustomer,line);
				data->cell_number=line;
				getline(ofscustomer,line);
				data->age=line;
				getline(ofscustomer,line);
				data->gender=line;
				getline(ofscustomer,line);
				data->cseats=line;
				getline(ofscustomer,line);	
				data->rute=line;
				getline(ofscustomer,line);		
				if(root==NULL)
					{
						root=data;
						continue;
					}
					customer *temp=root;
			        while(temp->next!=NULL)
			        {
				        temp=temp->next;
			        }
			        temp->next=data;	
			}
		}while(!ofscustomer.eof());
		
		
		ofscustomer.close();
	}
	
	
	void addcustomer()
	{
		cin.ignore();
		if(head==NULL)
		{
			cout<<"NO TRAINS AVAILABLE RIGHT NOW !!"<<endl;
			return;
		}
		customer *data=new customer;
		cout<<endl<<endl;
		cout<<"SELECT THE TRAIN ID"<<endl;
		cin>>data->cid;	
		int flag=0;
		train *temp = head;
		while(temp!=NULL)
		{
			if(data->cid==temp->trainid)
			{
				flag=1;	
			}
			temp=temp->next;
		}
		if(flag==0)
		{
			cout<<"ENTER VALID TRAIN ID"<<endl;
			delete temp;
			return;
		}
		cout<<"ENTER NUMBER OF SEATS FOR THE CUSTOMER"<<endl;
		cin>>data->cseats;
		train *temp2 = head;
		while(temp2!=NULL)
		{
			if(data->cid==temp2->trainid)
			{
				int cs,as;
				stringstream geek(data->cseats);
				geek>>cs;
				stringstream geek1(temp2->seats);
				geek1>>as;
				if(cs > as)
				{
					cout<<"NOT ENOUGH SEATS AVAILABE !!"<<endl;
					return;
				}
				else
				{
					as=as-cs;
					ostringstream obj;
					obj<<as;
					temp2->seats=obj.str();
					
					string a="  TO  ";
					data->rute=temp2->departure+a;
					data->rute=data->rute+temp2->arrival;
				}
				
			}
			temp2=temp2->next;
		}
		cout<<"ENTER ENTER CNIC:"<<endl;
		cin>>data->cnic;
		cout<<"ENTER THE NAME OF PASENGER"<<endl;
		cin>>data->cname;
		cout<<"ENTER CELL NUMBER"<<endl;
		cin>>data->cell_number;
		cout<<"ENTER THE AGE OF THE CUSTOMER"<<endl;
		cin>>data->age;
		cout<<"ENTER GENDER M/F"<<endl;
		cin>>data->gender;
		if(root==NULL)
		{
			root=data;
			system("cls");
			return;
		}
		customer *curr=root;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=data;
		system("cls");
	}
	
	
	void DisplayCustomrData()
	{
		
		
		
			int n;
			cout<<"========================================="<<endl;
			cout<<"*******RAILWAY RESERVATION SYSTEM*******"<<endl;
			cout<<"========================================="<<endl;
			cout<<"1-DISPLAY DATA IN DESCENDING ORDER ( USING STACK )"<<endl;
			cout<<"2-DISPLAY DATA IN ASSENDING ORDER ( USING QUEUE )"<<endl;
			cout<<"========================================="<<endl;
			cin>>n;
		
			if(n==1)
			{
				if(root==NULL)
				{
					cout<<"NO RECORD AVALIABLE !!"<<endl;
					return;
				}
				stack <customer*> obj;
		    	customer *data=root;
				while(data!=NULL)
		    	{
		    		obj.push(data);
		    		data=data->next;
		    	}
		    	while(!obj.empty())
				{
					data=obj.top();
                    obj.pop();
                    cout<<endl;
                    cout<<"CNIC : ";
					cout<<data->cnic;
					cout<<endl;
					cout<<"NAME : ";
					cout<<data->cname;
					cout<<endl;
					cout<<"PHONE NUMBER : ";
					cout<<data->cell_number;
					cout<<endl;
					cout<<"AGE OF THE CUSTOMER : ";
					cout<<data->age;
					cout<<endl;
					cout<<"GENDER : ";
					cout<<data->gender;
					cout<<endl;
					cout<<"SEATS : ";
					cout<<data->cseats;
					cout<<endl;
					cout<<"RUTE USEN BY PASSENGER : ";
					cout<<data->rute;		
					cout<<endl<<endl;
				}	
			}
		else if(n==2)
		{
			if(root==NULL)
			{
				cout<<"NO RECORD AVALIABLE !!"<<endl;
				return;
			}
			queue <customer*> obj;
		    customer *data=root;
			while(data!=NULL)
		    {
		    	obj.push(data);
		    	data=data->next;		
		    }
		    while(!obj.empty())
			{
				data=obj.front();
                obj.pop();
       		    cout<<endl;
                cout<<"CNIC : ";
				cout<<data->cnic;
				cout<<endl;
				cout<<"NAME : ";
				cout<<data->cname;
				cout<<endl;
				cout<<"PHONE NUMBER : ";
				cout<<data->cell_number;
				cout<<endl;
				cout<<"AGE OF THE CUSTOMER";
				cout<<data->age;
				cout<<endl;
				cout<<"GENDER : ";
				cout<<data->gender;
				cout<<endl;
				cout<<"SEATS : ";
				cout<<data->cseats;
				cout<<"RUTE USEN BY PASSENGER : ";
				cout<<data->rute;
				cout<<endl;
				cout<<endl<<endl;
			}
		}
		else if(n>2)
		{
			cout<<"INVALID ENTRY !"<<endl;
		}
		
		
	}
	void searchcustomer()
	{
		customer *data=root;
		if(head==NULL)
		{
			cout<<"NO DATA AVAILABLE !!"<<endl;
			return;
		}
		string n;
		cout<<"ENTER THE CNIC OF CUSTOMER YOU WANT TO SEARCH :";
		cin>>n;
		while(data!=NULL)
		{
			if(n==data->cnic)
			{
				cout<<"CNIC : ";
				cout<<data->cnic;
				cout<<endl;
				cout<<"NAME : ";
				cout<<data->cname;
				cout<<endl;
				cout<<"PHONE NUMBER : ";
				cout<<data->cell_number;
				cout<<endl;
				cout<<"AGE OF THE CUSTOMER : ";
				cout<<data->age;
				cout<<endl;
				cout<<"GENDER : ";
				cout<<data->gender;
				cout<<endl;
				cout<<"SEATS : ";
				cout<<data->cseats;
				cout<<"RUTE USEN BY PASSENGER : ";
				cout<<data->rute;
				cout<<endl;
				return;
			}
			data=data->next;
		}
		cout<<"NO RECORD AVAILABLE !!"<<endl;
	}
	
	
	void removecustomer()
	{	
		if(root==NULL)
		{
			cout<<"NO RECORD AVALIABLE !!"<<endl;
			return;
		}
		string n;
		cout<<"ENTER THE CNIC OF THE CUSTOMER YOU WANT TO DELETE :";
		cin>>n;
		if(root->cnic==n)
		{
			root=root->next;
			cout<<"DELETED SUCESSFULLY !!"<<endl;
			return;
		}
		customer *temp=root;
		customer *prev;
		while(temp->next!=NULL)
		{
			if(temp->cnic==n)
			{
				prev->next=temp->next;
				cout<<"DELETED SUCESSFULLY !!"<<endl;
				return;
			}
			prev=temp;
			temp=temp->next;
		}
	}
	
	
	void chanecustomerdata()
	{
		if(head==NULL)
		{
			cout<<"NO RECORD AVAILABLE !!"<<endl;
			return;
		}	
		string n;
		cout<<"ENTER THE CNIC OF THE CUSTOMER YOU WANT TO CHANGE :";
		cin>>n;
		customer *data= root;
		int a;
		while (data!=NULL)
		{
			if(data->cnic==n)
			{
				cout<<"1-NAME OF PASSENGER"<<endl;
				cout<<"2-CEL NUMBER OF THE PASSENGER"<<endl;
				cout<<"3-AGE OF PASSENGER"<<endl;
				cout<<"4-GENDER OF THE CUSTOMER"<<endl;
				cin>>a;
				if(a==1)
				{
					cout<<"ENTER NEW NAME OF PASSENGER : ";
					cin>>n;
					data->cname=n;	
				}
				if(a==2)
				{	
					cout<<"ENTER NEW CELL NO. OF PASSENGER : ";
					cin>>n;
					data->cell_number=n;	
				}
				if(a==3)
				{
					cout<<"ENTER NEW AGE OF PASSENGER : ";
					cin>>n;
					data->cell_number=n;	
				}
				if(a==4)
				{
					cout<<"ENTER NEW GENDER OF PASSENGER : ";
					cin>>n;
					data->gender=n;		
				}
			}
			data=data->next;
		}
	}
	
	
	void savecustomer()
	{
		ofstream file;
		file.open("temp.txt");
		customer *temp=root;
		int i=1;
		while(temp!=0)
		{
			file<<temp->cnic<<endl;
			file<<temp->cname<<endl;
		    file<<temp->cell_number<<endl;
			file<<temp->age<<endl;
		    file<<temp->gender<<endl;
			file<<temp->cseats<<endl;
			file<<temp->rute<<endl<<endl;
			temp=temp->next;
		}
		file.close();
		remove("CUSTOMER.txt");
		rename("temp.txt","CUSTOMER.txt");
	}
	
	
	void restore_default()
	{
		remove("CUSTOMER.txt");
		remove("TRAIN.txt");
	}
	
};


int main()
{
	customerdata obj;
	obj.setcustomer();
	obj.settrain();
	int check;;
	string adminpass="1234";
	string adminname="faizan";
	string userpass="4321";
	string user_name="faizan";
	string username,password;
	int a;
	
	
	while(a!=3)
	{
		system("color 0a");
		cout<<"\t\t\t\t****************************************"<<endl;
		cout<<"\t\t\t\t\t*******RAILWAY RESERVATION SYSTEM*******"<<endl;
		cout<<"\t\t\t\t\t****************************************"<<endl;
		cout<<endl;
		cout<<"\t\t\t\t\t1-LOGIN AS ADMIN"<<endl;
		cout<<"\t\t\t\t\t2-LOGIN AS USER"<<endl;
		cout<<"\t\t\t\t\t3-EXIT"<<endl;
		cout<<endl;
		cout<<"\t\t\t\t\t****************************************"<<endl;
		cout<<"\t\t\t\t\t\t";
		cin>>a;
		system("cls");
		
		
		if(a==1)
		{
		do
		{  
			system("color 0b");
			cout<<endl;
			cout<<"\t\t\t\t\t\tENTER USERNAME "<<endl<<"\t\t\t\t\t\t\t";
	    	cin>>username;
	    	system("cls");
	    	if(username!=adminname)
	    	{
	    		cout<<endl<<"\t\t\t\t\t\t   USERNAME DOESNOT MATCH !"<<endl;
			}
		}while(username!=adminname);
		
		
		do
		{
			string password1;
			char ch;
		    cout<<endl<<"\t\t\t\t\t\t   ENTER PASSWORD :"<<endl<<"\t\t\t\t\t\t        ";
		    ch=_getch();
		    while(ch!=13)
		    {
	    		password1.push_back(ch);
	    		cout<<"*";
	    		ch=_getch();
			}
	    	system("cls");
			if(password1!=adminpass)
			{
			    cout<<endl<<"\t\t\t\t\t\tPASSWORD DOESNOT MATCH !"<<endl;
			}
			else 
			break;
			password=password1;
		}while(password!=adminpass);
		
		
		while(check!=9)
		{
			if(a==1)
			{
				system("color 0e");
				cout<<"========================================="<<endl;
				cout<<"*******RAILWAY RESERVATION SYSTEM*******"<<endl;
				cout<<"========================================="<<endl;
				cout<<"1-ADD TRAINS TO STSTEM"<<endl;
				cout<<"2-BOOK TICKETS"<<endl;
				cout<<"3-VIEW TRAIN DATA AVAILABLE"<<endl;
				cout<<"4-VIEW CUSTOMER DATA AVAILABLE"<<endl;
				cout<<"5-SEARCH TRAIN"<<endl;
				cout<<"6-SEARCH CUSTOMER"<<endl;
				cout<<"7-SETTING"<<endl;
				cout<<"8-SIGN OUT"<<endl;
				cout<<"9-EXIT APPLICATION"<<endl;
				cout<<"========================================="<<endl;
				cin>>check;
				system("cls");
				
				if(check==1)
				{
					obj.addtrain();
				}
				else if(check==2)
				{
					obj.DisplayTrainData(1);
					cout<<"SELECT ID BETWEEN ABOVE TRAINS"<<endl<<endl;
					 obj.addcustomer();
				}				
				else if(check==3)
				{
					obj.DisplayTrainData(0);
				}
				else if(check==4)
				{
					obj.DisplayCustomrData();
				}
				else if(check==5)
				{
					obj.searchtrain();
				}
				else if(check==6)
				{
					obj.searchcustomer();
				}
				else if(check==8)
				{
					break;
				}
				else if(check==9)
				{
					obj.savetrain();
					obj.savecustomer();
					system("cls");
					cout<<endl;
					break;	
				}
				else if(check==7)
				{
					int a1;
					while(a1!=6)
					{
						cout<<"========================================="<<endl;
						cout<<"*******RAILWAY RESERVATION SYSTEM*******"<<endl;
						cout<<"========================================="<<endl;
						cout<<"1-CANCEL TRAIN"<<endl;
						cout<<"2-CANCEL BOOKING"<<endl;
						cout<<"3-EDIT CUSTOMER DATA"<<endl;
						cout<<"4-EDIT TRAIN DATA"<<endl;
						cout<<"5-RESTORE TO DEFAULT"<<endl;
						cout<<"6-EXIT TO MAIN MENU"<<endl;
						cout<<"========================================="<<endl;
						cin>>a1;
						system("cls");
						if(a1==1)
						{
							 obj.removetrain();
						}
						else if(a1==2)
						{
							obj.removecustomer();
						}
						else if(a1==3)
						{
							obj.chanecustomerdata();
						}
						else if(a1==4)
						{
							obj.changetraindata();
						}
						else if(a1==5)
						{
							obj.restore_default();
						}
						else if(a1==6)
						{
							break;
						}
					}
			
				}
			}
		}
		}
			else if(a==2)
			{
				do
			{
				system("color 0b");  
				cout<<endl;
				cout<<"\t\t\t\t\t\t\tENTER USERNAME"<<endl<<"\t\t\t\t\t\t\t";
		    	cin>>username;
		    	system("cls");
		    	if(username!=user_name)
		    	{
		    		cout<<endl<<"\t\t\t\t\t\tPASSWORD DOESNOT MATCH !"<<endl;
				}
			}while(username!=user_name);
			
				
			do
			{
				string password1;
				char ch;		
			    cout<<endl<<"\t\t\t\t\t\tENTER PASWORD :"<<endl<<"\t\t\t\t\t\t        ";
			    ch=_getch();
			    while(ch!=13)
			    {
		    		password1.push_back(ch);
		    		cout<<"*";
		    		ch=_getch();
				}
		    	system("cls");
				if(password1!=userpass)
				{
				    cout<<endl<<"\t\t\t\t\t\tPASSWORD DOESNOT MATCH !"<<endl;
				}
				password=password1;
			}while(password!=userpass);
			
		
			while(check!=7)
			{	
				system("color 0e");
				cout<<"========================================="<<endl;
				cout<<"*******RAILWAY RESERVATION SYSTEM*******"<<endl;
				cout<<"========================================="<<endl;
				cout<<"1-BOOK TICKETS"<<endl;
				cout<<"2-VIEW TRAIN DATA AVAILABLE"<<endl;
				cout<<"3-VIEW CUSTOMER DATA AVAILABLE"<<endl;
				cout<<"4-SEARCH TRAIN"<<endl;
				cout<<"5-SEARCH CUSTOMER"<<endl;
				cout<<"6-SIGN OUT"<<endl;
				cout<<"7-EXIT APPLICATION"<<endl;
				cout<<"========================================="<<endl;
				cin>>check;
				system("cls");
				if(check==1)
				{
					obj.DisplayTrainData(1);
					cout<<"SELECT ID BETWEEN ABOVE TRAINS"<<endl<<endl;
					obj.addcustomer();
				}
				if(check==2)
				{
					obj.DisplayTrainData(0);
				}
				if(check==3)
				{
					obj.DisplayCustomrData();
				}
				if(check==4)
				{
					obj.searchtrain();
				}
				if(check==5)
				{
					obj.searchcustomer();
				}
				if(check==6)
				{
					break;
				}		
				if(check==7)
				{
					obj.savetrain();
					obj.savecustomer();
					system("cls");
					cout<<endl;
					break;
				}
			}
		}
	
	
		if(a==3)
		{
			break;
		}	
		else if(check==9 || check==7)
		{
			break;
		}		
	}			
}
