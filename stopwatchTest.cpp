#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

static bool stop = false;
static int s= 0;
static int m = 0;
static int h = 0;


void counter() {

    while(stop == false) {
      s++;
      if(s>59) {
          s= 0;
          m++;
      }
      if(m >59) {
          m = 0;
          h++;
      }
      this_thread::sleep_for(chrono::seconds(1));
    }

}

string zeroPrefix(int n) {
    if(n <10) {
        return "0";
    }else {
        return "";
    }
}

int main() {
    
    cout << "Press enter to stop timer \n";
    thread timer(counter);
    cin.get();
    stop = true;
    timer.join();
    
    cout << zeroPrefix(h) << h << ":" << zeroPrefix(m) << m << ":" << zeroPrefix(s) << s << "\n";

}