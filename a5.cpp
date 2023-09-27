#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Graph sınıfı, graf yapısını temsil eder
class Graph {
public:
    int V; // Node sayısı
    vector<vector<pair<int, int>>> adj; // Her node'un komşuları ve maliyetleri

    Graph(int V) : V(V) {
        adj.resize(V + 1);
    }

    // Yeni bir kenar (edge) eklemek için bir fonksiyon
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Çünkü kenarlar çift yönlüdür
    }

    // En kısa yolu hesaplayan Dijkstra algoritması
    int dijkstra(int src, int dest) {
        vector<int> dist(V + 1, INT_MAX); // Node'lara olan en kısa mesafe
        dist[src] = 0; // Başlangıç node'unun mesafesi 0

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-Heap
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue; // Daha iyi bir yolu zaten bulmuşsak atla

            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dest];
    }
};

int main() {
    int N, M; // Node ve edge sayısı
    cin >> N >> M;

    Graph graph(N);

    // Edge'leri grafik üzerine ekle
    for (int i = 0; i < M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph.addEdge(u, v, cost);
    }

    // En kısa yol hesabı
    int src, dest;
    cin >> src >> dest; // Başlangıç ve hedef node'larını al

    int shortestPath = graph.dijkstra(src, dest);

    cout << "Minimum maliyet: " << shortestPath << endl;

    return 0;
}
