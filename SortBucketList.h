#ifndef SORTBUCKETLIST_H
#define SORTBUCKETLIST_H

#include <iostream>
#include <cstring>

using namespace std;

//Precondition: All array elements must be of integer type
class SortBucketList
{
    private:
        int position;
        int * arr;
        int sz;

    public:
        SortBucketList();
        SortBucketList(int);
        SortBucketList(int*, int);
        ~SortBucketList();
        void insertElement(int element);
        void setSize(int newSz);
        void setArray(int * arr);
        int * getArray();
        int getSize();
        int getPosition();
        void RadixSort();
        void CountSort(int);
};
#endif // SORTBUCKETLIST_H
