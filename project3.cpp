#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>  // for setw
using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;  // Map to store item frequencies

public:
    void readInputFile(string filename) {
        // Read the input file and populate the itemFrequency map
        ifstream inputFile(filename);
        if (inputFile.is_open()) {
            string item;
            while (getline(inputFile, item)) {
                itemFrequency[item]++;
            }
            inputFile.close();
        }
        else {
            cout << "Error opening file: " << filename << endl;
        }
    }

    void printItemFrequency() {
        // Print item frequencies
        cout << "Item Frequencies:\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void printHistogram() {
        // Print item frequencies as a histogram
        cout << "Item Histogram:\n";
        for (const auto& pair : itemFrequency) {
            cout << setw(15) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    void saveDataToFile(string filename) {
        // Save item frequencies to a data file
        ofstream outputFile(filename);
        if (outputFile.is_open()) {
            for (const auto& pair : itemFrequency) {
                outputFile << pair.first << " " << pair.second << endl;
            }
            outputFile.close();
            cout << "Data saved to " << filename << endl;
        }
        else {
            cout << "Error creating file: " << filename << endl;
        }
    }

    int searchItemFrequency(string item) {
        // Search for the frequency of a specific item
        return itemFrequency[item];
    }
};

int main() {
    GroceryTracker groceryTracker;

    // Read input file
    groceryTracker.readInputFile("\\\\apporto.com\\dfs\\SNHU\\Users\\kholoodalkoha_snhu\\Desktop\\Project3\\CS210_Project_Three_Input_File.txt");

    int choice;
    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Print item frequencies\n";
        cout << "3. Print item histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        // Input validation
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            // Menu option one: Search for an item
            string searchItem;
            cout << "Enter the item you wish to search for: ";
            cin >> searchItem;

            int frequency = groceryTracker.searchItemFrequency(searchItem);
            cout << "Frequency of " << searchItem << ": " << frequency << endl;
            break;
        }
        case 2:
            // Menu option two: Print item frequencies
            groceryTracker.printItemFrequency();
            break;
        case 3:
            // Menu option three: Print item histogram
            groceryTracker.printHistogram();
            break;
        case 4:
            // Save data to file before exiting
            groceryTracker.saveDataToFile("frequency.dat");
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
