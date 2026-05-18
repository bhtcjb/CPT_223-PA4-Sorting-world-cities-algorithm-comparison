# CPT_223-PA4-Sorting-world-cities-algorithm-comparison
Sorting world cities dataset runtime performance comparison between insertion sort and merge sort for CPT_223 class

# Design Decisions
The container used for sorting in this implimentation is a std::vector of custom City types. Comparator functions are made using lambdas, and constructed at runtime using std::function. Population and latitude are sorted descending, while city and country are sorted ascending. Since sorting missing data is meaningless, for this implimentation, if any one of the city, country, population, or latitude fields are missing, this data is omitted (i.e. not inserted into the vector). Reading in the CSV assumes all fields are quoted, and no misformatting. Only the fields city, country, population, and latitude are read in. Insertion sort utilizes loop-based implimentation, while merge sort uses recursive implimentation. Sorting algorithms utilize no move operations as an arbitrary but consistant decision for fair comparison.

# Testing
Test cases for sorting algorithms utilize cassert. Both insertion sort and merge sort utilize the same set of test cases.

First, std::vector type object of City types is initialized, as well as a descending compare-by-population comparitor.

(1) Sort is tested on an empty vector to ensure no crashes or errors.

Then a City type object is inserted into the vector.

(2) Sort is tested on a single element vector to ensure the algorithm correctly identifies the vector as sorted when no other elements are involved.

Two more insertions into the vector are made such that the vector is in reverse order, i.e. ascending by population.

(3) Sort is tested on a reverse order vector to ensure the algorithm can completely reverse a backward set of data.

(4) Now that the vector is ordered, sort is tested on an already ordered vector to ensure the algorithm keeps the correct order intact.

Vector data is replaced unordered by population.

(5.0) Normal case sort by population is tested on a randomly ordered vector for general functionality.

New comparitor is made to sort ascending by city.

(5.1) Normal case sort by city is tested for general functionality.

New comparitor is made to sort ascending by country.

(5.2) Normal case sort by country is tested for general functionality.

New comparitor is made to sort descending by latitude.

(5.3) Normal case sort by latitude is tested for general functionality.

New std::vector of integers is initialized as well as a descending integer comparator.

(6) Normal case sort integers is tested to ensure type generality.


# Performance Analysis

|------------|---------------------|---------------------|
| Field      | Insertion Sort (ms) | Merge Sort (ms)     |
|------------|---------------------|---------------------|
|------------|---------------------|---------------------|
| population |        5.96         |       170.40        |
|------------|---------------------|---------------------|
| city       |      42458.30       |       211.79        |
|------------|---------------------|---------------------|
| country    |      40298.86       |       193.15        |
|------------|---------------------|---------------------|
| latitude   |      42078.27       |       177.10        |
|------------|---------------------|---------------------|


# Reflection
Merge sort generally outcompeted insertion sort in most cases. Merge sort took around the same amount of time each run, ranging from roughly 170-215 ms. Insertion sort also took around the same amount of time each run in 3/4 cases, ranging from roughly 40000-43000 ms. Generally, merge sort was about 200x faster than insertion sort for this dataset. However, when the selected field was population, insertion sort finished extremely fast at 5.96 ms, completely dominating merge sort in this case. This behavior is exactly what is expected considering the theoretical best and average case time-complexities for each algorithm. Average case time-complexity for insertion sort is O(n^2) due to the nested loops, while average case time-complexity for merge sort is O(nlogn) due to its divide and conquer strategy. This explains why insertion sort generally took so much longer than merge sort, since for the large dataset of the almost 50000 cities that are effectively randomly ordered, the quadratic increase in time becomes overwhelming for insertion sort. On the other hand, insertion sort has an advantage over merge sort, being that insertion sort is adaptive and can cut sorting short when data is already ordered, while merge sort follows a fixed algorithm that always sorts the same amount regardless of starting conditions. Best case scenario, when the data is already ordered, insertion sort has an O(n) time complexity, which is faster than the best case for merge sort, which has an O(nlogn) time complexity. This is why when sorting by population, insertion sort performs much better, because the dataset is already ordered descending by population, meaning insertion sort's best case is met.
