#include <iostream>
#include <chrono>
#include <thread> // allows us to display single threads of execution (thread class)
using namespace std;

/*---------------------------/
    Increments integer i by 1 every second until enter has been pressed on the 
    keyboard. The thread 'worker' points towards the DoWork function, which 
    we then use to stop all code from exectuing unitl the first cin.get() 
    has been entered, from then on we run everything following worker.join().
    We also show that the two threads are different by displaying their ids.
/---------------------------*/ 


static bool enterPressed = false;
static int i = 0;
void DoWork() {
    cout << "Started thread id = " << this_thread::get_id()<< '\n'; //shows thread id
    while(!enterPressed)
    {
        cout << i << '\n';
        i++;
        this_thread::sleep_for(chrono::seconds(1)); //wait for 1 second
    }

}

 int main()  {

    thread worker(DoWork); /* creates new thread called worker which points  
                            towards DoWork() function */
    cin.get();
    enterPressed = true; 
    worker.join(); // no code underneath this will exceute until the worker thread is done

    cout << "Started thread id = " << this_thread::get_id() << '\n';
    cout << "You pressed enter! This only took you " << i << " seconds to do! \n";
    
 }