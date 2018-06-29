#include <iostream>
#include <vector>
#include <algorithm>

// Asks user a number using std::cin while simultaneously 
// making sure that it is really a number.
//
// NOTE: std::cin << X returns false if it cannot cast given 
// input value into X. Therefore, we loop until correct value 
// is given.
//
int ask_number() {
  int input;

  std::cout << "  Type a number: ";
  while( !(std::cin >> input) ) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid input, try again: ";
  }

  return input;
}


int main()
{
  int N = 10; // number of integers we ask from user
  int number;

  // TODO: implement vector container named vec. 
  //       What is type of the incoming numbers?
  std::vector<int> vec;

  std::cout << "Give me " << N << " numbers :\n";
  for(int i=0; i<N; i++) {
    number = ask_number();

    //TODO: add elements to the container
    vec.push_back(number);
  }


  // printing vector
  std::cout << "You gave: ";
  for(auto i : vec) {
    std::cout << i << ", ";
  }
  std::cout << '\n';


  // TODO: implement sort
  std::sort(vec.begin(), vec.end());

  // printing vector again
  std::cout << "In sorted form it is:";
  for(auto i : vec) {
    std::cout << i << ", ";
  }
  std::cout << '\n';


  // TODO implement smallest and largest number output
  int smallest, largest; 

  smallest = std::min_element();
  largest = std::max_element();

  std::cout << "Smallest number is: " << smallest << '\n';
  std::cout << "Largest number is : " << largest << '\n';

}
