#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  // SK starts the game.
  if (N % 2) {
    cout << "SK";
  } else {
    cout << "CY";
  }
}
