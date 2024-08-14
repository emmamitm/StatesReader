# StatesReader
The StatesReader is a project written in C++ that reads and interprets data from a CSV file. It features functionality for handling data related to different states such as population, per capita income, number of households, and median household income. It also has an additional function for generating random numbers.
## Features
Reads data from a CSV file - the file should contain data on states, their population, per capita income, number of households, and median household income.
Interprets data and stores it in a structured way using a data struct. The data is then pushed into a vector for further use.
Prints out the data in an organized manner for each state:
  State
    Population: (population)
    Per Capita Income: (perCapitaIncome)
    Median Household Income: (medianHouseholdIncome)
    Number of Households: (numberOfHouseholds)
## Usage
To use this code in your own context, ensure that your CSV file data matches the struct included in the code. Update the openFile function with the correct file name.
Additionally, the code contains a random number generator to simulate rolling dice. You can select this option from the given main menu at runtime.
Installation
Clone the repository
Make sure to have a compiler that supports C++ installed on your machine. This code has been written using C++ standard.
Compile the code using any compiler of your choice
Run the executable file
