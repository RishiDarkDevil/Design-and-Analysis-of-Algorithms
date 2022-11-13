# Problem
Given the following approximation algorithm to find the optimal solution to the Travelling Salesman Person. Prove the upper bound on the approximate tour ( $c(E)$) given by the algorithm stated below.
$$c(E) \le \frac{3}{2}c(TSP)$$
where $c(TSP)$ is the optimal tour cost(i.e. path cost) and the graph follows triangle inequality i.e. 
$$w(u, v) \le w(u, p) + w(p, v)$$
Here $u, v$ are vertices and $w(u, v)$ means the weight of the edge connecting vertex $u$ and $v$.

# Algorithm
- Consider a graph $G$ that follows triangle inequality.
- Use already existing polynomial time algorithms (say, PRIM's algorithm) to construct Minimum Spanning Tree of the graph $G$, call it $H$.
- Now, by Handshaking Lemma there exists even number of odd degreee vertices on the Minimum Spanning Tree, consider these vertices to be a new graph $O$.
- Considering only $O$, construct a Minimum-Weight Matching for $O$, say $M$.
- Take $H\cup M$, remove repeated vertices and form a Eulerian Circuit, call it $E$.
- This $E$ gives us an approximate tour of vertices in $G$.

# Proof
Let's make an obvious observation at first.
- Let $TSP$ be the optimal tour of graph $G$.
- Removing an edge from $TSP$ leaves us with a spanning tree of graph $G$, name it $TSP^{*}$.
- Now, $H$ being the minimum spanning tree, we have $c(H) \le c(TSP^{*}) \le c(TSP)$.
- As $c(H) = c(MST)$, we have $c(MST) \le c(TSP)$, where $c(MST)$ is the cost of the minimum spanning tree of $G$.

Now, for the upper bound we will look at the following steps,
- Consider the Euler's Tour, we obtained by this approximation algorithm. It is easy to observe that $c(E) = c(H) + c(M) = c(MST) + c(M) \le c(TSP) + c(M)$.
- So, it is enough to prove $c(M) \le \frac{1}{2}c(TSP)$
- Now, as we have already seen in the algorithm that $|O|$ is even and hence posses a perfect matching.
- Let $N$ be the optimal tour on the vertices of $O$.
- Let $M_1$ and $M_2$ be two perfect matching of $O$ formed by taking edges of $N$ alternatively.
- Since, $M$ is the minimum-weight perfect matching we have $$c(M) \le \min(M_1, M_2) \le \frac{1}{2}c(N) \le \frac{1}{2}c(TSP)$$.
- We got $\min(M_1, M_2) \le \frac{1}{2}c(N)$ above as $c(M_1) + c(M_2) = c(N)$.
- Finally, we used $c(N) \le c(TSP)$ as we can simply skip the even-degree vertices of $MST$ in $TSP$ to get a tour of $O$, say $T$. Now, by the triangle inequality $c(T) \le c(TSP)$.
- But, as $N$ is the optimal tour of $O$, we have $c(N) \le c(T)$. Therefore, $c(N) \le c(TSP)$

Thus, it is proven that $$c(E) \le c(TSP) + \frac{1}{2}c(TSP) = \frac{1}{2}c(TSP)$$.
