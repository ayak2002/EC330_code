#include <vector>
#include <string>
#include "bfilter.h"

//source for APHash: http://www.partow.net/programming/hashfunctions/index.html#StringHashing
//source for FNV: https://www.programmingalgorithms.com/algorithm/fnv-hash/cpp/
//source for MurmurHash: https://stackoverflow.com/questions/7666509/hash-function-for-string


class FNV : public HashFun {
    unsigned int operator()(const std::string& key){
        unsigned int h = 2166136261;
        int i;

        for ( i = 0; i < key.length(); i++ ){
            h = ( h * 16777619) ^ key[i];
        }
        return h;
    }
};

class APHash : public HashFun {
    unsigned int operator()(const std::string& key) {
        unsigned int hash = 0xAAAAAAAA;
        for (int i = 0; i < key.length(); i++){
            hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ (key[i]) * (hash >> 3)) :
                                     (~((hash << 11) + ((key[i]) ^ (hash >> 5))));
        }

        return hash;
    }
};


class MurmurHash : public HashFun {
    unsigned int operator()(const std::string& key) {
        unsigned long h = 525201411107845655ull;
        for (int i = 0; i < key.length(); i++) {
            h ^= key[i];
            h *= 0x5bd1e9955bd1e995;
            h ^= h >> 47;
        }
  return h;
    }
};

void BloomFilter::add_hash_funs() {
    FNV *h1 = new FNV();
    APHash *h2 = new APHash();
    MurmurHash *h3 = new MurmurHash();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
    this->hash_funs.push_back(h3);
}


void BloomFilter::insert(const std::string& key) {
    for(int i = 0; i < this->hash_funs.size(); i++) {
        int hash_result = this->call_hash(i, key) % 330;
        (this->filter)[hash_result] = 1;
    }
}

bool BloomFilter::member(const std::string& key) {
    for(int i = 0; i < this->hash_funs.size(); i++) {
        unsigned int hash = this->call_hash(i, key);
        if((this->filter)[hash % 330] == 0) {
            return false;
        }
    }
    return true;
}
