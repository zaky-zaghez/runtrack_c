#define SIZE 9
#define EMPTY 0

int is_valid(int grid[SIZE][SIZE], int row, int col, int num);

int find_empty_cell(int grid[SIZE][SIZE], int *row, int *col)
{
    for (*row = 0; *row < SIZE; (*row)++)
        for (*col = 0; *col < SIZE; (*col)++)
            if (grid[*row][*col] == EMPTY)
                return 1;
    return 0;
}

int is_valid(int grid[SIZE][SIZE], int row, int col, int num)
{
    // Vérifie la ligne
    for (int x = 0; x < SIZE; x++)
        if (grid[row][x] == num)
            return 0;

    // Vérifie la colonne
    for (int x = 0; x < SIZE; x++)
        if (grid[x][col] == num)
            return 0;

    // Vérifie le bloc 3x3
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[box_row + i][box_col + j] == num)
                return 0;

    return 1;
}

int sudoku_solver(int grid[SIZE][SIZE])
{
    int row, col;

    // Si plus de case vide, c'est résolu
    if (!find_empty_cell(grid, &row, &col))
        return 1;

    // Essai des chiffres 1-9
    for (int num = 1; num <= SIZE; num++)
    {
        if (is_valid(grid, row, col, num))
        {
            grid[row][col] = num;

            if (sudoku_solver(grid))
                return 1;

            grid[row][col] = EMPTY;
        }
    }

    return 0;
}