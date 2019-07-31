using System;

namespace DS.Collections
{
    public class Matrix<T>
    {
        public enum MatrixOrder
        {
            RowMajor, ColumnMajor
        }
        protected T[] _Matrix;
        public int[] Dimensions { get; protected set; }
        public MatrixOrder Order { get; private set; } = MatrixOrder.RowMajor;
        public Matrix(params int[] dims)
        {
            Dimensions = dims;
            int totalNoOfElements = 1;
            foreach(int dim in dims)
            {
                totalNoOfElements *= dim;
            }
            _Matrix = new T[totalNoOfElements];
            Array.Fill(_Matrix, default);
        }
        public void Fill(T value)
        {
            Array.Fill(_Matrix, value);
        }
        public T this[params int[] dims]
        {
            // Reference: https://en.wikipedia.org/wiki/Row-_and_column-major_order
            get
            {
                if (dims.Length != Dimensions.Length)
                {
                    throw new IndexOutOfRangeException();
                }
                int pos = 0;
                int dimMultiplier = 1;
                if (Order == MatrixOrder.RowMajor)
                {
                    for (int index = Dimensions.Length - 1; index >= 0; index--)
                    {
                        pos += (dimMultiplier * dims[index]);
                        dimMultiplier *= Dimensions[index];
                    }
                }
                if (Order == MatrixOrder.ColumnMajor)
                {
                    for (int index = 0; index < Dimensions.Length; index++)
                    {
                        pos += (dimMultiplier * dims[index]);
                        dimMultiplier *= Dimensions[index];
                    }
                }
                if (pos >= _Matrix.Length)
                {
                    throw new IndexOutOfRangeException();
                }
                return _Matrix[pos];
            }
            set
            {
                if (dims.Length != Dimensions.Length)
                {
                    throw new IndexOutOfRangeException();
                }
                int pos = 0;
                int dimMultiplier = 1;
                if (Order == MatrixOrder.RowMajor)
                {
                    for (int index = Dimensions.Length - 1; index >= 0; index--)
                    {
                        pos += (dimMultiplier * dims[index]);
                        dimMultiplier *= Dimensions[index];
                    }
                }
                if (Order == MatrixOrder.ColumnMajor)
                {
                    for (int index = 0; index < Dimensions.Length; index++)
                    {
                        pos += (dimMultiplier * dims[index]);
                        dimMultiplier *= Dimensions[index];
                    }
                }
                if (pos >= _Matrix.Length)
                {
                    throw new IndexOutOfRangeException();
                }
                _Matrix[pos] = value;
                // Console.WriteLine($"Adding to {pos}, value {_Matrix[pos]}");
            }
        }
        public void Transpose()
        {
            if (Dimensions.Length != 2)
            {
                throw new InvalidOperationException();
            }
            for (int row_index = 0; row_index < Dimensions[0]; row_index++)
            {
                for (int col_index = 0; col_index < Dimensions[1]; col_index++)
                {
                    this[row_index,col_index] = this[col_index,row_index];
                }
            }
        }
        public override string ToString()
        {
            string rep = "";
            if (Dimensions.Length == 1)
            {
                for (int row_index = 0; row_index < Dimensions[0]; row_index++)
                {
                    rep += $"{_Matrix[row_index]} ";
                    rep += "\n";
                }
            }
            else if (Dimensions.Length == 2)
            {
                for (int row_index = 0; row_index < Dimensions[0]; row_index++)
                {
                    for (int col_index = 0; col_index < Dimensions[1]; col_index++)
                    {
                        rep += $"{_Matrix[row_index*Dimensions[1] + col_index]} ";
                    }
                    rep += "\n";
                }
            }
            else
            {
                rep += $"Matrix<{typeof(T)}>( ";
                for (int index = 0; index < Dimensions.Length; index++)
                {
                    if (index == Dimensions.Length - 1)
                        rep += $"{Dimensions[index]} ";
                    else
                        rep += $"{Dimensions[index]}, ";
                }
                rep += ")";
            }
            return rep;
        }
    }
}
