// main.cpp -- Starter code for CPTS 223 Sorting Assignment
//
// This file provides:
//   - A working REPL (Read-Eval-Print Loop) with command parsing
//   - Timer usage example for measuring sort performance
//
// Your job:
//   - Create City.h / City.cpp (your City class)
//   - Create Sorting.h (your templated insertionSort and mergeSort)
//   - Fill in the TODO sections below to wire everything together
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <iomanip>
#include <fstream>

#include "Timer.h"
#include "City.h"
#include "Sorting.h"



// ----------------------------------------------------------------
// Timer usage example (delete this function once you understand it)
// ----------------------------------------------------------------
void timerExample() {
    Timer timer;

    timer.start();
    // ... do some work ...
    long sum = 0;
    for (long i = 0; i < 1000000; ++i) {
        sum += i;
    }
    timer.stop();

    std::cout << "Example elapsed time: "
              << std::fixed << std::setprecision(2)
              << timer.elapsedMilliseconds() << " ms" << std::endl;
    std::cout << "(sum = " << sum << ")" << std::endl;
}

std::vector<City> loadCities(const std::string& citiesCsv) {

    std::ifstream citiesStream(citiesCsv);
    std::vector<City> citiesList{};
    std::string buffer = "",
        city = "",
        country = "",
        population = "",
        latitude = "";

    // skip top line
    getline(citiesStream, buffer);

    // city
    citiesStream.ignore();
    while(getline(citiesStream, buffer, '"')) {

        city = buffer;

        // city_ascii
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');

        // lat
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');
        latitude = buffer;

        // lng
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');

        // country
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');
        country = buffer;

        // iso2
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');

        // iso3
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');

        // admin_name
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');

        // capital
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');

        // population
        citiesStream.ignore(2);
        getline(citiesStream, buffer, '"');
        population = buffer;      

        // id
        citiesStream.ignore(2);
        getline(citiesStream, buffer);

        // exclude missing data
        if (city != "" && country != "" && population != "" && latitude != "") {

            citiesList.emplace_back(City(city, country, stol(population), stod(latitude)));
        }


        citiesStream.ignore();
    }

    return citiesList;
}

// ----------------------------------------------------------------
// TODO: Implement handleSortCommand
// ----------------------------------------------------------------
// This function should:
//   1. Validate the field name and build the appropriate comparator
//   2. Make a fresh copy of masterData (so sorts don't affect each other)
//   3. Call the right sorting algorithm (insertionSort or mergeSort)
//      wrapped in timer.start() / timer.stop()
//   4. Print the top 10 results and the elapsed time
//
// Hint: Use std::function<bool(const City&, const City&)> for your
//       comparator, or pass lambdas directly to your sort templates.
//
void handleSortCommand(const std::string& algorithmName,
                       const std::string& fieldName,
                       const std::vector<City>& masterData) {
    
    std::function<bool(const City&, const City&)> comparator;
    bool success = true;
    
    if (fieldName == "city") {

        // lambda function
        comparator = [](const City& a, const City& b) { 

            return a.getCity() < b.getCity();
        };
    } 
    else if (fieldName == "country") {

        comparator = [](const City& a, const City& b) { 

            return a.getCountry() < b.getCountry();
        };
    } 
    else if (fieldName == "population") {

        comparator = [](const City& a, const City& b) { 

            return a.getPopulation() > b.getPopulation(); 
        };
    } 
    else if (fieldName == "latitude") {

        comparator = [](const City& a, const City& b) { 

            return a.getLatitude() > b.getLatitude(); 
        };
    } 
    else {

        std::cout << "Invalid field!" << std::endl;
        success = false;
    }

    if (success) {

        std::vector<City> copyData = masterData;

        Timer timer;

        // time sorting algorithm
        timer.start();

        if (algorithmName == "insertionSort") {

            Sorting::insertionSort(copyData, comparator);

        } 
        else if (algorithmName == "mergeSort") {

            Sorting::mergeSort(copyData, comparator);
        }
        else {

            std::cout << "Invalid sorting algorithm!" << std::endl;
            success = false;
        }
    
        timer.stop();

        if (success) {

            // print top 10 and elapsed time
            for (size_t i = 0; i < 10 && i < copyData.size(); ++i) {

                std::cout << copyData[i] << std::endl;
            }

            std::cout << std::endl << "Elapsed time: "
              << std::fixed << std::setprecision(2)
              << timer.elapsedMilliseconds() << " ms" << std::endl;
        }

    }
}


int main() {

    // TODO: Load the CSV dataset into a container of your choice.
    //       Example:
    std::vector<City> cities = loadCities("worldcities.csv");
    std::cout << "Loaded " << cities.size() << " cities." << std::endl;

    // ---- REPL: Do not modify below this line ----

    std::string line;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            break; // EOF
        }

        // Trim leading whitespace
        size_t start = line.find_first_not_of(" \t");
        if (start == std::string::npos) continue;
        line = line.substr(start);

        if (line == "quit" || line == "exit") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        // Parse command: <algorithm> <field>
        std::istringstream iss(line);
        std::string algorithm, field;
        iss >> algorithm >> field;

        if (algorithm.empty() || field.empty()) {
            std::cout << "Usage: <algorithm> <field>" << std::endl;
            std::cout << "  Algorithms: insertionSort, mergeSort" << std::endl;
            std::cout << "  Fields: population, city, country, latitude"
                      << std::endl;
            std::cout << "  Or type 'quit' to exit." << std::endl;
            continue;
        }

        // Validate algorithm name
        if (algorithm != "insertionSort" && algorithm != "mergeSort") {
            std::cout << "Unknown algorithm: " << algorithm << std::endl;
            std::cout << "Valid algorithms: insertionSort, mergeSort"
                      << std::endl;
            continue;
        }

        // Validate field name
        if (field != "population" && field != "city" &&
            field != "country" && field != "latitude") {
            std::cout << "Unknown field: " << field << std::endl;
            std::cout << "Valid fields: population, city, country, latitude"
                      << std::endl;
            continue;
        }

        // TODO: Call your handleSortCommand function here.
        handleSortCommand(algorithm, field, cities);

        std::cout << std::endl;
    }

    return 0;
}
