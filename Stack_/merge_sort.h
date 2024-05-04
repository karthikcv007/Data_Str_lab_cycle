#ifndef MERGE_SORT_H
 #define MERGE_SORT_H
 template<typename T>
 class MergeSort {
 public:
 static void mergeSort(T* arr, int size);
 private:
 static void merge(T* arr, int left, int middle, int right);
 };
 #endif