#include <list>
#include <string>
using namespace std;
typedef std::pair<int, int> CompareIndex;

class CompareSet
{
public:
    std::list<CompareIndex> CompareIndexes;
    void Add(int x, int y);
    bool Contains(int v);

    CompareSet& operator=(const CompareSet& sompareSet);
};


class SortingNetwork
{
private:
    std::list<CompareSet> Compares;
    float fitness;
    int inputSize;
    void Insert(int x, int y, int index);
    void Insert(int x, int y);
    void GenerateTestSets();

public:
    int Size() const;
    SortingNetwork& operator=(const SortingNetwork& sortingNetwork);

    SortingNetwork(const SortingNetwork& sortingNetwork);
    SortingNetwork(int size, int inputsize);

    void CreateRandomCompareSets(std::vector<std::pair<int, int>>& sets);
    void Insert(std::vector<std::pair<int, int>>& sets, int index);
    void Set(std::vector<std::pair<int, int>>& sets, int index);
    void Set(int index1, std::list<CompareSet>::iterator cit);
    void Set(int index1, CompareSet& compareset);
    std::string Dec2Gray(unsigned n);
    float EvaluateComparisonSets(const std::vector<std::pair<std::string, std::string>>& tests);
    bool Evaluate(std::vector<int> v);
    void Sort(std::vector<int>& v);
    void Mutate1(int index);
    void Mutate2(int index);
    void Mutate3();
    void Mutate4();
    void Remove(int index);
    float Fitness() const;
    void Print();

    std::list<CompareSet>::iterator GetCompareSet(int setnumber);
};
