#ifndef SORTING_H
#define SORTING_H

namespace Sorting {

    template <typename T, typename Comparator>
    void insertionSort(std::vector<T>& data, Comparator comp) {

        size_t size = data.size();
        T value{};

        for (size_t i = 1, j = 0; i < size; ++i) {

            // temp save this value
            value = data[i]; 

            // until the temp value is sorted relative to prior elements
            for (j = i; j > 0 && comp(value, data[j - 1]); --j) {

                // move each subsequent element down by one
                data[j] = data[j - 1];
            }

            // insert value
            data[j] = value; 
        }

    }

    namespace Internal {

        // splits and merges some section of the vector into the correct order
        template <typename T, typename Comparator>
        void merge(std::vector<T>& data, Comparator comp, size_t left, size_t mid, size_t right) {

            // split section into smaller vectors
            size_t leftSize = mid - left + 1,
                rightSize = right - mid;
            std::vector<T> leftSplit(leftSize), 
                rightSplit(rightSize);

            // fill smaller sections with data from original vector
            for (size_t i = 0; i < leftSize; ++i) {

                leftSplit[i] = data[left + i];
            }
            for (size_t i = 0; i < rightSize; ++i) {

                rightSplit[i] = data[mid + 1 + i];
            }

            // replace data from original vector with data from sections but in order
            size_t i = 0, j = 0, k = left;
            for (; i < leftSize && j < rightSize; ++k) {

                if (comp(leftSplit[i], rightSplit[j])) {

                    data[k] = leftSplit[i];
                    ++i;
                } 
                else {

                    data[k] = rightSplit[j];
                    ++j;
                }
            }
            // we have gone through all of one section, so fill remaining elements from other section
            for (; i < leftSize; ++i, ++k) {
            
                data[k] = leftSplit[i];
            }
            for (; j < rightSize; ++j, ++k) {

                data[k] = rightSplit[j];
            }

        }

        // recursive helper for merge sort
        template <typename T, typename Comparator>
        void mergeSortHelper(std::vector<T>& data, Comparator comp, size_t left, size_t right) {

            // recusive case
            if (left < right) {

                size_t mid = ((right - left) / 2) + left;

                // go left side
                mergeSortHelper(data, comp, left, mid);
                // go right side
                mergeSortHelper(data, comp, mid + 1, right);

                // order this subsection
                merge(data, comp, left, mid, right);
            }

        }
    }

    template <typename T, typename Comparator>
    void mergeSort(std::vector<T>& data, Comparator comp) {

        if (!data.empty()) {

            Internal::mergeSortHelper(data, comp, 0, data.size() - 1);
        }
    }


};


#endif