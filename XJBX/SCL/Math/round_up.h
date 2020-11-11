//将一个数向上取整到8的倍数

unsigned Round_Up(unsigned bytes){
    return ((bytes + 7) & ~(7));
}