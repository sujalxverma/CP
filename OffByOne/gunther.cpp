/*
Use of #ifdef and #endif.

How it Works ?
- We define macro called DEBUG.
- Now #ifdef, will execute the code written in this scope, only if this
  macro exist, otherwisw it will ignore it.
*/

#include <iostream>
using namespace std;

#define DEBUG

int main()
{

#ifdef DEBUG
    cout << "Debug is ON\n";
#endif

    cout << "Hello Sujal\n";

    return 0;
}

/*
#include <iostream>
using namespace std;

int main() {

#ifdef TEST
    cout << "Test version" << endl;
#else
    cout << "Production version" << endl;
#endif

    return 0;
}

*/