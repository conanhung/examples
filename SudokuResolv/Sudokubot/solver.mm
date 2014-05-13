//
//Copyright 2011 Haoest
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

//
//  solver.m
//  Sudokubot
//
//  Created by Haoest on 4/5/11.
//  Copyright 2011 none. All rights reserved.
//

#import "cvutil.hpp"
#import "solver.hpp"

using namespace std;

@implementation solver

@synthesize board;

int boardUnitIndexes[9][9] = {
    {0,1,2, 9, 10, 11, 18, 19, 20},
    {3,4,5, 12,13, 14, 21, 22, 23},
    {6,7,8, 15,16, 17, 24, 25, 26},
    
    {27,28,29, 36,37,38, 45,46,47},
    {30,31,32, 39,40,41, 48,49,50},
    {33,34,35, 42,43,44, 51,52,53},
    
    {54,55,56, 63,64,65, 72,73,74},
    {57,58,59, 66,67,68, 75,76,77},
    {60,61,62, 69,70,71, 78,79,80}};

int * getUnitSequence(int row, int column);


+(solver*) solverWithHints: (int**) hints{
    solver *rv = [[solver alloc] init];
    rv.board = new int*[9];
    for (int i=0; i<9; i++){
        rv.board[i] = new int[9];
    }
    for (int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            rv.board[i][j] = hints[i][j];
        }
    }
    return rv;
}

set<int> getBagOfNine(){
    set<int> rv;
    for(int i=1; i<10; i++){
        rv.insert(i);
    }
    return rv;
}

int* getUnitSequence(int row, int column){
    int r = row/3;
    int c = column/3;
    return boardUnitIndexes[r*3+c];
}

set<int> getBoxSampleSpace(int **currentBoard, int rowPosition, int columnPosition){
    if (currentBoard[rowPosition][columnPosition]>0){
        set<int> empty;
        return empty;
    }
    set<int> rv = getBagOfNine();
    for(int i=0; i<9; i++){
        set<int>::iterator it;
        if ((it = rv.find(currentBoard[rowPosition][i])) != rv.end()){
            rv.erase( it );
        }
        if ((it = rv.find(currentBoard[i][columnPosition])) != rv.end()){
            rv.erase( it );
        }
    }
    int *unitSequence = getUnitSequence(rowPosition, columnPosition);
    for(int i=0; i<9; i++){
        int ordinalIndex = unitSequence[i];
        rv.erase(currentBoard[ordinalIndex/9][ordinalIndex%9]);
    }
    return rv;
}

bool isUniqueInRowColumnUnit(int** currentBoard, int boxValue, int boxIndex){
    int row = boxIndex /9;
    int column = boxIndex %9;
    int *unitSequence = getUnitSequence(row, column);
    for (int i=0; i<9; i++){
        //row
        if (currentBoard[row][i] == boxValue){
            return false;
        }
        //column
        if (currentBoard[i][column] == boxValue){
            return false;
        }
        //unit
        int ordinalIndex = unitSequence[i];
        if (currentBoard[ordinalIndex/9][ordinalIndex%9] == boxValue){
            return false;
        }
    }
    return true;
}

bool trySolveRecursively(int** currentBoard, set<int> boxSpace[9][9], int boxIndex){
    if (boxIndex == 9*9){
        return true;
    }
    set<int> &curBox = boxSpace[boxIndex/9][boxIndex%9];
    if (curBox.size() ==0){ // is hint
        return trySolveRecursively(currentBoard, boxSpace, boxIndex+1);
    }
    for(set<int>::iterator it = curBox.begin(); it != curBox.end(); it++){
        if (isUniqueInRowColumnUnit(currentBoard, *it, boxIndex)){
            currentBoard[boxIndex/9][boxIndex%9] = *it;
            if (trySolveRecursively(currentBoard, boxSpace, boxIndex+1)){
                return true;
            }
        }
    }
    currentBoard[boxIndex/9][boxIndex%9] = 0;
    return false;
}

//return null if no solution
-(int**) trySolve{
    set<int> boxSpace[9][9];
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            boxSpace[i][j] = getBoxSampleSpace(board, i,j);
        }
    }
    if( trySolveRecursively(board, boxSpace, 0)){
        return board;
    }
    return nil;
}

+(bool) verifySolution: (int**) completedBoard{
    int **board = completedBoard;
    for (int i=0; i<9; i++){
        for(int j=0; j<8; j++){
            int *unitSequence = boardUnitIndexes[i];
            for (int k=j+1; k<9; k++){
                // horizontal check
                if (board[i][k] == board[i][j]){
                    return false;
                }
                // vertical
                if (board[k][i] == board[j][i]){
                    return false;
                }
                // unit
                int ordinalIndex_j = unitSequence[j];
                int ordinalIndex_k = unitSequence[k];
                if (board[ordinalIndex_j/9][ordinalIndex_j%9] == board[ordinalIndex_k/9][ordinalIndex_k%9]){
                    return false;
                }
            }
        }
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int gridValue = board[i][j];
            if (gridValue <= 0 || gridValue > 9){
                return false;
            }
        }
        
    }
    return true;
}

+(bool) verifyHints:(int**) hints{
    int **board = hints;
    for (int i=0; i<9; i++){
        for(int j=0; j<8; j++){
            int *unitSequence = boardUnitIndexes[i];
            for (int k=j+1; k<9; k++){
                // horizontal check
                if (board[i][k] == board[i][j] && board[i][j] != 0){
                    return false;
                }
                // vertical
                if (board[k][i] == board[j][i] && board[j][i] != 0){
                    return false;
                }
                // unit
                int ordinalIndex_j = unitSequence[j];
                int ordinalIndex_k = unitSequence[k];
                if (board[ordinalIndex_j/9][ordinalIndex_j%9] != 0 && board[ordinalIndex_j/9][ordinalIndex_j%9] == board[ordinalIndex_k/9][ordinalIndex_k%9]){
                    return false;
                }
            }
        }
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int gridValue = board[i][j];
            if (gridValue < 0 || gridValue > 9){
                return false;
            }
        }
        
    }
    return true;
}


- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

- (void)dealloc
{
    [super dealloc];

}


@end
