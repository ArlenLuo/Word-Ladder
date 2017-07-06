# Word Ladder

Word ladder is a word game invented by Lewis Carroll. 

A word ladder puzzle begins with two words, and to solve the puzzle one must find a chain of other words to link the two, in which two adjacent words (that is, words in successive steps) differ by one letter. For example, dog->dig->pig. This is a program to find a word ladder based on two input words.

This program is based on DFS. Every time we change a letter and do duplicate check. If we reach a dead end, we do backtracking until we reach a conclusion.

### Compiler

Ubuntu g++

### Usage

<pre>
~$ make
~$ ./WordLadder
//Follow the instructions to input two words
</pre>

### Screenshot：

![](.\screenshot.jpg)

# 词语接龙

这是一个实现英语词语接龙游戏的程序。

游戏规则：如果start word是dog，destination word是pig，那么dog->dig->pig即视为一条ladder。这个程序基于DFS搜索，可以查找两个词之间是否存在这样的ladder并输出其中一条。

### 编译环境：

Ubuntu g++

### 用法：

<pre>
~$ make
~$ ./WordLadder
//再根据提示输入两个单词即可
</pre>

### 示例：

![](.\screenshot.jpg)
