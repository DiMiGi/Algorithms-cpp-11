#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define INF 1e8

using namespace std;

template<class type> class BinarySearch
{
  type left, right, comparator;
  vector<type> container;

  /* THIS FUNCTION MUST BE MODIFIED DEPENDING OF THE PROBLEM */
  bool search_at_left(type middle){
    return comparator <= this->container[middle];
  }

  public:
    /* CONTRUCTORS */
    BinarySearch(){}
    BinarySearch(type left,type right){
      this->left = left;
      this->right = right;
      rep(i,left){
        this->container.push_back(INF);
      }
    }
    BinarySearch(vector<type> container, type left, type right,type comparator){
      this->left = left;
      this->right = right;
      this->container = container;
      this->comparator = comparator;
    }
    /* END OF CONTRUCTORS */

    /* FUNCTIONS */
    void set_container(vector<type> container){
      this.container = container;
    }

    void add_to_container(type element){
      this->container.push_back(element);
    }

    void set_comparator(type comparator){
      this->comparator = comparator;
    }

    /* END OF FUNCTIONS */

    /* BINARY SEARCH FUNCTIONS */
    type searchInt(){
      if (comparator < left || comparator > right) {
        return INF;
      }
      while (left < right) {
        type middle = left + right >> 1;
        std::cout << "l : " << left << " r : " << right << " m : "<< middle << '\n';
        if(search_at_left(middle))
          right = middle;
        else
          left = middle + 1;
      }
      return right; // middle is out of context
    }

    type searchDouble(){
      if (comparator < left || comparator > right) {
        return INF;
      }
      rep(i,50){
        type middle = (left + right) * .5;
        if (search_at_left(middle))
          right = middle;
        else
          left = middle;
      }
      return right; // middle is out of context
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

  int i = 1, j = 5;
  BinarySearch<int> bs = BinarySearch<int>(i,j);
  for(i; i <= j; i++){
    bs.add_to_container(i);
  }
  bs.set_comparator(INF);
  int ans = bs.searchInt();
  cout << "ans : " << ans << '\n';
  return 0;
}
