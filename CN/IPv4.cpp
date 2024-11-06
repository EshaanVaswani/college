#include <bits/stdc++.h>
using namespace std;

bool check_ip(const string &ip_address)
{
   regex validIpRe(
       R"(^((25[0-5]|2[0-4][0-9]|[0-1]?[0-9]?[0-9])\.){3}(25[0-5]|2[0-4][0-9]|[0-1]?[0-9]?[0-9])$)");

   return regex_match(ip_address, validIpRe);
}

string identify_class(const string &ip_address)
{
   int firstOctet = stoi(ip_address.substr(0, ip_address.find('.')));
   if (firstOctet <= 127)
      return "class_A";
   else if (firstOctet <= 191)
      return "class_B";
   else if (firstOctet <= 223)
      return "class_C";
   else if (firstOctet <= 239)
      return "class_D";
   else
      return "class_E";
}

string retrieve_default_mask(const string &ipClass)
{
   if (ipClass == "class_A")
      return "255.0.0.0";
   else if (ipClass == "class_B")
      return "255.255.0.0";
   else if (ipClass == "class_C")
      return "255.255.255.0";
   else
      return "";
}

int borrow_bits(int n)
{
   int bits = 0;
   while ((1 << bits) < n)
      bits++;
   return bits;
}

pair<int, int> calculate_subnet_info(int borrowedBits, int defaultBits)
{
   int totalBits = defaultBits + borrowedBits;
   int numOfHosts = pow(2, (32 - totalBits)) - 2;
   return {totalBits, numOfHosts};
}

string calculate_network_address(const string &ip, int cidr, int subnetIndex)
{
   int octets[4];
   sscanf(ip.c_str(), "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

   int networkValue = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
   int subnetSize = pow(2, 32 - cidr);
   networkValue = (networkValue & (~subnetSize + 1)) + (subnetIndex * subnetSize);

   return to_string((networkValue >> 24) & 0xFF) + "." + to_string((networkValue >> 16) & 0xFF) + "." +
          to_string((networkValue >> 8) & 0xFF) + "." + to_string(networkValue & 0xFF);
}

string calculate_broadcast_address(const string &networkAddress, int cidr)
{
   int octets[4];
   sscanf(networkAddress.c_str(), "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

   int networkValue = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
   int subnetSize = pow(2, 32 - cidr);
   int broadcastValue = networkValue + subnetSize - 1;

   return to_string((broadcastValue >> 24) & 0xFF) + "." + to_string((broadcastValue >> 16) & 0xFF) + "." +
          to_string((broadcastValue >> 8) & 0xFF) + "." + to_string(broadcastValue & 0xFF);
}

int calculate_default_bits(const string &defaultMask)
{
   int octets[4];
   sscanf(defaultMask.c_str(), "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

   int bits = 0;
   for (int i = 0; i < 4; i++)
   {
      bits += __builtin_popcount(octets[i]);
   }
   return bits;
}

int main()
{
   string ip;
   cout << "Enter an IPv4 address: ";
   cin >> ip;

   if (check_ip(ip))
   {
      string ipClass = identify_class(ip);
      if (ipClass == "class_D" || ipClass == "class_E")
      {
         cout << "No subnetting allowed for Class D or Class E." << endl;
         return 0;
      }

      cout << "Class of IP: " << ipClass << endl;
      cout << "Enter number of subnets required: ";
      int x;
      cin >> x;

      string defaultMask = retrieve_default_mask(ipClass);
      if (defaultMask.empty())
      {
         cout << "No Default Mask" << endl;
         return 0;
      }

      cout << "Default Mask: " << defaultMask << endl;
      int defaultBits = calculate_default_bits(defaultMask);
      int borrowedBits = borrow_bits(x);
      auto subnetInfo = calculate_subnet_info(borrowedBits, defaultBits);
      int newCIDR = subnetInfo.first;
      int usableHosts = subnetInfo.second;

      cout << "No. of bits borrowed: " << borrowedBits << endl;
      cout << "New CIDR: /" << newCIDR << endl;

      for (int i = 0; i < x; i++)
      {
         string networkAddress = calculate_network_address(ip, newCIDR, i);
         string broadcastAddress = calculate_broadcast_address(networkAddress, newCIDR);

         cout << "Subnet " << (i + 1) << ":" << endl;
         cout << "Network Address: " << networkAddress << endl;
         cout << "Broadcast Address: " << broadcastAddress << endl;
         cout << "Number of Usable Hosts: " << usableHosts << endl;
      }
   }
   else
   {
      cout << "Invalid IP address format." << endl;
   }

   return 0;
}
