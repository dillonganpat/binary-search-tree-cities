//816044402 
//DILLON GANPAT 




#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Data.h"
using namespace std;

#define QUIT 99


void displayCity (City city) {
	cout << "NAME: " << city.name << endl;
    cout << "LATITUDE: " << city.latitude << endl;
    cout << "LONGITUDE: " << city.longitude << endl;
    cout << "COUNTRY: " << city.country << endl;
    cout << "COUNTRY CODE: " << city.country_iso2 << endl;
    cout << "POPULATION: " << city.population << endl;
}


int main () {
	int choice;
	char fileName [25] = "worldcities.txt";
	char commandsFile [25] = "Commands.txt";
	ifstream inputFile;
	int command;
	int numcities;
	City city;

	BTNode * root = initBSTFromFile (fileName);
	
	cout << endl;	
	cout << "--> Processing commands from commands file ..."  << endl;
		
	inputFile.open(commandsFile);
	
	if (!inputFile.is_open()) {
		cout << "--> Commands file could not be opened. Aborting ..." << endl;
		exit (1);
	}

		
	inputFile >> command;
	
	
	
///////////////////////////////////////////////////////////////////////////////
	
 while (command != 99) {
    
        cout << endl;
        cout << "COMMAND " << command << ":" << endl;
        
        if (command == 10) {
            City city;
            inputFile >> city.name >> city.latitude >> city.longitude >> city.country >> city.country_iso2 >> city.population;
            
            BTNode* found = containsBST(root, city.name);
            
            if (found != NULL) {
                cout << "--> " << city.name << " is already in the BST." << endl;
            } else {
                root = insertBST(root, city);
                cout << "--> " << city.name << " inserted in the BST." << endl;
            }
            
        }
        
        
        
        else if (command == 11) {
            string cityName;
            inputFile >> cityName;
            
            BTNode* found = containsBST(root, cityName);
            if (found != NULL) {
                cout << "--> " << cityName << " is in the BST." << endl;
                cout << endl; 
                displayCity(found->data);
            } else {
                cout << "--> " << cityName << " is NOT in the BST." << endl;
            }
        }
        
        
            
        else if (command == 12) {
            string cityName;
            inputFile >> cityName;
            
            BTNode* found = containsBST(root, cityName);
            if (found != NULL) {
                root = deleteBST(root, cityName);
                cout << "--> " << cityName << " deleted from BST." << endl;
            } else {
                cout << "--> " << cityName << " is NOT in the BST." << endl;
            }
        }
        
        
        
        else if (command == 13) {
            statisticsBST(root);
        }
        
    
        else if (command == 22) {
    string lowerName, upperName;
    inputFile >> lowerName >> upperName;
    cout << "Displaying all keys in the BST between " << lowerName << " and " << upperName << ":" << endl;
    cout << endl; 
    
    rangeBST(root, lowerName, upperName);
    
    cout << endl; 
}
        
        
        else if (command == 23) {
            cout << "--> Re-balancing the BST ..." << endl;
            root = reBalanceBST(root);
        }
        inputFile >> command;
    }
    inputFile.close();
    
    return 0;
}

