#include <iostream>
#include <thread>
#include <random>
#include <stdexcept>
#include <vector>

using std::cout;
using std::endl;
using std::invalid_argument;
using std::mt19937;
using std::random_device;
using std::stoi;
using std::thread;
using std::uniform_int_distribution;
using std::vector;

void GenerateRandomNumbers(int id, int number)
{

    // min, max dist
    int min = 0;
    int max = 9999;

    // get random seed
    std::random_device rd;

    // generator with seed
    std::mt19937 gen(rd());

    // get distribution
    std::uniform_int_distribution<int> dis(min, max);

    // loop forever until we break
    while (true)
        if (dis(gen) == number)
            break;

    cout << "Thread <" << id << "> completed." << endl;
}

int main(int argc, char** argv)
{
    // if command line arg is present
    if (argc > 1)
    {

        try
        {

            // number of threads and command line int conversion
            size_t maxThreads = 10;
            int num = stoi(argv[1]);

            // store threads in vector to join later
            vector<thread> threads(maxThreads);

            // spawn 10 threds
            for (size_t i = 0; i < maxThreads; ++i)
            {

                // spawn threads
                threads[i] = thread(GenerateRandomNumbers, i, num);
            }

            // wait for threads the finish
            for (auto& t : threads)
                t.join();

            cout << "All threads have finished finding numbers.\n";
        }
        catch (const invalid_argument& e)
        {
            cout << "Error: Invalid number provided as command line argument\n";
        }
        catch (...)
        {
            cout << "Error: Could not spawn threads\n";
        }
    }
    else
    {
        cout << "No command line argument provided\n";
    }

    return 0;
}