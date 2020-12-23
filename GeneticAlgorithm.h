#pragma once
#include <vector>
#include "SortingNetwork.h"
#include <string>
using namespace std;

class GeneticAlgorithm
{
private:
    std::vector<SortingNetwork*> population;
    std::vector<bool> changedSet;
    SortingNetwork* bestNetwork;
    int mutationRate;
    int crossoverRate;
    int populationSize;
    int bestIndividual;
    int tournamentSize;
    float bestScore;
    int testInputSize;

    std::vector<std::pair<std::string, std::string>> testInputs;

public:

    GeneticAlgorithm(int popSize, int mutation, int crossover, int inputsize, int comparesize,
        int tournamentsize, int testinputsize);

    void CreateRandomPopulation(int popsize, int inputsize, int comparesize);
    void Evaluate();
    void Mutation();
    void Crossover();
    void Selection();

    float BestScore();
    int BestIndividual();
    SortingNetwork* GetBestNetwork();
    void GeneticAlgorithm::GenerateTestSets(int inputSize);
};
