#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include "fstream"
#include "string"
using namespace std;

mt19937 random_mt;

struct data{
    string State;
    int perCapitaIncone;
    int population;
    int medianHouseholdIncome;
    int numberOfHouseholds;

};
int Random(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}
void openFile(string FileName, vector<data>& datavector){
    ifstream inFile(FileName, ios_base:: binary);
    vector<string> values;


    string State;
    string perCapitaIncome1;
    string population1;
    string medianHouseHoleIncome1;
    string numberOfHouses;

    string line;
    getline(inFile, line, '\r');
    if(inFile.is_open()){
        while (getline(inFile, line, '\n')){ //while u can geta line
            getline(inFile, line, ',');
            values.push_back(line);
            int count =3;
            while (count>0){
                getline(inFile, line, ',');
                values.push_back(line);
                count--;
            }
            getline(inFile, line, '\r');
            values.push_back(line);

        }

        inFile.close();

    }
    for (int i = 0; i < values.size()-5; i+=5) {
        State = values.at(i);
        perCapitaIncome1 = values.at(i+1);
        population1 = values.at(i+2);
        medianHouseHoleIncome1 = values.at(i+3);
        numberOfHouses = values.at(i+4);

        data d;
        d.State =State;
        d.perCapitaIncone = stoi(perCapitaIncome1);
        d.numberOfHouseholds = stoi(numberOfHouses);
        d.population = stoi(population1);
        d.medianHouseholdIncome = stoi(medianHouseHoleIncome1);
        datavector.push_back(d);

    }

}

void forLoop(int numberOfSides, vector<int>& values, map<int, int> &diceMap){
    for (int j = 1; j <= numberOfSides; ++j) {
        int count =0;
        for (int i = 0; i < values.size() ; ++i) {
            if(j== values.at(i)){
                count++;
            }

        }
        diceMap.emplace(j,count);
    }

}
void PrintMap(map<int, int> &diceMap){
    auto iter = diceMap.begin();
    for(; iter!= diceMap.end(); ++iter){
        cout<< iter->first << ": " << iter->second<<endl;

    }

}
void PrintMap2(map<string, data> &stateData){
    /*Alabama
    Population: 4849377
    Per Capita Income: 23606
    Median Household Income: 42830
    Number of Households: 1841217*/

    auto iter = stateData.begin();
    for(; iter!= stateData.end(); ++iter){
        cout<< iter->first <<endl;
        cout<< "Population: " << iter->second.population <<endl;
        cout<< "Per Capita Income: " << iter->second.perCapitaIncone << endl;
        cout<< "Median Household Income: " << iter->second.medianHouseholdIncome <<endl;
        cout<< "Number of Households: " << iter->second.numberOfHouseholds << endl;

    }

}
void print1(data data1){
    cout<< data1.State <<endl;
    cout<< "Population: " << data1.population <<endl;
    cout<< "Per Capita Income: " << data1.perCapitaIncone << endl;
    cout<< "Median Household Income: " << data1.medianHouseholdIncome <<endl;
    cout<< "Number of Households: " << data1.numberOfHouseholds<< endl;

}
void RollDice(int numberOfRolls, int numberOfSides){
    map<int, int> diceMap;
    vector<int> values;
    for (int i = 0; i < numberOfRolls; ++i) {
        int key = Random(1,numberOfSides);
        values.push_back(key);
    }
    forLoop(numberOfSides, values, diceMap);
    PrintMap(diceMap);
}

int main()
{
    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;

    if (option == 1)
    {
        int randomSeed;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);


        cout << "Number of times to roll the die: ";
        // user input
        int rolls;
        cin >> rolls;



        cout << "Number of sides on this die: ";
        // user input
        int sides;
        cin >> sides;

        // Roll Dice

        RollDice(rolls, sides);


    }
    else if (option == 2)
    {
        // Load the states
        vector<data> dataVector;
        openFile("states.csv", dataVector);

        map<string, data> myStates;

        for (int i = 0; i < dataVector.size(); ++i) {
            string name = dataVector.at(i).State;
            myStates.emplace(name, dataVector.at(i));
        }

        // Get input for option 1 (show all states) or 2 (do a search for a particular state)
        int selection;
        cout<< "1. Print all states"<<endl;
        cout<< "2. Search for a state" << endl;

        cin >> selection;

        if(selection ==1){
            PrintMap2(myStates);
        }
        else if(selection==2){
            string input;
            cin >> input;

            for (int i = 0; i < dataVector.size(); ++i) {
                if(input == dataVector.at(i).State){
                    print1(dataVector.at(i));
                    break;
                }
                else if(i == dataVector.size()-1){
                    cout<< "No match found for " << input<< endl;
                }
            }

        }

    }

    return 0;
}
