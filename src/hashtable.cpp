#include "hash_table.hpp"
#include <iostream>
#include <stdexcept>

template <typename K, typename V>
HashTable<K, V>::HashTable() : table(DEFAULT_SIZE) {}

template <typename K, typename V>
int HashTable<K, V>::hashFunction(const K& key) const {
    return std::hash<K>()(key) % table.size();
}

template <typename K, typename V>
void  HashTable<K, V>::insert(const K& key, const V& value) {
    int index = hashFunction(key);
    for (auto& pair : table[index]){
        if (pair.first == key){
            pair.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
}


template <typename K, typename V>
void HashTable<K, V>::remove(const K& key){
   int index = hashFunction(key);
   table[index].remove_if([&key](const std::pair<K, V>& pair){
    return pair.first == key;
   });
}

template <typename K, typename V>
V HashTable<K, V>::find(const K& key) const {
    int index = hashFunction(key);
    for (const auto& pair : table[index]){
        if(pair.first == key){
            return pair.second;
        }
    }
    throw std::runtime_error("Key not found");
}


template<typename K, typename V>
bool HashTable<K, V>::contains(const K& key) const {
    int index = hashFunction(key);
    for (const auto& pair : table[index]){
        if(pair.first == key){
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
void HashTable<K, V>::print() const {
    for (size_t i = 0; i < table.size(); ++i){
        std:cout << "Bucket " << i << ": ";
        for (const auto& pair : table[i]){
            std:cout << "[" << pair.first << ": " << pair.second << "]";
        }
    std::cout << std::endl;
    }
}















