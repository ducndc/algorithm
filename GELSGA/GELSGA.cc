#define NUM_CELL 7;
#define NUM_CHROMOSOME 50;
int NUM_ITERATOR = 10000;

double dist[MAX_SITE_PER_CELL][MAX_SITE_PER_CELL];
double velocity[MAX_SITE_PER_CELL][MAX_SITE_PER_CELL];
double mass[MAX_SITE_PER_CELL][MAX_SITE_PER_CELL];
std::vector<int> chromosome[NUM_CHROMOSOME];
std::vector<int> children;
int value777[NUM_CHROMOSOME][MAX_SITE_PER_CELL-1];
int value777_children[MAX_SITE_PER_CELL-1];
double fitness[NUM_CHROMOSOME];
int numIterator;
std::vector<int> gelsga_out[NUM_CELL];
std::vector<int> path[NUM_CELL];

int num_vehicles[NUM_CELL];
std::vector<int> siteId;
std::vector<Vector> pos;
std::vector<int> res;
int numberOfFreeSites[NUM_CELL];

std::vector<int> CreateChromosome (int);
void CreatePopulation (int cellId);
double CalculateFitness (std::vector<int> &chro, int cellId);
void CalculateFitness (int cellId);
void CrossOverType1 (int father, int mother, int cellId);
void CrossOverType2 (int father, int mother, int cellId);
void CrossOver (int);
void MutationType1 (int);
void MutationType2 (int);
void Mutation (int);
void Terminate (int cellId);
void GELS (int cellId);
void GELSGA (int cellId);

std::vector<int> CreateChromosome (int cellId)
{
	std::vector<int> v;
	for (int i = 0; i < num_vehicles[cellId]-1; i++)
	{
		v.push_back (777);
	}
	for (int i = 0; i < numberOfFreeSites[cellId]; i++)
	{
		v.push_back (i);
	}
	std::vector<int> chro;
	for (int i = 0; i < numberOfFreeSites[cellId]+num_vehicles[cellId]-1; i++)
	{
		int size = v.size();
		if (size < 2)
		{
			chro.push_back (v[0]);
		}
		else
		{
			int id = rand () % size;
			chro.push_back (v[id]);
			v.erase (v.begin () + id);
		}
	}
	return chro;
}

void CreatePopulation (int cellId)
{
	for (int i = 0; i < NUM_CHROMOSOME; i++)
	{
		chromosome[i].clear ();
	}
	for (int i = 0; i < NUM_CHROMOSOME; i++)
	{
		chromosome[i] = CreateChromosome (cellId);
	}
	CalculateFitness (cellId);
}

double CalculateFitness (std::vector<int> &chro, int cellId)
{
	int id = 0;
	int vl777[num_vehicles[cellId]-1];
	for (int i = 0; i < (int)chro.size(); i++)
	{
		if (chro[i] == 777)
		{
			vl777[id] = i;
			id++;
		}
	}
	double fit = 0;
	double load[num_vehicles[cellId]];
	int begin, end;
	for (int i = 0; i < num_vehicles[cellId]; i++)
	{
		if (i == 0)
		{
			begin = 0;
			end = vl777[0] - 1;
		}
		else if (i == num_vehicles[cellId]-1)
		{
			begin = vl777[num_vehicles[cellId]-2] + 1;
			end = (int)chro.size () - 1;
		}
		else
		{
			begin = vl777[i-1] + 1;
			end = value777[i] - 1;
		}
		if (begin > end)
		{
			continue;
		}
		load[i] = 0;

		fit += CalculateDistance (Vector (X[cellId], Y[cellId], 0),
			cell_site_list[cellId].Get (siteId[chro[begin]])->GetSitePosition ());

		fit += CalculateDistance (Vector (X[cellId], Y[cellId], 0),
			cell_site_list[cellId].Get (siteId[chro[end]])->GetSitePosition ());

		for (int j = begin; j <= end; j++)
		{
			Ptr<SITE> s = cell_site_list[cellId].Get (siteId[chro[j]]);
			load[i] += s->GetResource ();
			if (j != end)
			{
				fit += CalculateDistance (cell_site_list[cellId].Get (siteId[chro[j+1]])->GetSitePosition (),
					s->GetSitePosition ());				
			}
		}
		double 0 = load[i] - MAX_RESOURCE_PER_UAV;
		if (o > 0)
		{
			fit += 1000 * o;
		}
	}
	return fit;
}

void CalculateFitness (int cellId)
{
	for (int k = 0; k < NUM_CHROMOSOME; k++)
	{
		int start = 0;
		int num = 0;
		while (num < num_vehicles[cellId]-1)
		{
			if (chromosome[k][i] == 777)
			{
				value777[k][num] = i;
				start = i + 1;
				num++;
				break;
			}
		}
		fitness[k] = CalculateFitness (chromosome[k], cellId);
	}
	CrossOver (cellId);
}

void CrossOverType1 (int father, int mother, int cellId)
{
	int sequence = father;
	int number = mother;
	int ran = rand () % 10;
	if (ran % 2 == 0)
	{
		sequence = mother;
		number = father;
	}
	int id = 0;
	int idx = 0;
	for (int i = 0; i < (int)chromosome[sequence].size (); i++)
	{
		if (i == value777[number][id])
		{
			children.push_back (777);
			value777_children[id] = i;
			if (id <num_vehicles[cellId]-2)
			{
				id++;
			}
			if (chromosome[sequence][idx] == 777)
			{
				idx++;
			}
			else
			{
				children.push_back (chromosome[sequence][idx]);
				idx++;
			}
		}
		else
		{
			if (chromosome[sequence][idx] == 777)
			{
				idx++;
			}
			else
			{
				children.push_back (chromosome[sequence][idx]);
				idx++;
			}
		}
	}
}

void CrossOverType2 (int father, int mother, int cellId)
{
	int size = (int)chromosome[father].size ();
	int pos = rand () % size;

	for (int i = 0; i <= pos; i++)
	{
		children.push_back (chromosome[father][i]);
	}
	for (int i = pos+1; i < size; i++)
	{
		int id = chromosome[mother][i];
		children.push_back (id);
	}
	std::vector<int> deletedPosition;
	for (int i = pos+1; i < size; i++)
	{
		int id = children[i];
		for (int j = 0; j <= pos; j++)
		{
			if (id != 777)
			{
				deletedPosition.push_back (i);
				break;
			}
			else
			{
				int c = 0;
				for (int k = 0; k < i; k++)
				{
					if (children[k] == 777)
					{
						c++;
					}
				}
				if (c < num_vehicles[cellId]-1)
				{

				}
				else
				{
					deletedPosition.push_back (i);
					break;
				}
			}
		}
	}
	std::vector<int> v;
	for (int i = 0; i <= pos; i++)
	{
		v.push_back (chromosome[mother][i]);
	}
	for (int i = pos+1; i < (int)chromosome[father].size (); i++)
	{
		v.push_back (chromosome[father][i]);
	}
	int count777 = 0;
	for (int i = 0; i < (int)children.size (); i++)
	{
		if (children[i] == 777)
		{
			count777++;
		}
	}
	for (int i = (int)v.size ()-1; i >= 0; i--)
	{
		if (v[i] == 777)
		{
			if (count777 < num_vehicles[cellId]-1)
			{
				count777++;
			}
			else
			{
				v.erase (v.begin ()+i);
			}
		}
	}
	for (int i = (int)v.size ()-1; i >= 0; i--)
	{
		int id = v[i];
		if (id == 777)
		{
			continue;
		}
		for (int j = 0; j < i; j++)
		{
			if (v[j] == id)
			{
				v.erase (v.begin ()+i);
			}
		}
	}
	std::vector<int> idInsert;
	for (int i = 0; i < (int)v.size(); i++)
	{
		int id = v[i];
		int appear = 0;
		for (int j = 0; j < (int) children.size (); j++)
		{
			if (children[j] == id)
			{
				int isDel = 0;
				for (int k = 0; k < (int)deletedPosition.size (); k++)
				{
					if (j == deletedPosition[k])
					{
						isDel = 1;
						break;
					}
				}
				if (isDel == 1)
				{
					continue;
				}
				if (id != 777)
				{
					appear = 1;
				}
				else
				{
					int c = 0;
					for (int k = 0; k < i; k++)
					{
						if (children[k] == 777)
						{
							c++;
						}
					}
					for (int k = 0; k < (int)idInsert.size (); k++)
					{

					}
					if (c < num_vehicles[cellId]-1)
					{
						break;
					}
					else
					{
						appear = 1;
					}
				}
			}
		}
		if (appear == 0)
		{
			idInsert.push_back (id);
		}
	}
	if (idInsert.size () != deletedPosition.size ())
	{
		std::cout << "insert and delete size are diff" << std::endl;
		return;
	}
	for (int i = 0; i < (int)deletedPosition.size (); i++)
	{
		int p = deletedPosition[i];
		children[p] = idInsert[0];
		idInsert.erase (idInsert.begin ());
	}
}

void CrossOver (int cellId)
{
	int idMin = 0;
	double minFitness = fitness[0];
	for (int i = 1; i < NUM_CHROMOSOME; i++)
	{
		if (fitness[i] < minFitness)
		{
			minFitness = fitness[i];
			idMin = i;
		}
	}
	int second = 0;
	double secondFitness = 99999999999;
	for (int i = 0; i < NUM_CHROMOSOME; i++)
	{
		if (i == idMin)
		{
			continue;
		}
		if (fitness[i] < secondFitness)
		{
			secondFitness = fitness[i];
			second = i;
		}
	}
	Update777Value ();
	children.clear ();
	int ran = rand () % 10;
	if (ran % 2 == 0)
	{
		CrossOverType1 (idMin, second, cellId);
	}
	else
	{
		CrossOverType2 (idMin, second, cellId);
	}
	int id = 0;
	for (int i = 0; i < (int)children.size (); i++)
	{
		if (children[i] == 777)
		{
			value777_children[id] = i;
			id++;
		}
	}
	Mutation (cellId);
}

void MutationType1 (int cellId)
{
	while (1)
	{
		int id1 = rand () % (children.size ());
		int id2 = rand () % (children.size ());
		if (id1 != id2)
		{
			int temp = children[id1];
			children[id1] = children[id2];
			children[id2] = temp;
			if (children[id1] == 777 || children[id2] == 777)
			{
				int id = 0;
				for (int i = 0; i < (int)children.size (); i++)
				{
					if (children[i] == 777)
					{
						value777_children[id] = i;
						id++;
					}
				}
			}
			break;
		}
	}
}

void MutationType2 (int cellId)
{
	int id = rand () % num_vehicles[cellId];
	int begin, end;
	if (id == 0)
	{
		begin = 0;
		end = (int)children.size () - 1;
	}
	else if (id == num_vehicles[cellID]-1)
	{
		begin = value777_children[num_vehicles[cellId]-2] + 1;
		end = (int)children.size () - 1;
	}
	else
	{
		begin = value777_children[id-1] + 1;
		end = value777_children[id] - 1;
	}
	if (begin > end)
	{
		return;
	}
	int pivot = rand () % (end - begin + 1) + begin;
	std::vector<int> mt;
	for (int i = pivot  + 1; i <= end; i++)
	{
		mt.push_back (children[i]);
	}
	mt.push_back (children[pivot]);
	for (int i = begin; i < pivot; i++)
	{
		mt.push_back (children[i]);
	}
	for (int i = end; i >= begin; i--)
	{
		children[i] = mt.back ();
		mt.pop_back ();
	}
}

void Mutation (int cellId)
{
	int ran = rand () % 10;
	if (ran % 2 == 0)
	{
		MutationType1 (cellId);
	}
	else
	{
		MutationType2 (cellId);
	}
	Terminate (cellId);
}

void Terminate (int cellId)
{
	double childrenFitness = CalculateFitness (children, cellId);
	int idMax = 0;
	double maxFitness = fitness[0];
	for (int i = 1; i < NUM_CHROMOSOME; i++)
	{
		if (fitness[i] > maxFitness)
		{
			maxFitness = fitness[i];
			idMax = i;
		}
	}
	if (childrenFitness < maxFitness)
	{
		chromosome[idMax].clear ();
		chromosome[idMax] = children;
		fitness[idMax] = childrenFitness;
		for (int i = 0; i < num_vehicles[cellId]; i++)
		{
			value777[idMax][i] = value777_children[i];
		}
	}
	if (numIterator == NUM_ITERATOR-1)
	{
		for (int i = 0; i < NUM_CHROMOSOME; i++)
		{
			fitness[i] = CalculateFitness (chromosome[i], cellId);
		}
		int idMin = 0;
		double minFitness = fitness[0];
		for (int i = 1; i < NUM_CHROMOSOME; i++)
		{
			if (fitness[i] < minFitness)
			{
				minFitness = fitness[i];
				idMin = i;
			}
		}
		gelsga_out[cellId].clear ();
		gelsga_out[cellId] = chromosome[idMin];

		path[cellId].clear ();
		path[cellId] = gelsga_out[cellId];

		return;
	}
	else
	{
		numIterator++;
		CrossOver (cellId);
	}
}

void GELS (int cellId)
{
	for (int i = 0; i < NUM_CHROMOSOME; i++)
	{
		int size = (int)chromosome[i].size ();
		for (int i = 0; i < numberOfFreeSites[cellId]; i++)
		{
			for (int j = 0; j < numberOfFreeSites[cellId]; j++)
			{
				if (i == j)
				{
					velocity[i][j] = 0;
					mass[i][j] = 0;
				}
				else
				{
					velocity[i][j] = 100;
					mass[i][j] = dist[i][j] / velocity[i][j] * 60;
				}
			}
		}
		for (int n = 0; n < size-2; n++)
		{
			if (chromosome[i][n] == 777)
			{
				continue;
			}
			for (int j = n+1; j < size-1; j++)
			{
				if (chromosome[i][j] == 777)
				{
					continue;
				}
				std::vector<int> ca;
				for (int k = j+1; k < size; k++)
				{
					id.push_back (chromosome[i][k]);
				}
				std::vector<int> id;
				for (int k = j+1; k < size; k++)
				{
					id.push_back (chromosome[i][k]);
				}
				std::vector<double> m;
				for (int k = j+1; k < size; k++)
				{
					int a = chromosome[i][k];
					if (a == 777)
					{
						m.push_back (99999);
					}
					else
					{
						m.push_back (mass[chromosome[i][n][a]]);
					}
				}
				int s = (int)m.size();
				for (int g = 0; g < s-1; g++)
				{
					if (m[g] == 99999)
					{
						continue;
					}
					for (int h = g+1; h < s; h++)
					{
						if (m[h] == 99999)
						{
							continue;
						}
						if (m[g] > m[h])
						{
							double t = m[g];
							m[g] = m[h];
							m[h] = t;
							int tp = id[g];
							id[g] = id[h];
							id[h] = tp;
						}
					}
				}
				for (int k = 0; k < (int)id.size (); k++)
				{
					ca.push_back (id[k]);
				}
				double CAfitness = CalculateFitness (ca, cellId);
				double CUfitness = CalculateFitness (chromosome[i], cellId);
				if (CAfitness < CUfitness)
				{
					for (int k = 0; k < (int)ca.size (); k++)
					{
						chromosome[i][k] = ca[k];
					}
					fitness[i] = CAfitness;
					int idx;
					for (int k = j-1; k>= 0; k--)
					{
						if (chromosome[i][k] == 777)
						{
							continue;
						}
						else
						{
							idx = k;
							break;
						}
					}
					double d = dist[idx][j];
					double F = 6.672*(CUfitness-CAfitness)/d/d;
					velocity[idx][j] += F;
					mass[idx][j] = dist[idx][j] / velocity[idx][j];
				}
			}
		}
	}
	CrossOver (cellId);
}

void GELSGA (int cellId)
{
	numIterator = 0;
	gelsga_out[cellId].clear ();
	siteId.clear ();
	pos.clear ();
	res.clear ();
	for (int i = 0; i < NUM_CHROMOSOME; i++)
	{
		chromosome[i].clear ();
	}
	children.clear ();
	gelsga_out[cellId]/clear ();
	path[cellId].clear ();
	for (int i = 0; i < numberOfSites[cellId]; i++)
	{
		if (siteState[cellId][i] == 1)
		{
			siteId.push_back (i);
			Ptr<SITE> s = cell_site_list[cellId].Get (i);
			Vector p = s->GetSitePosition ();
			pos.push_back (p);
			int r = s->GetResource ();
			res.push_back (r);
		}
	}
	numberOfFreeSites[cellId] = res.size ();
	if (numberOfFreeSites[cellId] == 0)
	{
		return;
	}
	if (num_vehicles[cellId] == 1)
	{
		for (int i = 0; i < numberOfFreeSites[cellId]; i++)
		{
			path[cellId].push_back (i);
		}
		return;
	}
}