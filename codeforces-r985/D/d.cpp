#include <climits>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Vertex {
    int index;
    map<int, Vertex*> connections;

    void connect(Vertex* vertex) {
        connections[vertex->index] = vertex;
        vertex->connections[this->index] = this;
    }

    void disconnect(Vertex* vertex) {
        connections.erase(vertex->index);
        vertex->connections.erase(this->index);
    }

    void performOp(Vertex* v1, Vertex* v2) {
        if (connections.count(v1->index)) {
            disconnect(v1);
        } else connect(v1);

        if (connections.count(v2->index)) disconnect(v2);
        else connect(v2);

        if (v1->connections.count(v2->index)) v1->disconnect(v2);
        else v1->connect(v2);
    }
};

struct Operation {
    int v1, v2, v3;

    Operation(int a, int b, int c) {
        v1=a+1;
        v2=b+1;
        v3=c+1;
    }
};

void run() {
    int n, m;
    cin >> n >> m;
    
    vector<Vertex> vertices(n, Vertex());
    for (int i=0; i < n; i++) {
        vertices[i].index = i;
    }
    for (int i=0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vertices[x-1].connections[y-1] = &vertices[y-1];
        vertices[y-1].connections[x-1] = &vertices[x-1];
    }

    vector<Operation> operations;

    // First, we remove as many edges as possible
    bool done = false;
    while (!done) {
        done = true;
        for (int i=0; i < n; i++) {
            while (vertices[i].connections.size() > 1) {
                done = false;
                Vertex* v1 = vertices[i].connections.begin()->second;
                Vertex* v2 = (++vertices[i].connections.begin())->second;
                operations.push_back(Operation(i, v1->index, v2->index));
        
                vertices[i].performOp(v1, v2);
            }
        }
    }

    // Check if graph is empty
    bool empty = true;
    int rootIndex = 0;
    for (int i=0; i < n; i++) {
        if (vertices[i].connections.size() != 0) {
            rootIndex = i;
            empty = false;
            break;
        }
    }

    // If the graph is not empty, we construct a tree
    if (!empty) {
        vector<bool> done(n, false);

        done[rootIndex] = true;
        done[vertices[rootIndex].connections.begin()->second->index] = true;

        Vertex* root = &vertices[rootIndex];
        Vertex* otherRoot = root->connections.begin()->second;
        int otherRootIndex = otherRoot->index;

        for (int i=0; i < n; i++) {
            if (done[i]) continue;

            if (vertices[i].connections.size() == 0) {

                vertices[i].performOp(root, otherRoot);
                operations.push_back(Operation(i, rootIndex, otherRootIndex));
                otherRoot = &vertices[i];
                otherRootIndex = i;

            } else if (vertices[i].connections.size() == 1) {

                int index = vertices[i].connections.begin()->first;
                vertices[i].performOp(root, &vertices[index]);
                operations.push_back(Operation(i, rootIndex, index));
                done[index] = true;

            } else {
                cout << "ERROR";
            }
        }
    }

    // Print out operations
    cout << operations.size() << endl;
    for (auto op : operations) {
        cout << op.v1 << " " << op.v2 << " " << op.v3 << endl;
    }
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}