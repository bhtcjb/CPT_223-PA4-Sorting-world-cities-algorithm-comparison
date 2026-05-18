#include <cassert>
#include <iostream>
#include <vector>
#include <functional>

#include "Sorting.h"
#include "City.h"

// g++-11 -g -Wall -std=c++17 test/testSorting.cpp -Iinclude -o testexe

void testInsertionSort() {

    std::cout << "Test Insertion Sort" << std::endl;

    std::vector<City> cityList = {};
    std::function<bool(const City&, const City&)> cityComparator;

    cityComparator = [](const City& a, const City& b) { 

        return a.getPopulation() > b.getPopulation(); 
    };


    // test empty vector
    Sorting::insertionSort(cityList, cityComparator);
    assert(cityList.empty());

    // test single element
    cityList.emplace_back(City("Pullman", "Washington", 2, 1.2));
    Sorting::insertionSort(cityList, cityComparator);
    assert(cityList[0].getPopulation() == 2);
    assert(cityList.size() == 1);

    // test reverse sorted input
    cityList.emplace_back(City("Moscow", "Idaho", 20, 2.2));
    cityList.emplace_back(City("Seattle", "United States", 200, 3.2));
    Sorting::insertionSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getPopulation() == 200);
    assert(cityList[1].getPopulation() == 20);
    assert(cityList[2].getPopulation() == 2);

    // test already sorted input
    Sorting::insertionSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getPopulation() == 200);
    assert(cityList[1].getPopulation() == 20);
    assert(cityList[2].getPopulation() == 2);

    // test normal sort by population
    cityList[0] = City("Pullman", "Washington", 2, 1.2);
    cityList[1] = City("Seattle", "United States", 200, 3.2);
    cityList[2] = City("Moscow", "Idaho", 20, 2.2);
    Sorting::insertionSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getPopulation() == 200);
    assert(cityList[1].getPopulation() == 20);
    assert(cityList[2].getPopulation() == 2);

    // test normal sort by city
    cityComparator = [](const City& a, const City& b) { 

        return a.getCity() < b.getCity();
    };
    Sorting::insertionSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getCity() == "Moscow");
    assert(cityList[1].getCity() == "Pullman");
    assert(cityList[2].getCity() == "Seattle");

    // test normal sort by country
    cityComparator = [](const City& a, const City& b) { 

        return a.getCountry() < b.getCountry();
    };
    Sorting::insertionSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getCountry() == "Idaho");
    assert(cityList[1].getCountry() == "United States");
    assert(cityList[2].getCountry() == "Washington");

    // test normal sort by latitude
    cityComparator = [](const City& a, const City& b) { 

        return a.getLatitude() > b.getLatitude(); 
    };
    Sorting::insertionSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getLatitude() == 3.2);
    assert(cityList[1].getLatitude() == 2.2);
    assert(cityList[2].getLatitude() == 1.2);

    // test type generality
    std::vector<int> intList = { 2, 3, 1 };
    std::function<bool(const int, const int)> intComparator;
    intComparator = [](const int a, const int b) { 

        return a > b; 
    };
    Sorting::insertionSort(intList, intComparator);
    assert(intList.size() == 3);
    assert(intList[0] == 3);
    assert(intList[1] == 2);
    assert(intList[2] == 1);

    std::cout << "PASSED" << std::endl;

}

void testMergeSort() {

    std::cout << "Test Merge Sort" << std::endl;

    std::vector<City> cityList = {};
    std::function<bool(const City&, const City&)> cityComparator;

    cityComparator = [](const City& a, const City& b) { 

        return a.getPopulation() > b.getPopulation(); 
    };


    // test empty vector
    Sorting::mergeSort(cityList, cityComparator);
    assert(cityList.empty());

    // test single element
    cityList.emplace_back(City("Pullman", "Washington", 2, 1.2));
    Sorting::mergeSort(cityList, cityComparator);
    assert(cityList[0].getPopulation() == 2);
    assert(cityList.size() == 1);

    // test reverse sorted input
    cityList.emplace_back(City("Moscow", "Idaho", 20, 2.2));
    cityList.emplace_back(City("Seattle", "United States", 200, 3.2));
    Sorting::mergeSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getPopulation() == 200);
    assert(cityList[1].getPopulation() == 20);
    assert(cityList[2].getPopulation() == 2);

    // test already sorted input
    Sorting::mergeSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getPopulation() == 200);
    assert(cityList[1].getPopulation() == 20);
    assert(cityList[2].getPopulation() == 2);

    // test normal sort by population
    cityList[0] = City("Pullman", "Washington", 2, 1.2);
    cityList[1] = City("Seattle", "United States", 200, 3.2);
    cityList[2] = City("Moscow", "Idaho", 20, 2.2);
    Sorting::mergeSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getPopulation() == 200);
    assert(cityList[1].getPopulation() == 20);
    assert(cityList[2].getPopulation() == 2);

    // test normal sort by city
    cityComparator = [](const City& a, const City& b) { 

        return a.getCity() < b.getCity();
    };
    Sorting::mergeSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getCity() == "Moscow");
    assert(cityList[1].getCity() == "Pullman");
    assert(cityList[2].getCity() == "Seattle");

    // test normal sort by country
    cityComparator = [](const City& a, const City& b) { 

        return a.getCountry() < b.getCountry();
    };
    Sorting::mergeSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getCountry() == "Idaho");
    assert(cityList[1].getCountry() == "United States");
    assert(cityList[2].getCountry() == "Washington");

    // test normal sort by latitude
    cityComparator = [](const City& a, const City& b) { 

        return a.getLatitude() > b.getLatitude(); 
    };
    Sorting::mergeSort(cityList, cityComparator);
    assert(cityList.size() == 3);
    assert(cityList[0].getLatitude() == 3.2);
    assert(cityList[1].getLatitude() == 2.2);
    assert(cityList[2].getLatitude() == 1.2);

    // test type generality
    std::vector<int> intList = { 2, 3, 1 };
    std::function<bool(const int, const int)> intComparator;
    intComparator = [](const int a, const int b) { 

        return a > b; 
    };
    Sorting::mergeSort(intList, intComparator);
    assert(intList.size() == 3);
    assert(intList[0] == 3);
    assert(intList[1] == 2);
    assert(intList[2] == 1);

    std::cout << "PASSED" << std::endl;

}

int main() {

    testInsertionSort();
    testMergeSort();


    return 0;
}