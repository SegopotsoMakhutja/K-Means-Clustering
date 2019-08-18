#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


// forward declaration of the functions used.
int sum(vector<int> input);
vector<double> computeMean(vector<int> xInput, vector<int> yInput, vector<double> kMean);

ofstream outputFile;

int main()
{
    outputFile.open("Output.txt"); // output file
    int counter = 0;
    int iteration = 1; // keep track of number of iterations

    vector<int> xInput = {2, 2, 8, 5, 7, 6, 1, 4};
    vector<int> yInput = {10, 5, 4, 8, 5, 4, 2, 9};
    vector<double> kMean = {2, 5, 1, 10, 8, 2};

    vector<double> centroids;
    vector<double> new_centroids;
    // centroids = computeMean(xInput, yInput, kMean); was just a check for the output

    double xcurrent_centroid1, xcurrent_centroid2, xcurrent_centroid3;
    double ycurrent_centroid1, ycurrent_centroid2, ycurrent_centroid3;

    double xnew_centroid1, xnew_centroid2, xnew_centroid3;
    double ynew_centroid1, ynew_centroid2, ynew_centroid3;

    
   for (;;)
   {
      outputFile << "Iteration " << iteration << endl;
      outputFile << "\n";

      if (counter == 0)
      {
         centroids = computeMean(xInput, yInput, kMean);
         new_centroids = centroids;
         xnew_centroid1 = centroids[0];
         xnew_centroid2 = centroids[1];
         xnew_centroid3 = centroids[2];

         ynew_centroid1 = centroids[3];
         ynew_centroid2 = centroids[4];
         ynew_centroid3 = centroids[5];

         xcurrent_centroid1 = xnew_centroid1;
         xcurrent_centroid2 = xnew_centroid2;
         xcurrent_centroid3 = xnew_centroid3;

         ycurrent_centroid1 = ynew_centroid1;
         ycurrent_centroid2 = ynew_centroid2;
         ycurrent_centroid3 = ynew_centroid3;

         counter++;
      }

      else
      {
         centroids = computeMean(xInput, yInput, new_centroids);
         new_centroids = centroids;
         xnew_centroid1 = centroids[0];
         xnew_centroid2 = centroids[1];
         xnew_centroid3 = centroids[2];

         ynew_centroid1 = centroids[3];
         ynew_centroid2 = centroids[4];
         ynew_centroid3 = centroids[5];

         if ((xnew_centroid1 == xcurrent_centroid1) && (xnew_centroid2 == xcurrent_centroid2) && (xnew_centroid3 == xcurrent_centroid3))
         {
            if ((ynew_centroid1 == ycurrent_centroid1) && (ynew_centroid2 == ycurrent_centroid2) && (ynew_centroid3 == ycurrent_centroid3))
            {
               break;
            }
         }

         xcurrent_centroid1 = xnew_centroid1;
         xcurrent_centroid2 = xnew_centroid2;
         xcurrent_centroid3 = xnew_centroid3;

         ycurrent_centroid1 = ynew_centroid1;
         ycurrent_centroid2 = ynew_centroid2;
         ycurrent_centroid3 = ynew_centroid3;
      }

      iteration++;
   }

    outputFile << "it needs " << iteration << " iterations to converge." << endl;

    outputFile.close(); // always close files
    
    return 0;
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
    double xcentroid1, xcentroid2, xcentroid3, ycentroid1, ycentroid2, ycentroid3;

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

    // calculating means of the clusters 
    double xsum1 = sum(xcluster1);
    double ysum1 = sum(ycluster1);

    xcentroid1 = xsum1 / xcluster1.size();
    ycentroid1 = ysum1 / ycluster1.size();

    double xsum2 = sum(xcluster2);
    double ysum2 = sum(ycluster2);

    xcentroid2 = xsum2 / xcluster2.size();
    ycentroid2 = ysum2 / ycluster2.size();

    double xsum3 = sum(xcluster3);
    double ysum3 = sum(ycluster3);

    xcentroid3 = xsum3 / xcluster3.size();
    ycentroid3 = ysum3 / ycluster3.size();

    outputFile << cluster1 << "\n";
    outputFile << "Centroid: " << "(" << xcentroid1 << ", " << ycentroid1 << ")" << endl;
    outputFile << "\n";
    
    outputFile << cluster2 << "\n";
    outputFile << "Centroid: " << "(" << xcentroid2 << ", " << ycentroid2 << ")" << endl;
    outputFile << "\n";
    
    outputFile << cluster3 << "\n";
    outputFile << "Centroid: " << "(" << xcentroid3 << ", " << ycentroid3 << ")" << endl;
    outputFile << "\n";

    clusters.push_back(xcentroid1);
    clusters.push_back(xcentroid2);
    clusters.push_back(xcentroid3);

    clusters.push_back(ycentroid1);
    clusters.push_back(ycentroid2);
    clusters.push_back(ycentroid3);

    return clusters;
}