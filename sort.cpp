/*
 * File: test-graph.cpp
 * Anthony Krivonos
 * 11/12/2018
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Prototypes
void print(vector<int>);
vector<int> bubbleSort(vector<int>);
vector<int> selectionSort(vector<int>);
vector<int> insertionSort(vector<int>);
vector<int> mergeSort(vector<int>);
vector<int> merge(vector<int>, vector<int>);
vector<int> quickSort(vector<int>);
vector<int> quickSortUtil(vector<int>&, int, int);
int partition(vector<int>&, int, int);

int main(int argc, char** argv) {

      vector<int> arrayToSort = { 4, 6, 9, 123, 5, 29, 53, 296 };

      cout << "Sorting the following list." << endl;
      print(arrayToSort);
      cout << "Sorted using bubble sort:" << endl;
      print(bubbleSort(arrayToSort));
      cout << "Sorted using selection sort:" << endl;
      print(selectionSort(arrayToSort));
      cout << "Sorted using insertion sort:" << endl;
      print(insertionSort(arrayToSort));
      cout << "Sorted using merge sort:" << endl;
      print(mergeSort(arrayToSort));
      cout << "Sorted using quicksort:" << endl;
      print(quickSort(arrayToSort));

      return 0;
}

// Neatly prints a vector
void print(vector<int> data) {
      cout << "[ ";
      for (int i = 0; i < data.size() - 1; i++) {
            cout << data.at(i) << ", ";
      }
      cout << data.at(data.size() - 1) << " ]" << endl;
}

// Sorts a given vector using bubble sort
vector<int> bubbleSort(vector<int> data) {
      for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data.size() - i - 1; j++) {
                  if (data.at(j) > data.at(j + 1)) {
                        swap(data[j], data[j + 1]);
                  }
            }
      }
      return data;
}

// Sorts a given vector using selection sort
vector<int> selectionSort(vector<int> data) {
      for (int i = 0; i < data.size(); i++) {
            int minIndex = i;
            for (int j = i; j < data.size(); j++) {
                  if (data.at(j) < data.at(minIndex)) {
                        minIndex = j;
                  }
            }
            swap(data[minIndex], data[i]);
      }
      return data;
}

// Sorts a given vector using selection sort
vector<int> insertionSort(vector<int> data) {
      for (int i = 1; i < data.size(); i++) {
            int j = i;
            while (data.at(j) < data.at(j - 1) && j > 0) {
                  swap(data[j], data[j - 1]);
                  j--;
            }
      }
      return data;
}

//
//    MARK: - Mergesort
//

// Sorts a given vector using merge sort
vector<int> mergeSort(vector<int> data) {
      if (data.size() > 1) {
            int halfSize = data.size()/2;
            vector<int> dataA = mergeSort(vector<int>(data.begin(), data.begin() + halfSize));
            vector<int> dataB = mergeSort(vector<int>(data.begin() + halfSize, data.end()));
            data = merge(dataA, dataB);
      }
      return data;
}

// Merges two vectors into a single sorted vector.
vector<int> merge(vector<int> dataA, vector<int> dataB) {

      vector<int> data;

      int i = 0, j = 0;

      while (i < dataA.size() && j < dataB.size()) {
            if (dataA.at(i) < dataB.at(j)) {
                  data.push_back(dataA.at(i));
                  i++;
            } else if (dataB.at(j) < dataA.at(i)) {
                  data.push_back(dataB.at(j));
                  j++;
            } else {
                  data.push_back(dataA.at(i));
                  i++;
                  j++;
            }
      }

      while (i < dataA.size()) {
            data.push_back(dataA.at(i));
            i++;
      }

      while (j < dataB.size()) {
            data.push_back(dataB.at(j));
            j++;
      }

      return data;
}

//
//    MARK: - Quicksort
//

// Sorts a given vector using quicksort
vector<int> quickSort(vector<int> data) {
      return quickSortUtil(data, 0, data.size() - 1);
}

// Utility method for quicksort
vector<int> quickSortUtil(vector<int> &data, int left, int right) {
      if (left < right) {
            int partitionIndex = partition(data, left, right);
            quickSortUtil(data, left, partitionIndex);
            quickSortUtil(data, partitionIndex + 1, right);
      }
      return data;
}

// Partitions the data into two halves in which all elements smaller than a pivot value are on the left, else elements are on the right.
int partition(vector<int> &data, int left, int right) {

      int pivot = data.at(left);

      int i = left;
      int j = right;

      while (true) {

            while (data.at(i) < pivot && i < right) {
                  i++;
            }

            while (data.at(j) > pivot && j > left) {
                  j--;
            }

            if (i >= j) {
                  return j;
            }

            swap(data[i], data[j]);
      }

      return 0;
}