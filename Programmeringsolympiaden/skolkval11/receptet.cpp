#include <iostream>

using namespace std;

int main()
{
   int ingNum, acq, need, cost, everyCost = 0;

   cin >> ingNum;

   for (int i = 0; i < ingNum; i++){
        cin >> acq >> need >> cost;
        if (need - acq > 0){
                everyCost += (need - acq) * cost;
        }
   }
   cout << everyCost << endl;

    return 0;
}
