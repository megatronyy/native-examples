#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

// function template, with default parameter
template <typename T, typename F = std::less<T>>
int compare(const T& v1, const T& v2, F f = F()) {
  if (f(v1, v2)) return -1;
  if (f(v2, v1)) return 1;
  return 0;
}

//member template
class DebugDelete {
 private:
  std::ostream& os;

 public:
  DebugDelete(std::ostream& s = std::cerr) : os(s) {}
  template <typename T>
  void operator()(T* p) const {
    os << "deleting unique_ptr" << std::endl;
    delete p;
  }
};

//class template, member template
template <typename T>
class Blob{
public:
    template <typename It> Blob(It b, It e);
};

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e){
    std::sort(b, e);
}

int main(){
    std::cout << "compare (0, 42) = " << compare (0, 42) << std::endl;
 
	double* p = new double;
	DebugDelete d;
	d(p); //使用时, 可以自动推倒模板
	int* ip = new int;
	DebugDelete() (ip);
	std::unique_ptr<int, DebugDelete> pi (new int, DebugDelete());
	std::unique_ptr<std::string, DebugDelete> ps (new std::string, DebugDelete());
 
	int ia[] = {9, 8, 7, 6, 5};
	std::vector<long> vi = {5, 4, 3, 2, 1, 0};
	std::deque<std::string> w = {"lady", "girl", "woman", "now"};
 
	Blob<int> a1(std::begin(ia), std::end(ia));
	Blob<int> a2(vi.begin(), vi.end());
	Blob<std::string> a3(w.begin(), w.end());
 
	std::cout << "int ia[] = ";
	for (const auto i : ia) { std::cout << i << " "; }
	std::cout << std::endl;
	std::cout << "std::vector<long> vi = ";
	for (const auto i : vi) { std::cout << i << " "; }
	std::cout << std::endl;
	std::cout << "std::list<const char*> w = ";
	for (const auto i : w) { std::cout << i << " "; }
	std::cout << std::endl;

    return 0;
}

