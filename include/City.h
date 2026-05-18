#ifndef CITY_H
#define CITY_H

#include <ostream>

struct City {

    public:

    // Default Constructor
    City(const std::string& city = "", const std::string& country = "", 
        const long& population = 0, const double latitude = 0.0) 
            : city(city), country(country), population(population), latitude(latitude) {
            }

    // Destructor
    ~City() {
    }

    // Copy Constructor
    City(const City& other) 
        : city(other.city), country(other.country), population(other.population), 
        latitude(other.latitude) {
    }

    // Copy Assignment
    City& operator=(const City& other) {

        if (this != &other) {

            city = other.city;
            country = other.country;
            population = other.population;
            latitude = other.latitude;

        }

        return *this;
    }

    // Move Constructor
    City(City&& other) noexcept 
        : city(std::move(other.city)), country(std::move(other.country)),
        population(other.population), latitude(other.latitude) {
    }

    // Move Assignment
    City& operator=(City&& other) noexcept {

        if (this != &other) {

            std::swap(city, other.city);
            std::swap(country, other.country);
            population = other.population;
            latitude = other.latitude;

        }

        return *this;
    }

    // Getters

    const std::string& getCity() const {

        return city;
    }

    const std::string& getCountry() const {

        return country;
    }

    const long& getPopulation() const {

        return population;
    }

    const double& getLatitude() const {

        return latitude;
    }

    private:

    std::string city;
    std::string country;
    long population;
    double latitude;

    friend std::ostream& operator<<(std::ostream& os, const City& city) {

        os << city.city << " | " << city.country << " | " << city.population << " | " << city.latitude;

        return os;
    }

};



#endif