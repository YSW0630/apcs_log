1. 用奇偶差作為索引值做一次前綴和還有後綴和。（我將奇數索引設為1, 偶數索引設為2），同時紀錄其實際索引值（用來判斷待會合併時會不會有越界的問題）

For example:
```cpp 
std::map<int, std::pair<int, int>> prefix, suffix; // first是索引，second的pair first是前綴/後綴和，second的pair second是其的實際索引值
```

2. 再來，判斷是否有只取左/右邊的情況。（可用二分搜）
3. 最後，尋找前綴/後綴和是否存在索引值互補的情況，換句話說就是兩索引值相加是否等於0。若存在，可用二分搜不斷尋找其最大值。
