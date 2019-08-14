#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

ofstream outputFile;

// forward declaration of the functions used.
int sum(vector<int> input);
vector<double> computeMean(vector<int> xInput, vector<int> yInput, vector<double> kMean);

int main()
{
}

int sum(vector<int> input)
{
    int res = 0;

    for (int i = 0; i < input.size(); ++i)
    {
        res += input[i];
    }

    return res;
}

vector<double> computeMean(vector<int> xInput, vector<int> yInput, vector<double> kMean)
{
    vector<int> xcluster1, xcluster2, xcluster3;

    vector<int> ycluster1, ycluster2, ycluster3;

    vector<double> clusters;

    double distance1, distance2, distance3;
    double xcentroid1, xcentroid2, xcentroid3, ycentroid1, ycentroid2, ycentroi3;

    string cluster1 = "Cluster 1: ";
    string cluster2 = "Cluster 2: ";
    string cluster3 = "Cluster 3: ";

    for (int i = 0; i < xInput.size(); i++)
    {
        // computing the distances
        distance1 = sqrt(pow(xInput[i] - kMean[0], 2) + pow(yInput[i] - kMean[3], 2));
        distance2 = sqrt(pow(xInput[i] - kMean[1], 2) + pow(yInput[i] - kMean[4], 2));
        distance3 = sqrt(pow(xInput[i] - kMean[2], 2) + pow(yInput[i] - kMean[5], 2));

        string str;
        stringstream str_num;
        str_num << i + 1;
        str = str_num.str();

        // comparing the euclidean distances
        if ((distance1 < distance2) && (distance1 < distance3))
        {
            xcluster1.push_back(xInput[i]);
            ycluster1.push_back(yInput[i]);
            cluster1 += str + " ";
        }

        else if ((distance2 < distance1) && (distance2 < distance3))
        {
            xcluster2.push_back(xInput[i]);
            ycluster2.push_back(yInput[i]);
            cluster2 += str + " ";
        }

        else if ((distance3 < distance1) && (distance3 < distance2))
        {
            xcluster3.push_back(xInput[i]);
            ycluster3.push_back(yInput[i]);
            cluster3 += str + " ";
        }
    }

    // mean 
    double xsum1 = sum(xcluster1);
    double ysum1 = sum(ycluster1);

    xcentriod1 = xsum1 / xcluster1.size();
    ycentriod1 = ysum1 / ycluster1.size();

    double xsum2 = sum(xcluster2);
    double ysum2 = sum(ycluster2);

    xcentriod2 = xsum2 / xcluster2.size();
    ycentriod2 = ysum2 / ycluster2.size();

    double xsum3 = sum(xcluster3);
    double ysum3 = sum(ycluster3);

    xcentriod3 = xsum3 / xcluster3.size();
    ycentriod3 = ysum3 / ycluster3.size();

    outputFile << cluster1 << "\n";
    outputFile << "Centriod: " << "(" << xcentroid1 << ", " << ycentroid1 << ")" << "\n";
    outputFile << cluster2 << "\n";
    outputFile << "Centriod: " << "(" << xcentroid2 << ", " << ycentroid2 << ")" << "\n";
    outputFile << cluster3 << "\n";
    outputFile << "Centriod: " << "(" << xcentroid3 << ", " << ycentroid3 << ")" << "\n";
    outputFile << "\n";

    clusters.push_back(xcentriod1);
    clusters.push_back(xcentriod2);
    clusters.push_back(xcentriod3);

    clusters.push_back(ycentriod1);
    clusters.push_back(ycentriod2);
    clusters.push_back(ycentriod3);

    return clusters;
}