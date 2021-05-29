#ifndef SORTBUCKETLIST_CPP
#define SORTBUCKETLIST_CPP

#include "SortBucketList.h"

SortBucketList::SortBucketList()
{
    position = 0;
    arr = NULL;
    sz = 0;
}

SortBucketList::SortBucketList(int newSz)
{
    sz = newSz;
}

SortBucketList::SortBucketList(int *, int)
{
    position = 0;
    arr = NULL;
    sz = 0;
}

SortBucketList::~SortBucketList()
{
    position = 0;
    arr = NULL;
    sz = 0;
}

void SortBucketList::setArray(int * newArr)
{
    arr = newArr;
}

void SortBucketList::setSize(int newSz)
{
    sz = newSz;
}

int SortBucketList::getPosition()
{
    return position;
}

void SortBucketList::insertElement(int element)
{
    arr[position++] = element;
}

int SortBucketList::getSize()
{
    return sz;
}

int* SortBucketList::getArray()
{
    return arr;
}

void SortBucketList::RadixSort()
{
    int max = arr[0];

    for(int i = 0; i < sz; i++)
        if(arr[i] > max)
            max = arr[i];

    for(int exp = 1; max / exp > 0; exp *= 10)
        CountSort(exp);
}

void SortBucketList::CountSort(int exp)
{
    int * Count = new int[10];

    memset(Count, 0, 10 * sizeof(arr[10]));

    for(int i = 0; i < sz; i++)
        Count[(arr[i]/exp) % 10]++;

    for(int index = 1; index < 10; index++)
        Count[index] += Count[index-1];

    int temp[sz];

    memset(temp, 0, sz * sizeof(arr[0]));

    for(int count = sz-1; count >= 0; count--)
    {
        temp[(Count[(arr[count]/exp) % 10])-1] = arr[count];
        Count[arr[count]/exp % 10]--;
    }

    for(int y = 0; y < sz; y++)
        arr[y] = temp[y];
}

#endif // SORTBUCKETLIST_CPP
