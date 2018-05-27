#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class graph
{
private:
	bool ** matrix;
	int vertices;

	void depthsearch(int vertex, vector<bool> & mark, ostream & stream)
	{
		mark[vertex] = true;
		stream << vertex << " ";
		for (int i = 0; i < vertices; ++i)
		{
			if (matrix[vertex][i] == 1 && !mark[i])
				depthsearch(i, mark, stream);
		}
	}
public:
	graph()
	{
		matrix = nullptr;
		vertices = 0;
	}
	~graph()
	{
		if (matrix)
		{
			for (int i = 0; i < vertices; i++)
				delete[] matrix[i];
			delete[] matrix;
		}
	}

	void depthsearch(int vertex, ostream & stream)
	{
		if (vertex < vertices)
		{
			vector<bool> mark(vertices);
			depthsearch(vertex, mark, stream);
		}
		else
		{
			ostringstream sstream;
			sstream << "graph consists of " << vertices << " vertices " << vertex;
			throw out_of_range(sstream.str());
		}
	}

	bool read(istream &stream)
	{
		bool success = true;
		if (stream >> vertices)
		{
			bool **elements = new bool *[vertices];
			for (int i = 0; success && i < vertices; ++i)
			{
				elements[i] = new bool[vertices];
				for (int j = 0; j < vertices; ++j)
				{
					if (!(stream >> elements[i][j]))
					{
						success = false;
						break;
					}
					if (elements[i][j] != 1 && elements[i][j] != 0)
					{
						success = false;
						break;
					}
				}
			}
			if (success)
			{
				matrix = new bool *[vertices];
				for (int i = 0; i < vertices; i++)
				{
					matrix[i] = new bool[vertices];
					for (int j = 0; j < vertices; j++)
						matrix[i][j] = elements[i][j];
				}
				for (int i = 0; i < vertices; ++i)
					delete[] elements[i];
				delete[] elements;
			}
			else success = false;
		}
		else success = false;
		return success;
	}
};