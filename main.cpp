#include <iostream> //header files
#include<fstream>
using namespace std;
class ticket //declaration of class
{
	
	public: string source[100];
	public: string destination[100];
	public: int passenger[100];
	public: ofstream myFile;
	public: int Distance(int dis[], int i, int j);  // to calculate the distance between source and destination 
	public: void print(string arr[],int a, int b);  // to print any array for a given starting index to a given ending index
	public: int cost(int d);  //to calulate the cost for the given distance
	public: void ticketPrint(int d, int c,int p, string r[],int x, int y);  // to print the ticket
	public: void copystr(string a[],string b[]); //to copy string array
	public: void copyint(int a[],int b[]); //to copy integer array
};

int ticket :: Distance(int dis[], int i, int j){ //it takes an array which has distance between the stops along with the source and destination index.
	int d=0;
	for(int a=i;a<j;a++)
	d=d+dis[a];
	
	return(d);
}

void ticket:: print(string arr[],int a, int b){ // this array is to print the array from its starting index to the given last index
	for(int i=a;i<b;i++)
	cout<<i<<" "<<arr[i]<<endl;
}

int ticket::cost(int d){  
	cout<<"-------------------------------------------"<<endl;
	cout<<"Select the type of bus."<<endl;   // two types of buses so the user has to choose the type of bus
	cout<<"1 for AC Bus (Rs.3 per Km)"<<endl;
	cout<<"2 for Non-AC Bus(Rs. 1.5 per Km)"<<endl;
	cout<<"-------------------------------------------"<<endl;
	int o,c;
	cin>>o;
	if(o==1){
		c=d*1.5;
	}
	else if(o==2){
		c=d*3;
	}
	else{
	cout<<"Wrong Choice"<<endl;
	}
	return(c);
}
void ticket:: ticketPrint(int dx,int c,int p,string r[], int x, int y){ // this function is used to print the ticket invoice.
	cout<<"-------------------------------------------"<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"Ticket Invoice"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Source: "<<r[x]<<endl;
	cout<<"Destination: "<<r[y]<<endl;
	cout<<"Distance: "<<dx<<endl;
	cout<<"Cost: Rs."<<c<<endl;
	cout<<"Total Cost: "<<p<<" X Rs."<<c<<"= Rs."<<p*c<<endl;
	cout<<""<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"HAVE A HAPPY AND SAFE JORUNEY!"<<endl;
	cout<<"-------------------------"<<endl;
	myFile.open("Tickets.csv",ios::app);
	myFile<<r[x]<<","<<r[y]<<","<<dx<<","<<c<<","<<p<<","<<p*c<<endl;
	
	
}
void ticket::copystr(string a[], string b[]){
	//this array is to copy a string array into another arrray
	for(int i=0;i<10;i++){
		b[i]=a[i];
	}
}

void ticket::copyint(int a[], int b[]){
	//this array is to copy an integer array into another array
	for(int i=0;i<9;i++){
		b[i]=a[i];
	}
}
int main() {
	ticket obj;
	int ti;
	ifstream File;
	cout<<"*******************************************\n\n"<<endl;
	cout << "Welcome to Bus Ticket System \n ";
	cout<<"-------------------------------------------"<<endl;
	cout<<"-------------------------------------------"<<endl;
	string route1[10]={"Hoshiarpur","Mahilpur","Saila Khurd","Garhshankar","Balachaur","Ropar","Kurali","Kharar","Mohali","Chandigarh"};
		int dis1[9]={23,8,12,25,25,16,13,9,4};
		string route2[10]={"Chnadigarh","Mohali","Kharar","Kurali","Ropar","Balachaur","Garhshankar","Saila Khurd","Mahilpur","Hoshiarpur"};
		int dis2[9]={4,9,13,16,25,25,12,8,23};
		string route3[10]={"Chandigarh","Zirakpur","Airport Lights","Banur","Chitkara", "Rajpura","Patiala Toll","Bahadurgarh","Punjabi Uni.","Patiala"};
		int dis3[9]={13,5,20,9,8,15,3,3,7};
		string route4[10]={"Patiala","Punjabi Uni.","Bahadurgarh","Patiala Toll","Rajpura","Chitkara","Banur","Airport Lights","Zirakpur","Chandigarh"};
		int dis4[9]={7,3,3,15,8,9,20,5,13};
		int x,y,k,di,ct,p;
		string route[10];
		int dis[9];
	
	cout<<"1. To get the ticket"<<endl;
	cout<<"2. To get the ticket history"<<endl;
	cin>>ti;
	
	switch(ti)
	{
		
	case 1:
		cout<<"-------------------------------------------"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"Choose your route"<<endl;
		cout<<"1 Hoshiarpur to Chandigarh"<<endl;
		cout<<"2 Chandigarh to Hoshiarpur"<<endl;
		cout<<"3 Chandigarh to Patiala"<<endl;
		cout<<"4 Patiala to Chandigarh"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cin>>k;
		if(k==1){
		obj.copystr(route1,route);
		obj.copyint(dis1,dis);
		}
		else if(k==2){
		obj.copystr(route2,route);
		obj.copyint(dis2,dis);
		}
		else if(k==3){
		obj.copystr(route3,route);
		obj.copyint(dis3,dis);
		}
		else if(k==4){
		obj.copystr(route4,route);
		obj.copyint(dis4,dis);
		}
		else cout<<"!!!!!!WRONG INPUT!!!!!!!"<<endl;
		
		cout<<"-------------------------------------------"<<endl;
		cout<<"The Route is: "<<endl;
		obj.print(route,0,10);
		cout<<"-------------------------------------------"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"Choose source"<<endl;
		cin>>x;
		cout<<"-------------------------------------------"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"Choose destination"<<endl;	
		obj.print(route,x+1,10);
		cout<<"-------------------------------------------"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cin>>y; 
		di=obj.Distance(dis,x,y);
		ct=obj.cost(di);
		cout<<"Enter the number of passengers"<<endl;
		p;cin>>p;
		cout<<"-------------------------------------------"<<endl;
		cout<<"-------------------------------------------"<<endl;
		obj.ticketPrint(di,ct,p,route,x,y);
		
	break;
	
	case 2 :
		File.open("Tickets.csv");
		while(File.good()){
			string line;
			getline(File,line,'\n');
			cout<<"\n"<<line;
			
		}
		File.close();
		break;
		
	default:
		cout<<"WRONG INPUT!!"<<endl;
	}
	cout<<"\n\n*******************************************"<<endl;
	return(0);
}
