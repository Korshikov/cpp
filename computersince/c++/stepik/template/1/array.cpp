#include <cstddef>

template <typename T>
class Array
{
    // Список операций:
    //
    // explicit Array(size_t size = 0, const T& value = T())
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    //
    // Array(const Array &)
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    //
    // ~Array()
    //   деструктор, если он вам необходим.
    //
    // Array& operator=(...)
    //   оператор присваивания.
    //
    // size_t size() const
    //   возвращает размер массива (количество
    //                              элементов).
    //
    // T& operator[](size_t)
    // const T& operator[](size_t) const
    //   две версии оператора доступа по индексу.
public:
    explicit Array(size_t size = 0, const T& value = T()):
    data(new T[size]),size_(size)
    {
        for(size_t t=0;t<size_;++t)
        {
            data[t]=value;
        }
    }

    Array(const Array & rhs):
    data(new T[rhs.size()]),size_(rhs.size())
    {
        for(size_t t=0;t<size_;++t)
        {
            data[t]=rhs[t];
        }
    }

    Array& operator=(const Array & rhs)
    {
        if(this!=&rhs)
        {
            delete[] data;
            size_ = rhs.size_;
            data = new T[size_];
            for(size_t t=0;t<size_;++t)
            {
                data[t]=rhs[t];
            }
        }
        return (*this);
    }

    ~Array()
    {
        delete[] data;
    }    

    size_t size() const
    {
        return size_;
    }

    T& operator[](size_t i)
    {
        return data[i];
    }
    
    const T& operator[](size_t i) const
    {
        return data[i];
    }


private:
    T* data;
    size_t size_;
};