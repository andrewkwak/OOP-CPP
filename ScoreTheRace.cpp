//Andrew Kwak
//Score the race HW 4

#include <iostream>
using namespace std; 
int main(){

	
	string outcome;
repeat:
do{
	int points['Z'+1]={0};
	int runners['Z'+1]={0};
	int num_runners=0;
	int teams=0;
	double scores['Z'+1]={0};
	double lowest = 100000000;   //just made it an arbitrarily large number that'll never be a possible score for later
	double winner = 0;
	
	
	cout<<"Enter the outcome of the race: ";
	cin>>outcome;
	for(int i = 0;i<outcome.length();i++){
		if(outcome=="done"){
			return 0;
		}
		if(outcome[i]<65 || outcome[i]>90){         //to make sureo only uppercases were typed
			cout<<"Sorry, only uppercases allowed."<<endl;
			goto repeat;
		}
		points[outcome[i]]+=i+1;
		runners[outcome[i]]+=1;
		num_runners =  runners[outcome[i]];         
	}
	for(int i='A';i<='Z';i++){
		if(runners[i]>0){
			if(runners[i]!=num_runners){
				cout<<"Error! Each teams does not have same number of runners."<<endl;
				goto repeat;
			}
		}
	}
	for(int i='A';i<='Z';i++){
		if(points[i]>0){
		scores[i]=points[i] / (double)num_runners;
		teams++;
			if(scores[i]<lowest){                  //this is where I used lowest to determine winner
				winner = i;
				lowest = scores[i];
			}
		}
	}
	
	cout<<"There are "<<teams<<" teams."<<endl;
	cout<<"Each team has "<<num_runners<<" runners."<<endl;
	for(int i='A';i<='Z';i++){
		if(scores[i]>0){
			cout<<(char)i<<": "<<scores[i]<<endl;
		}
	}
	cout<<"The winning team is team "<<(char)winner<<" with a score of "<<lowest<<endl;
}
while(outcome!="done");	

}


