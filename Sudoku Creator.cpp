#include <iostream>
#include "Validator.h"

static const int x = 9;	// Static because global variable and we don't want redefinition we indicate that it is the same variable throughout program.  Source: https://youtu.be/j0_u26Vpb4w?list=PLrOv9FMX8xJEEQFU_eAvYTsyudrewymNl&t=254
static const int y = 9;	// If it's not const then it won't act like we want it to(and array requires const)

void printArray(int(&arr)[x][y]) {
    for (int i = 0; i < 9; i++)
    {
        std::cout << "  ";
        for (int j = 0; j < 9; j++)
        {
            if (!(j % 3) && (j != 0)) std::cout << "| "; // space vertically
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
        if (i == 2 || i == 5) std::cout << "  =====================" << std::endl; // space horizontally and organize
    }
}

bool check_in_box(int arr[][9], int X, int Y, int &boxNum, int currentNum) {
    if (!(X % 3)) { // in 0,3,6
        switch (X)
        {
        default:
            break;
        }
    }
    if (false);

    return false;
}

bool check_col_and_row(int(&arr)[x][y], int X = 0, int Y = 0, int boxNum = 0, int currentNum = -1) // fills potential spots with -currentNum
{
    // check row
        // check forward from y (depends on y)
        // check bacward from y

    bool result = false; // found placement options
    bool Placed = false;
    int potential = 0;    // to loop through random
    int potential_coordinates[1][1];
    int box = 0;

    int Checked = 0;

    //==========================
    // check X in box# ?
    if (Y < 3) {
        box = 1;

    }
    else if ((Y < 6) and (Y > 2)) {
        box = 2;

    }else {
        box = 3;
                
    }
    //==========================

    // if placed false for all in row
    while (Checked <= 2) 
    {
        for (int i = 0; i < 9; i++) {
            if ((arr[X][i] == currentNum) && (!Placed)) {
                Placed = true;
            }
            else if ((!Placed) && (Checked == 1)) {
                // if in same box as X then mark potential

                if ((i < 3) and (box == 1)) {
                    potential++; 
                    arr[X][i] = -currentNum;
                    result = true; // found a potential spot
                }
                else if (((i < 6) and (i > 2)) && (box == 2)) {
                    potential++;
                    arr[X][i] = -currentNum;
                    result = true;
                }
                else if ((i > 5) && (box == 3)){
                    potential++;
                    arr[X][i] = -currentNum;
                    result = true;
                }
                //==========================



            }
        }
        Checked++;
    }

    

    // check column

    //printArray(arr); // test

    return false;
}

bool fill_Sudoku(int(&arr)[x][y]) {
    
#if 0
    int currentNum = 1;
    // Loop through Sudoku
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            // call check if position valid for placing
            if (check_col_and_row(arr, i, j, 0, currentNum)) {
                // if true
                // set current number to posX posY
                /////arr[i][j] = currentNum;
            }
            
                // place number (keep acount that number was placed in box)

        }
        std::cout << std::endl;
        if (i == 2 || i == 5) std::cout << "=====================" << std::endl; // space horizontally and organize
    }
    
#endif

    // testing
    check_col_and_row(arr, 8, 4, 0, 1);

    //test print
    printArray(arr);

    return false;
}

int main()
{
    // create Sudoku template
    int sudoku[9][9] = {
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},

        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},

        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0}
    };

    //printArray(sudoku); // test

    ////========================
    // create completed Sudoku
    fill_Sudoku(sudoku);

    // if number couldn't be filled in
        // call number swaper



    //set valid if not in array of number. Well, yes but no
}