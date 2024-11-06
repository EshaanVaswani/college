#include <bits/stdc++.h>
using namespace std;

int calcPBit(vector<int> &arr, int p)
{
   int parity = 0;
   for (int i = 1; i < arr.size(); i++)
   {
      if (((i >> (p - 1)) & 1) == 1)
      {
         parity ^= arr[i];
      }
   }
   cout << "Redundancy bit calculated: " << parity << endl;
   return parity;
}

vector<int> genHamCode(vector<int> &data)
{
   int dLen = data.size();
   int r = 0;

   while (pow(2, r) < dLen + r + 1)
   {
      r++;
   }

   vector<int> hamCode(dLen + r + 1);
   int j = 0;

   for (int i = 1; i < hamCode.size(); i++)
   {
      if (pow(2, j) == i)
      {
         j++;
      }
      else
      {
         hamCode[i] = data[--dLen];
      }
   }

   for (int i = 0; i < r; i++)
   {
      int pPos = pow(2, i);
      hamCode[pPos] = calcPBit(hamCode, i + 1);
   }

   return hamCode;
}

int detectErr(vector<int> &hamCode, int r)
{
   int errPos = 0;

   for (int i = 0; i < r; i++)
   {
      int pPos = 1 << i;
      int parity = calcPBit(hamCode, i + 1);
      if (parity == 1)
      {
         errPos |= pPos;
      }
   }

   string binaryErrorPos = bitset<8>(errPos).to_string();
   cout << "Error position in binary: " << binaryErrorPos << endl;
   return errPos;
}

int main()
{
   int n;
   cout << "Enter number of data bits: ";
   cin >> n;

   vector<int> data(n);
   cout << "Enter data bits: ";
   for (int i = 0; i < n; i++)
   {
      cin >> data[i];
   }

   vector<int> hamCode = genHamCode(data);
   int r = hamCode.size() - n;

   cout << "Hamming Code formed: ";
   for (int i = hamCode.size() - 1; i >= 1; i--)
   {
      cout << hamCode[i] << " ";
   }
   cout << endl;

   cout << "Enter received Hamming Code: ";
   for (int i = hamCode.size() - 1; i >= 1; i--)
   {
      cin >> hamCode[i];
   }

   int errPos = detectErr(hamCode, r);
   if (errPos == 0)
   {
      cout << "No error detected." << endl;
   }
   else if (errPos <= hamCode.size() - 1)
   {
      cout << "Single-bit error detected at position: " << errPos << endl;
      hamCode[errPos] ^= 1;
      cout << "Corrected Hamming Code: ";
      for (int i = hamCode.size() - 1; i >= 1; i--)
      {
         cout << hamCode[i] << " ";
      }
      cout << endl;
   }
   else
   {
      cout << "Double-bit error detected." << endl;
   }

   return 0;
}
