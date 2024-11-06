#include <bits/stdc++.h>
using namespace std;

int XOR(int x, int y)
{
   return (x == y) ? 0 : 1;
}

vector<int> moduloDivision(vector<int> dividend, vector<int> divisor)
{
   vector<int> remainder = dividend;
   for (int i = 0; i <= dividend.size() - divisor.size(); i++)
   {
      if (remainder[i] == 1)
      {
         for (int j = 0; j < divisor.size(); j++)
         {
            remainder[i + j] = XOR(remainder[i + j], divisor[j]);
         }
      }
   }
   return remainder;
}

void displayCRC(const vector<int> &remainder, int dataLength)
{
   cout << "CRC is: ";
   for (int i = dataLength; i < remainder.size(); i++)
   {
      cout << remainder[i];
   }
   cout << endl;
}

void displayCheckSum(const vector<int> &dividend)
{
   cout << "Checksum code is: ";
   for (int i = 0; i < dividend.size(); i++)
   {
      cout << dividend[i];
   }
   cout << endl;
}

void checkReceiverSide(vector<int> &received, vector<int> &divisor)
{
   vector<int> remainder = moduloDivision(received, divisor);
   bool isValid = true;
   cout << "Remainder at receiver side: ";
   for (int i = received.size() - divisor.size() + 1; i < received.size(); i++)
   {
      cout << remainder[i];
      if (remainder[i] != 0)
      {
         isValid = false;
      }
   }
   cout << endl;
   if (isValid)
   {
      cout << "Data is accepted." << endl;
   }
   else
   {
      cout << "Data is rejected." << endl;
   }
}

void changeRandomBits(vector<int> &data, int numBits)
{
   srand(time(0));
   for (int i = 0; i < numBits; i++)
   {
      int bitPosition = rand() % data.size();
      data[bitPosition] = (data[bitPosition] == 0) ? 1 : 0;
   }
}

int main()
{
   string data, check;
   cout << "Enter data bits: ";
   cin >> data;
   cout << "Enter check bits: ";
   cin >> check;

   vector<int> dividend(data.size() + check.size() - 1, 0);
   vector<int> divisor(check.size(), 0);

   for (int i = 0; i < data.size(); i++)
   {
      dividend[i] = data[i] - '0';
   }
   for (int i = 0; i < check.size(); i++)
   {
      divisor[i] = check[i] - '0';
   }

   vector<int> remainder = moduloDivision(dividend, divisor);

   for (int i = 0; i < check.size() - 1; i++)
   {
      dividend[data.size() + i] = remainder[data.size() + i];
   }

   displayCRC(remainder, data.size());
   displayCheckSum(dividend);

   cout << "Simulating data reception..." << endl;
   checkReceiverSide(dividend, divisor);

   int numBits;
   cout << "Enter number of bits to change (1 or 2): ";
   cin >> numBits;
   changeRandomBits(dividend, numBits);

   cout << "Data after random bit change: ";
   for (int i = 0; i < dividend.size(); i++)
   {
      cout << dividend[i];
   }
   cout << endl;

   cout << "Checking modified data at receiver side..." << endl;
   checkReceiverSide(dividend, divisor);

   return 0;
}
