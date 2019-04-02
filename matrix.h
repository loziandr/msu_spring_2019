
#include<exception>


class Matrix
{
private:
    class Row
{
    int* row;
    int size;
public:
    int& operator[](int number)
    {
        if(number < size && number >= 0) return row[number];
        else throw std:: out_of_range("");
    }
    const int operator[](int number) const
    {
        if(number < size && number >= 0) return row[number];
        else throw std:: out_of_range("");
    }

    void initial(int cols)
    {
        row = new int[cols];
        size = cols;
    }
    int* deleted()
    {
        return row;
    }

};
    int amount_rows;
    int amount_colomes;
    Row* Rows;
public:
    Matrix(int rows, int cols)
    {
        amount_rows = rows;
        amount_colomes = cols;
        Rows = new Row[rows];
        for(int i = 0; i < rows; ++i) Rows[i].initial(cols);
    }

    Row operator[](int number)
    {
        if(number < amount_rows && number >= 0) return Rows[number];
        else throw std:: out_of_range("");
    }


    const Row operator[](int number) const
    {
        if(number < amount_rows && number >= 0) return Rows[number];
        else throw std:: out_of_range("");
    }
    bool operator == (const Matrix& right) const
    {
        if(amount_rows == right.amount_rows && amount_colomes == right.amount_colomes)
        {
            for(int i = 0; i < amount_rows; ++i)
                for(int j = 0; j < amount_colomes; ++j)
                {
                    if(Rows[i][j] != right[i][j]) return false;
                }
            return true;
        }
        return false;
    }

    bool operator != (const Matrix& right) const
    {
         return !((*this) == right);
    }

    int getRows() const
    {
        return amount_rows;
    }

	int getColumns() const
	{
        return amount_colomes;
	}

	Matrix& operator *= (int number)
	{
	    for(int i = 0; i < amount_rows; ++i)
            for(int j = 0; j < amount_colomes; ++j) Rows[i][j] *= number;
        return *this;
	}
   ~Matrix()
	{
	    for(int i = 0; i < amount_rows; ++i)
            delete [] Rows[i].deleted();
	    delete [] Rows;
	}
};


