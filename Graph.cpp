

#include "Graph.h"
#include <cmath>
#include <climits>
#include <functional>
#include <list>
#include <queue>
#include <utility>
#include <vector>

 //filling our graph with counted distance between verteces;


void Graph::fillDist() {
    const int MaxDist = _Node.size() ;
    for (int i = 0; i < MaxDist; i++)
    {
        std::vector<float> V;
        for(int j = 0; j < MaxDist;j++)
        {
            V.push_back(sqrt(pow((_Node[i].first - _Node[j].first),2) + pow((_Node[i].second - _Node[j].second),2)));
        }
        _Dist.push_back(V);

    }

}
//realisation of efficient Prim algorithm
void Graph::Prim() {

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> startNode;

    std::vector<int> allVert(VetrexNum, INT_MAX),
            Par(VetrexNum, INT_MIN);
    std::vector<bool> MstCheck(VetrexNum, false);
    startNode.push(std::make_pair(0, 0));
    allVert[0] = 0;
    int currVert;
    while (!startNode.empty()) {
        currVert = startNode.top().second;
        startNode.pop();
        MstCheck[currVert] = true;
        for (std::list<std::pair<int, int>>::iterator it = _List[currVert].begin(); it != _List[currVert].end(); ++it) {
            int v = (*it).first,
                    _weight = (*it).second;
            if (allVert[v] > _weight && !MstCheck[v])
            {
                allVert[v] = _weight;
                startNode.push(std::make_pair(allVert[v], v));
                allVert[v] = currVert;
            }
        }
    }
}