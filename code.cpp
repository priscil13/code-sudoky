# code-sudoky
using System;

class SudokuSolver
{
    private const int SIZE = 9;

    private int[,] grid = new int[SIZE, SIZE];

    public void InitializeGrid()
    {
        // Здесь вы можете заполнить сетку Судоку числами
        // Замените 0 на числа от 1 до 9, где 0 представляет пустую ячейку
        // Пример:
        grid = new int[,]
        {
            { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
            { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
            { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
            { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
            { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
            { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
            { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
            { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
            { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
        };
    }

    public void PrintGrid()
    {
        for (int row = 0; row < SIZE; row++)
        {
            for (int col = 0; col < SIZE; col++)
            {
                Console.Write(grid[row, col] + " ");
            }
            Console.WriteLine();
        }
    }

    public bool SolveSudoku()
    {
        int row, col;
        if (!FindUnassignedCell(out row, out col))
            return true;

        for (int num = 1; num <= SIZE; num++)
        {
            if (IsValidMove(num, row, col))
            {
                grid[row, col] = num;

                if (SolveSudoku())
                    return true;

                grid[row, col] = 0; // Отмена хода
            }
        }

        return false;
    }

    private bool FindUnassignedCell(out int row, out int col)
    {
        for (row = 0; row < SIZE; row++)
        {
            for (col = 0; col < SIZE; col++)
            {
                if (grid[row, col] == 0)
                    return true;
            }
        }

        row = -1;
        col = -1;
        return false;
    }

    private bool IsValidMove(int num, int row, int col)
    {
        return !UsedInRow(num, row) && !UsedInColumn(num, col) && !UsedInBox(num, row - row % 3, col - col % 3);
    }

    private bool UsedInRow(int num, int row)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (grid[row, col] == num)
