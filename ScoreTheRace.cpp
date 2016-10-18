//Andrew Kwak
//Score the race 
//
//Some number of teams are participating in a race. You are not told how many teams are participating but
// you do know that:
//  Each team has a name, which is one of the uppercase letters A-Z.
//  No two teams have the same name, so there are a maximum number of 26 teams.
//  Each team has the same number of members.
//  No two runners cross the finish line at the same time – i.e. there are no ties.
// At the end of the race we can write the results as a string of characters indicating the order in which
// runners crossed the finish line.
// For example: ZZAZAA
// We can see there were two teams: A and Z. Team A’s runners finished in 3rd, 5th and 6th place. Team Z’s
// runners finished in 1st, 2nd and 4th place.
// Scoring the race
// Each runner is assigned a score equal to their finishing place. In the example above team Z’s runners
// achieved scores of 1, 2 and 4. Team A’s runners scores were 3, 5, and 6 respectively.
// The team’s score is the sum of the members score divided by the number of people on the team. So team
// A’s score is (3+5+6)/3 = 14/3=4.66 and team Z’s score is (1+2+4)/3=7/3=2.33

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


