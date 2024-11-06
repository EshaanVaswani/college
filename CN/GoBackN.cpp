#include <bits/stdc++.h>
using namespace std;

int main()
{
   int windowSize, totalFrames;

   cout << "Enter window size: ";
   cin >> windowSize;
   cout << "Enter total frames to be sent: ";
   cin >> totalFrames;

   vector<int> senderFrames(totalFrames);
   for (int i = 0; i < totalFrames; i++)
   {
      senderFrames[i] = i;
   }

   cout << "Data frames: ";
   for (int i = 0; i < totalFrames; i++)
   {
      cout << senderFrames[i] << " | ";
   }
   cout << endl;

   int choice;
   cout << "Do you want to start sending frames (0/1): ";
   cin >> choice;
   cout << endl;

   if (choice == 1)
   {
      int ptrOnWindowLeftSender = 0;
      int ptrOnWindowLeftReceiver = 0;
      int totalSentFrames = 0;

      while (ptrOnWindowLeftSender < totalFrames)
      {
         int count = 0;
         cout << "At Sender End:" << endl;

         for (int i = ptrOnWindowLeftSender; (i < totalFrames && count < windowSize); i++)
         {
            cout << "Sent frame[" << (i + 1) << "]" << endl;
            ptrOnWindowLeftSender++;
            totalSentFrames++;
            count++;
         }
         cout << endl;

         cout << "At Receiver End:" << endl;
         int j = 0;
         count = 0;

         for (int i = ptrOnWindowLeftReceiver; (i < totalFrames && count < windowSize); i++)
         {
            char yN;
            cout << "Did you receive frame[" << (i + 1) << "](y/n): ";
            cin >> yN;

            if (yN == 'n')
            {
               cout << "Frames will again be sent from frame no. " << (i + 1) << endl;
               cout << endl;
               ptrOnWindowLeftSender = i;
               break;
            }
            else
            {
               j++;
               ptrOnWindowLeftReceiver++;
            }
            count++;
         }

         if (j == windowSize)
         {
            cout << "All frames from this window sent without errors. Sending next frames..." << endl;
            cout << endl;
         }
      }

      cout << endl;
      cout << "All frames are sent." << endl;
      cout << "Total number of frames sent including retransmission is " << totalSentFrames << endl;
   }

   return 0;
}
