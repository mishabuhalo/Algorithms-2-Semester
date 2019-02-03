#include "Graph.h"


bool Graph::dfs(vector<vector<int>>& graph, vector<int>& color, int vertex, int prevVertex)
{
	color[vertex] = 0;
	bool firstPrevVertex = true;
	for (int i = 0; i < int(graph[vertex].size()); i++)
	{
		int currVertex = graph[vertex][i];
		if (color[currVertex] == -1)
		{
			if (dfs(graph, color, currVertex, vertex))
			{
				return true;
			}
		}
		else if(color[currVertex] == 0)
		{
			if (currVertex == prevVertex && firstPrevVertex)
			{
				firstPrevVertex = false;
			}
			else
				return true;
		}
	}
	color[vertex] = 1;
	return false;
}

void Graph::fillGraph(vector<int>& result, vector<vector<pair<int, int>>>& graph, int vertex, int flag)
{
	for (int i = 0; i < int(graph[vertex].size()); i++)
	{
		int currVertex = graph[vertex][i].first;
		if (result[currVertex] == flag)
		{
			result[currVertex] = graph[vertex][i].second - result[vertex];
			fillGraph(result, graph, currVertex, flag);
		}
	}
}

pair<int, vector<int>> Graph::hashingData(vector<shared_ptr<MusicShop>>& objects)
{
	int seed = 6;
	int length = int(objects.size());
	vector<int> firstHash(objects.size());
	vector<int> secondHash(objects.size());

	bool flag = false;
	while (!flag)
	{
		seed++;
		for (int i = 0; i < length; i++)
		{
			firstHash[i] = firstHashing(objects[i]->GetArtist(), seed, 20*length);
			secondHash[i] = secondHashing(objects[i]->GetArtist(), seed, 20*length);
		}

		vector<vector<int>> graph(20 * length);
		for (int i = 0; i < length; i++)
		{
			graph[firstHash[i]].push_back(secondHash[i]);
			graph[secondHash[i]].push_back(firstHash[i]);
		}

		vector<int> color(20 * length, -1);

		bool hasCycle = false;
		for (int i = 0; i < 20 * length && !hasCycle; ++i)
		{
			if (color[i] == -1 && graph[i].size() > 0)
			{
				if (dfs(graph, color, i, -1))
				{
					hasCycle = true;
				}
			}
		}

		if (hasCycle)
		{
			graph.clear();
		}
		else
		{
			flag = true;
		}
	}

	vector<vector<pair<int, int> > > graph(20 * length);

	for (int i = 0; i < length; ++i)
	{
		graph[firstHash[i]].push_back({ secondHash[i], i });
		graph[secondHash[i]].push_back({ firstHash[i], i });
	}

	vector<int> result(20 * length, 20 * length);

	for (int i = 0; i < 20 * length; ++i)
	{
		if (result[i] == 20 * length)
		{
			result[i] = 0;

			fillGraph(result, graph, i, 20 * length);
		}
	}

	return { seed, result };

}
