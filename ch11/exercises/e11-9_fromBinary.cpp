#include "../../std_lib_facilities.h"

#include <iostream>
#include <fstream>
#include <vector>


int main (void) {
   std::cout << "Please enter input file name\n";

   std::string fname;
   std::cin >> fname;
   std::ifstream ifs (fname.c_str());

   if (!ifs)
      std::cerr << "Cannot open file " << fname << " for reading.\n";

   std::cout << "Please enter output file name\n";
   std::cin >> fname;
   std::ofstream ofs (fname.c_str(), std::ios::binary);

   if (!ifs)
      std::cerr << "Cannot open file " << fname << " for writting.\n";


   for (int x; ifs.read(as_bytes(x), sizeof(int));) {
      ofs.write((char*) &x, sizeof(int));
   }   

   return 0;
}
