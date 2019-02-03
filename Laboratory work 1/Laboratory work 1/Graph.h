#pragma once

#include "Hash.h"
#include "MusicShop.h"
#include <vector>
#include <map>

class Graph
{
	static bool dfs(vector<vector<int>> &graph, vector<int>&color, int vertex, int prevVertex);

	static void fillGraph(vector<int> &result, vector<vector<pair<int, int> > > &graph, int vertex, int flag);

public:
	static pair<int, vector<int>> hashingData(vector<shared_ptr<MusicShop>> &objects);
};

