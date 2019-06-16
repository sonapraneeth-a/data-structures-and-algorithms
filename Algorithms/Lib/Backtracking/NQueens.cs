using System;
using System.Collections.Generic;
using Miscellaneous;

namespace Backtracking
{
    public static class NQueens
    {
        static char queen = 'Q';
        static char empty = '-';
        public static void Solve(int N)
        {
            Board<char> board = new Board<char>(N, N);
            board.Fill(empty);
            Helper(board, N);
        }
        public static void Helper(Board<char> board, int N)
        {
            if (N == 0)
            {
                Console.WriteLine("Final solution");
                Console.WriteLine($"{board}");
                return;
            }
            else
            {
                int numRows = board.Dimensions[0];
                int numCols = board.Dimensions[1];
                for (int row_index = 0; row_index < numRows; row_index++)
                {
                    for (int col_index = 0; col_index < numCols; col_index++)
                    {
                        Console.WriteLine("Finding safe position for this board");
                        Console.WriteLine($"{board}");
                        Tuple<int, int, bool> position = FindSafePosition(ref board);
                        if (position.Item3 == true)
                        {
                            Console.WriteLine($"Safe position: {position}");
                            board[position.Item1, position.Item2] = 'Q';
                            Console.WriteLine($"{board}");
                            Helper(board, N - 1);
                        }
                        else
                        {
                            board[position.Item1, position.Item2] = empty;
                        }
                    }
                }
            }
        }
        private static Tuple<int, int, bool> FindSafePosition(ref Board<char> board)
        {
            int numRows = board.Dimensions[0];
            int numCols = board.Dimensions[1];
            Tuple<int, int, bool> SafePosition = Tuple.Create(0, 0, false);
            bool found = false;
            for (int row_index = 0; row_index < numRows; row_index++)
            {
                for (int col_index = 0; col_index < numCols; col_index++)
                {
                    Console.WriteLine($"Check if ({row_index}, {col_index}) is a safe position");
                    found = IsSafePosition(ref board, row_index, col_index);
                    if (found)
                    {
                        Console.WriteLine($"({row_index}, {col_index}) is a safe position");
                        SafePosition = Tuple.Create(row_index, col_index, true);
                        break;
                    }
                }
                if (found) break;
            }
            return SafePosition;
        }
        private static bool IsSafePosition(ref Board<char> board, int row_index, int col_index)
        {
            // Check row
            Console.Write($"Checking row ({row_index}): ");
            for(int index = 0; index < board.Dimensions[1]; index++)
            {
                Console.Write($"{index} ");
                if (board[row_index, index] == 'Q')
                {
                    Console.WriteLine("");
                    return false;
                }
            }
            Console.WriteLine("");
            // Check column
            Console.Write($"Checking col ({col_index}): ");
            for (int index = 0; index < board.Dimensions[0]; index++)
            {
                Console.Write($"{index} ");
                if (board[index, col_index] == 'Q')
                {
                    Console.WriteLine("");
                    return false;
                }
            }
            Console.WriteLine("");
            // Check left-to-right diagonal
            Console.Write("Checking left-to-right diagonal: ");
            int start_row = (row_index >= col_index ? row_index - col_index : 0);
            int start_col = (col_index >= row_index ? col_index - row_index : 0);
            while (start_row < board.Dimensions[0] && start_col < board.Dimensions[1])
            {
                Console.Write($"({start_row},{start_col}) ");
                if (board[start_row, start_col] == 'Q')
                {
                    Console.WriteLine("");
                    return false;
                }
                start_row++; start_col++;
            }
            Console.WriteLine("");
            // Check right-to-left diagonal
            if (row_index + col_index < board.Dimensions[0])
            {
                start_row = row_index + col_index;
                start_col = 0;
            }
            else
            {
                start_row = board.Dimensions[0] - 1;
                start_col = col_index - (board.Dimensions[0] - 1 - row_index);

            }
            Console.Write("Checking right-to-left diagonal: ");
            while (start_row >= 0 && start_col < board.Dimensions[1])
            {
                Console.Write($"({start_row},{start_col}) ");
                if (board[start_row, start_col] == 'Q')
                {
                    Console.WriteLine("");
                    return false;
                }
                start_row--; start_col++;
            }
            Console.WriteLine("");
            return true;
        }
    }
}
