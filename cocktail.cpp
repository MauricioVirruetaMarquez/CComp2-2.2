
#include <iostream>

using namespace std;

void cocktailSort(int* arr, int n){
  bool swapped = true;
  int start = 0;
  int end = n - 1;

  while (swapped) {
    swapped = false;
    for (int* i = arr + start; i < arr + end; i++){
      if (*i > *(i+1)){
        swap(*i, *(i+1));
        swapped = true;
      }
    }
    if (!swapped) break;
    swapped = false;
    end--;

    for (int* i = arr + end - 1; i >= arr + start; --i){
      if (*i > *(i + 1)){
        swap(*i, *(i + 1));
        swapped = true;
      }
    }
    start++;
  }
}

int main(){
  int arr[]= { 3,25,16,24,26,18,19,3,4,5,8,27};

  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Array before sorting: \n";
  for (int i=0; i<n; ++i)
    cout << arr[i] << " ";
  cocktailSort(arr, n);

  cout << "\nArray after sorting: \n";
  for (int i=0; i<n; ++i)
    cout << arr[i] << " ";
  cout<<endl;
  return 0;
}
