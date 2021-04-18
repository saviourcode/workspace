#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
using namespace std;

struct FileDescriptor
{
    // Store the name of the file
    string inputFileName;
    string outputFileName;

    // File Descriptors
    fstream input;
    ofstream output;
};

class NodeRecord
{
public:
    NodeRecord(){};
    ~NodeRecord(){};

    // Total number of nodes
    size_t numNodes = 0;

    // Channels of Controller
    FileDescriptor *channels;

    // Create the channels
    void createChannels();
};

void NodeRecord::createChannels()
{
    channels = new FileDescriptor[numNodes];

    for (size_t i = 0; i < numNodes; i++)
    {
        // Give a name to the files
        channels[i].inputFileName = string("output_") + char('0' + i);
        channels[i].outputFileName = string("input_") + char('0' + i);

        // Create the files
        channels[i].input.open(channels[i].inputFileName.c_str(), ios::in);
        channels[i].output.open(channels[i].outputFileName.c_str(), ios::out | ios::app);

        if(channels[i].input.fail())
        {
            cout << "Controller: Node " << i << " No input file" << endl;
            exit(1);
        }
        if(channels[i].output.fail())
        {
            cout << "Controller: Node " << i << " No output file" << endl;
            exit(1);
        }
    }
}

class Controller
{
public:
    Controller(size_t duration) : duration(duration)
    {
        setChannel();
        createNodeChannels();
    };
    ~Controller(){};

    // Duration
    size_t duration;

    // Read File
    string readFile();

private:
    // Channels of Controller
    FileDescriptor channel;

    // Node Record Entries
    NodeRecord nodes;

    // Init Channels
    void setChannel();

    //Create New Channels
    void createNodeChannels();

    //Parse the strings
    void parseString(string);
};

void Controller::parseString(string line) //Waring: Single Sequencial Digit Parser only!!
{
    // Store the characters
    char c1 = line[0];
    char c2 = line[2];

    if (unsigned(c1 - '0') + 1 > nodes.numNodes || unsigned(c2 - '0') + 1 > nodes.numNodes)
    {
        if ((c1 - '0') > (c2 - '0'))
            nodes.numNodes = c1 - '0' + 1;
        else
            nodes.numNodes = c2 - '0' + 1;
    }
}

void Controller::createNodeChannels()
{
    // Check and Parse the topology file
    string line;
    while (getline(channel.input, line) && !channel.input.eof())
    {
        parseString(line);
    }

    // Create the Channels
    nodes.createChannels();
}

void Controller::setChannel()
{
    // Store the name of the file to open
    channel.inputFileName = string("topology");
    channel.outputFileName = "";

    // Open the file as input
    channel.input.open(channel.inputFileName.c_str(), ios::in);
    if (channel.input.fail())
    {
        cout << "No file";
        exit(1);
    }
}

string Controller::readFile()
{
    string line = "";
    getline(channel.input, line);
    if (channel.input.eof())
    {
        channel.input.clear();
        line = "";
    }
    //cout << "Bad:" << channel.input.bad() << " EOF:" << channel.input.eof() << " Fail:" << channel.input.fail() << " GOOD:"<< channel.input.good();
    cout << line << endl;
    return line;
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

    // Let the nodes get init
    sleep(2);

    //Create a node
    Controller controller(arg);

    // Start the algo
    for (size_t i = 0; i < controller.duration; i++)
    {
        if (i % 30 == 0)
            controller.readFile();

        sleep(1);
    }
    cout << "Controller Done" << endl;

    return 0;
}