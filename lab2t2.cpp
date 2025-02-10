#include<iostream>
using namespace std;
class teamug{
	private:
	string brand;
	string color;
	int capacity;
	int CurrentFillLevel;
	public:
		teamug(string b, string c, int cap, int fill) : brand(b), color(c), capacity(cap), CurrentFillLevel(fill) {}
		
	void siptea(){
		if(CurrentFillLevel!=0){
			--CurrentFillLevel;
			cout<<"sip taken.\n";
		}else{
			cout<<"Refill\n";
		}
	}
	void refill(){
		if(CheckLevel()==0){
			CurrentFillLevel=capacity;
			cout<<"Cup filled to the max capacity: "<<capacity;
		}else{
			cout<<"Not empty, refill failed.\n";
		}
	}
	int CheckLevel(){
		return CurrentFillLevel;
		cout<<CurrentFillLevel;
	}
};
int main(){
	teamug mug1("omicron","Black",8,1);
	mug1.siptea();
	mug1.CheckLevel();
	mug1.refill();
	
}