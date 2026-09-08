// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.
#include<iostream>
using namespace std;

int main(){
int initial_population = 312032486 ;

int births, deaths, immigrants;
int seconds_in_year = 365*24*60*60;

// births deaths and immigrants per year
 births = seconds_in_year/7;
 deaths = seconds_in_year/13;
 immigrants = seconds_in_year/45;
 int pop_change = births-deaths+immigrants;

 //dispalying for next 5 years
 for(int i = 1; i<6; i++){
   int population = initial_population + i*(pop_change);
    cout<<"population for year "<< i <<" is "<< population<<" \n";
 }




    return 0;
}

