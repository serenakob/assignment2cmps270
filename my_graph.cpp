
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <map>
using namespace std;

struct Graph { 
public:
    Graph(const vector<int> &s, const vector<int> &e);
    int numOutgoing(const int nodeid);
    const vector<int> * adjacent(const int nodeid);
    vector<int> s, e;
};

//Constructs a Graph, where starts and ends represent the ordered list of edges’ start and endpoints.
Graph::Graph(const vector<int> &s, const vector<int> &e) {
    if (s.size() != e.size()) {
        throw errc::invalid_argument; // throws invalid argument error if lengths are unequal
    }
    this->s = s;
    this->e = e;
}
 //requires: nodeid should be in the graph
//effects: returns the number of outgoing edges from nodeid and throws invalid_argument if node_id is not a valid node in the graph

int Graph::numOutgoing(const int nodeid) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == nodeid) {
            count++; // counts all the nodes that have an incoming edge from nodeID
        }
    }
    return count;
}

 //requires: nodeid should be in the graph
 //effects: returns the nodes that are adjacent to the node with the given id and invalid_argument if node_id is not a valid node in the graph
const vector<int> * Graph::adjacent(const int nodeid) {
    vector<int>* temp; // initializes pointer
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == nodeid) {
            temp->push_back(e[i]); // adds edges of nodeID to vector
        }
    }
    return temp;
}

// Tested for error when starts and ends have unequal lengths
int main()
{
    int V = 5;
    vector<int> starts(6);
    starts.push_back(0);
    starts.push_back(0);
    starts.push_back(0);
    starts.push_back(4);
    starts.push_back(4);
    starts.push_back(3);
    vector<int> ends(6);
    ends.push_back(1);
    ends.push_back(2);
    ends.push_back(3);
    ends.push_back(3);
    ends.push_back(1);
    ends.push_back(1);


    Graph graph(starts, ends);

    const vector<int> result = *graph.adjacent(4); 
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " "; 
    }
    cout << "\n" << endl;
    cout << graph.numOutgoing(0) << endl; 
    return 0;
}
