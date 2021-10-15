#include <bits/stdc++.h>

#define ll long long int
#define ld long double

using namespace std;

void file_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Vertex
{
public:
    ll id;
    vector<ll> connectedEdges;

    Vertex(ll id)
    {
        this->id = id;
    }

    void addEdge(ll id)
    {
        connectedEdges.push_back(id);
    }

    ll noOfEdges()
    {
        return connectedEdges.size();
    }

    ll getEdge(ll position)
    {
        return connectedEdges[position];
    }
};

class Edge
{
public:
    ll id, start, end, weight;

    Edge(ll id, ll start, ll end, ll weight)
    {
        this->id = id;
        this->start = start;
        this->end = end;
        this->weight = weight;
    }

    ll getOtherVertex(ll vertex)
    {
        // cout << "in get other vertex" << endl;
        // cout << "vertex is " << vertex << endl;
        // cout << "edge is " << start << " and " << end << endl;
        if (vertex == start)
        {
            return end;
        }
        else if (vertex == end)
        {
            return start;
        }
    }
};

class Graph
{
public:
    vector<Vertex> vertices;
    vector<Edge> edges;
    vector<vector<ll>> routes;

    Graph()
    {
    }

    void addVertex(Vertex v)
    {
        vertices.push_back(v);
    }

    void addEdge(Edge e)
    {
        edges.push_back(e);
    }

    Vertex *getVertexById(ll id)
    {
        for (ll i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].id == id)
            {
                return &vertices[i];
            }
        }
    }

    Edge *getEdgeById(ll id)
    {
        for (ll i = 0; i < edges.size(); i++)
        {
            if (edges[i].id == id)
            {
                return &edges[i];
            }
        }
    }

    ll getEdgeIdByStartAndEnd(ll start, ll end)
    {
        for (ll i = 0; i < edges.size(); i++)
        {
            Edge e = edges[i];
            if ((e.start == start && e.end == end) || (e.start == end && e.end == start))
            {
                return e.id;
            }
        }
    }

    void addThisAsFinalRoute(vector<ll> *route, ll end)
    {
        vector<ll> rt(*route);
        rt.push_back(end);
        routes.push_back(rt);
    }

    bool vertexInRoute(ll vertex, vector<ll> *route)
    {
        // cout << "route vector is ";
        // for (ll i = 0; i < route->size(); i++)
        // {
        //     cout << route->at(i) << " ";
        // }
        // if (route->size() == 0)
        //     cout << "empty ";
        // cout << "and vertex is " << vertex << endl;
        for (ll i = 0; i < route->size(); i++)
        {
            if (route->at(i) == vertex)
            {
                return true;
            }
        }
        return false;
    }

    void findRoutes(ll nextVertex, ll end, vector<ll> *currentRoute)
    {
        // cout << "Current vertex is " << nextVertex << " end is " << end << " and route vector size is " << currentRoute->size() << endl;
        if (nextVertex == end)
        {
            // cout << "current vertex is end vertex" << endl;
            addThisAsFinalRoute(currentRoute, end);
            return;
        }
        if (vertexInRoute(nextVertex, currentRoute))
        {
            // cout << "current vertex is already covered" << endl;
            return;
        }
        currentRoute->push_back(nextVertex);
        Vertex *v = getVertexById(nextVertex);
        for (ll i = 0; i < v->noOfEdges(); i++)
        {
            // cout << "For vertex " << nextVertex << " edge no " << i << endl;
            Edge *e = getEdgeById(v->getEdge(i));
            findRoutes(e->getOtherVertex(nextVertex), end, currentRoute);
        }
        currentRoute->pop_back();
    }

    ll getMinimumOfRoute(vector<ll> route)
    {
        ll minWeightId, minWeight;
        minWeightId = getEdgeIdByStartAndEnd(route[0], route[1]);
        minWeight = getEdgeById(minWeightId)->weight;
        for (ll i = 1; i < route.size() - 1; i++)
        {
            ll edgeId = getEdgeIdByStartAndEnd(route[i], route[i + 1]);
            ll edgeWeight = getEdgeById(edgeId)->weight;
            if (edgeWeight < minWeight)
            {
                minWeight = edgeWeight;
                minWeightId = edgeId;
            }
        }
        return minWeight;
    }

    ll getSolutionRoute()
    {
        ll maxFromMinRouteWeight;
        maxFromMinRouteWeight = getMinimumOfRoute(routes[0]);
        for (ll i = 1; i < routes.size(); i++)
        {
            vector<ll> currentRoute = routes[i];
            ll weight = getMinimumOfRoute(currentRoute);
            if (weight > maxFromMinRouteWeight)
            {
                maxFromMinRouteWeight = weight;
            }
        }
        return maxFromMinRouteWeight;
    }

    ll calculateAnswerFromWeightFactor(ll weightFactor, ll noOfPeople)
    {
        return (noOfPeople / weightFactor) * 2 - 1;
    }

    ll solve(ll start, ll end, ll noOfPeople)
    {
        vector<ll> *currentRoute = new vector<ll>();
        findRoutes(start, end, currentRoute);
        // cout << "Size of routes is " << routes.size() << endl;
        // cout << "Routes are" << endl;
        // for (ll i = 0; i < routes.size(); i++)
        // {
        //     for (ll j = 0; j < routes[i].size(); j++)
        //     {
        //         cout << routes[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        ll weightFactor = getSolutionRoute();
        ll answer = calculateAnswerFromWeightFactor(weightFactor, noOfPeople);
        return answer;
    }
};

int main()
{
    file_io();
    ll N, R, start, end, noOfPeople;
    Graph *graph;
    ll scenarioNo = 1;
    while (true)
    {
        graph = new Graph();
        cin >> N >> R;
        if (N == 0)
        {
            break;
        }
        for (ll i = 0; i < N; i++)
        {
            Vertex v(i + 1);
            graph->addVertex(v);
        }
        for (ll i = 0; i < R; i++)
        {
            ll start, end, weight;
            cin >> start >> end >> weight;
            Edge e(i, start, end, weight);
            graph->addEdge(e);
            graph->getVertexById(start)->addEdge(i);
            graph->getVertexById(end)->addEdge(i);
        }
        cin >> start >> end >> noOfPeople;
        ll answer = graph->solve(start, end, noOfPeople);
        cout << "Scenario #" << scenarioNo++ << endl;
        cout << "Minimum Number of Trips = " << answer << endl;
    }

    return 0;
}