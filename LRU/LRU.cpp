// LRU.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
#include <list>
using namespace std;

//class LRUCache{
//	map<int, int> keyValueMap;
//	list<int> keyList;
//	int maxSize;
//
//private:
//	void insert(int key, int value) {
//		keyList.push_back(key);
//		keyValueMap[key]	= value;
//	}
//
//	void updateList(int key) {
//		keyList.remove(key);
//		keyList.push_back(key);	
//	}
//
//	void removeLRU() {
//		int key = keyList.front();
//		keyList.erase(keyList.begin());
//		keyValueMap.erase(keyValueMap.find(key));
//	}
//
//public:
//    LRUCache(int capacity) {
//        maxSize	= capacity;
//    }
//    
//    int get(int key) {
//		if (keyValueMap.find(key) == keyValueMap.end())
//		{
//			return -1;
//		}
//		else
//		{
//			updateList(key);
//			return keyValueMap[key];
//		}
//    }
//    
//    void set(int key, int value) {
//		if (keyValueMap.find(key) != keyValueMap.end())
//		{
//			updateList(key);
//			keyValueMap[key] = value;
//		}
//		else
//		{
//			if (keyValueMap.size() == maxSize) 
//			{
//				removeLRU();
//			}
//
//			insert(key, value);
//		}
//    }
//};

class LRUCache{
	map<int, pair<int, long long> > keyValueMap;
	map<long long, int> idKeyMap;

	long long id;
	int maxSize;

private:
	void insert(int key, int value) {
		idKeyMap[++id]		= key;
		keyValueMap[key]	= make_pair(value, id);
	}

	void updateList(map<int, pair<int, long long> >::iterator it) {
		map<long long, int>::const_iterator it2 = idKeyMap.find(it->second.second);
		idKeyMap.erase(it2);
		idKeyMap[++id]		= it->first;
		it->second.second	= id;
	}

	void removeLRU() {
		int key = idKeyMap.begin()->second;
		keyValueMap.erase(keyValueMap.find(key));
		idKeyMap.erase(idKeyMap.begin());
	}

public:
    LRUCache(int capacity) {
        maxSize	= capacity;
		id = 0;
    }
    
    int get(int key) {
		map<int, pair<int, long long> >::iterator it = keyValueMap.find(key);
		if (it == keyValueMap.end())
		{
			return -1;
		}
		else
		{
			updateList(it);
			return it->second.first;
		}
    }
    
    void set(int key, int value) {
		map<int, pair<int, long long> >::iterator it = keyValueMap.find(key);
		if (it != keyValueMap.end())
		{
			updateList(it);
			it->second.first = value;
		}
		else
		{
			if (keyValueMap.size() == maxSize) 
			{
				removeLRU();
			}

			insert(key, value);
		}
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
	LRUCache* cache = new LRUCache(2);
	cache->set(2, 2);
	cache->set(1, 1);
	cache->get(2);
	cache->set(4, 1);
	cache->get(1);
	cache->get(2);

	return 0;
}

