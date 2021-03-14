package sbgo

import (
	"container/list"
)

const base = 769

type pp struct {
	key, value int
}

type MyHashMap struct {
	data []list.List
}

func (this *MyHashMap) hash(key int) int {
	return key % base
}

/** Initialize your data structure here. */
func Constructor() MyHashMap {
	return MyHashMap{make([]list.List, base)}
}

/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int) {
	h := this.hash(key)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if et := e.Value.(pp); et.key == key {
			e.Value = pp{key, value}
			return
		}
	}
	this.data[h].PushBack(pp{key, value})
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
	h := this.hash(key)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if et := e.Value.(pp); et.key == key {
			return et.value
		}
	}
	return -1
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int) {
	h := this.hash(key)
	for e := this.data[h].Front(); e != nil; e = e.Next() {
		if e.Value.(pp).key == key {
			this.data[h].Remove(e)
			return
		}
	}
}
