# Simple Threading Example
This is a simple demonstration of multithreading in C++. 
The program takes an integer as a command line argument from the user and then spawns 10 threads.
Each thread which each generate a random number between 0 and 9999 repeatedly until they match the user input number.
When any thread finishes matching it will display it's unique ID so the user can see the order the threads completed.

## How To Run
1. Download the source cpp file
2. Compile with `g++ -std=c++11 -o filename source.cpp -pthread` where filename is the desired executable filename and source.cpp is the name of the source code file.
3. Run with `./filename` in terminal.

## Screenshot
<img src="https://github.com/thomas-martin-uf/Simple-Threading-Example/assets/109101463/700bf30b-d884-475e-a83d-c7e30157b9dd" alt="Your Image" style="width: 500px;">
