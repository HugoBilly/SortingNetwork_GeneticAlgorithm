// SortingNetwork_GeneticAlgorithm_02.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <iterator> 
#include <vector>
#include <string>
#include "SortingNetwork.h"
#include "GeneticAlgorithm.h"
using namespace std;

typedef std::vector<int>::iterator iter_s;

template<typename T, typename InputIterator>
void Print(std::ostream& ostr,
    InputIterator itbegin,
    InputIterator itend,
    const std::string& delimiter)
{
    std::copy(itbegin,
        itend,
        std::ostream_iterator<T>(ostr, delimiter.c_str()));
}

int main()
{
    const int popsize = 100;
    const int tournamentsize = popsize / 10;
    const int mutation = 10;
    const int crossover = 45;
    const int inputsize = 4;
    const int comparesize = inputsize * 2;
    const int testInputSize = inputsize * 50;
    const int maxIterations = 500;

    GeneticAlgorithm ga(popsize, mutation, crossover, inputsize, comparesize, tournamentsize,
        testInputSize);

    ga.Evaluate();

    int iteration = 0;

    while (iteration < maxIterations)
    {
        ga.Selection();
        ga.Crossover();
        ga.Mutation();
        ga.Evaluate();

        if (iteration % 20 == 0)
        {
            std::cout << "Iteration: " << std::setw(4) << iteration
                << " Best fitness = " << std::setprecision(4) << std::setw(5) << ga.BestScore()
                << " No. compare sets = " << ga.GetBestNetwork()->Size() << std::endl;
        }

        iteration++;
    }

    //int T1[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100 };
    int T2[] = { 5000, 4999, 4998, 4997, 4996, 4995, 4994, 4993, 4992, 4991, 4990, 4989, 4988, 4987, 4986, 4985, 4984, 4983, 4982, 4981, 4980, 4979, 4978, 4977, 4976, 4975, 4974, 4973, 4972, 4971, 4970, 4969, 4968, 4967, 4966, 4965, 4964, 4963, 4962, 4961, 4960, 4959, 4958, 4957, 4956, 4955, 4954, 4953, 4952, 4951, 4950, 4949, 4948, 4947, 4946, 4945, 4944, 4943, 4942, 4941, 4940, 4939, 4938, 4937, 4936, 4935, 4934, 4933, 4932, 4931, 4930, 4929, 4928, 4927, 4926, 4925, 4924, 4923, 4922, 4921, 4920, 4919, 4918, 4917, 4916, 4915, 4914, 4913, 4912, 4911, 4910, 4909, 4908, 4907, 4906, 4905, 4904, 4903, 4902, 4901 };
    //int T3[] = {-9999, -9995, -9982, -9981, -9975, -9975, -9969, -9968, -9962, -9962, -9961, -9959, -9954, -9954, -9952, -9947, -9946, -9945, -9939, -9936, -9936, -9929, -9928, -9923, -9922, -9918, -9917, -9916, -9914, -9912, -9905, -9904, -9903, -9902, -9900, -9897, -9894, -9891, -9889, -9874, -9873, -9872, -9871, -9853, -9847, -9845, -9844, -9844, -9842, -9834, -9821, -9821, -9816, -9814, -9813, -9813, -9813, -9812, -9808, -9796, -9795, -9795, -9792, -9787, -9785, -9783, -9781, -9781, -9778, -9778, -9776, -9774, -9770, -9770, -9766, -9765, -9761, -9755, -9753, -9746, -9741, -9737, -9730, -9716, -9711, -9708, -9706, -9699, -9694, -9691, -9690, -9687, -9685, -9681, -9677, -9676, -9670, -9670, -9668, -9663};
    //int T4[] = {0, 0, 2, 3, 2, 1, 1, 7, 5, 3, 5, 4, 8, 9, 11, 3, 15, 5, 16, 14, 6, 4, 9, 8, 6, 3, 13, 1, 12, 10, 9, 30, 27, 27, 21, 5, 29, 5, 33, 3, 1, 2, 20, 37, 22, 42, 42, 41, 4, 30, 34, 6, 39, 51, 13, 3, 56, 18, 29, 59, 47, 27, 62, 17, 1, 31, 23, 62, 3, 57, 68, 38, 52, 72, 17, 12, 1, 31, 30, 71, 44, 74, 32, 27, 53, 35, 31, 67, 15, 73, 8, 47, 33, 6, 90, 65, 79, 48, 70, 96};

    std::vector<int> input(T2, T2 + inputsize);
    std::vector<int> output1(T2, T2 + inputsize);

    std::cout << std::endl;
    std::cout << "Input set:" << std::endl << std::endl;
    Print<int, iter_s>(std::cout, input.begin(), input.end(), " ");
    SortingNetwork* nw = ga.GetBestNetwork();
    nw->Sort(output1);
    std::cout << std::endl << std::endl;
    std::cout << "Input set after network sort:" << std::endl << std::endl;
    Print<int, iter_s>(std::cout, output1.begin(), output1.end(), " ");

    std::cout << std::endl << std::endl;
    std::cout << "Sorting network: " << std::endl << std::endl;
    nw->Print();

    std::cout << std::endl;
    std::cout << "Exhaustive evaluation fitness = " << nw->EvaluateNetworkExhaustively() << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "Press any key to exit.";
    getchar();

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
