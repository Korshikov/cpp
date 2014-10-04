/* 
 * File:   big_integer_data.cpp
 * Author: delf
 * 
 * Created on 15 Июнь 2014 г., 14:26
 */

#include "big_integer_data.h"
#include <vector>
#include <cstdint>

big_integer_data::big_integer_data()
{
    counter = 0;
    /*data = new std::vector<singleWord>(1);
    data->resize(1);
    data->at(0) = 0;*/
}

big_integer_data::big_integer_data(const doubleWord& rhs) 
{

    if(((rhs<<wordSize==signByteArray[0])&&(!(rhs&(1<<(wordSize-1)))))||
       ((rhs<<wordSize==signByteArray[1])&&(rhs&(1<<(wordSize-1)))))
    {
        counter = rhs;
    }
    else
    {
        counter = 1;
        data = new std::vector<singleWord>;
        data->resize(2);
        data->at(0) = rhs;
        data->at(1) = rhs>>wordSize;
    }
}

big_integer_data::big_integer_data(const big_integer_data& rhs)
{
    if(rhs.data)
    {
        data = new std::vector<singleWord>;
        data->resize(rhs.size());
        std::copy(rhs.data->begin(),rhs.data->end(),data->begin());
        counter = 1;
    }
    else
    {
        counter = rhs.counter;
    }
}

big_integer_data::~big_integer_data() 
{
    if(data)
    {
        delete data;
    }
}

big_integer_data* big_integer_data::connect() 
{
    counter++;
    return this;
}

void big_integer_data::disconnect() 
{
    if(--counter==0)
    {
        this->~big_integer_data();
    }
}

big_integer_data& big_integer_data::normalize() {
    if(data)
    {
        indexType i= size()-1;
        if(at(i)&(1<<(wordSize-1))) //is negative
        {
            for(;(i>0)&&(at(i)==signByteArray[1])&&(at(i-1)&(1<<(wordSize-1)));i--){
                ;
            }
        }
        else
        {
            for(;(i>0)&&(at(i)==signByteArray[0])&&(!(at(i-1)&(1<<(wordSize-1))));i--)
            {
                ;
            }
        }
        if(i>1){
            data->resize(i+1);
            return *this;
        }
        else
        {
            counter=data->at(0);
            delete data;
        }
        
    }
    return *this;
}



indexType big_integer_data::size() const {            
    if(data)
    {
        return data->size();
    }
    else
    {
        return 1;
    }
}

big_integer_data& big_integer_data::resize(indexType newSize) 
{
    singleWord pad = signByteArray[at(size()-1)&(1<<(wordSize-1))];
    if(data)
    {
        if(size()==newSize)
        {
            big_integer_data* result = new big_integer_data(*this);
            return *result;
        }
        if(newSize>1)
        {
            big_integer_data* result = new big_integer_data(*this);
            result->data->resize(newSize,pad);
            return *result;
        }
        else
        {
            big_integer_data* result = new big_integer_data;
            result->counter = data->at(0);
            return *result;
        }
    }
    else
    {
        if(newSize==1)
        {
            return *(new big_integer_data(*this));
        }
        else
        {
            big_integer_data *result = new big_integer_data;
            result->data = new std::vector<singleWord>;
            result->data->resize(newSize,pad);
            result->data->at(0)= counter;
            result->counter = 1;
            return *result;
        }
    }
}

const singleWord& big_integer_data::at(const indexType& i) {
    if(i>=size())
    {
        return signByteArray[at(size()-1)&(1<<(wordSize-1))];
    }
    if(data)
    {
        return data->at(i);
    }
    else
    {
        return counter;
    }
}

singleWord& big_integer_data::modifideAt(const indexType& i) {
    if(data)
    {
        return data->at(i);
    }
    else
    {
        return counter;
    }
}
