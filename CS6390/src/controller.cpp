#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

struct FileDescriptor
{
    // Store the name of the file
    //string inputFileName;
    string inputFileName;

    // File Descriptors
    //ofstream input;
    fstream input;
};

class Controller
{
public:
    Controller(size_t duration) : duration(duration)
    {
        setChannels();
    };
    ~Controller(){};

    // Duration
    size_t duration;

    // Read File
    void readFile();

private:
    // Channels of Controller
    FileDescriptor channel;

    // Init Channels
    void setChannels();
};

void Controller::setChannels()
{
    channel.inputFileName = string("output_0");

    //Create the Input channel
    channel.input.open(channel.inputFileName.c_str(), ofstream::out | ofstream::app);
    channel.input.close();

    channel.input.open(channel.inputFileName.c_str(), ios::in);
    if (channel.input.fail())
    {
        cout << "No file";
        exit(1);
    }
}

void Controller::readFile()
{
    channel.input.clear();
    string line = " nothing";
    getline(channel.input,line);
    cout << "Bad:" << channel.input.bad() << " EOF:" << channel.input.eof() << " Fail:" << channel.input.fail() << " GOOD:"<< channel.input.good();
    cout << line << endl;
}

int main(int argc, char *argv[])
{
    //Check number of arguments
    if (argc != 2)
    {
        cout << "too " << (argc < 3 ? "few " : "many ") << "arguments passed" << endl;
        cout << "Requires: Duration" << endl;
        return -1;
    }

    //Convert Char Array to long int
    long int arg = strtol(argv[1], NULL, 10);

    //Create a node
    Controller controller(arg);
    cout << endl;
    for (size_t i = 0; i < controller.duration; i++)
    {
        controller.readFile();

        sleep(1);
    }
    cout << "Controller Done" << endl;

    return 0;
}