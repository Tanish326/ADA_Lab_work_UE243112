Practical 1 - 
AIM - To find sum of n numbers using reccursion 
Algorithm - 
step1 - Start
step2 - Read an integer n
step3 - Call the function sum(n)
step4 - If n == 0, return 0
step5 - Else, return n + sum(n-1)
step6 - Store the returned value in result
step7 -Print result
step8 - Stop
use cases - 
1) Mathematical calculations

2) Teaching recursion concepts

3) Problem-solving in competitive programming

4) Computing series sums

Time complexity analysis 
reccurance relation 
T(n) = c + T(n-1) 
<img width="1847" height="832" alt="image" src="https://github.com/user-attachments/assets/2a4b2c2b-3c29-4cd4-ada6-3cace58680e6" />
practical 2 - 
Aim - To compute x raised to  power n using an optimized recursive method with logarithmic time complexity.
algo - 
Start

Read base x and exponent n

Call function power(x, n)

If n == 0, return 1

If n is even:

Compute half = power(x, n/2)

Return half * half

If n is odd:

Compute half = power(x, n/2)

Return x * half * half

Print the result

Stop

Use Cases

Fast modular exponentiation

Cryptography (RSA, Diffie-Hellman)

Scientific computing

Competitive programming

Recurrence Relation ->
T(n) = T(n/2) + c 
<img width="1759" height="880" alt="image" src="https://github.com/user-attachments/assets/f522259c-7c85-4a5b-ac67-6c41c0f22c94" />

practical 3 - 
Aim - To generate and print all permutations of a given string using recursion.
Algorithm used - 
Start

Read the input string s

Call function permute(s, l, r)

If l == r, print the string

For i from l to r:

Swap s[l] with s[i]

Recursively call permute(s, l+1, r)

Swap back s[l] with s[i] (backtrack)

Use cases - 
Generating anagrams

Password cracking simulations

Combinatorics problems

Testing all possible arrangements

Stop
Time analysis - 
Reccurance relation 
T(n) = c + n*T(n-1) 
<img width="1856" height="942" alt="image" src="https://github.com/user-attachments/assets/d4c80319-2600-4a37-b3dc-8e3ffd6c4369" />

Practical -4 
Aim -To generate all possible binary combinations (0 and 1) of length n using recursion, which forms the truth table for n boolean variables.
Algo used ->
Start

Read integer n (number of variables)

Create an array arr of size n

Call function generate(pos)

If pos == n:

Print the array as one row of the truth table

Return

Set arr[pos] = 0 and call generate(pos + 1)

Set arr[pos] = 1 and call generate(pos + 1)

Stop

Use Cases ->

Digital logic design

Boolean function testing

Circuit simulation

Logic gate verification

Time analysis ->
reccurance relation - 
T(n) = 2*T(n-1) +c 
<img width="1671" height="888" alt="image" src="https://github.com/user-attachments/assets/e3984322-c1a6-4df1-b3dc-10b3253a4e81" />

Practical -5 
AIM - 
To move n disks from the Source rod to the Destination rod using an Auxiliary rod following the rules of Tower of Hanoi.
Algo used - 
Start

Read integer n (number of disks)

Call function TOH(n, source, auxiliary, destination)

If n == 1:

Move disk 1 from source to destination

Return

Move n-1 disks from source to auxiliary using destination

Move disk n from source to destination

Move n-1 disks from auxiliary to destination using source

Stop
Use cases - >
Understanding recursion and stack behavior

Algorithm design practice

Disk scheduling simulations

Puzzle solving and game logic
Time analysis - 
Reccurance relation - 
T(n) = 2*T(n-1) + 1 
<img width="1753" height="874" alt="image" src="https://github.com/user-attachments/assets/7533aeaa-1666-4496-a34f-ff792d2be47c" />
Practical - 6 
AIM - 
To search for a given element in an array using a recursive linear search technique.
Algorithm used - 
Start

Read array size n and elements

Read the target element key

Call function linearSearch(arr, n, key, index) with index = 0

If index == n, return -1 (not found)

If arr[index] == key, return index

Else call linearSearch(arr, n, key, index + 1)

Print result

Stop
Use cases - 
Searching in small datasets

Educational recursion examples

Simple lookup operations

Time complexity analysis ->
T(n) = T(n-1) + c 
<img width="1919" height="967" alt="image" src="https://github.com/user-attachments/assets/16b19553-25ef-4b44-97b9-53f5a6d2aa97" />

Practical 7- 
Aim - To evaluate a polynomial expression efficiently using Horner’s Rule with recursion.
Algo used - 
Start

Read degree n

Read coefficients array a[0…n]

Read value of x

Call function horner(a, n, x)

If n == 0, return a[0]

Else return:
Print the result

Stop
USE CASE =>
Polynomial evaluation in compilers

Signal processing

Numerical methods

Scientific computing

Time complexity analysis =>
T(n) = T(n-1) + 1
<img width="955" height="696" alt="image" src="https://github.com/user-attachments/assets/8bbd6817-44a3-4d72-82c9-261c50f917aa" />

  Practical -8 
  Aim - 
  To sort an array of n elements in ascending order using iterative Selection Sort.
  ALGO USED - 
  Start

Read array size n and elements arr[0…n-1]

For i = 0 to n-2:

Set minIndex = i

For j = i+1 to n-1:

If arr[j] < arr[minIndex], update minIndex = j

Swap arr[i] with arr[minIndex]

Print the sorted array

Stop

Use cases - 
Sorting small arrays

Learning basic sorting techniques

Step-by-step algorithmic practice

Time analysis ->
time is o(n^2) both for worst and best case 
<img width="1691" height="909" alt="image" src="https://github.com/user-attachments/assets/9ad2fce5-324e-4b4a-a69c-e4e48c3dd9d2" />

Practical - 9 
Aim ->
to find the missing number in a sequence of consecutive integers using an efficient method.
Algo used ->
Start

Read array arr[] of size n-1

Loop through the array from i = 0 to n-2

Calculate expected_bit0 = 1 if i % 2 == 0 else 0

Calculate actual_bit0 = arr[i] & 1

If actual_bit0 != expected_bit0, return i → missing index

If no mismatch found, return n-1

Stop
Use cases ->
Detecting missing items in bit-patterned sequences

Low-level data validation / hardware testing

Competitive programming / algorithm optimization exercises

Time complexity analysis 
<img width="1816" height="863" alt="image" src="https://github.com/user-attachments/assets/37259260-6e93-4599-82ac-f2a033ffeffc" />

Practical - 10 
Aim -> 
To find the first occurrence of duplicate elements in an array using a simple nested loop approach.
Algo used ->
Start

Read array arr[] of size n

For i = 0 to n-2:

For j = i+1 to n-1:

If arr[i] == arr[j]:

Return i (index of first duplicate)

If no duplicates found, return -1

Stop
Use cases ->
Simple duplicate detection in small arrays

Educational example to understand brute-force searching

Can be used in exams and lab practicals to demonstrate nested loops logic

Time complexity anslysis ->
<img width="1847" height="933" alt="image" src="https://github.com/user-attachments/assets/a15efc43-4279-43dd-9bb7-fb2c0df0b3fd" />

Practical -11 
Aim - to find number of bounces of a ball thrown from a height 
Algo used -
Start

Read initial velocity vel and set bounce count n = 0

Call function bounce(vel, n)

If vel < 1, return n (base case)

Else:

Multiply velocity by 0.575

Increment n by 1

Recursively call bounce(0.575 * vel, n)

Print total number of bounces

Stop
Use case - 
Physics simulations (ball bounce, energy loss)

Teaching recursion and logarithmic processes

Game physics and animations

Time analysis ->
<img width="1714" height="877" alt="image" src="https://github.com/user-attachments/assets/7eff5b6b-b403-409f-9e75-df98b6340f38" />


Practical - 12 
Aim : to do sorting of given array using merge sort divide and conquer 
algo used :
MERGE_SORT(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        
        MERGE_SORT(arr, left, mid)
        MERGE_SORT(arr, mid + 1, right)
        
        MERGE(arr, left, mid, right)

MERGE(arr, left, mid, right):
    L = arr[left...mid]
    R = arr[mid+1...right]

    i = 0, j = 0, k = left

    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1

    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1

  time complexity analyis 
  
<img width="1650" height="841" alt="image" src="https://github.com/user-attachments/assets/8882986d-087a-40ee-9cb2-f448a241fa4e" />

Recurance relation : T(n) = T(n/2) + n

Applications :
External Sorting (Big Data / Files)
Used when data doesn’t fit in memory (disk-based sorting)
Linked List Sorting
Works efficiently because no random access is needed
Stable Sorting Required
Preserves order of equal elements (useful in databases)
Inversion Count Problems
Used to count number of inversions in an array
Parallel Processing
Easily parallelizable due to divide-and-conquer

Practical - 13 
Aim : to sort the elements of given array using quick sort and find time complexity 
Algo used 
QUICK_SORT(arr, low, high):
    if low < high:
        pi = PARTITION(arr, low, high)

        QUICK_SORT(arr, low, pi - 1)
        QUICK_SORT(arr, pi + 1, high)


PARTITION(arr, low, high):
    pivot = arr[high]   // choosing last element as pivot
    i = low - 1

    for j = low to high - 1:
        if arr[j] <= pivot:
            i += 1
            swap(arr[i], arr[j])

    swap(arr[i + 1], arr[high])

    return i + 1

    Complexity analyis 
    <img width="1745" height="854" alt="image" src="https://github.com/user-attachments/assets/a1d1d5e5-bdb2-4e58-a8d3-f6a73ac8a809" />
 recurance relation 
 T(n) = T(n/2) + n
 Applications :
 General Purpose Sorting (In-Memory)
Very fast in practice, used in many libraries
Low Memory Environments
In-place algorithm (no extra array required)
Cache Efficient Sorting
Good locality of reference → faster on real machines
Partition-Based Problems
Used in problems like:
finding kth smallest/largest element
Quick Select algorithm
Used in Standard Libraries
Many languages use optimized Quick Sort variants

Practical - 14 
Aim : to search for the element in a array using binary search
algo used :
Binary_search(int array[],int low,int high,int target){
    if(low==high){
      if(target == array[low])
      return true
      else
      return false
    }
    int mid = (low + high)/2;
    if(target==array[mid])
    return true;
    else if(target > array[mid])
    return Binary_search(array,mid+1,high,target)
    else
    return Binary_search(array,low,mid-1,target)
    
    
}
Complexity analysis
Recurance relation 
T(n) = T(n/2) + c
<img width="1710" height="874" alt="image" src="https://github.com/user-attachments/assets/a2af3269-35a5-4a04-94a5-3d1a2d631915" />
Applications :
Searching in Sorted Arrays
Fast lookup in O(log n)
Finding Boundaries
First/last occurrence of an element
Search in Monotonic Functions
Used in problems where answer space is sorted
Optimization Problems (Binary Search on Answer)
Used in:
minimizing/maximizing values
allocation problems (books, pages, etc.)
Real-World Uses
Searching in databases
Finding values in large datasets

Practical -15 
Aim : to find max , min from a given array using divide and conquer 
Algorithm used :
int findmaxmin(int array[],int min_elem,int max_elem,int low,int high){
if(low==high){
    if(array[low] > ma_elem)
    return array[low]
    else if(array[low] < min_elem)
    return array[low]
    
}
if(low == high + 1)
if(array[low] > array[high])
if(array[low] > max_elem)
return array[low]
else
return array[high]
else
if(array[low] < min_elem)
return array[low]
else
return array[high]

int mid = (low + high)/2;
return  findmaxmin(array,max_elem,min_elem,low,mid)
return findmaxmin(array,max_elem,min_elem,mid+1,high)

analysis 

<img width="945" height="714" alt="image" src="https://github.com/user-attachments/assets/24f2453a-5136-4e7c-828f-c1882d39884c" />
T(n) = T(n/2) + c


Practical- 16
Aim : to join the points given and form a polygen using divide and conquer
algo used :
QUICK_HULL(points):
    find leftmost point A and rightmost point B

    hull = {}

    find points on left side of line AB → S1
    find points on right side of line AB → S2

    FIND_HULL(S1, A, B, hull)
    FIND_HULL(S2, B, A, hull)

    return hull


FIND_HULL(S, P, Q, hull):
    if S is empty:
        add Q to hull
        return

    find point C in S farthest from line PQ

    find points left of line PC → S1
    find points left of line CQ → S2

    FIND_HULL(S1, P, C, hull)
    FIND_HULL(S2, C, Q, hull)

  complexity anaylysis :
  <img width="1919" height="870" alt="image" src="https://github.com/user-attachments/assets/0c5d8606-d0f8-44e0-81ca-b0e0733bea43" />

Applications :
Quick Hull is used to find the convex boundary of point sets in graphics, GIS, image processing, and collision detection.

Practical - 17
Aim : to multiply 2 matrices using divide and conquer 
algo used 
MULTIPLY(A, B, n):
    create matrix C of size n x n

    if n == 1:
        C[0][0] = A[0][0] * B[0][0]
        return C

    divide A into A11, A12, A21, A22
    divide B into B11, B12, B21, B22

    C11 = MULTIPLY(A11, B11, n/2) + MULTIPLY(A12, B21, n/2)
    C12 = MULTIPLY(A11, B12, n/2) + MULTIPLY(A12, B22, n/2)
    C21 = MULTIPLY(A21, B11, n/2) + MULTIPLY(A22, B21, n/2)
    C22 = MULTIPLY(A21, B12, n/2) + MULTIPLY(A22, B22, n/2)

    combine C11, C12, C21, C22 into matrix C

    return C
    <img width="920" height="731" alt="image" src="https://github.com/user-attachments/assets/531e99b7-1732-44a9-89e1-8813790ff41c" />

 T(n) = T(n/2) + n^2

 <img width="900" height="719" alt="image" src="https://github.com/user-attachments/assets/5f3cf6d6-db13-43b6-9642-2a80fd32432d" />

 Using Strassens 
 algo used : 
 Strassen(A, B):
    if size == 1:
        return A * B


    divide A, B into submatrices

    compute M1 to M7

    compute C11, C12, C21, C22

    combine into result matrix C

    return C

 Time complexity analyis 
 <img width="925" height="728" alt="image" src="https://github.com/user-attachments/assets/feeca13c-03e5-4790-a5d1-4e5d3023beac" />

 Practical - 19 
 Aim : to find optimize solution for collecting n items in the bag with weight w and  earning maximum profit 
 algo used :
 struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight >
           (double)b.value / b.weight;
}

double fractionalKnapsack(vector<Item>& items, int W) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0;

    for (auto &it : items) {
        if (W == 0) break;

        if (it.weight <= W) {
            W -= it.weight;
            totalValue += it.value;
        }
        else {
            totalValue += it.value * ((double)W / it.weight);
            W = 0;
        }
    }

    return totalValue;
}

Complexity analysis 
<img width="1758" height="832" alt="image" src="https://github.com/user-attachments/assets/982e048b-9dba-420b-9949-df6b04963d55" />
<img width="1414" height="866" alt="image" src="https://github.com/user-attachments/assets/b4e327ac-a08c-4409-a253-961bb96ac8f1" />
<img width="1391" height="850" alt="image" src="https://github.com/user-attachments/assets/10080f09-a7e8-4ecf-8476-0938a7788acf" />

Practical -20 
Aim : schedule the cpu time for the proceses given such that max number of processes are compatable with each other 
algo used 
struct Activity {
    int start, finish;
};

bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}

int activitySelection(vector<Activity>& arr) {
    sort(arr.begin(), arr.end(), cmp);

    int count = 1;
    int lastFinish = arr[0].finish;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].start >= lastFinish) {
            count++;
            lastFinish = arr[i].finish;
        }
    }

    return count;
}
complexity analysis 
<img width="1728" height="864" alt="image" src="https://github.com/user-attachments/assets/139c9ab5-2497-4e24-9f24-8e3154db0b3c" />
Applications :
 1. Meeting Room Scheduling

Used to schedule maximum number of meetings in a single room without overlap. Common in offices, schools, and event planning.

2. CPU Scheduling (Operating Systems)

Helps in scheduling processes or jobs efficiently to maximize CPU utilization and reduce idle time.

 3. Cloud Computing Task Scheduling

Used in cloud platforms to assign time slots to different tasks so that servers are efficiently utilized.

 4. Network Bandwidth Allocation

Used in communication systems to schedule data packets and allocate transmission time without collision.

Practical - 21 
Aim : To find the shortest distance bw any two points in a graph 
algo used :
dijkastra 
vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
complexity analyis 

<img width="1595" height="789" alt="image" src="https://github.com/user-attachments/assets/b7894034-5ec9-40ed-89c3-638ddda52af4" />


Applications :
GPS Navigation Systems

Used in applications like Google Maps to find the shortest or fastest route between two locations.

 2. Internet Routing (Network Routing)

Used in computer networks to determine the best path for data packets between routers.

 3. Shortest Path in Maps

Helps in finding shortest distance between cities, locations, or nodes in map-based applications.

 4. Telecommunication Networks

Used to efficiently route calls and data through the least-cost path in telecom networks.

practical 22 :
Aim : To find the minimum spanning tree in a graph using prims 
algo used :
function Prim(graph, V):
    for each vertex v:
        key[v] = INF
        parent[v] = -1
        inMST[v] = false

    key[0] = 0
    minHeap.push({0, 0})   

    while heap not empty:
        u = extractMin()

        if inMST[u] == true:
            continue

        inMST[u] = true

        for each (v, weight) in adj[u]:
            if inMST[v] == false AND weight < key[v]:
                key[v] = weight
                parent[v] = u
                minHeap.push({key[v], v})

    return parent array (MST)

Time complexity anslyis 
<img width="1449" height="857" alt="image" src="https://github.com/user-attachments/assets/5e25b540-2f0c-49d2-90e2-fe4e098a8a1d" />

Applications :
 Network Design – Used to design cost-efficient computer networks (LAN/WAN, internet backbone).
 Utility Networks – Planning water supply, gas pipelines, and electricity distribution systems.
 Road & Railway Construction – Connecting cities with minimum construction cost.
 Telecommunication Networks – Designing efficient communication line layouts.
 VLSI Circuit Design – Minimizing wiring cost and improving efficiency in chips.
 Clustering (Machine Learning) – Used in data clustering using Minimum Spanning Tree.

 Practical 23 :
 aim : to find minimum spanning tree using krushkal algo 
 algo used :
 struct Edge {
    int u, v, wt;
};

bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

vector<Edge> kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            mst.push_back(e);
            unionSet(e.u, e.v, parent, rank);
        }
    }

    return mst;
}

Time complexity anslyis 
<img width="1718" height="790" alt="image" src="https://github.com/user-attachments/assets/b5bd638b-8d04-4e4e-b378-b966b6a2c66f" />
Applications :
 Network Design – Used to design cost-efficient computer networks (LAN/WAN, internet backbone).
 Utility Networks – Planning water supply, gas pipelines, and electricity distribution systems.
 Road & Railway Construction – Connecting cities with minimum construction cost.
 Telecommunication Networks – Designing efficient communication line layouts.
 VLSI Circuit Design – Minimizing wiring cost and improving efficiency in chips.
 Clustering (Machine Learning) – Used in data clustering using Minimum Spanning Tree.

 Practical 24 : 
 Aim : To detect a cycle in a graph using disjoint set 
 algo used 
 vector<int> parent, rank;

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

bool detectCycle(int V, vector<pair<int,int>>& edges) {
    parent.resize(V);
    rank.assign(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (find(u) == find(v))
            return true;   

        unionSet(u, v);
    }

    return false;
}
complexity anslyis 
<img width="893" height="699" alt="image" src="https://github.com/user-attachments/assets/50abb639-5a8f-40f5-9e0a-123e5d5318b0" />
 Used in Kruskal’s Algorithm to avoid cycles while building MST
 Used in network design to ensure no loops in connections
 Used in telecommunication networks for loop-free routing
 Helps in deadlock detection (resource allocation systems)
 Used to check if a graph is a valid tree (acyclic connected graph)
 Used in dynamic connectivity problems where edges are added over time

practical 25 :
Aim : To calculate stages and number of vertices in each stage in a multistaged graph
algo used 
vector<int> findStages(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0), stage(V, 0);
    queue<int> q;

    
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            stage[i] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            stage[v] = max(stage[v], stage[u] + 1);

            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return stage;
}
complexity analysis :
<img width="889" height="684" alt="image" src="https://github.com/user-attachments/assets/53fee218-994e-40f5-af12-5501a6229f79" />

applications :
Shortest Path Problems – Used in routing systems (like finding optimal path in stages from source to destination).
Navigation Systems – GPS and map applications where decisions are made step-by-step across multiple stages.
 Production Planning – Used in manufacturing processes where work is completed in sequential stages.
 Dynamic Programming Problems – Many DP problems (like optimal path, cost minimization) are modeled using multistage graphs.
 Network Routing – Packet routing where data moves through multiple intermediate stages (routers).
 Game Theory / AI Pathfinding – Decision making in multi-level games or AI state transitions.

 Practical 26 :
 Aim : to find shortest distance from source to sink using forward approach in a Multistaged graph 
 algo used :
 Start from source node
Initialize: cost[source] = 0, others = ∞
Move stage by stage (left → right)
For each edge u → v:
Update: cost[v] = min(cost[v], cost[u] + weight(u,v))
Final answer is the cost at destination node

complexity analyis
<img width="915" height="689" alt="image" src="https://github.com/user-attachments/assets/3a5bac04-61fb-447c-be6b-8dd0da0d10e7" />

Practical 27 :
Aim : using backward approach 
Start from destination node
Initialize: cost[destination] = 0
Move stage by stage (right → left)
For each edge u → v:
Update: cost[u] = min(cost[u], weight(u,v) + cost[v])
Final answer is the cost at source n

<img width="923" height="719" alt="image" src="https://github.com/user-attachments/assets/81ace2db-ebc0-437c-b121-034c70455247" />

Practical 28 :
Aim : to find minimum number of scaler multiplications when matrices are multiplied with given order 
algo used 
int matrixChainMultiplication(vector<int> &p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n-1];
}
<img width="877" height="671" alt="image" src="https://github.com/user-attachments/assets/e64cf391-5b02-427d-a7f4-463a0708e8a0" />
Applications :
Compiler Optimization – Used in optimizing expression evaluation and reducing computation cost in compilers.
 Matrix Computations in Scientific Computing – Efficient multiplication of multiple matrices in simulations and numerical methods.
 Machine Learning / Deep Learning – Used in optimizing chained matrix operations in neural networks.
 Computer Graphics – Applied in transformations (rotation, scaling, projection) involving multiple matrix multiplications.
 Signal Processing – Helps optimize filter and transformation operations involving matrices.
 Dynamic Programming Problems – Used as a base model for interval DP problems and optimization techniques.

Practical 29 :
Aim : To find longest common subsequence from the two strings
Algo used 
int lcs(string a , string b)
int n = a.size()
int m = b.size()
initialize dp[n+1][m+1]
for( i = 0 to n)
dp[i][0] = 0
for(i= 0 to m)
dp[0][i] = 0

for(i = 1 to n)
for (j = 1 to m)
if(a[i-1]==b[j-1]
     dp[i][j] = 1 + dp[i-1][j-1]
else
dp[i][j] = max(dp[i-1][j],dp[i][j-1])

time complexity analyis 
o(n*m)
<img width="1755" height="854" alt="image" src="https://github.com/user-attachments/assets/b7a225de-abce-40fe-a702-80277a2a0c7b" />

applications : 
. File Comparison

LCS is used in file comparison tools such as diff utilities and version control systems to identify added, deleted, or modified lines between two files.

2. DNA Sequence Matching

In bioinformatics, LCS helps compare DNA, RNA, and protein sequences to find similarities, which is useful in gene analysis and medical research.

3. Plagiarism Detection

LCS is used to compare documents, assignments, and source code to detect copied or similar content.

practical - 30 
Aim : to find shortest path bw any two pairs 
Algo used 
# Algorithm to Find Shortest Distance and Path

## Step 1: Initialize Distance Matrix

Create a distance matrix `dist[][]` where:

* `dist[i][j] = weight of edge between i and j`
* If no direct edge exists, set `dist[i][j] = INF`
* `dist[i][i] = 0`

Also create a `next[][]` matrix for path reconstruction:

* `next[i][j] = j` if edge exists
* `next[i][j] = -1` if no path exists

---

## Step 2: Update Shortest Distances

For every intermediate vertex `k`:

For every source vertex `i`:

For every destination vertex `j`:

Check:

```text id="6e2zzt"
if dist[i][k] + dist[k][j] < dist[i][j]
```

Then update:

```text id="3rmfkh"
dist[i][j] = dist[i][k] + dist[k][j]
next[i][j] = next[i][k]
```

This means a shorter path is found through vertex `k`.

---

## Step 3: Find Shortest Distance

After all iterations:

```text id="g7r1qv"
dist[i][j]
```

contains the shortest distance between every pair of vertices.

---

## Step 4: Reconstruct Path

To print path from source `u` to destination `v`:

* If `next[u][v] == -1`, no path exists
* Otherwise:

  * Print `u`
  * Repeatedly set:

```text id="dhvx6m"
u = next[u][v]
```

until `u == v`

This gives the complete shortest path.

---

## Time Complexity

O(V³)

where V = number of vertices

---

## Space Complexity

O(V²)

for distance and path matrices

---

## Conclusion

This algorithm finds the shortest distance between all pairs of vertices and also reconstructs the actual shortest path using the `next[][]` matrix.

Complexity analyis 
<img width="1389" height="908" alt="image" src="https://github.com/user-attachments/assets/26b28616-ff41-496a-9c0c-e64c02eafaba" />

  












