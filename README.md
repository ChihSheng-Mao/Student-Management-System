# Student Management System

## 專案介紹

本專案為 C++ Template 延伸自主練習作業，主題為「學生成績管理系統（Student Management System）」。

本程式使用 C++17 開發，結合 STL（Standard Template Library）與 Template Function，實作學生資料管理功能，包含新增、查詢、排序及成績統計等操作。

---

## 開發環境

- Language：C++
- Standard：C++17
- Compiler：g++
- Operating System：Windows / Linux

---

## 使用技術

- struct
- vector
- sort()
- Template Function
- Lambda Expression

---

## 功能介紹

- 新增學生資料
- 學號重複時覆蓋原資料
- 列出所有學生
- 依成績由高到低排序
- 依學號查詢學生
- 顯示成績統計
  - 平均分數
  - 最高分
  - 最低分
  - 及格人數
  - 不及格人數

---

## 資料結構

```cpp
struct Student
{
    string id;
    string name;
    int score;
};
```

所有學生資料使用 `vector<Student>` 儲存。

---

## Template Function

本專案實作了兩個 Template Function：

```cpp
template <class T>
T getMax(T a, T b);

template <class T>
T getMin(T a, T b);
```

並在成績統計功能中實際呼叫，用來計算最高分與最低分。

---

## 編譯方式

```bash
g++ -std=c++17 main.cpp -o main
```

---

## 執行方式

### Windows

```bash
main.exe
```

### Linux / macOS

```bash
./main
```

---

## 專案結構

```
Student-Management-System/
│
├── main.cpp
├── README.md
└── report.pdf
```

---

## 程式流程

```
主選單
   │
   ├── 新增學生
   ├── 列出學生
   ├── 成績排序
   ├── 查詢學生
   ├── 成績統計
   └── 離開程式
