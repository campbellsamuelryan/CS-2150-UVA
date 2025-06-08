//Samuel Campbell
//CS2150 'bitCounter.cpp'

#include <iostream>

#include <string>
#include <cmath>

using namespace std;

int bitCounter(int n)
{
  if (n / 2 == 0)
  {
    return 1;
  }
  else if (n % 2 == 0)
  {
    return bitCounter(n / 2);
  }
  else
  {
    return 1 + bitCounter(n / 2);
  }
}

string baseConverter(int num, int base ){
  int dec=0;
  string subResult="";
  string result = "";
   if (num == 0){
    return "0";
   }

   while(num){
    int rem  = num % (base);
    num /= (base);
    if(rem < 0) {

      rem += num;
      num++;

    }
    subResult += to_string(rem);

   }
   
    for (int i = subResult.length() - 1; i >= 0; i--){
        result.push_back(subResult[i]);
    }

   
   return result;
}

int main(int argc, char **argv)
{

  int bitCount = atoi(argv[1]);
  cout << bitCount << " has " << bitCounter(bitCount) << " bit(s)" << endl;

  string num = string(argv[2]);
  int start = atoi(argv[3]);
  int end = atoi(argv[4]);
  cout << num << " (base " << start << ") "
       << "= " << baseConverter(stoi(num), end) << " (base " << end << ")" << endl;

  return 0;
}
