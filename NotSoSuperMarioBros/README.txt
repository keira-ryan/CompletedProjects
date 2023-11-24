Keira Ryan
Programming Assignment 2: Not So Super Mario Bros.

Source Files Submitted: Mario.cpp, FileProcessor.cpp, World.cpp, and main.cpp

No known runtime or compiletime errors

No known deviations from specifications

References Used:
- In Class Arrays.cpp code used as reference for creating and 
  deleting 3 dimensional array using pointers
- Used the following site as reference for how to seed all srand() instances: 
  https://en.cppreference.com/w/cpp/numeric/random/srand
- Used stoi() method to convert std::string to int after reading abou it in the 
  the following site: https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/ 
- Used the following source to determine how to get a specific range of numbers from rand():
  https://cplusplus.com/forum/beginner/236128/#:~:text=rand()%20%25%20100%20%2B%201%20takes,1%2C%20100%5D%2C%20inclusive. 
- I really needed to review using rdbuffer to transfer the cout contents to the log file in the play method of the FileProcessor 
  class. To do so, I referenced the following websites that gave explanations and examples of how rdbuffer and redirection
  in c++ works:
  https://www.geeksforgeeks.org/io-redirection-c/ 
  https://cplusplus.com/reference/ios/ios/rdbuf/
  https://en.cppreference.com/w/cpp/io/basic_ios/rdbuf 
  https://stackoverflow.com/questions/10150468/how-to-redirect-cin-and-cout-to-files 
  https://www.geeksforgeeks.org/io-redirection-c/ 

To run the project:
g++ *.cpp -o Mario
./Mario input.txt log.txt
