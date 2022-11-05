#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Graph{

public:

    Graph(const vector<int> &starts, const vector<int> &ends){
        for (int i = 0; i < starts.size(); i++){
            adj[starts[i]].push_back(ends[i]);
            }
        }
        //requires: nodeid should be a node in the graph        
        //Effects: returns the nodes that are adjacent to the node with the given id and throws invalid_argument if nodeid is not a valid node in the graph
        const vector<int> &adjacent(const int node_id) const{
            if (adj.find(node_id) == adj.end()){
                throw invalid_argument("nodeid is not in graph");
            }
            return adj.at(node_id);
        }
        //Requires: nodeid should be a node in the graph
        //Effects: returns the number of outgoing edges from nodeid and throws invalid_argument if nodeid is not a valid node in the graph
        int numOutgoing(const int nodeid) const{
            if (adj.find(nodeid) == adj.end()){
                throw invalid_argument("nodeid is not in the graph");
            }
            return adj.at(nodeid).size();
        }


        //Requires: nodeId is a valid node in the graph
        //Effects: returns a vector 
        vector<int> hasCycle(int nodeid, vector<bool> &visited, vector<int> &path){
            visited[nodeid] = true;
            vector<int> ourList;
            path.push_back(nodeid);
            for (int i = 0; i < adj[nodeid].size(); i++){
                if (!visited[adj[nodeid][i]]){
                    ourList = hasCycle(adj[nodeid][i], visited, path);
                }
                else{
                for (int j = 0; j < path.size(); j++){
                if (path[j] == adj[nodeid][i]){
                for (int k = j; k < path.size(); k++){
                    ourList.push_back(path[k]);
                }
                    ourList.push_back(adj[nodeid][i]);
                    return ourList;
                }
                }
                }
                }
                path.pop_back();
                return ourList;
            }
    private:
        map<int, vector<int> > adj;
    };