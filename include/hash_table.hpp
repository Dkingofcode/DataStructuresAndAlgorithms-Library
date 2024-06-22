#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <vector>
#include <list>
#include <utility>


template <typename K, typename V>
class HashTable {
    private:
         static const int DEFAULT_SIZE = 10;
         std::vector<std::list<std::pair<K, V>>> table;
         int hashFunction(const K& key) const;

         public:
             HashTable();

             void insert(const K& key, const V& value);
             void remove(const K& key);
             V find(const K& key) const;
             bool contains(const K& key) const;
             void print() const;
};

#include "hashtable.cpp"

#endif

