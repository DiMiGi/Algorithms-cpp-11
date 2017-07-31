#include <bits/stdc++.h>
#define iterations(i,n) for(int i = 0; i < n; ++i)
#define INF 1e8

using namespace std;

template<class type> class BinarySearch
{
  type left, right;
  vector<type> container;

  /* THIS FUNCTION MUST BE MODIFIED DEPENDING OF THE PROBLEM */
  bool search_at_left(type middle, type searched_number){
    return searched_number <= this->container[middle];
  }

  public:
    /* CONTRUCTORS */
    BinarySearch(){}
    BinarySearch(type left,type right){
      this->left = left;
      this->right = right;
      iterations(i,left){
        this->container.push_back(INF);
      }
    }
    BinarySearch(vector<type> container, type left, type right){
      this->left = left;
      this->right = right;
      this->container = container;
    }
    /* END OF CONTRUCTORS */

    /* FUNCTIONS */
    void set_container(vector<type> container){
      this->container = container;
    }

    void add_to_container(type element){
      this->container.push_back(element);
    }

    /* END OF FUNCTIONS */

    /* BINARY SEARCH FUNCTIONS */
    type searchInt(type from, type to, type searched_number){
      left = from; right = to;
      while (left < right) {
        type middle = left + right >> 1;
        std::cout << "left : " << left << " right : " << right << " middle : "<< middle << '\n';
        if(search_at_left(middle, searched_number))
          right = middle;
        else
          left = middle + 1;
      }
      if(this->container[right] == searched_number)
        return right; // middle is out of context
      else
        return INF;
    }

    type searchDouble(type from, type to, type searched_number){
      left = from; right = to;
      iterations(i,50){
        type middle = (left + right) * .5;
        if (search_at_left(middle, searched_number))
          right = middle;
        else
          left = middle;
      }
      if(this->container[right] == searched_number)
        return right; // middle is out of context
      else
        return INF;
    }
    /* END OF BINARY SEARCH FUNCTIONS */
};

int main() {
  /*
    Syncronization with I/O of printf/scanf with cout/cin is false
    Using these lines be ware of using just one of them, cin/cout OR scanf/printf. NOT BOTH.
  */
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  BinarySearch<int> bs = BinarySearch<int>(0,n);
  int lecture;
  iterations(i,n){
    cin >> lecture;
    bs.add_to_container(lecture);
  }
  cout << '\n';
  while (cin >> lecture) {
    int ans = bs.searchInt(0,n-1,lecture);
    cout << "answer : " << ans << '\n';
  }
  return 0;
}
