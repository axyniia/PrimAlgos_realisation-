

#ifndef PRIM__GRAPH_H
#define PRIM__GRAPH_H
#include <vector>
#include <list>


class Graph{
public:

    Graph(std::vector<std::pair<float, float>> node) : _Node(node) {}
    void fillDist();
    void Prim();



private:
    std::vector<std::pair<float, float>> _Node;
    std::vector<std::vector<float>> _Dist;
    std::list<std::pair<int, int>> *_List;
    int VetrexNum;

};


#endif //PRIM__GRAPH_H
