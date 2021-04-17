#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Think about the class of the node, what all data structures will be required
Think about what all member functions will be required to handle the files.
*/

struct FileDescriptor
{
    // Store the name of the Files
    string inputFileName;
    string outputFileName;
    string receivedFileName;

    // File Desciptors
    fstream input;
    ofstream output;
    ofstream receivedData;
};

struct Routing
{
    // Destination Node
    size_t dest;

    // Buffer for the data to be sent
    string dataMessage;

    // Keep track of Incoming Neighbors
    size_t incomingNeighbor[10][10];

    // In-tree of a Node
    size_t intree[10][10];
};

class Node
{
public:
    Node(size_t ID, size_t duration, size_t dest, string dataMessage);
    ~Node();

private:
    // ID of the node
    size_t ID;

    // Duration
    size_t duration;

    // Channels of the Node
    FileDescriptor channel;

    // Routing Data Structure
    Routing msg;

    // init the channels
    void setChannel();
};

Node::Node(size_t ID, size_t duration, size_t dest, string dataMessage = "") : ID(ID), duration(duration)
{
    setChannel();
}

Node::~Node()
{
    channel.input.close();
    channel.output.close();
    channel.receivedData.close();
}

void Node::setChannel()
{
    channel.inputFileName = string("input_") + char('0' + ID);
    channel.outputFileName = string("output_") + char('0' + ID);
    channel.receivedFileName = char('0' + ID) + string("_received");

    //cout << channel.inputFileName << endl;
    //cout << channel.outputFileName << endl;
    //cout << channel.receivedFileName << endl;

    //Create the Input channel
    channel.input.open(channel.inputFileName, ofstream::out);
    channel.input.close();

    channel.input.open(channel.inputFileName, ifstream::in);
    channel.output.open(channel.outputFileName, ofstream::out | ofstream::app);
    channel.receivedData.open(channel.receivedFileName, ofstream::out | ofstream::app);
}

int main(int argc, char *argv[])
{
    //Check number of arguments
    if (argc < 4 || argc > 5)
    {
        cout << "too " << (argc < 4 ? "few " : "many ") << "arguments passed" << endl;
        return -1;
    }

    //Convert Char Array to long int
    long int arg[3];
    for (int i = 0; i < 3; i++)
        arg[i] = strtol(argv[i + 1], NULL, 10);

    //Check if a node is going to send data or not
    string data;
    if (arg[2] == -1)
        data = "";
    else
        data = argv[4];

    Node node(arg[0], arg[1], arg[2], data);

    //Init the class of the nodes here
    //Check for the count of argc, throw exeception

    //Built a driver to do the stuff within the particular duration
    // Send Hello Message every 30 seconds
    // Send In tree message every 10 seconds
    // Send Data message every 15 seconds
    // Read the Input file and update the received file if neccessary

    //Add sleep(1) after for every one second,
}