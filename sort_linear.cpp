#include <bits/stdc++.h>

using namespace std;

/* Complexity order is the quantity of elements to be ordered E if and only if K = max(E)-min(E) + 1 < size(E) if not the Complexity is the quantity of elements
   between min(E) and max(E), both inclusive.
   This algorithm can be used for ages, heights or to sort elements in a delimited range.
   i.e A = [10000000 100 1]
   the array A has 3 elements but it going to iterate 10000000 times before sort the elements.
*/

template<class type> class LinearSort
{

  typedef vector<type> list;

  list frecuency;



  public:
    LinearSort(){}

    list sort(list elements){
      list sorted_elements = list(elements.size());
      type minimum = elements[distance(elements.begin(),min_element(elements.begin(),elements.end()))]; // O(n)
      type maximum = elements[distance(elements.begin(),max_element(elements.begin(),elements.end()))]; // O(n)

      frecuency = list(maximum - minimum + 1, 0);

      for (unsigned int i = 0; i < elements.size(); i++) {  // O(n)
        frecuency[ elements[i] - minimum ]++;
      }

      for (unsigned int i = 1; i < frecuency.size(); i++) { // O(k = max(elements) - min(elements) + 1)
        frecuency[i] = frecuency[i-1] + frecuency[i];
      }

      for (int i = (elements.size() - 1); i >= 0 ; i--) { // O(n)
        int position = --frecuency[elements[i]-minimum];
        sorted_elements[position] = elements[i];
      }
      cout << "O(" << max(elements.size(),frecuency.size()) << ")\n";
      return sorted_elements;
    }

};

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(true){
    cin >> n;

    if(n==0)
      break;

    vector<int> elements = vector<int>(n);

    for (int i = 0; i < n; i++) {
      cin >> elements[i];
    }

    LinearSort<int> s = LinearSort<int>();

    vector<int> sorted = s.sort(elements);

    cout << "ans: |";
    for(int num : sorted){
      cout << " " << num << " |";
    }
    cout << "\n";
  }



  return 0;
}
