/*

Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE 3110
Instructor: Robert Renka
Date: 12/5/17

                        CSCE 3110  Program #6


        Due date:  Tuesday, 12/05/2017


        Write a program that implements Kruskal's algorithm (Figure 9.58)
        with vertices designated by integers 1 to N and integer edge
        weights.  Refer to Figures 8.6 - 8.9 for the disjoint set class
        and union/find algorithm.  Code for the priority queue is in
        Figures 6.4, 6.12, and 6.14.

        Include a main function that stores the graph of Figure 9.48
        and prints a table of edgelist in the minimum spanning tree.

        Include error checks and comments as always.


        Your program should be implemented in a single file named
        prog6_Name.cpp, where Name is your last name, and submitted
        via Blackboard.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * Disjoint set class.
 * Use union by rank and path compression.
 * Elements in the set are numbered starting at 0.
 */
class DisjSet {
    public:
        explicit
    /**
     * Construct the disjoint sets object.
     * numElements is the initial number of disjoint sets.
     */
    DisjSet(int numElements): s(numElements, -1) {}


    /**
     * Perform a find.
     * Error checks omitted again for simplicity.
     * Return the set containing x.
     */
    int find(int x) const {
        if (s[x] < 0)
            return x;
        else
            return find(s[x]);
    }

    /**
     * Perform a find with path compression.
     * Error checks omitted again for simplicity.
     * Return the set containing x.
     */
    int find(int x) {
        if (s[x] < 0)
            return x;
        else
            return s[x] = find(s[x]);
    }

    /**
     * Union two disjoint sets.
     * For simplicity, we assume root1 and root2 are distinct
     * and represent set names.
     * root1 is the root of set 1.
     * root2 is the root of set 2.
     */
    void unionSets(int root1, int root2) {
        if (s[root2] < s[root1]) // root2 is deeper
            s[root1] = root2; // Make root2 new root
        else {
            if (s[root1] == s[root2])
                --s[root1]; // Update height if same
            s[root2] = root1; // Make root1 new root
        }
    }


    private:
        vector < int > s;
};

template < typename Comparable >
    class BinaryHeap {
        public:
            explicit BinaryHeap(int capacity = 100): array(capacity + 1), currentSize {
                0
            } {}

        explicit BinaryHeap(const vector < Comparable > & items): array(items.size() + 10), currentSize {
            static_cast<int>(items.size())
        } {
            for (int i = 0; i < items.size(); ++i)
                array[i + 1] = items[i];
            buildHeap();
        }

        bool isEmpty() const {
            return currentSize == 0;
        }

        /**
         * Find the smallest item in the priority queue.
         * Return the smallest item, or throw Underflow if empty.
         */
        const Comparable & findMin() const {
            if (isEmpty())
                return;
            return array[1];
        }

        /**
         * Insert item x, allowing duplicates.
         */
        void insert(const Comparable & x) {
            if (currentSize == array.size() - 1)
                array.resize(array.size() * 2);

            // Percolate up
            int hole = ++currentSize;
            Comparable copy = x;

            array[0] = std::move(copy);
            for (; x < array[hole / 2]; hole /= 2)
                array[hole] = std::move(array[hole / 2]);
            array[hole] = std::move(array[0]);
        }


        /**
         * Insert item x, allowing duplicates.
         */
        void insert(Comparable && x) {
            if (currentSize == array.size() - 1)
                array.resize(array.size() * 2);

            // Percolate up
            int hole = ++currentSize;
            for (; hole > 1 && x < array[hole / 2]; hole /= 2)
                array[hole] = std::move(array[hole / 2]);
            array[hole] = std::move(x);
        }

        /**
         * Remove the minimum item.
         * Throws UnderflowException if empty.
         */
        void deleteMin() {
            if (isEmpty())
                return;

            array[1] = std::move(array[currentSize--]);
            percolateDown(1);
        }

        /**
         * Remove the minimum item and place it in minItem.
         * Throws Underflow if empty.
         */
        void deleteMin(Comparable & minItem) {
            if (isEmpty())
                return;

            minItem = std::move(array[1]);
            array[1] = std::move(array[currentSize--]);
            percolateDown(1);
        }

        void makeEmpty() {
            currentSize = 0;
        }

        private:
            int currentSize; // Number of elements in heap
        vector < Comparable > array; // The heap array

        /**
         * Establish heap order property from an arbitrary
         * arrangement of items. Runs in linear time.
         */
        void buildHeap() {
            for (int i = currentSize / 2; i > 0; --i)
                percolateDown(i);
        }

        /**
         * Internal method to percolate down in the heap.
         * hole is the index at which the percolate begins.
         */
        void percolateDown(int hole) {
            int child;
            Comparable tmp = std::move(array[hole]);

            for (; hole * 2 <= currentSize; hole = child) {
                child = hole * 2;
                if (child != currentSize && array[child + 1] < array[child])
                    ++child;
                if (array[child] < tmp)
                    array[hole] = std::move(array[child]);
                else
                    break;
            }
            array[hole] = std::move(tmp);
        }
    };

class Graph {

    public:

        class Edge {
            public:
                int v1, v2, weight;

            explicit Edge(): weight(0) {}

            explicit Edge(int a, int b, int w): v1(a), v2(b), weight(w) {}

            int getWeight() const {
                return weight;
            }

            int getFirstint() const {
                return v1;
            }
            int getSecondint() const {
                return v2;
            }

            bool operator > (Edge & e) {
                return this->getWeight() > e.getWeight();
            }

            bool operator < (Edge & e) {
                return this->getWeight() < e.getWeight();
            }

            bool operator == (Edge & e) {
                return this->getWeight() == e.getWeight();
            }

            friend ostream & operator << (ostream & os,
                const Edge & e) {
                printf("[%d, %d]\tw: %d", e.getFirstint(), e.getSecondint(), e.getWeight());
                return os;
            }

        };

    private:
        int NUM_VERTICES;
    vector < Edge > edgelist;
    set < int > vertices;

    public:
        vector < Edge > getedges() {
            return edgelist;
        }

    void addEdge(int v1, int v2, int w) {

        //cout << v1 << endl;
        //cout << v2 << endl;
        //cout << w << endl;


        Edge e(v1, v2, w);
        edgelist.push_back(e);
        vertices.insert(v1);
        vertices.insert(v2);
        NUM_VERTICES = vertices.size();


        //cout << e << " " << NUM_VERTICES << endl;

    }

    explicit Graph(): NUM_VERTICES(0) {

    }

    void kruskal() {
        vector < Edge > minSpanningTree;
        int edgelistAccepted = 0;
        DisjSet ds(NUM_VERTICES);
        BinaryHeap < Edge > pq(getedges());
        Edge e;
        int u, v;

        while (edgelistAccepted < NUM_VERTICES - 1) {
            pq.deleteMin(e); // Edge e = (u. v)
            //cout << e;
            u = e.getFirstint();
            v = e.getSecondint();
            //cout << " u: "<< u << " " << v << endl;
            int uset = ds.find(u);
            int vset = ds.find(v);
            if (uset != vset) {
                // Accept the edge
                edgelistAccepted++;
                minSpanningTree.push_back(e);
                ds.unionSets(uset, vset);
            }
        }

        cout << "Printing all edges in the minimum spanning tree: \n";
        for (Edge e: minSpanningTree) {
            cout << e << endl;
        }
    }
};

int main() {
    Graph g;

/*
    // First Graph on  Figure 9.48
    // 1. a
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 1);

    // 2. b
    g.addEdge(2, 4, 2);

    // 3. c
    g.addEdge(3, 6, 2);

    // 4. d
    g.addEdge(4, 6, 3);

    // 5. s
    g.addEdge(5, 1, 3);
    g.addEdge(5, 2, 2);

    // 6. t
*/

    // Second Graph of Figure 9.48
    // 1. a
    g.addEdge(0, 1, 1);
    g.addEdge(0, 3, 3);
    g.addEdge(0, 4, 3);

    // 2. b
    g.addEdge(1, 4, 2);

    // 3. c
    g.addEdge(2, 0, 2);
    g.addEdge(2, 5, 1);

    // 4. d
    g.addEdge(3, 0, 1);
    g.addEdge(3, 1, 2);

    // 5. s
    g.addEdge(4, 0, 1);

    // 6. t
    g.addEdge(5, 2, 2);
    g.addEdge(5, 3, 3);

    g.kruskal();
    return 0;
}
