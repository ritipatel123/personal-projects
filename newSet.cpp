//
//  newSet.cpp
//  project2
//
//  Created by Riti Patel on 4/13/24.
//

#include <iostream>
#include <string>
#include "newSet.h"
using namespace std;

Set::Set() {
    m_size = 0;
    m_max = DEFAULT_MAX_ITEMS;
    m_items = new ItemType[m_max];
}

Set::Set(int max) {
    m_size = 0;
    m_max = max;
    m_items = new ItemType[m_max];
}

Set::~Set() {
    delete [] m_items;
}

Set::Set(const Set& other) {
    m_size = other.m_size;
    m_max = other.m_max;
    m_items = new ItemType[m_max];

    for (int k = 0; k < m_size; k++) {
        m_items[k] = other.m_items[k];
    }
}
Set& Set::operator=(const Set& rhs) {
    if (this != &rhs)
        {
            Set temp(rhs);
            this->swap(temp);
        }

        return *this;
    }
bool Set::empty() const {
    return (m_size == 0);
}
int Set::size() const {
    return m_size;
}
bool Set::insert(const ItemType& value) {
    if (m_size >= m_max)
            return false;

        if (m_size == 0)
        {
            m_size = 1;
            m_items[0] = value;
            return true;
        }

        for (int i = 0; i < m_size; i++)
        {
            if (m_items[i] == value)
                return false;
        }

        for (int i = 0; i < m_size; i++)
        {
            if (m_items[i] > value)
            {

                for (int j = m_size; j > i; j--)
                {
                    m_items[j] = m_items[j - 1];
                }

                m_items[i] = value;
                m_size++;
                return true;
            }
        }

        m_items[m_size] = value;
        m_size++;

        return true;
    }

bool Set::erase(const ItemType& value) {
    for (int i = 0; i < m_size; i++)
        {
            if (m_items[i] == value)
            {
                for (int j = i; j < m_size - 1; j++)
                {
                    m_items[j] = m_items[j + 1];
                }
                m_size--;
                return true;
            }
        }

        return false;
    }
bool Set::contains(const ItemType& value) const {
    for (int k = 0; k < m_size; k++) {
        if (m_items[k] == value)
            return true;
    }
    return false;
}
bool Set::get(int i, ItemType& value) const {
    if ( !(0 <= i && i < m_size) )
        return false;

    ItemType item;
    // just do the same comparison each loop
    for (int j = 0; j < m_size; j++) {
        item = m_items[j];
        int counter = 0;
        for (int k = 0; k < m_size; k++) {
            if (k == j)
                continue;
            else {
                if (m_items[k] < item)
                    counter++;
            }
        }
        if (counter == i)
                  break;
          }

        value = item;
        return true;
      }

void Set::swap(Set& other) {
    int greater = m_size;
    if (other.size() > m_size)
        greater = other.size();
    for (int i = 0; i < greater; i++) {
        ItemType temp = m_items[i];
        m_items[i] = other.m_items[i];
        other.m_items[i] = temp;
    }
    int tempSize, tempMax;

    tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;

    tempMax = m_max;
    m_max = other.m_max;
    other.m_max = tempMax;
}
