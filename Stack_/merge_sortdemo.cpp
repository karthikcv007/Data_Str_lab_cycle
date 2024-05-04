#include <iostream>

#include "merge_sort.cpp"
int main() {
  int intArr[] = {12, 11, 13, 5, 6, 7};
  MergeSort<int>::mergeSort(intArr, sizeof(intArr) / sizeof(int));
  std::cout << "Sorted integer array: ";
  for (int i = 0; i < sizeof(intArr) / sizeof(int); i++)
    std::cout << intArr[i] << " ";
  std::cout << std::endl;
  double doubleArr[] = {3.14, 1.618, 2.718, 0.577};
  MergeSort<double>::mergeSort(doubleArr, sizeof(doubleArr) / sizeof(double));
  std::cout << "Sorted double array: ";
  for (int i = 0; i < sizeof(doubleArr) / sizeof(double); i++)
    std::cout << doubleArr[i] << " ";
  std::cout << std::endl;
  return 0;
}