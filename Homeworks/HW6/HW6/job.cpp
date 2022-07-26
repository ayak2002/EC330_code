
#include "job.h"
#include <vector>
#include <map>
#include <stack>

//builds a matrix where the row corresponds to a job, and each element in that row is a dependent of that job
void buildMatrix1(std::vector<pair<int, int>> &dependencies, std::vector<std::vector<int>> &neighborMat){
  for(int i = 0; i < dependencies.size(); i++){
    neighborMat[dependencies[i].first-1].push_back(dependencies[i].second);
  }
}

//if there is a cycle, then the job depends on itself, so it cannot finish
//isCycle uses Depth First Search to detect cycles
bool isCycle(std::vector<std::vector<int>> &neighborMat, vector<bool> visitedVec, int current) {
  if((current < neighborMat.size()) && (visitedVec[current] == false)){
    visitedVec[current] = true;
    for(int i = 0; i < neighborMat[current].size(); i++) {
      int newCurrent = neighborMat[current][i] - 1;
      if(visitedVec[newCurrent] == true) {
        return true;
      }
      else {
        return isCycle(neighborMat, visitedVec, newCurrent);
      }
    }
  }
  return false;
}

//canFinish calls isCycle and if any cycle is detected, the jobs cannot finish running
bool canFinish(int n, std::vector<pair<int, int>> &dependencies) {
  std::vector<std::vector<int>> neighborMat(n);
  buildMatrix1(dependencies, neighborMat);
  vector<bool> visitedVec (n, false);
  int current = 0;
  for(int i = 0; i < neighborMat.size(); i++) {
    if(isCycle(neighborMat, visitedVec, i) == true) {
      return false;
    }
  }
  return true;
}

//if the job we want to run depends on more jobs than the number of slots that come before the wanted slot, we cannot run the job.
void buildMatrix2(std::vector<pair<int, int>> &dependencies, std::vector<std::vector<int>> &neighborMat){
  for(int i = 0; i < dependencies.size(); i++){
    neighborMat[dependencies[i].second-1].push_back(dependencies[i].first);
  }
}

int getDep(int j, std::vector<bool> &depArr, std::vector<std::vector<int>> &neighborMat){
  int count = 0;
  for(int i = 0; i < neighborMat[j-1].size(); i++) {
    if(!depArr[neighborMat[j-1][i]-1]) {
      depArr[neighborMat[j-1][i]-1] = true;
      count += 1 + getDep(neighborMat[j-1][i], depArr, neighborMat);
    }
  }
  return count;
}

//canRun calls countDep to get the number of dependents and compares it to i
bool canRun(int n, std::vector<pair<int, int>> &dependencies, int j, int i) {
  int count = 0;
  std::vector<bool> depArr(n, false);
  std::vector<std::vector<int>> neighborMat(n);
  buildMatrix2(dependencies, neighborMat);
  if(!canFinish(n, dependencies)) {
    return false;
  }
  else {
    count = getDep(j, depArr, neighborMat);
    if (count >= i) {
      return false;
    }
  }
  return true;
}
