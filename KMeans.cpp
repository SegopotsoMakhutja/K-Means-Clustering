#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int sum(vector<int> input);
vector<double> computeMean(vector<int> xInput, vector<int> yInput, vector<double> kMean);

int main(){


}

int sum(vector<int> input)
{
    int res = 0;
    
    for(int i = 0; i < input.size(); ++i)
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
}