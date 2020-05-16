#include <iostream> //header files
using namespace std;
class ticket //declaration of class
{
	
	public: string source[100];
	public: string destination[100];
	public: int passenger[100];
	public: int count=0;
	public: int Distance(int dis[], int i, int j);  // to calculate the distance between source and destination 
	public: void print(string arr[],int a, int b);  // to print any array for a given starting index to a given ending index
	public: int cost(int d);  //to calulate the cost for the given distance
	public: void ticketPrint(int d, int c,int p, string r[],int x, int y);  // to print the ticket
	public: void data(int x, int y, int p,string route[]); 	//to store the printed ticket in the records.
};

int ticket :: Distance(int dis[], int i, int j){
	int d=0;
	for(int a=i;a<j;a++)
	d=d+dis[a];
	
	return(d);
}

void ticket:: print(string arr[],int a, int b){
	for(int i=a;i<b;i++)
	cout<<i<<" "<<arr[i]<<endl;
}

int ticket::cost(int d){
	cout<<"-------------------------"<<endl;
	cout<<"Select the type of bus."<<endl;
	cout<<"1 for AC Bus"<<endl;
	cout<<"2 for Non-AC Bus"<<endl;
	cout<<"-------------------------"<<endl;
	int o,c;
	cin>>o;
	if(o==1){
		c=d*1.5;
	}
	else if(o==2){
		c=d*3;
	}
	return(c);
}
void ticket::data(int x, int y, int p, string route[])
{
	source[count]=route[x];
	destination[count]=route[y];
	passenger[count]=p;
}
void ticket:: ticketPrint(int dx,int c,int p,string r[], int x, int y){
	cout<<"Ticket Invoice"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Source: "<<r[x]<<endl;
	cout<<"Destination: "<<r[y]<<endl;
	cout<<"Distance: "<<dx<<endl;
	cout<<"Cost: "<<endl;
	cout<<"Total Cost: "<<p<<" X "<<c<<"="<<p*c<<endl;
	cout<<""<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"HAVE A HAPPY AND SAFE JORUNEY!"<<endl;
	cout<<"-------------------------"<<endl;
	++count;
}
int main() {
	cout << "Welcome to Bus Ticket Counter\n";
	string route1[10]={"Hoshiarpur","Mahilpur","Saila Khurd","Garhshankar","Balachaur","Ropar","Kurali","Kharar","Mohali","Chandigarh"};
	int dis1[9]={23,8,12,25,25,16,13,9,4};
	
	ticket obj;
	cout<<"The Route is: "<<endl;
	obj.print(route1,0,10);
	cout<<"Choose source"<<endl;
	int x,y; cin>>x;
	cout<<"Choose destination"<<endl;
	obj.print(route1,x,10);
	cin>>y; 
	int di=obj.Distance(dis1,x,y);
	int ct=obj.cost(di);
	cout<<"Enter the number of passengers"<<endl;
	int p;cin>>p;
	obj.ticketPrint(di,ct,p,route1,x,y);
	obj.data(x,y,p,route1);
	return(0);
}


