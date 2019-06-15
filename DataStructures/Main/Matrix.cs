using System;
using System.Collections.Generic;
using System.Text;
using Collections;

namespace Main
{
    public static class MatrixMain
    {
        public static void All()
        {
            MatrixMain.Constructor();
            MatrixMain.Fill();
            MatrixMain.OperatorAccess();
        }
        public static void Constructor()
        {
            Console.WriteLine("=== Matrix Constructors ===");

            Console.WriteLine("--- Matrix Constructor(1) ---");
            Matrix<int> mat_c1_01 = new Matrix<int>(2, 3, 4);
            Console.WriteLine($"{mat_c1_01}");
            Matrix<int> mat_c1_02 = new Matrix<int>(2, 3);
            Console.WriteLine($"{mat_c1_02}");

            Console.WriteLine("--- Matrix Constructor(2) ---");
            Matrix<int> mat_c2_01 = new Matrix<int>(2, 3, 4);
            Console.WriteLine($"{mat_c2_01}");
            Matrix<int> mat_c2_02 = new Matrix<int>(2, 3);
            Console.WriteLine($"{mat_c2_02}");

            Console.WriteLine();
        }

        public static void Fill()
        {
            Console.WriteLine("--- Matrix Fill(1) ---");
            Matrix<int> mat_01 = new Matrix<int>(2, 3, 4);
            mat_01.Fill(-1);
            Console.WriteLine($"{mat_01}");
            Matrix<int> mat_02 = new Matrix<int>(2, 3);
            mat_02.Fill(5);
            Console.WriteLine($"{mat_02}");
        }

        public static void OperatorAccess()
        {
            Console.WriteLine("--- Matrix OperatorAccess(1,2) ---");
            Matrix<int> mat_01 = new Matrix<int>(2, 3);
            int[,] array = new int[2, 3] { {1,2,3}, {4,5,6} };
            for (int row_index = 0; row_index < 2; row_index++)
            {
                for (int col_index = 0; col_index < 3; col_index++)
                {
                    // Console.WriteLine($"Adding {array[row_index, col_index]} to {row_index}, {col_index}");
                    mat_01[row_index, col_index] = array[row_index, col_index];
                }
            }
            Console.WriteLine($"{mat_01}");
        }
    }
}
