# 想法
1. 進 ```while true``` 迴圈先依魔王順序放炸彈
2. 移動所有魔王, 並在移動後順便標記踩到炸彈的魔王所在的位置 (可以用map<pair<int, int>,  int> // 0: 無炸彈, 1: 有炸彈, 2: 被踩)
3. 迭代整個map並依序刪除被標記的位置
4. 檢查所有魔王是否還活著 (全gg了就break ```while true``` 迴圈)

C++按照題目模擬約4ms
[題目連結](https://zerojudge.tw/ShowProblem?problemid=g276)
