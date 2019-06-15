using System;

using Collections;

namespace Miscellaneous
{
    public class Board<T> : Matrix<T>
    {
        private int Width { get; set; } = 3;
        private int Height { get; set; } = 1;
        public Board(params int[] dims)
        {
            if (dims.Length == 2)
            {
                this.Dimensions = dims;
                int totalNoOfElements = 1;
                foreach (int dim in dims)
                {
                    totalNoOfElements *= dim;
                }
                this._Matrix = new T[totalNoOfElements];
                Array.Fill(_Matrix, default);
            }
            else
            {
                throw new InvalidOperationException();
            }
        }
        public override string ToString()
        {
            string rep = "";
            for (int row_index = 0; row_index < Dimensions[0]; row_index++)
            {
                rep += PrintRow(row_index);
            }
            return rep;
        }
        private string PrintRow(int row_index)
        {
            String rep = "";
            if (row_index == 0)
            {
                rep += "+";
                for (int index = 0; index < Dimensions[1]; index++)
                {
                    rep += "---+";
                }
                rep += "\n";
            }
            rep += "|";
            for (int index = 0; index < Dimensions[1]; index++)
            {
                rep += $" {_Matrix[row_index * Dimensions[1] + index]} |";
            }
            rep += "\n+";
            for (int index = 0; index < Dimensions[1]; index++)
            {
                rep += "---+";
            }
            rep += "\n";
            return rep;
        }
    }
}
