#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


// Function Prototypes
double getPricePerGallon();
int getRooms();
int calcWallSpace(int);
void calcPaint(int, double, int&, double&);
void calcLabor(int, double&, double&);



int main()
{
	// Constant and variables
	int rooms;			// Number of rooms
	int sqrFeet;		// Total Square feet of walls
	double pricePaint;	// Price of paint per gallon
	int gallons;
	double pcost;
	double lcost;
	double hours;
	double totalCost;


	// Intro
	cout << "Paint Job Estimator ...\n\n";
	
	// Prompt user for price
	pricePaint = getPricePerGallon();
	
	// Prompt user for number of rooms
	rooms = getRooms(); 
	
	// Prompt user and calculate total square feet
	sqrFeet = calcWallSpace(rooms);

	// Display Estimates
	cout << "\n\n\tPaint Job Estimate" << endl << endl;
	
	calcPaint(sqrFeet, pricePaint, gallons, pcost);

	calcLabor(sqrFeet,hours, lcost);

	totalCost = pcost + lcost;

	cout << "\t\t\t----------" << endl << "Total Cost: \t\t$ " << totalCost;

	return(0);
}

double getPricePerGallon()
{
	double pricePaint;

	do
	{
		cout << "Price per gallon of paint (>=0): ";
		cin >> pricePaint;
		
		if (pricePaint < 0) // Validation
			cout << "Error ... Invalid price per gallon of paint. Try again.\n";

	} while (pricePaint < 0);
	return pricePaint;
}

int getRooms()
{
	int rooms;
	do
	{
		cout << "\nNumber of rooms to be painted (>=1): ";
		cin >> rooms;

		if (rooms < 1) // Validation
			cout << "Error ... Invalid number of rooms. Try again.";

	} while (rooms < 1);
	return rooms;
} 

int calcWallSpace(int r)
{
	int measurement;
	int sqrFeet = 0;
	int i;

	cout << "\nSquare feet of wall space (>=25)\n";
	
	// ask for rooms
	for (i = 1; i <= r; i++)
		do
		{			
			cout << "\t Room " << i << ": ";
			cin >> measurement;
						
			if (measurement < 25) // Validation
				cout << "\t Error ... Incorrect wall space for the room. Try again.\n";
			
			// Update total square feet
			sqrFeet += measurement;

		} while (measurement < 25);

				
		// Increment counter
		i++;
	return sqrFeet;
}

void calcPaint(int sqrFeet, double pricePaint, int& gallons, double& pcost)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Paint ...\n";
	gallons = sqrFeet / 115;
	cout << "Gallons of Paint: \t" << gallons << endl;

	pcost = gallons * pricePaint;
	cout << "Cost of Paint: \t\t$ " << pcost << endl << endl;

	return;
}

void calcLabor(int sqrFeet, double& hours, double& lcost)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Labor ...\n";
	hours = (sqrFeet * 8) / 115;
	cout << "Hours of Labor: \t" << hours << endl;

	lcost = (hours * 200) / 8;
	cout << "Cost of Labor: \t\t$ " << lcost << endl;

	return;
}
