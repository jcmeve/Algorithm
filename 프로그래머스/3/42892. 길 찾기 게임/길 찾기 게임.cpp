#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int id, x, y;
    int left;
    int right;
};

bool comp(const Node& lhs, const Node& rhs){
    if(lhs.y != rhs.y){
        return lhs.y > rhs.y;
    }
    return lhs.x < rhs.x;
}

vector<Node> nodes;

void makeTree(int nodeIdx, int lBound, int rBound){
    Node* node = &nodes[nodeIdx];
    
    for(int i = nodeIdx; i < nodes.size(); ++i){
        if(nodes[i].y < node->y && nodes[i].x < rBound && nodes[i].x > lBound){
            if(nodes[i].x < node->x && node->left == -1){
                node->left = i;   
                makeTree(i, lBound, node->x);
            }else if(nodes[i].x > node->x && node->right == -1){
                node->right = i;
                makeTree(i, node->x, rBound);
                break;
            }
        } 
    }
}

void preorder(int idx, vector<int>& res) {
    if (idx == -1) return;
    res.push_back(nodes[idx].id);
    preorder(nodes[idx].left, res);
    preorder(nodes[idx].right, res);
}
                     
void postorder(int idx, vector<int>& res) {
    if (idx == -1) return;
    postorder(nodes[idx].left, res);
    postorder(nodes[idx].right, res);
    res.push_back(nodes[idx].id);
}              
                     
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    nodes = vector<Node>(nodeinfo.size());
    for(int i = 0; i < nodeinfo.size(); ++i){
        nodes[i].id = i+1;
        nodes[i].x = nodeinfo[i][0];
        nodes[i].y = nodeinfo[i][1];
        nodes[i].left = -1;
        nodes[i].right = -1;
    }
    
    sort(nodes.begin(),nodes.end(), comp);
    
    makeTree(0, -1 , 100001);
    preorder(0, answer[0]);
    postorder(0, answer[1]);
    return answer;
}