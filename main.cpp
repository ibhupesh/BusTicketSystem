#include <iostream> //header files
using namespace std;
class ticket //declaration of class
{
	string route1[10]={"Hoshiarpur","Mahilpur","Saila Khurd","Garhshankar","Balachaur","Ropar","Kurali","Kharar","Mohali","Chandigarh"};
	int dis1[9]={23,8,12,25,25,16,13,9,4};
	
	public: int Distance(int dis[], int i, int j);  // to calculate the distance between source and destination 
	public: void print(int arr[],int a, int b);  // to print any array for a given starting index to a given ending index
	public: int cost(int d);  //to calulate the cost for the given distance
	public: void ticketPrint(int d, int c, string r[],int x, int y);  // to print the ticket
	public: void data(int x, int y, int c); 	//to store the printed ticket in the records.
};

int ticket :: Distance(int dis[], int i, int j){
	int d=0;
	for(int a=i;a<j;a++)
	d=d+dis[a];
	
	return(d);
}

void ticket:: print(int arr[],int a, int b){
	for(int i=a;i<b;i++)
	cout<<i<<" "<<arr[i]<<endl;
}

int ticket::cost(int d){
	cout<<"Select the type of bus."<<endl;
	cout<<"1 for AC Bus"<<endl;
	cout<<"2 for Non-AC Bus"<<endl;
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
void ticket:: ticketPrint(int dx,int c,string r[], int x, int y){
	cout<<"Ticket Invoice"<<endl;
	
}

int main() {
	cout << "Welcome to Bus Ticket Counter\n";
}
