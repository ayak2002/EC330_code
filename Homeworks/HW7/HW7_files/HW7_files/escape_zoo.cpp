#include "escape_zoo.h"
#include <algorithm>
#include <iostream>
#include <queue>

motion_plan escape_route(grid const &M, coordinate init_coordinate, Heading init_heading) {
    // your implementation here
    int m = M.size();
    int n = M[0].size();
    std::vector <std::vector<bool>> visited(m); //visited matrix
    std::vector <std::vector<std::pair<std::size_t, std::size_t>>> pred(m); //predecessor matrix
    std::vector <std::vector<Action>> directions(m); //directions matrix
    std::vector <std::vector<Heading>> h(m); //heading matrix
    for(int i = 0; i < m; i++) {
        visited[i].resize(n);
        directions[i].resize(n);
        pred[i].resize(n);
        h[i].resize(n);
    }
    motion_plan plan;
    h[init_coordinate.first][init_coordinate.second] = init_heading;
    std::queue <std::pair<std::size_t, std::size_t>> myQ;
    myQ.push(init_coordinate); 
    visited[init_coordinate.first][init_coordinate.second] = true; 
    std::pair<std::size_t, std::size_t> myCoord;
    while (!myQ.empty()) {
        myCoord = myQ.front(); //for each coordinate in the queue: 
        myQ.pop();
        if(h[myCoord.first][myCoord.second] == North) { //check the orientation
            if(myCoord.first == 0) { //check if Alex has reached an exit
                 std::pair<std::size_t, std::size_t> target = myCoord; //use the predecessor and directions matrices to trace back the directions to the shortest path
                 while(target != init_coordinate){
                    plan.push_back(directions[target.first][target.second]);
                    target = pred[target.first][target.second];
                 }
                 reverse(plan.begin(), plan.end());
                 return plan;
            }
            else{ //if the exit is not reached, push to the queue the cases where Alex goes either straight or left while keeping track of predecessors, directions and orientations
                if(!visited[myCoord.first-1][myCoord.second] && !M[myCoord.first-1][myCoord.second]) {
                    visited[myCoord.first-1][myCoord.second] = true;
                    pred[myCoord.first-1][myCoord.second]=myCoord;
                    directions[myCoord.first-1][myCoord.second] = go_straight;
                    myQ.push(std::make_pair(myCoord.first-1, myCoord.second));
                    h[myCoord.first-1][myCoord.second] = North;
                }
                if(!visited[myCoord.first][myCoord.second-1] && !M[myCoord.first][myCoord.second-1]) {
                    visited[myCoord.first][myCoord.second-1] = true;
                    pred[myCoord.first][myCoord.second-1] = myCoord;
                    directions[myCoord.first][myCoord.second-1] = go_left;
                    myQ.push(std::make_pair(myCoord.first, myCoord.second-1));
                    h[myCoord.first][myCoord.second-1] = West;
                }  
            }   
        } 
        if(h[myCoord.first][myCoord.second] == South) { //do the same for other cases
            if(myCoord.first == m-1) {
                 std::pair<std::size_t, std::size_t> target = myCoord;
                 while(target != init_coordinate){
                    plan.push_back(directions[target.first][target.second]);
                    target = pred[target.first][target.second];
                 }
                 reverse(plan.begin(), plan.end());
                 return plan;
            }
            else{
                if(!visited [myCoord.first+1][myCoord.second] && !M[myCoord.first+1][myCoord.second]) {
                    visited[myCoord.first+1][myCoord.second] = true;
                    pred[myCoord.first+1][myCoord.second] = myCoord;
                    directions[myCoord.first+1][myCoord.second] = go_straight;
                    myQ.push(std::make_pair(myCoord.first+1, myCoord.second));
                    h[myCoord.first+1][myCoord.second] = South;
                }
                if(!visited [myCoord.first][myCoord.second+1] && !M[myCoord.first][myCoord.second+1]){
                    visited [myCoord.first][myCoord.second+1] = true;
                    pred [myCoord.first][myCoord.second+1] = myCoord;
                    directions [myCoord.first][myCoord.second+1] = go_left;
                    myQ.push(std::make_pair(myCoord.first, myCoord.second+1));
                    h[myCoord.first][myCoord.second+1] = East;
                }  
            }  
        }
        if(h[myCoord.first][myCoord.second] == East) { //do the same for other cases
            if(myCoord.second == n-1) {
                 std::pair<std::size_t, std::size_t> target = myCoord;
                 while(target != init_coordinate){
                    plan.push_back(directions[target.first][target.second]);
                    target = pred[target.first][target.second];
                 }
                 reverse(plan.begin(), plan.end());
                 return plan;
            }
            else{
                if(!visited [myCoord.first][myCoord.second+1] && !M[myCoord.first][myCoord.second+1]) {
                    visited [myCoord.first][myCoord.second+1] = true;
                    pred [myCoord.first][myCoord.second+1] = myCoord;
                    directions [myCoord.first][myCoord.second+1] = go_straight;
                    myQ.push(std::make_pair(myCoord.first, myCoord.second+1));
                    h[myCoord.first][myCoord.second+1] = East;
                }
                if(!visited [myCoord.first-1][myCoord.second] && !M[myCoord.first-1][myCoord.second]) {
                    visited [myCoord.first-1][myCoord.second] = true;
                    pred [myCoord.first-1][myCoord.second] = myCoord;
                    directions [myCoord.first-1][myCoord.second] = go_left;
                    myQ.push(std::make_pair (myCoord.first-1, myCoord.second));
                    h[myCoord.first-1][myCoord.second] = North;
                }  
            }  
        }
        if(h[myCoord.first][myCoord.second] == West) { //do the same for other cases
            if(myCoord.second == 0) {
                 std::pair<std::size_t, std::size_t> target = myCoord;
                 while(target != init_coordinate){
                    plan.push_back(directions[target.first][target.second]);
                    target = pred[target.first][target.second];
                 }
                 reverse(plan.begin(), plan.end());
                 return plan;
            }
            else{
                if(!visited [myCoord.first][myCoord.second-1] && !M[myCoord.first][myCoord.second-1]) {
                    visited [myCoord.first][myCoord.second-1] = true;
                    pred[myCoord.first][myCoord.second-1] = myCoord;
                    directions [myCoord.first][myCoord.second-1] = go_straight;
                    myQ.push(std::make_pair(myCoord.first, myCoord.second-1));
                    h[myCoord.first][myCoord.second-1] = West;
                }
                if(!visited [myCoord.first+1][myCoord.second] && !M[myCoord.first+1][myCoord.second]) {
                    visited [myCoord.first+1][myCoord.second] = true;
                    pred [myCoord.first+1][myCoord.second] = myCoord;
                    directions [myCoord.first+1][myCoord.second] = go_left;
                    myQ.push(std::make_pair(myCoord.first+1, myCoord.second));
                    h[myCoord.first+1][myCoord.second] = South;
                }  
            }  
        }
    }
    return plan; //return an empty vector if plan has not been returned already
}
